/**********************************************************************************************************************
** Name:		EngineRoom.cpp
** Description: This a child class of the base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#ifndef ENGINEROOM_HPP
#define ENGINEROOM_HPP

#include "Room.h"
#include "Purse.h"
#include <string>
using std::string;

#include <vector>
using std::vector;


class EngineRoom :
	public Room
{
private:
	vector<string> roomNavOptions;			// Options Vector to pass to menu function
	vector<string> roomSearchOptions;			// Options Vector to pass to menu function

	string searchPrompt;					//Last menu item for nav menu
	string navigationPrompt;				//Last menu item for search menu
public:
	EngineRoom();
	~EngineRoom();

	virtual int navMenu();
	virtual void searchRoom(Purse*, int*);
	virtual bool roomChallange(Purse*, int*);

};
#endif
