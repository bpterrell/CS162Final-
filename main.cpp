/***********************************************************************************************************************
** Program name: Final Game
** Author: Brian Terrell
** Date:  06/13/2017
** Description: This is a game where you have to find what is takes to kill an alien hiding in your space ship 
** Resources: C. Merrill's project
***********************************************************************************************************************/


#include "GameController.h"
#include "Menu.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;


int main()
{
	cout << "\nAliens on an ISS!\n\nYou must find the alien on the ISS and nuetralize the threat before is kills the crew!"
		"\nHint: The alien can only sense body heat, and it breath through its skin. Also it is the \nsize of a large dog so take the biggest weapon you can find! "
		"\nHint: Also you have a purse that can carry 3 items if you drop an item you cannot pick it\n back up and you have 10 minutes to kill the alien.\n\n";
	bool played = false;
	string gameTitle = "";		// Title to pass to menu function

	vector<string> gameOptions;			// Options Vector to pass to menu function
	gameOptions.push_back("Play Game");
	gameOptions.push_back("Restart Game");
	gameOptions.push_back("Cheat Sheet");


	int option = menuDisp(gameTitle, gameOptions);	// Call to member function

	GameController thisGame;

													// Loop to hold open menu function until terminated
	while (option != 0)
	{
		switch (option)		
		{
		case 1:
		{
			if (!played) 
			{
				played = true;			//flag set to true if game has been played
				thisGame.playGame();
			}
			else cout << "\nChoose the play again option.\n";
		} break;

		case 2:
		{
			thisGame = GameController();		// destruct - construct of Game object
			played = false;			//reset flag set to false if game has been played
		} break;
		case 3:
		{
			//Cheat Sheet
			cout << "Cheat Sheet, Press Enter to Return to the Main Menu.\n";
			cout << "1: Control Room - Pick up key\n";
			cout << "2: Bio Lab - Pick up Wash Bottle of HCL and Match - Drop Key - Door Code is: 75\n";
			cout << "3: Crew Quarters - Pick up MP3 Player\n";
			cout << "4: Storage - Pick up Axe - Drop MP3 Player\n";
			cout << "5: Physics Lab - Pick up Laser\n";
			cout << "6: Alien is just passed the storage room\n";
			cin.ignore();
			cin.get();
		} break;

		default: cout << "Invalid entry, try again.";	// input validation
		}
		option = menuDisp(gameTitle, gameOptions);	// re-print menu within loop
	}

	return 0;
}

