/**********************************************************************************************************************
** Name:		CrewQuarters.cpp
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
#include "CrewQuarters.h"
#include "Menu.h"
#include "Purse.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;


CrewQuarters::CrewQuarters()
{
	setRoomName("Crew Quarters");

	roomNavOptions.push_back("Go Back to Control Room");
	searchPrompt = "Search this room";

	roomSearchOptions.push_back("Yuri's Locker");
	roomSearchOptions.push_back("Buzz's Locker");
	roomSearchOptions.push_back("Audrey's Locker");
	roomSearchOptions.push_back("Manage Purse");
	navigationPrompt = "Return to Navigation Menu";
}


CrewQuarters::~CrewQuarters()
{
}


/**********************************************************************************************************************
** Name:		int ChildClass::navMenu()
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
int CrewQuarters::navMenu()
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
		return 3;		//return
	} break;

	default: cout << "Invalid entry, try again.";	// input validation
	}
	return -1;
}


/**********************************************************************************************************************
** Name:		void ChildClass::searchRoom(Purse * thisPurse)
** Description: This function displays search menu and accepts user input.
***********************************************************************************************************************/
void CrewQuarters::searchRoom(Purse * thisPurse, int* thisgameStatus)
{
	if (!roomChallange(thisPurse, thisgameStatus))
	{
		return;
	}

	cout << "\n\nSearch Menu:  ";
	int option = subMenuDispFixed(getRoomName(), roomSearchOptions, navigationPrompt);
	while (option != 0)
	{
		switch (option)
		{
		case 1:
		{
			if (searchYuri())					//call search function
				setItem1(!thisPurse->addToPurse("Deodorant"));	//if true, then add to purse
		} break;

		case 2:
		{
			if (searchBuzz())					//call search function
				setItem2(!thisPurse->addToPurse("Jump Rope"));	//if true, then add to purse
		} break;

		case 3:
		{
			if (searchAudrey())					//call search function
				setItem3(!thisPurse->addToPurse("MP3 Player"));	//if true, then add to purse
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
bool CrewQuarters::roomChallange(Purse* thisPurse, int* thisgameStatus)
{
	cout << "Something is wreaking havok on the electrical system in here.\nCheck your purse for a match to give you a bit of light..."
		"\n(Sure, why are we lighting our way throught the ISS with a match?)\n";
	
	if (thisPurse->searchPurse("Match"))
	{
		cout << "You have a match! Great! Start Searching!\n";
		thisPurse->searchRemovePurse("Match");
		return true;
		
	}
	else
	{
		cout << "You have no match! Bad! Go back and find one!\n";
		return false;
	}
}


/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool CrewQuarters::searchYuri()
{
	//has Item been picked up
	if (!getItem1())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the Yuri's locker you found a stick of deodorant...\n"
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
bool CrewQuarters::searchBuzz()
{
	//has Item been picked up
	if (!getItem2())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the Buzz's locker you found a jump rope.\n"
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
bool CrewQuarters::searchAudrey()
{
	//has Item been picked up
	if (!getItem3())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching Audrey's locker you found an MP3 player.\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}
