/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::ANIMAL CLASS HEADER FILE
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age = 0;
		int cost = 0;
		int numberOfBabies = 0;
		const int BASE_FOOD_COST = 10;
		const int BASE_PAYOFF_DIVISOR = 5;
	public:
		int getAge();
		void incrementAge();
		void setCost(int);
		void setNumberOfBabies(int);
		
};
#endif
