/**********************************************************************************************************************
** Name:		Purse.h
** Description: This class manages the function of an item container used in the game. 
***********************************************************************************************************************/
#ifndef PURSE_HPP
#define PURSE_HPP
#include <string>
using std::string;

#include <vector>
using std::vector;

class Purse
{
public:
	Purse();
	~Purse();
private:
	unsigned int purseSize;
	vector<string> purseVector;

public:
	bool addToPurse(string);
	void removeFromPurse(int);
	bool searchPurse(string);
	void searchRemovePurse(string item);
	void printPurse();
	void ManagePurse();
};

#endif