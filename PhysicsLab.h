/**********************************************************************************************************************
** Name:		CrewQuarterscpp
** Description: This a a child function of the base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#ifndef PHYSICSLAB_HPP
#define PHYSICSLAB_HPP

#include "Room.h"
#include "Purse.h"
#include <string>
using std::string;

#include <vector>
using std::vector;


class PhysicsLab :
	public Room
{
private:
	vector<string> roomNavOptions;			// Options Vector to pass to menu function
	vector<string> roomSearchOptions;			// Options Vector to pass to menu function

	string searchPrompt;					//Last menu item for nav menu
	string navigationPrompt;				//Last menu item for search menu

	bool isDoorBlocked;
public:
	PhysicsLab();
	~PhysicsLab();

	virtual int navMenu();
	virtual void searchRoom(Purse*, int*);
	virtual bool roomChallange(Purse*, int*);

	bool searchNotebook();
	bool searchOpticsKit();
	bool searchVelcroWall();
};
#endif