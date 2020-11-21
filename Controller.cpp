#include "Controller.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <unistd.h>
#include "Weapon.h"

using namespace std;
// this is the main function to run the game
void Controller::Run()
{
	string user_name;
	if (!EnterGame(user_name))
	{
		Exit();
		return;
	}
	Hero hero(user_name);

	Menu menu;
	while (true)						//this while-loop is to show the main menu for the game
	{
		int sel = menu.HomePage();
		switch (sel)
		{
		case 0:
			StayInVillage(hero);
			break;
		case 1:
			AdventureIsland(hero);
			break;
		case 2:
			Store(hero);
			break;
		case 3:
			hero.SaveRecord();
			break;
		case 4:
			Exit();
			return;
		}
	}
}

bool Controller::EnterGame(string &user_name)					// this function is use for when the user is first time into the game
{
	cout << "******************************************Welcome to Save the Princess******************************************" << endl;
	while (true)
	{
		Menu menu;
		int sel = menu.Welcome();
		if (sel == 0)
		{
			if (Login(user_name)) return true;
		}
		else if (sel == 1)
		{
			Register();
		}
		else
		{
			return false;
		}
	}
}

bool Controller::Login(string &user_name)				// this is login function
{
	cout << "User login:" << endl;
	map<string, string> datas; LoadUserDatabase(datas);
	string password;
	cout << "user name:";
	cin >> user_name;
	cout << "password:";
	cin >> password;
	if (datas.count(user_name) == 0)
	{
		cout << "User name does not exist!" << endl << endl; return false;
	}
	else if (datas[user_name] != password)
	{
		cout << "Password is incorrect!" << endl << endl; return false;
	}
	else
	{
		cout << "Login success!\n" << endl;
		return true;
	}
}

void Controller::Register()							// this is register function
{
	cout << "Register:" << endl;
	map<string, string> datas; LoadUserDatabase(datas);
	string user_name, password1, password2;
	do
	{
		cout << "Input user name:";
		cin >> user_name;
		if (datas.count(user_name))
		{
			cout << "User " << user_name << " is already exist!" << endl;
		}
		else
		{
			break;
		}
	} while (true);
	do
	{
		cout << "Set your password:";
		cin >> password1;
		cout << "Confirm your password:";
		cin >> password2;
		if (password1 != password2)
		{
			cout << "The two passwords are not the same!" << endl;
		}
	} while (password1 != password2);
	datas[user_name] = password1;
	SaveUserDatabase(datas);
	cout << "Register success!\n" << endl;
}

void Controller::Exit()								// function to show bye bye when exit the game
{
	cout << "Bye bye!" << endl;
}

void Controller::AdventureIsland(Hero & hero)						// when user choose AdventureIsland and will join to this function
{	if(hero.m_stage==7){

	cout<<"You have successfully complelted the game and save the princess!"<<endl;
	cout<<"If you want to play again, please create a new account! Thank you for you support!"<<endl;
	cout<<"After 15 second, we will back to menu."<<endl;
    sleep(15);
	return;


}
	cout << "You are in AdventureIsland now!\nCurrent stage : " << hero.m_stage<< endl;
	if (hero.m_stage == 6)
	{
		cout << "You meet the big boss!" << endl;
		Monster monster(hero.m_stage, 0);
		Fight(hero, monster);
		if (monster.m_health == 0) cout << "You have successfully defeated the \"final boss\" and saved the princess.Congratulations!" << endl;
		hero.m_stage++;
	}
	else
	{	cout<<"The coming dice number will decide the difficulty of the Monster!(higher number,stronger monster)"<<endl;
		sleep(3);
		int dice = rand() % 6 + 1;
		cout << "dice number:" << dice << endl;
		Monster monster(hero.m_stage, dice);
		Fight(hero, monster);
	}
}

void Controller::StayInVillage(Hero & hero) 				
{
	hero.Recovery();
	cout << "Hero's health and mana have been restored" << endl;
	sleep(2);
	hero.ShowInformation();
}

void Controller::Store(Hero & hero)
{
	Menu menu;
	int sel = menu.Store();
	switch (sel)
	{
	case 0:
		BuyWeapon(hero);
		break;
	case 1:
		BuyEuipment(hero);
		break;
    case 2:
        BuyPotions(hero);
        break;
	default:
		break;
	}
}

void Controller::BuyWeapon(Hero & hero)
{
	Menu menu;
	shared_ptr<Weapon> ptr_weapon = Factory::CreateWeapon(menu.Weapons());
	if (hero.m_money >= ptr_weapon->m_value)
	{
		cout << "You bought a " << ptr_weapon->m_name << ".\n" << endl;
		hero.m_money -= ptr_weapon->m_value;
		hero.AddWeapon(ptr_weapon);
	}
	else
	{
		cout << "Sorry,you don't have enough money yet.You can get money by killing monsters.\n" << endl;
	}
}

void Controller::BuyEuipment(Hero & hero)
{
	Menu menu;
	string equipment = menu.GetContent(menu.Equipment());
    if(hero.m_money >= 10){
	cout << "You bought a " << equipment << ".\n" << endl;
        hero.AddEquipment(equipment);
        hero.m_money -=10;
    }
    else{
        
        cout << "Sorry,you don't have enough money yet.You can get money by killing monsters.\n" << endl;
    }
}

void Controller::BuyPotions(Hero & hero)
{
    Menu menu;
    int buypotion = menu.Potions();
    
    if(hero.m_money>=5 && buypotion==0){
        cout << "You bought a Health Potion."<<endl;
        hero.m_bag[buypotion]+=1;
        hero.m_money -=5;
    }
    else if(hero.m_money>=5 && buypotion==1){
        cout << "You bought a Mana Potion."<<endl;
        hero.m_bag[buypotion]+=1;
        hero.m_money -=5;
    }
    else{
        cout << "Sorry,you don't have enough money yet.You can get money by killing monsters.\n" << endl;
    }
}

void Controller::Fight(Hero & hero, Monster & monster)
{
	cout << "\nFighting..." << endl;
	while (true)
	{	
		int stage_level=0;
		int leave = false;
		sleep(3);
		hero.ShowInformation();
		monster.ShowInformation();
		Menu menu;
		int action_hero = menu.Action();
		switch (action_hero)
		{
		case 0:
                while(!Attack(hero, monster)){
                    cout<<"You don't have enough mana!"<<endl;
                }
			
			break;
		case 1:
                if (!Bag(hero))
                {
                    cout << "You don't have this type of Potion." << endl;
			}
			break;
		case 2:
			leave = true;
			break;
		default:
			break;
		}
		if (leave)
		{
			cout << "You choosed leave." << endl;
			break;
		}
		if (monster.m_health <= 0)
		{
			cout << "Congratulations, you killed the monster!" << endl;
			hero.m_money += monster.m_reward;
			++stage_level;
			if(stage_level==3){ 
			hero.m_stage++;
			stage_level=0;}
			
			break;
		}
		int action_monster = 1;
		if (action_monster)
		{	
			int damage= monster.m_attack_power-hero.m_defense;
			if(damage<0){
			damage=0;
			}
			hero.m_health-=damage;
			cout<<"you are damaged by monster attack"<<"(HP -"<<damage<<")"<<endl;
		}
		if (hero.m_health <= 0)
		{
			cout << "You were killed by " << monster.m_role_name << endl;
			break;
		}
	}
	cout << "The battle is over!\n" << endl;
}

bool Controller::Attack(Role & attacker, Role & defender)
{
    Menu menu;
    int damage;
    int attackway =menu.Attackway(attacker.m_role);
    if(attackway==0&&attacker.m_role!=1){
        
        damage = attacker.m_attack_power - defender.m_defense;
        
    }
    else if(attackway == 0 && attacker.m_role == 1){
        
        damage = attacker.m_spell_power - defender.m_defense;

        
    }
    else if(attackway == 1 && attacker.m_role !=1){
        if(attacker.m_blue>=15){attacker.m_blue-=15;
            damage = attacker.m_attack_power*1.2 + attacker.m_spell_power - defender.m_defense;}
        else{return false;}
        
    }
    else{
        if(attacker.m_blue>=15){
        attacker.m_blue-=15;
            damage = attacker.m_spell_power*1.5 - defender.m_defense;}
        else{return false;}
        
    }
    if (damage < 0) damage = 0;
    defender.m_health -= damage;
    if (defender.m_health < 0) defender.m_health = 0;
	cout << attacker.m_role_name << " -> " << defender.m_role_name << "(By Attack),damage:" << damage << endl;
    
    return true;
}

bool Controller::Bag(Role & attacker)
{
    Menu menu;
    int bag_select= menu.Bag();
    if(bag_select==0&&attacker.m_bag[bag_select]>=1){
        
        attacker.m_health+=30;
	if(attacker.m_health>100)
		attacker.m_health=100;
        attacker.m_bag[bag_select]-=1;
        cout<< "Successfully used Health Potion!"<<endl;
    }
    if(bag_select==1&&attacker.m_bag[bag_select]>=1){
        
        attacker.m_blue+=30;
	if(attacker.m_blue>100)
		attacker.m_blue=100;
        attacker.m_bag[bag_select]-=1;
        cout<< "Successfully used Mana Potion!"<<endl;
    }
    else{
        return false;
    }

	return true;
}

void Controller::LoadUserDatabase(map<string, string> &datas)
{
	ifstream is("user_database");
	while (!is.eof())
	{
		string user_name, password;
		is >> user_name >> password;
		if (user_name.empty() || password.empty()) break;
		datas[user_name] = password;
	}
	is.close();
}

void Controller::SaveUserDatabase(map<string, string> &datas)
{
	ofstream os("user_database");
	int count = 0;
	for (auto data : datas)
	{
		os << data.first << " " << data.second;
		if (++count <= datas.size()) cout << endl;
	}
	os.close();
}
