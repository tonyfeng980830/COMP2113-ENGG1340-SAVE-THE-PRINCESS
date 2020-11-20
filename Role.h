#include <string>
#include <vector>
#include <memory>
#include "Weapon.h"

//The class of Role
class Role
{
public:
	//Name of the Role
	std::string m_role_name;
    
    int m_role;
	//Current Health Points of the role
	int m_health;
	//Current Magic Points of the role
	int m_blue;
	//Current Attack Power of the role
	int m_attack_power;
	//Current Spell Power of the role
	int m_spell_power;
	//Current Defense of the role
	int m_defense;

	int m_bag[2];
};

//The class of Hero, sub class inheriting from Base Class(Role)
class Hero : public Role
{
public:
	//Constructor of Hero，the input value is the User name.This function will check whether the this ID has game progress, if so, load it, otherwise it‘ll create a new one
	Hero(std::string user_name);
	//Adding a weapon. Input value ptr_weapon means adding weapon
	void AddWeapon(std::shared_ptr<Weapon> ptr_weapon);
	//Adding a equipment. Input value eqiupment means adding equipment
	void AddEquipment(std::string eqiupment);
	//Recovery HP and MP
	void Recovery();
	//Show the information of the hero
	void ShowInformation();
	//Save record
	void SaveRecord();
	//Money that the hero owned
	int m_money;
	//Current stage the hero in
	int m_stage;
    
    
private:
	//Load the record
	bool LoadRecord();
	//Create a new hero
	void Create();
	//The user name of the hero is bound to
	std::string m_user_name;
	//List of Weapon that the hero owned
	std::vector<std::shared_ptr<Weapon>> m_weapons;
	//List of Equipment that the hero owned
	std::vector<std::string> m_equipment;
};

//The class of Monster, sub class inheriting from Base Class(Role)
class Monster : public Role
{
public:
	//Creating a monster based on the stage and dice
	Monster(int stage, int dice);
	//Show the information of the monster
	void ShowInformation();
	int m_reward;
};

