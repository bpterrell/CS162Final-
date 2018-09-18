/**********************************************************************************************************************
** Name:		Purse.h
** Description: This class manages the function of an item container used in the game.
***********************************************************************************************************************/
#include "Purse.h"
#include "validator.h"
#include <string>
using std::string;

#include <vector>
using std::vector;


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Purse::Purse()
{
	purseSize = 3;			//Three items allowed in purse
}


Purse::~Purse()
{
}


/***********************************************************************************************************************
**	Name:	bool Purse::addToPurse(string item)
**	Description:	This function adds an item to the purse vector
***********************************************************************************************************************/
bool Purse::addToPurse(string item)
{
	if (purseVector.size() < purseSize)
	{
		purseVector.push_back(item);
		return true;
	}
	else
	{
		cout << "Your Purse is full please, remove item/s and try again.\n";
		return false;
	}
}


/***********************************************************************************************************************
**	Name:	void Purse::removeFromPurse(int element)
**	Description:	This function removes a an element from the vector
***********************************************************************************************************************/
void Purse::removeFromPurse(int element)
{
	purseVector.erase(purseVector.begin() + element);
}


/***********************************************************************************************************************
**	Name:	bool Purse::searchPurse(string item)
**	Description:	This function searches the purse vector for a string
***********************************************************************************************************************/
bool Purse::searchPurse(string item)
{
	for (unsigned int i = 0; i < purseVector.size(); i++)
	{
		if (item == purseVector.at(i))
		{
			return true;
		}
	}
	return false;
}


/***********************************************************************************************************************
**	Name:	void Purse::searchRemovePurse(string item)
**	Description:	This function seaches the vector for a string and removes the element
***********************************************************************************************************************/
void Purse::searchRemovePurse(string item)
{
	for (unsigned int i = 0; i < purseVector.size(); i++)
	{
		if (item == purseVector.at(i))
		{
			purseVector.erase(purseVector.begin() + i);
		}
	}
}


/***********************************************************************************************************************
**	Name:	void Purse::printPurse()
**	Description:	This function prints the entire vector
***********************************************************************************************************************/
void Purse::printPurse()
{
	for (unsigned int i = 0; i < purseVector.size(); i++)
	{
		cout << i + 1 << "    " << purseVector.at(i) << endl;
	}
}


/***********************************************************************************************************************
**	Name:	void Purse::ManagePurse()
**	Description:	This function provides a menu to manage the purse vector
***********************************************************************************************************************/
void Purse::ManagePurse()
{
	cout << "Please select an item to remove from your purse.\n";
	printPurse();
	cout << '0' << "    " << " TO EXIT\n";
	
	int itemNumber = validInt(0, purseVector.size());
	//cin >> itemNumber;

	if (itemNumber != 0)
	{
		removeFromPurse(itemNumber - 1);
	}
	return;
}
