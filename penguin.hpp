/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *::PENGUIN CLASS HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "animal.hpp"

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin : public Animal
{
	private:
		int foodCost = BASE_FOOD_COST;
		int payoff = 0;
	public:
		Penguin(int);
		int getFoodCost();
		int getPayoff();
};
#endif
