/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2	
 *:::ZOO CLASS HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "menu.hpp"
class Zoo
{
	private:
		Menu buyOptionMenu;
		Menu quitMenu;
		Menu gameStartMenu;
		Menu feedTypesMenu;

		int feedChoice = 0;
		int playerMoney = 50000;

		int numOfTigers = 0;			//tracks anim
		int numOfPenguins = 0;			//population
		int numOfTurtles = 0;			//in zoo
	
		int tigerArrayCapacity = 10;		//tracks and
		int penguinArrayCapacity = 10;		//maintains
		int turtleArrayCapacity = 10;		//array caps

		Tiger* tigerPointer = nullptr;		//pointers for copying
		Penguin* penguinPointer = nullptr;	//animal obejcts
		Turtle* turtlePointer = nullptr;	//from add member
							//functions

		Tiger** arrayOfTigers = nullptr;	//animal
		Penguin** arrayOfPenguins = nullptr;	//exhibits
		Turtle** arrayOfTurtles = nullptr;	//

		Tiger** copyOfTigers = nullptr;		//used in copying
		Penguin** copyOfPenguins = nullptr;	//arrays during
		Turtle** copyOfTurtles = nullptr;	//doubling of cap

	public:
		Zoo();
		~Zoo();
		void ageTheAnimals();
		void feedTheAnimals();
		void selectRandomEvent();
		void sicknessEvent();
		void boomInAttendanceEvent();
		void babiesAreBornEvent();
		void incomeForDay();
		void endOfDayBuyOption();
		int quitGamePrompt();
		int gameStartMenuPrompt();
		void gameSetupPhase();
		void showStats();
		void addTiger(int);
		void addPenguin(int);
		void addTurtle(int);
		
};
#endif
