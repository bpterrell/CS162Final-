/**********************************************************************************************************************
** Name:		Menu.cpp
** Description: This function provides a menu function when provided a vector of menu options, it returns an int value
				for option
***********************************************************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
using std::vector;
using std::string;


	int menuDisp(string, vector<string> const &);
	int subMenuDisp(string, vector<string> const &);
	int subMenuDispFixed(string, vector<string> const &, string);

#endif
