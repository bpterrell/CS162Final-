/**********************************************************************************************************************
** Name:		BioLab.cpp
** Description: This a a child function of the base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#include "BioLab.h"
#include "Menu.h"
#include "Purse.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;


BioLab::BioLab()
{
	setRoomName("Bio Lab");
	roomNavOptions.push_back("Go Back to Control Room");
	searchPrompt = "Search this room";

	roomSearchOptions.push_back("Chemical Storage");
	roomSearchOptions.push_back("Lab Equipment Storage");
	roomSearchOptions.push_back("Space Junk Drawer");
	roomSearchOptions.push_back("Manage Purse");
	navigationPrompt = "Return to Navigation Menu";
}


BioLab::~BioLab()
{
}


/**********************************************************************************************************************
** Name:		int ChildClass::navMenu()
** Description: This function displays navigation menu and accepts user input.
***********************************************************************************************************************/
int BioLab::navMenu()
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
	return 1;		//call room to up
	} break;

	default: cout << "Invalid entry, try again.";	// input validation
	}
	return -1;
}


/**********************************************************************************************************************
** Name:		void ChildClass::searchRoom(Purse * thisPurse)
** Description: This function displays search menu and accepts user input.
***********************************************************************************************************************/
void BioLab::searchRoom(Purse * thisPurse, int* thisgameStatus)
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
			if (searchChemLocker(thisPurse))					//call search function
				setItem1(!thisPurse->addToPurse("Wash Bottle of HCL"));	//if true, then add to purse
		} break;

		case 2:
		{
			if (searchLabEquipLocker())							//call search function
				setItem2(!thisPurse->addToPurse("Petri Dish of M&Ms..."));	//if true, then add to purse
		} break;

		case 3:
		{
			if (searchDrawer())									//call search function
				setItem3(!thisPurse->addToPurse("Match"));	//if true, then add to purse
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
bool BioLab::roomChallange(Purse* thisPurse, int* thisgameStatus)
{
	cout << "Yuri is nowhere to be found and he spun the lock to the Bio Lab.\n\nUse this riddle to determine the code to get in:"
		"\n\nIt's a two digit number\nThe first digit is 2 more than the second digit\nIt's between 60 and 80, but not 64 (Try: 75)\n\n";

	cout << "Choose one:\n";
	cout << "1) 64\n";
	cout << "2) 42\n";
	cout << "3) 86\n";
	cout << "4) 75\n\n";

	
	int code;
	
	cout << "Enter choice:";
	cin >> code;

	if (code == 4)
	{
		cout << "You have numbers down!\n";
		return true;
	}
	cout << "\n\nSorry! Go practice your numbers! (Try: 75)\n";
	return false;
}


/**********************************************************************************************************************
** Name:		bool ChildClass::search______()
** Description:  This function drives the room area search
***********************************************************************************************************************/
bool BioLab::searchChemLocker(Purse * thisPurse)
{
	//has Item been picked up
	if (!getItem1())
	{
		cout << "Nothing to see here...\n";
		return false;
	}
	cout << "The chemical storage is locked.\n";
	if (!thisPurse->searchPurse("Key"))
	{
		cout << "You must have a key to gain access!\n";
		return false;
	}
	cout << "Great! You have the key!\n";

	cout << "Upon searching the chemical storage you found a wash bottle of HCL...\n"
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
bool BioLab::searchLabEquipLocker()
{
	//has Item been picked up
	if (!getItem2())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the lab equipment storageyou found a petri dish of M&Ms... Yuri!!!!!\n"
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
bool BioLab::searchDrawer()
{
	//has Item been picked up
	if (!getItem3())
	{
		cout << "Nothing to see here...\n";
		return false;
	}

	cout << "Upon searching the space junk drawer you found a match.\n"
		<< "Would you like to keep it? (y or n)\n";

	char YorN;
	cin >> YorN;

	if (YorN == 'Y' || YorN == 'y')
	{
		return true;
	}
	return false;
}
