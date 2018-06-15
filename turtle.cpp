/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::TURTLE CLASS IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"
#include "turtle.hpp"

/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Turtle::Turtle(int ageArg)
{
	age = ageArg;
	cost = 100;
	payoff = cost / (BASE_PAYOFF_DIVISOR * 4);
	numberOfBabies = 10;
}


/*****************************************************************************
 *GET_FOOD_COST: accessor function for food cost 
 ****************************************************************************/

int Turtle::getFoodCost()
{
	return foodCost;
}



/*****************************************************************************
 *GET_PAYOFF: accessor function for payoff 
 ****************************************************************************/

int Turtle::getPayoff()
{
	return payoff;
}
