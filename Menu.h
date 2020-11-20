#pragma once
#include <string>
#include <vector>
//
class Menu
{
public:
	//Display the Welcome menu,and the user is prompted to create or login the account，The return value represents the index selected by the user
	int Welcome();
	//SelectHero menu，the user is prompted to select a hero，The return value represents the index selected by the user
	int SelectHero();
	//Homepage,The return value represents the index selected by the user
	int HomePage();
	//Store menu, the user is prompted to choose buy a weapon or equipment
	int Store();
	//Weapons menu, the user is prompted to select a weapon
	int Weapons();
	//Eequipment menu, the user is prompted to select a equipment
	int Equipment();
	//Action menu, the user is prompted to select (Attack,Bag,Leave)when fighting
	int Action();
	//Get the selection of the user.Input value represents the index selected by the user
    int Bag();
    
    int Potions();
    
   int Attackway(int role);
    
	std::string GetContent(int sel);
private:
	//Display the menu,and the user is prompted to input a value. The return value represents the index selected by the user
	int Show();
	//This variable preserves the menu options
	std::vector<std::string> m_items;
};

