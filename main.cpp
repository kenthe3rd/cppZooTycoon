/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *:::MAIN FUNCTION:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */
#include "zoo.hpp"
int main()
{
	int userChoice = 0;
	Zoo myZoo;
	myZoo.gameSetupPhase();
	while(userChoice != 2)
	{
		myZoo.ageTheAnimals();
		myZoo.feedTheAnimals();
		myZoo.selectRandomEvent();
		myZoo.incomeForDay();
		myZoo.endOfDayBuyOption();
		myZoo.showStats();
		userChoice = myZoo.quitGamePrompt();
	}
	return 0;
}
