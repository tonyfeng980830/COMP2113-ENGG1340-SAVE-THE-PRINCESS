#include "Weapon.h"
using namespace std;


//Constructor
Weapon::Weapon()
{
}

//Destructor
Weapon::~Weapon()
{
}

Sword::Sword()
{
	m_name = "Sword";
	m_attack_gain = 20;
	m_spell_gain = 0;
	m_value = 10;
}

Wand::Wand()
{
	m_name = "Wand";
	m_attack_gain = 5;
	m_spell_gain = 15;
	m_value = 10;
}

Crossbow::Crossbow()
{
	m_name = "Crossbow";
	m_attack_gain = 15;
	m_spell_gain = 5;
	m_value = 10;
}

//Create a weapon based on the id，the input value id represents the id of the weapon，corresponding to the Store's Menu，the return value is a smart pointer that points to a class object Weapon
shared_ptr<Weapon> Factory::CreateWeapon(int id)
{
	switch (id)
	{
	case 0:
		return shared_ptr<Weapon>(new Sword);
	case 1:
		return shared_ptr<Weapon>(new Wand);
	case 2:
		return shared_ptr<Weapon>(new Crossbow);
	default:
		return nullptr;
	}
}

//Create a weapon according to the name of the weapon.The input value name represents the name of the weapon,and the return value is a smart pointer that points to a class object Weapon
shared_ptr<Weapon> Factory::CreateWeapon(string name)
{
	if (name == "Sword")
		return shared_ptr<Weapon>(new Sword);
	else if (name == "Wand")
		return shared_ptr<Weapon>(new Wand);
	else if (name == "Crossbow")
		return shared_ptr<Weapon>(new Crossbow);
	else
		return nullptr;
}
