/***********************************************************************************************************************
**	Name:	validator.h
**	Description: recieves an iostream input, verifies in to be an
***********************************************************************************************************************/

#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

int validInt();

int validInt(int isGrtrThn);

int validInt(int, int);

float validFlt(float lo, float hi);

bool validInt(int, int, int);

bool validYorN();

bool validSorI();

bool validIorN();

#endif