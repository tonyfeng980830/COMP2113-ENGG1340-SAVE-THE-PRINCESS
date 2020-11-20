#include "Menu.h"
#include <iostream>
using namespace std;

//Display the menu,and the user is prompted to input a value. The return value represents the index selected by the user
int Menu::Show()
{	
	int sel = 0;
	cout<<"------------------------------------------------------"<<endl;
	do
	{
        for (int i = 0; i < m_items.size(); i++) {
            
            cout << i << "." << m_items[i]<<endl;
            
        }
	cout<<"------------------------------------------------------"<<endl;
		cout << "Please enter your choice:";
		cin >> sel;
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			sel=-1;
		}
		if (sel < 0 || sel >= m_items.size())
		{
			cout << "Your selection is out of range!" << endl;
		}
		cout << endl;
	} while (sel < 0 || sel >= m_items.size());

	for(int i =0;i<10;i++)
		cout<<endl;

	return sel;
}

//Display the Welcome menu,and the user is prompted to create or login the account，The return value represents the index selected by the user
int Menu::Welcome()
{
	m_items.clear();
	m_items.push_back("Login");
	m_items.push_back("Register");
	m_items.push_back("Exit");
	return Show();
}

//SelectHero menu，the user is prompted to select a hero，The return value represents the index selected by the user
int Menu::SelectHero()
{
	cout << "Select a hero:" << endl;
	m_items.clear();
	m_items.push_back("warrior");
	m_items.push_back("mage");
	m_items.push_back("marksman");
	return Show();
}

//Homepage,The return value represents the index selected by the user
int Menu::HomePage()
{
	cout << "HomePage" << endl;
	m_items.clear();
	m_items.push_back("Stay in the Village(Sleep a night for healing)");
	m_items.push_back("Go to the Adventure Island");
	m_items.push_back("Store");
	m_items.push_back("Save game progress");
	m_items.push_back("Exit");
	return Show();
}

//Store menu, the user is prompted to choose buy a weapon or equipment
int Menu::Store()
{
	cout << "What you need?" << endl;
	m_items.clear();
	m_items.push_back("Weapons");
	m_items.push_back("Equipment");
    m_items.push_back("Potions");
	return Show();
}

//Weapons menu, the user is prompted to select a weapon
int Menu::Weapons()
{
	cout << "What weapon do you want to buy?" << endl;
	m_items.clear();
	m_items.push_back("Sword      ( AD:+20 | AP:+0 )----$10");    
	m_items.push_back("Wand       ( AD:+5  | AP:+15)----$10");
	m_items.push_back("Crossbow   ( AD:+15 | AP:+5 )----$10");
	return Show();
}

//Eequipment menu, the user is prompted to select a equipment
int Menu::Equipment()
{
	cout << "What equipment do you want to buy?" << endl;
	m_items.clear();
	m_items.push_back("Armor      ( Defense:+10)-------$10");
	return Show();
}

//Action menu, the user is prompted to select (Attack,Bag,Leave)when fighting
int Menu::Action()
{
	cout << "Choose your action:" << endl;
	m_items.clear();
	m_items.push_back("Attack");
	m_items.push_back("Bag");
	m_items.push_back("Leave");
	return Show();
}

int Menu::Bag()
{
    cout << "Choose your Potion:" << endl;
    m_items.clear();
    m_items.push_back("Health Potion(HP+30)");
    m_items.push_back("Mana Potion(MP+30)");
    return Show();
}

int Menu::Potions()
{
    cout << "What potions do you want to buy?" << endl;
    m_items.clear();
    m_items.push_back("Health Potion ( HP+30 )----$5");
    m_items.push_back("Mana Potion   ( MP+30 )----$5");
    return Show();
    
}

int Menu::Attackway(int role)
{
    cout<< "Choose a way to attack the monster"<<endl;
    if(role==0){
        m_items.clear();
        m_items.push_back("Slashing");
        m_items.push_back("Dragon Slash (-15MP)");
    }
    if(role==1){
        m_items.clear();
        m_items.push_back("Fire Ball");
        m_items.push_back("Fire Whirl (-15MP)");
    }
    if(role==2){
        m_items.clear();
        m_items.push_back("Accurate Shooting");
        m_items.push_back("Shooting Spree (-15MP)");
    }
    
    return Show();
}
//Get the selection of the user.Input value represents the index selected by the user
string Menu::GetContent(int sel)
{
	return m_items[sel];
}
