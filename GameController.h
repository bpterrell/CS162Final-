/**********************************************************************************************************************
** Name:		GameController.cpp
** Description: This class acts as a game driver
***********************************************************************************************************************/
#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include "Room.h"
#include "Purse.h"
#include "ControlRoom.h"
#include "CrewQuarters.h"
#include "BioLab.h"
#include "PhysicsLab.h"
#include "Storage.h"
#include "EngineRoom.h"

class GameController
{
public:
	GameController();
	~GameController();
private:
	time_t startTime;
	time_t currentTime;

	int movesRemaining;
	int *gameStatus;
	
	Room* ControlRoomPtr;
	Room* CrewQuartersPtr;
	Room* BioLabPtr;
	Room* PhysicsLabPtr;
	Room* StoragePtr;
	Room* SpookyRoomPtr;
	Room *LocationPntr;

	Purse* thisPurse;
public:
	void playGame();
};

#endif
