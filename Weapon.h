#pragma once
#include <string>
#include <memory>
//Weapon
class Weapon
{
public:
	//Constructor
	Weapon();
	//Destructor
	~Weapon();
	//Name of weapons
	std::string m_name;
	//Money needed to buy weapons
	int m_value;
	//Physical attack power provided by the weapon
	int m_attack_gain;
	//Spell power provided by the weapon
	int m_spell_gain;
    
    int m_defense;
};

//Warrior's weapon
class Sword :public Weapon
{
public:
	Sword();
};

//Mage's weapon
class Wand :public Weapon
{
public:
	Wand();
}; 

//Marksman's weapon
class Crossbow :public Weapon
{
public:
	Crossbow();
};

//Weapon Factory
class Factory
{
public:
	//Create a weapon based on the id，the input value id represents the id of the weapon，corresponding to the Store's Menu，the return value is a smart pointer that points to a class object Weapon
	static std::shared_ptr<Weapon> CreateWeapon(int id);
	//Create a weapon according to the name of the weapon.The input value name represents the name of the weapon,and the return value is a smart pointer that points to a class object Weapon
	static std::shared_ptr<Weapon> CreateWeapon(std::string name);
};
