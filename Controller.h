#pragma once
#include <map>
#include <string>
#include "Role.h"

//controller
class Controller
{
public:
	//function to run the game
	void Run();

	bool EnterGame(std::string &user_name);

	bool Login(std::string &user_name);

	void Register();

	void Exit();

	void AdventureIsland(Hero &hero);

	void StayInVillage(Hero &hero);

	void Store(Hero &hero);

	void BuyWeapon(Hero &hero);

	void BuyEuipment(Hero &hero);
    
    void BuyPotions(Hero &hero);

	void Fight(Hero &hero, Monster &monster);

	bool Attack(Role& Attacker, Role& defender);

	bool Bag(Role& Attacker);
private:
	//Load User’s Database，load User‘s Database in hard disk into memory through datas
	void LoadUserDatabase(std::map<std::string, std::string> &datas);
	//Save User‘s Database，save User‘s Database in datas into the hard disk
	void SaveUserDatabase(std::map<std::string, std::string> &datas);
};

