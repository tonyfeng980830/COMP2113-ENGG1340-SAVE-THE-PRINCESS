# COMP2113-ENGG1340-Group Project
# SAVE THE PRINCESS
A text-based role-playing game written in C++. 

# Group Members
1. Feng Guoze 303564152
2. CHAN YUMAN 3035685483


## Game Description:
* Save the Princess is a text-based adventure role-playing game. In the game, a princess in distress has been kidnapped. The player must defeat monsters to save her from the Big Bad. The game's difficulty gradually increases as you reach higher stages. Like a normal RPG, the key to win is to carefully decide which action to take at different stages.

## Instructions:
* Firstly, you need to create or login your account.
  * For the new players, they should select the role they want to, eg,.warrior, mage, marksman.
* On the home page, you can choose to stay in the Village or go to the Adventure Island. Moverover, there is a store where you can buy your weapons and equipment.
  * Once you choose Adventure Island, there are totally 5 stages you need to reach in Adventure Island. You need to walk through each stage and beat down all the monsters that you encounter. When you enter the stage, You will be asked to throw the dice to move forward. (different number determines different level of monsters you will face in that stage)
  * When you choose Store, there will be many weapons and equipment that you can buy based on your money and what stage you are in.
* In the Adventure Island, when engaging the monsters, you have 3 actions to choose from at each round.
  * Attack, Bag, Leave
  * You need to make careful consideration based on your enemy and your stats (eg. Health point, attack, deference and mana point).
* The game is completed when the player has successfully defeated the "final boss" and saved the princess.
* Players will be given the choice of starting a new game or continuing previously saved game progress.
* Players will be given the option to exit game in the Village game and save his progress.

## List of features: 
* Generation of random game sets or events: 
  * Outcomes of random draw of dice determine various levels and fights of the game.
  * The player can choose action 4: make your pet to attack from different attack styles, which has a random chance of hitting the enemy successfully.
* Data structures for storing game status:
  * Dynamic memory management: We will store the player’s username and his progress using dynamic memory manipulation in files. Moreover, we also create a struct() function to initialize the basic information based on what character that the user chooses. Moreover, we also utilize integer and character array to save the game progress
* File input/output: 
  * Files shall be used to store the player's game progress and output it as maps (.txt files).
* Program codes in multiple files:
  * In our main.cpp, it includes the major functions like allowing users to move freely from Village, store, and Adventure Island. On top of that, main.cpp is also responsible to keep showing health points, attack, deference and mana point to users. Moreover, main.cpp will have different headers like store.h, Adventure_lsland.h and so on.
  * We also design different stories corresponding to different characters. In addition, the end of the game is different based on the user choices in the end. These all of the game stories will be designed in GameStory.h.
  * Besides, the rule of the game will also be designed in GameRule.h. For example, the decreasing and increasing value of the health point, attack, deference and mana point. 






