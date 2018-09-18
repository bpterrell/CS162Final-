/**********************************************************************************************************************
** Name:		CrewQuarters.cpp
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
#include "EngineRoom.h"
#include "Menu.h"
#include "Purse.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;


EngineRoom::EngineRoom()
{
	setRoomName("Spooky Room");
	roomNavOptions.push_back("Go Back to Storage Room");
	searchPrompt = "Search for source of the noise";

	roomSearchOptions.push_back("Fuel Storage Pod");
	roomSearchOptions.push_back("Under the Floor");
	roomSearchOptions.push_back("Electrical Panel");

	navigationPrompt = "Return to Navigation Menu";
}


EngineRoom::~EngineRoom()
{
}


/**********************************************************************************************************************
** Name:		int ChildClass::navMenu()
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
int EngineRoom::navMenu()
{
	cout << "\n\nSTOP! You hear the noise of something banging around when you turn on the lights!";

	cout << "\n\nNavigation Menu:  ";
	int option = subMenuDispFixed(getRoomName(), roomNavOptions, searchPrompt);

	switch (option)
	{

	case 0:
	{
		return 0;	//return
	} break;

	case 1:
	{
		return 4;	//call room to left
	} break;

	default: cout << "Invalid entry, try again.";	// input validation
	}
	return -1;
}


/**********************************************************************************************************************
** Name:		void ChildClass::searchRoom(Purse * thisPurse)
** Description: This function displays search menu and accepts user input.
***********************************************************************************************************************/
void EngineRoom::searchRoom(Purse * thisPurse, int* thisgameStatus)
{
	//roomChallange()

	cout << "\n\nSearch Menu:  ";
	int option = subMenuDispFixed(getRoomName(), roomSearchOptions, navigationPrompt);
	while (option != 0)
	{
		switch (option)
		{
		case 1:
		{
			roomChallange(thisPurse, thisgameStatus);
		} break;

		case 2:
		{
			cout << "You pull up a piece of decking and crawl in. You are toast if the alien has the jump on you in here! Lucky that slimy monster has not found access to here!\n";
		} break;

		case 3:
		{
			cout << "Upon opening the electrical panel you discover slime on the wiring, but no sign of the alien!\n";
		} break;

		case 4:
		{
			thisPurse->ManagePurse();	//Call purse managment
		} break;

		default: cout << "Invalid entry, try again.";	// input validation
		}
		if (*thisgameStatus) return;
		option = subMenuDispFixed(getRoomName(), roomSearchOptions, navigationPrompt);	// re-print menu within loop
	}
}


/**********************************************************************************************************************
** Name:		void ChildClass::roomChallange()
** Description: This function drives the room challange
***********************************************************************************************************************/
bool EngineRoom::roomChallange(Purse* thisPurse, int* thisgameStatus)
{
	if (thisPurse->searchPurse("Axe") && thisPurse->searchPurse("Freakin Laser") && thisPurse->searchPurse("Wash Bottle of HCL"))
	{
		cout << "You were able to weaken the alien by temporaly blinding it with the laser, then suffocating it with a spray of HCL,"
			"\nand finally delived the kill with the fire axe. All without compromising the ship, well at least not much...\n";

		cout << "...hissS...";
		*thisgameStatus = 1;
	}
	else
	{
		cout << "You're DEAD Bro! \nREMEMEBER: The alien can only sense heat, its respiration is through its skin, and will die when tramatically bashed to pieces.\n"
		"Go find three things that will make that happen!\n";
		*thisgameStatus = 1;
	}
	return false;

}
