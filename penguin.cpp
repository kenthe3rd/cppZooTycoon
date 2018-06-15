/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *::PENGUIN CLASS IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"
#include "penguin.hpp"
/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Penguin::Penguin(int ageArg)
{
	age = ageArg;
	cost = 1000;
	payoff = cost / (BASE_PAYOFF_DIVISOR * 2);
	numberOfBabies = 5;
}



/*****************************************************************************
 *GET_FOOD_COST: accessor function for food cost 
 ****************************************************************************/

int Penguin::getFoodCost()
{
	return foodCost;
}



/*****************************************************************************
 *GET_PAYOFF: accessor function for payoff 
 ****************************************************************************/

int Penguin::getPayoff()
{
	return payoff;
}
