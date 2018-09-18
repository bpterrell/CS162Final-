/**********************************************************************************************************************
** Name:		PhysicsLab.cpp
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
#include "PhysicsLab.h"
#include "Menu.h"
#include "Purse.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;


PhysicsLab::PhysicsLab()
{
	setRoomName("Physics Lab");

	roomNavOptions.push_back("Go Back to Control Room");
	searchPrompt = "Search this room";

	roomSearchOptions.push_back("Desk");
	roomSearchOptions.push_back("Optics Kit");
	roomSearchOptions.push_back("Velcro Wall");
	roomSearchOptions.push_back("Manage Purse");
	navigationPrompt = "Return to Navigation Menu";

	isDoorBlocked = true;
}


PhysicsLab::~PhysicsLab()
{

}


/**********************************************************************************************************************
** Name:		int ChildClass::navMenu()
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
int PhysicsLab::navMenu()
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
void PhysicsLab::searchRoom(Purse * thisPurse, int* thisgameStatus)
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
			searchNotebook();		//call search function nothing to add to purse
		} break;
		case 2:
		{
			if (searchOpticsKit())					//call search function
				setItem2(!thisPurse->addToPurse("Freakin Laser"));	//if true, then add to purse
		} break;

		case 3:
		{
			if (searchVelcroWall())					//call search function
				setItem3(!thisPurse->addToPurse("Spring Scale"));	//if true, then add to purse
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
bool PhysicsLab::roomChallange(Purse* thisPurse, int* thisgameStatus)
{
	if (!isDoorBlocked)
		return true; 

	cout << "A piece of equipment fell infront of the door, jamming it closed. You can \npush the door partially open but you cannot reach what need to be moved.\n"
		"Check your purse for something that might help...\n";
	
	//Gate keeper conditional 
	if (thisPurse->searchPurse("Jump Rope"))
	{
		cout << "You have a jump rope and you used it to snag the blockage.\n";
		isDoorBlocked = false;
		return true;

	}
	
	//Gate keeper conditional 
	else if (thisPurse->searchPurse("Axe"))
	{
		cout << "You have an axe and you used it to break down the door.\n";
		isDoorBlocked = false;
		return true;

	}
	else
	{
		cout << "You have nothing that will work. Go find something!\n";
		return false;
	}

}


/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool PhysicsLab::searchNotebook()
{

	cout << "Upon searching the notebook you find Physics, which can lead to great enlightenment!\n"
		<< "Would you like to be enlightened? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		cout << "Wow! Physics looks good on you! (Don't worry, nothing was added to your purse...)\n";
		return true;
	}
	return false;
}

/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool PhysicsLab::searchOpticsKit()
{
	//has Item been picked up
	if (!getItem2())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the optics kit you found a portable high powered infrared laser. AKA: Freakn Laser\n"
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
bool PhysicsLab::searchVelcroWall()
{
	//has Item been picked up
	if (!getItem3())
	{
		cout << "Nothing to see here...\n";
		return false;
	}
	cout << "Upon searching the velcro wall you find a spring scale.\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}
