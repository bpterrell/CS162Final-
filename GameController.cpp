/**********************************************************************************************************************
** Name:		GameController.cpp
** Description: This class acts as a game driver
***********************************************************************************************************************/
#include "GameController.h"
#include "Purse.h"
#include <chrono>
#include <thread>
#include <ctime>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

GameController::GameController()
{
	movesRemaining = 30;
	gameStatus = new int(0);			//0 = alive, 1 = game over won/dead
	
	//Room derived class pointers
	ControlRoomPtr = new ControlRoom;
	CrewQuartersPtr = new CrewQuarters;
	BioLabPtr = new BioLab;
	PhysicsLabPtr = new PhysicsLab;
	StoragePtr = new Storage;
	SpookyRoomPtr = new EngineRoom;
	
	//Current Location
	LocationPntr = ControlRoomPtr;

	//Pointer to purse
	thisPurse = new Purse;
	
	//Set control room navigation pointers
	ControlRoomPtr->setUP(CrewQuartersPtr);
	ControlRoomPtr->setDN(BioLabPtr);
	ControlRoomPtr->setLT(PhysicsLabPtr);
	ControlRoomPtr->setRT(StoragePtr);

	//Set Crew Quarters navigation pointers
	CrewQuartersPtr->setDN(ControlRoomPtr);

	//Set bio lab navigation pointers
	BioLabPtr->setUP(ControlRoomPtr);
	
	//Set physics lab navigation pointers
	PhysicsLabPtr->setRT(ControlRoomPtr);

	//Set storage navigation pointers
	StoragePtr->setLT(ControlRoomPtr);
	StoragePtr->setRT(SpookyRoomPtr);
	
	//Set engine room navigation pointers
	SpookyRoomPtr->setLT(StoragePtr);
}


GameController::~GameController()
{
	//delete all pointers
	delete ControlRoomPtr;
	delete CrewQuartersPtr;
	delete BioLabPtr;
	delete PhysicsLabPtr;
	delete StoragePtr;
	delete SpookyRoomPtr;
	delete gameStatus;
	delete thisPurse;
}

/**********************************************************************************************************************
** Name:		void GameController::playGame()
** Description: This function completes all need to complete the game 
***********************************************************************************************************************/
void GameController::playGame()
{
	//update time
	time(&startTime);
	
	do
	{
		//Timer
		time(&currentTime);
		cout << endl << endl << "TIME REMAINING:  " << (600 - (currentTime - startTime)) << " Seconds." << endl << endl;
		
		//Call nav menu
		int whereto = LocationPntr->navMenu();
		
		switch (whereto)
		{
		case 0:
		{
			LocationPntr->searchRoom(thisPurse, gameStatus);		//search room
		} break;
		case 1:
		{
			LocationPntr = LocationPntr->getUP();					//go up
		} break;

		case 2:
		{
			LocationPntr = LocationPntr->getRT();					//go right
		} break;

		case 3:
		{
			LocationPntr = LocationPntr->getDN();					//go down
		} break;

		case 4:
		{
			LocationPntr = LocationPntr->getLT();					//go left
		} break;
		case 5:
		{
			return;
		} break;
		
		default: cout << "Invalid entry, try again!";	// input validation
		}
		
		//update time
		time(&currentTime);

		//if you have taken more than 10 mins you die
		if ((currentTime - startTime) > 600)
		{
			cout << "You have failed to complete the mision in the alloted time! SORRY\n";
			return;
		}
	} while (*gameStatus == 0);		//loop till game over
	return;
}
