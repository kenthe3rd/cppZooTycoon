/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::ANIMAL CLASS IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"

/*****************************************************************************
 *GET_AGE: accessor for age variable
 ****************************************************************************/

int Animal::getAge()
{
	return age;
}

/*****************************************************************************
 *INCREMENT_AGE: increments age variable
 ****************************************************************************/

void Animal::incrementAge()
{
	age++;
}



/*****************************************************************************
 *SET_COST: mutator for cost variable
 ****************************************************************************/

void Animal::setCost(int costArg)
{
	cost = costArg;
}



/*****************************************************************************
 *SET_NUMBER_OF_BABIES: mutator for numberOfBabies member variable
 ****************************************************************************/

void Animal::setNumberOfBabies(int babiesArg)
{
	numberOfBabies = babiesArg;
}
