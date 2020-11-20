#include "Menu.h"
#include "Role.h"
#include <fstream>
#include <iostream>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

using namespace std;

//Constructor of Hero，the input value is the User name.This function will check whether the this ID has game progress, if so, load it, otherwise it‘ll create a new one
Hero::Hero(string user_name)
{
	m_user_name = user_name;
	if (!LoadRecord())
	{
		Create();
		SaveRecord();
	}
}

//Adding a weapon. Input value ptr_weapon means adding weapon
void Hero::AddWeapon(shared_ptr<Weapon> ptr_weapon)
{
	m_weapons.push_back(ptr_weapon);
	m_attack_power += ptr_weapon->m_attack_gain;
	m_spell_power += ptr_weapon->m_spell_gain;
}

//Adding a equipment. Input value eqiupment means adding equipment
void Hero::AddEquipment(std::string eqiupment)
{
	m_equipment.push_back(eqiupment);
    m_defense +=10;
}

//Recovery HP and MP
void Hero::Recovery()
{
	m_health = 200;
	m_blue = 100;
}

//Show the information of the hero
void Hero::ShowInformation()
{   
	cout << "************************ Hero ************************" << endl;
	cout << "name : " << m_role_name << endl;
	cout <<RED<< "HP : " << m_health <<RESET<< endl;
	cout <<BLUE<<"MP : " << m_blue <<RESET <<endl;
	cout << "Attack power : " << m_attack_power << endl;
	cout << "Defense : " << m_defense << endl;
	cout << "Spell power : " << m_spell_power << endl;
	cout <<YELLOW <<"Money : " << m_money <<RESET<< endl;
	cout << "Stage : " << m_stage << endl;
        cout <<GREEN <<"Health Potion : " << m_bag[0] << endl;
        cout << "Mana Potion : " << m_bag[1] <<RESET<<endl;
	if (m_weapons.size())
	{
		cout << "Weapon list:\n\t";
		for (auto weapon : m_weapons)
		{
			cout << weapon->m_name << " ";
		}
		cout << endl;
	}
	if (m_equipment.size())
	{
		cout << "Equipment list:\n\t";
		for (auto equipment : m_equipment)
		{
			cout << equipment << " ";
		}
		cout << endl;
	}
	cout << "******************************************************" << endl;
	cout << endl;
}

//Load the record
bool Hero::LoadRecord()
{
	ifstream is(m_user_name);
	if (!is.is_open()) return false;
	else
    {           is >> m_role;
		is >> m_role_name;
		is >> m_attack_power;
		is >> m_spell_power;
		is >> m_defense;
		is >> m_health;
		is >> m_blue;
		is >> m_money;
		is >> m_stage;
                is >> m_bag[0];
                is >> m_bag[1];
		int size;
		is >> size;
		for (int i = 0; i < size; i++)
		{
			string weapon; is >> weapon;
			shared_ptr<Weapon> ptr_weapon = Factory::CreateWeapon(weapon);
			m_weapons.push_back(ptr_weapon);
		}
		is >> size;
		for (int i = 0; i < size; i++)
		{
			string equipment; is >> equipment;
			m_equipment.push_back(equipment);
		}
	}
	is.close();
	return true;
}

//Save the record
void Hero::SaveRecord()
{
	ofstream os(m_user_name);
        os << m_role << endl;
	os << m_role_name << endl;
	os << m_attack_power << endl;
	os << m_spell_power << endl;
	os << m_defense << endl;
	os << m_health << endl;
	os << m_blue << endl;
	os << m_money << endl;
	os << m_stage << endl;
        os << m_bag[0] << endl;
        os << m_bag[1] << endl;
    	os << m_weapons.size() <<endl;
	for (auto weapon : m_weapons)
	{
		os << weapon->m_name << endl;
	}
	os << m_equipment.size() << endl;
	for (auto equipment : m_equipment)
	{
		os << equipment << endl;
	}
	os.close();
	cout<<"Successfully saved!"<<endl;
}

//Create a new Hero
void Hero::Create()
{
	cout << "Create your hero:" << endl;
	Menu menu;
	int sel = menu.SelectHero();
	m_role_name = menu.GetContent(sel);
	m_money = 0;
	m_stage = 1;
	switch (sel)
	{
	case 0:
        m_role = 0;
		m_health = 200;
		m_blue = 100;
		m_attack_power = 40;
		m_spell_power = 10;
		m_defense = 40;
		m_bag[0]=1;
		m_bag[1]=1;
		break;
	case 1:
        m_role = 1;
		m_health = 200;
		m_blue = 100;
		m_attack_power = 10;
		m_spell_power = 40;
		m_defense = 25;
		m_bag[0]=1;
		m_bag[1]=1;
		break;
	case 2:
        m_role = 2;
		m_health = 200;
		m_blue = 100;
		m_attack_power = 30;
		m_spell_power = 20;
		m_defense = 30;
		m_bag[0]=1;
		m_bag[1]=1;
		break;
	default:
		break;
	}
}

//Creating a Monster based on the stage and dice
Monster::Monster(int stage, int dice)
{
	if (stage == 6)
	{
		m_role_name = "The Big Bad";
		m_health = 1000;
		m_blue = 100;
		m_attack_power = 80;
		m_defense = 80;
		m_spell_power = 50;
		m_reward = 0;
	}
	else
	{
		m_role_name = "Monster_" + to_string(stage) + "_" + to_string(dice);
		m_health = 100*stage+10*dice;
		m_blue = 100;
		m_attack_power = 10 * stage + (10 - dice) * 2;
		m_defense = 10 * stage + dice * 2;
		m_spell_power = stage * 10 + dice * 3;
		m_reward = 5 * stage + dice * 2;
	}
}

//Show the information of the Monster
void Monster::ShowInformation()
{  
	cout << "********************** Monster ***********************" << endl;
	cout << "name : " << m_role_name << endl;
	cout <<RED<<"HP : " << m_health <<RESET<< endl;
	cout << "MP : " << m_blue << endl;
	cout << "Attack power : " << m_attack_power << endl;
	cout << "Defense : " << m_defense << endl;
	cout << "Spell power : " << m_spell_power << endl;
	cout << YELLOW<<"Reward : " << m_reward <<RESET<< endl;
	cout << "******************************************************" << endl;
	cout << endl;
}
