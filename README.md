# COMP2113-ENGG1340-Group Project
# SAVE THE PRINCESS
A text-based role-playing game written in C++. 

# Group Members
1. Feng Guoze 3035641528
2. CHAN YUMAN 3035685483


## Game Description:
* Save the Princess is a text-based adventure role-playing game. In the game, a princess in distress has been kidnapped. The player must defeat monsters to save her from the Big Bad. The game's difficulty gradually increases as you reach higher stages. Like a normal RPG, the key to win is to carefully decide which action to take at different stages.

## Instructions:
* Firstly, you need to create or login your account.
  * For the new players, they should select the role they want to, eg,.warrior, mage, marksman.
* On the home page, you can choose to stay in the Village or go to the Adventure Island. Moverover, there is a store where you can buy your weapons, equipment and Potions.
  * Once you choose Adventure Island, there are totally 6 stages you need to reach in Adventure Island. You need to walk through each stage and beat down all the monsters that you encounter(there are 3 monsters in each stage). When you enter the stage, You will be asked to throw the dice. (different number determines different level of monsters you will face in that stage)
  * When you choose Store, there will be many weapons and equipment that you can buy based on your money and what stage you are in( All weapons and equipment can be buy again and the parameters of your character will be also increase). Moreover, You can also buy health and mana potions and use it when you are in fighting.
* In the Adventure Island, when engaging the monsters, you have 3 actions to choose from at each round.
  * Attack, Bag, Leave
  * In option Attack, you will have two attack ways. One is normal attack, another one is strong attack( it will comsume mana).
  * In option Bag, you can use health or mana potion to heal. However, you will lose the attack opportunity.
  * You need to make careful consideration based on your enemy and your stats (eg. Health point, attack, deference and mana point).
* The game is completed when the player has successfully defeated the "final boss" and saved the princess.
* Players will be given the option to exit game in the Village game and save his progress.

## List of features
* Generation of random game sets or events: 
  * Outcomes of random draw of dice determine various levels and fights of the game.
* Data structures for storing game status:
  * Dynamic memory management: We will store the player’s username and his progress using dynamic memory manipulation in files. Moreover, we also create a struct() function to initialize the basic information based on what character that the user chooses. Moreover, we also utilize integer array, struct, class, STL containers and pointer to save the game progress.
* File input/output: 
  * Files shall be used to store the player's game progress and output it as maps (.txt files).
* Program codes in multiple files:
  * In our main.cpp, it includes the major functions like allowing users to move freely from Village, store, and Adventure Island. On top of that, main.cpp is also responsible to keep showing health points, attack, deference and mana point to users. Moreover, main.cpp will have different files like Weapon.h, Menu.h and so on.
  * Besides, the some rules of the game will also be designed in Role.h and Role.cpp. For example, the decreasing and increasing value of the health point, attack, deference and mana point. 






