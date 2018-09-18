/**********************************************************************************************************************
** Name:		BioLab.cpp
** Description: This a child function of the base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#ifndef BIOLAB_HPP
#define BIOLAB_HPP

#include "Room.h"
#include "Purse.h"
#include <string>
using std::string;

#include <vector>
using std::vector;


class BioLab :
	public Room
{
private:
	vector<string> roomNavOptions;			// Options Vector to pass to menu function
	vector<string> roomSearchOptions;			// Options Vector to pass to menu function

	string searchPrompt;					//Last menu item for nav menu
	string navigationPrompt;				//Last menu item for search menu
public:
	BioLab();
	~BioLab();

	virtual int navMenu();
	virtual void searchRoom(Purse*, int*);
	virtual bool roomChallange(Purse*, int*);

	bool searchChemLocker(Purse*);
	bool searchLabEquipLocker();
	bool searchDrawer();
};
#endif