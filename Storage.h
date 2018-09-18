/**********************************************************************************************************************
** Name:		CrewQuarters.cpp
** Description: This a a child function of the base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Room.h"
#include "Purse.h"
#include <string>
using std::string;

#include <vector>
using std::vector;


class Storage :
	public Room
{
private:
	vector<string> roomNavOptions;			// Options Vector to pass to menu function
	vector<string> roomSearchOptions;			// Options Vector to pass to menu function

	string searchPrompt;					//Last menu item for nav menu
	string navigationPrompt;				//Last menu item for search menu

public:
	Storage();
	~Storage();

	virtual int navMenu();
	virtual void searchRoom(Purse*, int*);
	virtual bool roomChallange(Purse*, int*);

	bool searchFireKit(Purse*);
	bool searchBlueCase();
	bool searchPinkCase();
};
#endif