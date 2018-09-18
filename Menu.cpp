/**********************************************************************************************************************
** Name:		Menu.cpp
** Description: This function provides a menu function when provided a vector of menu options, it returns an int value 
				for option
***********************************************************************************************************************/
#include "validator.h"
#include "Menu.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
	

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::right;

/***********************************************************************************************************************
**	Name:	int menuDisp(string title, vector<string> const &menuOptions)
**	Description:	This function provides a menu function when provided a vector of menu options, it returns an int value 
					for option
***********************************************************************************************************************/
int menuDisp(string title, vector<string> const &menuOptions)
{

	//display title
	cout << title << endl << endl;
	cout << "Choose from the following options:" << endl;

	//Display menu 
	for (unsigned int i = 0; i < menuOptions.size(); i++)
	{
		cout << right << setw(5) << i + 1 << ") " << menuOptions.at(i) << endl;
	}

	//Fixed exit command
	cout << setw(7) << "0) " << "EXIT" << endl;

	// return valid menu option 
	int option = validInt(0, menuOptions.size());
	return option;
}


/***********************************************************************************************************************
**	Name:	int subMenuDisp(string title, vector<string> const &menuOptions)
**	Description:	This function provides a menu function when provided a vector of menu options, it returns an int value
for option
***********************************************************************************************************************/
int subMenuDisp(string title, vector<string> const &menuOptions)
{

	//display title
	cout << title << endl << endl;
	cout << "Choose from the following options:" << endl;

	//Display menu 
	for (unsigned int i = 0; i < menuOptions.size(); i++)
	{
		cout << right << setw(5) << i + 1 << ") " << menuOptions.at(i) << endl;
	}


	// return valid menu option 
	int option = validInt(1, menuOptions.size());
	return option;
}

/***********************************************************************************************************************
**	Name:	int subMenuDispFixed(string title, vector<string> const &menuOptions)
**	Description:	This function provides a menu function when provided a vector of menu options, it returns an int value
for option
***********************************************************************************************************************/
int subMenuDispFixed(string title, vector<string> const &menuOptions, string fixedOption0)
{

	//display title
	cout << title << endl << endl;
	cout << "Choose from the following options:" << endl;
	
	//Fixed exit command
	cout << right << setw(7) << "0) " << fixedOption0 << endl;
	
	//Display menu 
	for (unsigned int i = 0; i < menuOptions.size(); i++)
	{
		cout << right << setw(5) << i + 1 << ") " << menuOptions.at(i) << endl;
	}

	// return valid menu option 
	int option = validInt(0, menuOptions.size());
	return option;
}

//https://www.gamedev.net/topic/644605-object-oriented-design-menu-system/  
//http://stackoverflow.com/questions/25992241/passing-reference-of-vector-of-objects-as-arguments-in-c

