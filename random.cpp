/***********************************************************************************************************************
** Name:  random 
** Description: Function provides random numbers within a range
***********************************************************************************************************************/
#include "random.h"
#include <cstdlib>
#include <ctime>
#include <random>
 
/***********************************************************************************************************************
** Name:  int random(int min, int max)
** Description: Function provides random numbers within a range
** source: www.learncpp.com
***********************************************************************************************************************/
int random(int min, int max)
{

	std::random_device rd;			//better random www.learncpp.com
	std::mt19937 mersenne(rd());
	return (mersenne() % (max - min + 1)) + min; // provides random value between min and max

}
