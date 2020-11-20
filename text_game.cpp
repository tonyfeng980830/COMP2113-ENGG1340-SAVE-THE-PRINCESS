    // text_game.cpp : Including main function. The program execution will start and end here.
//

#include <iostream>
#include "Controller.h"
int main()
{
	Controller game_controller;
	game_controller.Run();
	getchar();
	return 0;
}
