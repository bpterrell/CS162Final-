/**********************************************************************************************************************
** Name:		Room.cpp
** Description: This an abstract base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#include "Room.h"

Room::Room()
{
	setItem1(true);
	setItem2(true);
	setItem3(true);
	
	rmPtrUP = NULL;
	rmPtrDN = NULL;
	rmPtrLT = NULL;
	rmPtrRT = NULL;
}

Room::~Room()
{
}

string Room::getRoomName()
{
	return roomName;
}

void Room::setRoomName(string roomName)
{
	this->roomName = roomName;
}

