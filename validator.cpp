/***********************************************************************************************************************
**	Name:	valiator.cpp
**	Description: recieves an iostream input, verifies in to be a valid value
***********************************************************************************************************************/
#include "validator.h"
#include <iostream>
#include <limits>
#include <iomanip>


/***********************************************************************************************************************
**	Name:	int validInt()
**	Description:	recieves an iostream input, verifies in to be an int and returns it
**	References:		http://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
***********************************************************************************************************************/
int validInt()
{
	int tempInt = 0;	// initialize variable to receive keyboard input

	std::cin >> tempInt;	// recieves keyboard input

							// loop if cin enters error state due to mismatched data type
	while (!std::cin)
	{
		std::cout << "Invalid value, please re-enter an int value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempInt;	// re-attempt to collect valid data
	}
	return tempInt;		//return int
}


/***********************************************************************************************************************
**	Name:	int validInt(int)
**	Description:	recieves an iostream input, verifies in to be an int and greater than the argument provided
**	References:		http://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
***********************************************************************************************************************/
int validInt(int isGrtrThn)		// is cin grater than param 
{
	int tempInt = 0;	// initialize variable to receive keyboard input

	std::cin >> tempInt;	// recieves keyboard input

							// loop if cin enters error state due to mismatched data type
	while (!std::cin || tempInt > isGrtrThn)
	{
		std::cout << "Invalid value, please re-enter an int value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempInt;	// re-attempt to collect valid data
	}
	return tempInt;		//return int
}



/***********************************************************************************************************************
**	Name:	int validInt(int, int) 
**	Description:	recieves an iostream input, verifies in to be an int and  to be in a range, then returns it
**	References:		http://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
***********************************************************************************************************************/
int validInt(int lo, int hi)
{
	int tempInt = 0;	// initialize variable to receive keyboard input

	std::cin >> tempInt;	// recieves keyboard input

	
	// loop if cin enters error state due to mismatched data type
	while (!std::cin || tempInt < lo || tempInt > hi)
	{
		std::cout << "Invalid value, please re-enter an int value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempInt;	// re-attempt to collect valid data
	}
	return tempInt;		//return int
}


/***********************************************************************************************************************
**	Name:	
**	Description:	
**	References:		http://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
***********************************************************************************************************************/
float validFlt(float lo, float hi)
{
	float tempFlt = 0;	// initialize variable to receive keyboard input

	std::cin >> tempFlt;	// recieves keyboard input


							// loop if cin enters error state due to mismatched data type
	while (!std::cin || tempFlt < lo || tempFlt > hi)
	{
		std::cout << "Invalid value, please re-enter an float value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempFlt;	// re-attempt to collect valid data
	}
	return tempFlt;		//return int
}


/***********************************************************************************************************************
**	Name:	bool validInt(int lo, int hi, int testVal)
**	Description:	function recieves min, max, and testValue > returns bool true if test value is within range
**	References:		http://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
***********************************************************************************************************************/
bool validInt(int lo, int hi, int testVal)
{
	if(testVal < lo || testVal > hi)
	{
		return false;
	}

	return true;

}


/***********************************************************************************************************************
**	Name:	bool validYorN()
**	Description:	Function provided a valid bool from a y o n input. 
**	References:		
***********************************************************************************************************************/
bool validYorN()
{
	char tempChar = ' ';	// initialize variable to receive keyboard input

	std::cin >> tempChar;	// recieves keyboard input

							// loop if cin enters error state due to mismatched data type
	while (!std::cin || !((tempChar == 'y' || tempChar == 'Y') || (tempChar == 'n' || tempChar == 'N')))
	{
		std::cout << "Invalid value, please re-enter a new value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempChar;	// re-attempt to collect valid data
	}
	//yes returns true
	if (tempChar == 'y' || tempChar == 'Y')
	{
		return true;
	}
	// no returns false
	return false;
	
}

/***********************************************************************************************************************
**	Name:	bool validSorI()
**	Description:	Function provided a valid bool from an input.
**	References:
***********************************************************************************************************************/
bool validSorI()
{
	char tempChar = ' ';	// initialize variable to receive keyboard input

	std::cin >> tempChar;	// recieves keyboard input

							// loop if cin enters error state due to mismatched data type
	while (!std::cin || !((tempChar == 's' || tempChar == 'S') || (tempChar == 'i' || tempChar == 'I')))
	{
		std::cout << "Invalid value, please re-enter a new value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempChar;	// re-attempt to collect valid data
	}
	//yes returns true
	if (tempChar == 's' || tempChar == 'S')
	{
		return true;
	}
	// no returns false
	return false;

}




/***********************************************************************************************************************
**	Name:	bool validIorN()
**	Description:	Function provided a valid bool from an input.
**	References:
***********************************************************************************************************************/
bool validIorN()
{
	char tempChar = ' ';	// initialize variable to receive keyboard input

	std::cin >> tempChar;	// recieves keyboard input

							// loop if cin enters error state due to mismatched data type
	while (!std::cin || !((tempChar == 'i' || tempChar == 'I') || (tempChar == 'n' || tempChar == 'N')))
	{
		std::cout << "Invalid value, please re-enter a new value." << std::endl;	// prompt for valid data
		std::cin.clear();		// clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//clear buffer
		std::cin >> tempChar;	// re-attempt to collect valid data
	}
	//yes returns true
	if (tempChar == 'i' || tempChar == 'I')
	{
		return true;
	}
	// no returns false
	return false;
	
}

