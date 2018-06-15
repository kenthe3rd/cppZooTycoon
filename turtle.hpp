/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::TURTLE CLASS HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"

#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle : public Animal
{
	private:
		int foodCost = (BASE_FOOD_COST / 2 );
		int payoff = 0;
	public:
		Turtle(int);
		int getFoodCost();	
		int getPayoff();
};
#endif
