/**********************************************************************************************************************
** Name:		Room.cpp
** Description: This an abstract base class Room, which controls the function of this room in the game.
***********************************************************************************************************************/
#ifndef	ROOM_HPP
#define ROOM_HPP
#include "Purse.h"

#include <string>
using std::string;

class Room
{
public:
	Room();
	virtual ~Room();
private:
	string roomName;
	bool roomlights;
	
	Room *rmPtrUP;
	Room *rmPtrDN;
	Room *rmPtrLT;
	Room *rmPtrRT;

	bool item1;
	bool item2;
	bool item3;

public:
	string getRoomName();
	void setRoomName(string roomName);
	
	void setUP(Room* rmPtr) { rmPtrUP = rmPtr; };
	void setDN(Room* rmPtr) { rmPtrDN = rmPtr; };
	void setLT(Room* rmPtr) { rmPtrLT = rmPtr; };
	void setRT(Room* rmPtr) { rmPtrRT = rmPtr; };
	
	Room* getUP() { return rmPtrUP; };
	Room* getDN() { return rmPtrDN; };
	Room* getLT() { return rmPtrLT; };
	Room* getRT() { return rmPtrRT; };

	void setItem1(bool TF) { item1 = TF; };
	void setItem2(bool TF) { item2 = TF; };
	void setItem3(bool TF) { item3 = TF; };
	
	bool getItem1() { return item1; };
	bool getItem2() { return item2; };
	bool getItem3() { return item3; };

	virtual int navMenu() = 0;
	virtual void searchRoom(Purse*, int*) = 0;
	virtual bool roomChallange(Purse*, int*) = 0;
	
};
#endif
