/**********************************************************************************************************************
** Name:		Storage.cpp
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
#include "Storage.h"
#include "Menu.h"
#include "Purse.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;


Storage::Storage()
{
	setRoomName("Dry Storage");
	roomNavOptions.push_back("Go Back to Control Room");
	roomNavOptions.push_back("Continue to Extra Spooky Area with Many Blind Spots (and probably no aliens... right?)");
	searchPrompt = "Search this room";

	roomSearchOptions.push_back("Fire Kit");
	roomSearchOptions.push_back("Blue Case");
	roomSearchOptions.push_back("Pink Case");
	roomSearchOptions.push_back("Manage Purse");
	navigationPrompt = "Return to Navigation Menu";
}


Storage::~Storage()
{
}


/**********************************************************************************************************************
** Name:		int ChildClass::navMenu()
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
int Storage::navMenu()
{
	cout << "\n\nNavigation Menu:  ";

	int option = subMenuDispFixed(getRoomName(), roomNavOptions, searchPrompt);

	switch (option)
	{

	case 0:
	{
		return 0;		//return
	} break;

	case 1:
	{
		return 4;		//call room to left
	} break;

	case 2:
	{
		return 2;		//call room to right
	} break;

	default: cout << "Invalid entry, try again.";	// input validation
	}
	return -1;
}


/**********************************************************************************************************************
** Name:		void ChildClass::searchRoom(Purse * thisPurse)
** Description: This function displays search menu and accepts user input.
***********************************************************************************************************************/
void Storage::searchRoom(Purse * thisPurse, int* thisgameStatus)
{

	cout << "\n\nSearch Menu:  ";
	int option = subMenuDispFixed(getRoomName(), roomSearchOptions, navigationPrompt);
	while (option != 0)
	{
		switch (option)
		{
		case 1:
		{
			if (searchFireKit(thisPurse))					//call search function
				setItem1(!thisPurse->addToPurse("Axe"));	//if true, then add to purse
		} break;

		case 2:
		{
			if (searchBlueCase())										//call search function
				setItem2(!thisPurse->addToPurse("Canned Priozhki"));	//if true, then add to purse
		} break;

		case 3:
		{
			if (searchPinkCase())									//call search function
				setItem3(!thisPurse->addToPurse("Duct Tape"));		//if true, then add to purse
		} break;

		case 4:
		{
			thisPurse->ManagePurse();	//Call purse managment
		} break;

		default: cout << "Invalid entry, try again.";	// input validation
		}
		option = subMenuDispFixed(getRoomName(), roomSearchOptions, navigationPrompt);	// re-print menu within loop
	}
}

/**********************************************************************************************************************
** Name:		bool Storage::roomChallange(Purse *, int *
** Description:  Dormant Function
***********************************************************************************************************************/
bool Storage::roomChallange(Purse *, int *)
{
	return false;
}


/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool Storage::searchFireKit(Purse* thisPurse)
{

	cout << "The fire kit is locked with an insane lock that requires you to play Bruce Springsteen's - \"I'm On Fire\"\n";
	
	//Gate keeper conditional 
	if (!thisPurse->searchPurse("MP3 Player"))
	{
		cout << "You must have a an MPS player to gain access!\n";
		return false;
	}
	cout << "Great! You have the MP3 Player!\n";

	//has Item been picked up
	if (!getItem1())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the fire kit you find an axe!!!!\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}

/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool Storage::searchBlueCase()
{
	//has Item been picked up
	if (!getItem2())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the blue case you found cans of Priozhki. AKA: Stuffed Buns\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}


/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool Storage::searchPinkCase()
{
	//has Item been picked up
	if (!getItem3())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching pink case you find a roll of duct tape.\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}
