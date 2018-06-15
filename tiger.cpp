/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::TIGER CLASS IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"
#include "tiger.hpp"

/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Tiger::Tiger(int ageArg)
{
	age = ageArg;
	cost = 10000;
	payoff = cost / BASE_PAYOFF_DIVISOR;
	numberOfBabies = 1;
}



/*****************************************************************************
 *GET_FOOD_COST: accessor function for food cost 
 ****************************************************************************/

int Tiger::getFoodCost()
{
	return foodCost;
}

/*****************************************************************************
 *GET_PAYOFF: accessor function for payoff 
 ****************************************************************************/

int Tiger::getPayoff()
{
	return payoff;
}
