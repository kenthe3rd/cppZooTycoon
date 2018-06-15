/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::TIGER CLASS HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"

#ifndef TIGER_HPP
#define TIGER_HPP

class Tiger : public Animal
{
	private:
		int foodCost = BASE_FOOD_COST * 5;
		int payoff = 0;
	public:
		Tiger(int);
		int getFoodCost();
		int getPayoff();
};
#endif
