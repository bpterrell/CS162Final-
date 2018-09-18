/**********************************************************************************************************************
** Name:		ControlRoom.cpp
** Description: This a a child function of the base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#include "ControlRoom.h"
#include "Menu.h"

#include "Purse.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;


ControlRoom::ControlRoom()
{
	setRoomName("Control Room");

	roomNavOptions.push_back("Go to Crew Quarters");
	roomNavOptions.push_back("Go to Dry Storage");
	roomNavOptions.push_back("Go to Bio Lab");
	roomNavOptions.push_back("Go to Physics Lab");
	roomNavOptions.push_back("Exit Game");
	searchPrompt = "Search the Control Room";
	
	roomSearchOptions.push_back("Captain's Console");
	roomSearchOptions.push_back("Navigation Console");
	roomSearchOptions.push_back("Communications Console ");
	roomSearchOptions.push_back("Manage Purse");
	navigationPrompt = "Return to Navigation Menu";
}


ControlRoom::~ControlRoom()
{
}

/**********************************************************************************************************************
** Name:		int ChildClass::navMenu()
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
int ControlRoom::navMenu()
{
	cout << "\n\nNavigation Menu:  ";
	return subMenuDispFixed(getRoomName(), roomNavOptions, searchPrompt);	//call menu function
	}

/**********************************************************************************************************************
** Name:		void ChildClass::searchRoom(Purse * thisPurse)
** Description: This function displays search menu and accepts user input.
***********************************************************************************************************************/
void ControlRoom::searchRoom(Purse * thisPurse, int* thisgameStatus)
{
	//roomChallange()
	
	cout << "\n\nSearch Menu:  ";
	int option = subMenuDispFixed(getRoomName(), roomSearchOptions, navigationPrompt);	//call menu function
	
	//loop to allow user to search entire room and switch case to call add to purse calls. 
	while (option != 0)
	{
		switch (option)
		{
		case 1:
		{
			if (searchCaptian())					//call search function
				setItem1(!thisPurse->addToPurse("Knife"));	//if true, then add to purse
		} break;

		case 2:
		{
			if (searchNavigation())					//call search function
				setItem2(!thisPurse->addToPurse("Key"));	//if true, then add to purse
		} break;

		case 3:
		{
			if (searchCommunications())					//call search function
				setItem3(!thisPurse->addToPurse("Super Glue"));	//if true, then add to purse
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
** Name:		void ChildClass::roomChallange()
** Description: This function drives the room challange
***********************************************************************************************************************/
bool ControlRoom::roomChallange(Purse* thisPurse, int* thisgameStatus)
{
	//cout << "This room has no challange.\n";
	return false;


}

/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool ControlRoom::searchCaptian()
{
	//has Item been picked up
	if (!getItem1())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the Captian's consol you found a knife!\n"
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
bool ControlRoom::searchNavigation()
{
	//has Item been picked up
	if (!getItem2())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the navigation console you found key.\n"
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
bool ControlRoom::searchCommunications()
{
	//has Item been picked up
	if (!getItem3())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching around the communications console you found a tube of superglue.\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}
