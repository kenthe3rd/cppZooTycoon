/* ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** **
 *Ken Hall	2/04/2018
 *
 *CS 162 400	Project 2
 *::ZOO CLASS IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */
#include <cstdlib>
#include <time.h>
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Zoo::Zoo()
{
	//seed for random numbers based on time
	srand(time(NULL));

	arrayOfTigers = new Tiger*[10];
	arrayOfPenguins = new Penguin*[10];
	arrayOfTurtles = new Turtle*[10];

	//set the menus' items
	buyOptionMenu.setItems(	"($10000 Buy tiger", 
				"($1000) Buy penguin", 
				"($100) Buy turtle", 
				"Don't buy an animal");


	quitMenu.setItems(	"Advance to next day",
				"Quit game");

	gameStartMenu.setItems(	"Buy 1",
				"Buy 2");

	feedTypesMenu.setItems(	"Cheap feed",
				"Generic feed",
				"Premium feed");
}


/*****************************************************************************
 *DESTRUCTOR
 ****************************************************************************/

Zoo::~Zoo()
{
	//free the space allocated to each animal
	for(int i=0; i<numOfTigers; i++)
	{
		delete arrayOfTigers[i];
	}

	for(int i=0; i<numOfPenguins; i++)
	{
		delete arrayOfPenguins[i];
	}

	for(int i=0; i<numOfTurtles; i++)
	{
		delete arrayOfTurtles[i];
	}

	//free the space allocated to the arrays for the animals
	delete[] arrayOfTigers;
	delete[] arrayOfPenguins;
	delete[] arrayOfTurtles;

//	delete[] copyOfTigers;
//	delete[] copyOfPenguins;
//	delete[] copyOfTurtles;
}


/*****************************************************************************
 *AGE_THE_ANIMALS: calls each animal's age increment function
 ****************************************************************************/

void Zoo::ageTheAnimals()
{
	for(int i=0; i<numOfTigers; i++)
	{
		arrayOfTigers[i]->incrementAge();
	}

	for(int i=0; i<numOfPenguins; i++)
	{
		arrayOfPenguins[i]->incrementAge();
	}

	for(int i=0; i<numOfTurtles; i++)
	{
		arrayOfTurtles[i]->incrementAge();
	}
}


/*****************************************************************************
 *FEED_THE_ANIMALS: subtracts money from player's account to buy feed 
 ****************************************************************************/

void Zoo::feedTheAnimals()
{
	cout << "Time to feed the animals.  Select a feed type." << endl;
	feedTypesMenu.displayMenu();
	feedChoice = feedTypesMenu.enforceValidInput();
	for(int i=0; i<numOfTigers; i++)
	{
		if(feedChoice == 1)
		{
			playerMoney -= arrayOfTigers[i]->getFoodCost()/2;
		}
		else if(feedChoice == 2)
		{
			playerMoney -= arrayOfTigers[i]->getFoodCost();
		}
		else if(feedChoice ==3)
		{
			playerMoney -= arrayOfTigers[i]->getFoodCost()*2;
		}
	}

	for(int i=0; i<numOfPenguins; i++)
	{
		if(feedChoice == 1)
		{
			playerMoney -= arrayOfPenguins[i]->getFoodCost()/2;
		}
		else if(feedChoice == 2)
		{
			playerMoney -= arrayOfPenguins[i]->getFoodCost();
		}
		else if(feedChoice == 3)
		{
			playerMoney -= arrayOfPenguins[i]->getFoodCost()*2;
		}
	}

	for(int i=0; i<numOfTurtles; i++)
	{
		if(feedChoice == 1)
		{
			playerMoney -= arrayOfTurtles[i]->getFoodCost()/2;
		}
		else if(feedChoice == 2)
		{
			playerMoney -= arrayOfTurtles[i]->getFoodCost();
		}
		else if(feedChoice == 3)
		{
			playerMoney -= arrayOfTurtles[i]->getFoodCost()*2;
		}
	}
}


/*****************************************************************************
 *SELECT_RANDOM_EVENT: randomly selects and calls a random event function 
 ****************************************************************************/

void Zoo::selectRandomEvent()
{
	int event = rand() % 4;
	if(feedChoice == 1)
	{
		//1 in 2 chance that sickness occurs, normally would be 1 / 4
		event = rand() % 2;
		if(event == 1)
		{
			//dodged the x2 likely sick event, rolling for other
			//event by putting sickness out of range
			event = (rand() % 3) + 1;
			cout << "Somehow, your animals are healthy "
			<< "in spite of the low quality feed." << endl;
		}
		else
		{
			cout << "Cheap feed causes sickness." << endl;
		}
	}
	if(feedChoice == 3)
	{
		//1 in 8 chance that sickness occurs
		 event = rand() % 8;
		if(event == 7)
		{
			//sickness still triggered in spite of feed quality
			event = 0;
			cout << "In spite of good feed, an animal "
			<< "still got sick and died." << endl;
		}
		else
		{
			//putting sickness out of range
			event = (rand() % 3) + 1;
			cout << "High quality feed keeps your animals "
			<< "in good health." << endl;
		}
	}
	if(event == 0)
	{
		//animal dies to sickness
		cout << endl << "An animal dies..." << endl;
		this->sicknessEvent();
	}
	else if(event == 1)
	{
		//extra money for tigers
		cout << endl << "It's a busy day! Bonus income today!" << endl;
		this->boomInAttendanceEvent();
	}
	else if(event == 2)
	{
		//Baby animals are borna
		cout << endl << "A baby animal is born..." << endl;
		this->babiesAreBornEvent();
	}
	else if(event == 3)
	{
		//NULL event...nothing happens here
		cout << endl << "Nothing unusual happens today." << endl;
	}
}



/*****************************************************************************
 *SICKNESS_EVENT: kill off one animal at random 
 ****************************************************************************/

void Zoo::sicknessEvent()
{
	if(numOfTigers != 0 || numOfPenguins != 0 || numOfTurtles != 0)
	{
		int elementToMoveTo = 0;
		int animalCategory = rand() % 3;
		if(animalCategory == 0)
		{
			//a tiger dies, if a tiger exists
			if(numOfTigers == 0)
			{
				this->sicknessEvent();
				animalCategory = -1;
			}
			else
			{
				int copiedTigerAge = 0;
				int deadTiger = rand() % numOfTigers;
				copyOfTigers = new Tiger*[tigerArrayCapacity];
				for(int i=0; i<numOfTigers; i++)
				{
					if(i != deadTiger)
					{
						copiedTigerAge =
						arrayOfTigers[i]->getAge();
						copyOfTigers[elementToMoveTo] =
						new Tiger(copiedTigerAge);
						elementToMoveTo++;
					}
					delete arrayOfTigers[i];
				}
				numOfTigers--;

				//copy back to the original array
				for(int i=0; i<numOfTigers; i++)
				{
					copiedTigerAge = 
					copyOfTigers[i]->getAge();
					arrayOfTigers[i] = 
					new Tiger(copiedTigerAge);
					delete copyOfTigers[i];
				}

				delete[] copyOfTigers;
				cout << "it was a tiger." << endl;
			}
		}

		if(animalCategory == 1)
		{
			//a penguin dies, if a penguin exists
			if(numOfPenguins == 0)
			{
				this->sicknessEvent();
				animalCategory = -1;
			}
			else
			{
				int copiedPenguinAge = 0;
				int deadPenguin = rand() % numOfPenguins;
				copyOfPenguins = 
				new Penguin*[penguinArrayCapacity];
				for(int i=0; i<numOfPenguins; i++)
				{
					if(i != deadPenguin)
					{
						copiedPenguinAge =
						arrayOfPenguins[i]->getAge();
						copyOfPenguins[elementToMoveTo] =
						new Penguin(copiedPenguinAge);
						elementToMoveTo++;
					}
					delete arrayOfPenguins[i];
				}
				numOfPenguins--;

				//copy back to the original array
				for(int i=0; i<numOfPenguins; i++)
				{
					copiedPenguinAge = 
					copyOfPenguins[i]->getAge();
					arrayOfPenguins[i] = 
					new Penguin(copiedPenguinAge);
					delete copyOfPenguins[i];
				}

				delete[] copyOfPenguins;
				cout << "it was a penguin." << endl;
			}
		}

		if(animalCategory == 2)
		{
			//a turtle dies, if a turtle exists
			if(numOfTurtles == 0)
			{
				this->sicknessEvent();
				animalCategory = -1;
			}
			else
			{
				int copiedTurtleAge = 0;
				int deadTurtle = rand() % numOfTurtles;
				copyOfTurtles = new Turtle*[turtleArrayCapacity];
				for(int i=0; i<numOfTurtles; i++)
				{
					if(i != deadTurtle)
					{
						copiedTurtleAge =
						arrayOfTurtles[i]->getAge();
						copyOfTurtles[elementToMoveTo] =
						new Turtle(copiedTurtleAge);
						elementToMoveTo++;
					}
					delete arrayOfTurtles[i];
				}
				numOfTurtles--;

				//copy back to the original array
				for(int i=0; i<numOfTurtles; i++)
				{
					copiedTurtleAge = 
					copyOfTurtles[i]->getAge();
					arrayOfTurtles[i] = 
					new Turtle(copiedTurtleAge);
					delete copyOfTurtles[i];
				}

				delete[] copyOfTurtles;
				cout << "it was a turtle." << endl;
			}
		}
	}
	else
	{
		cout << endl << "Just kidding...somehow you killed off "
		<< "all of your animals already..." << endl;
	}
}


/*****************************************************************************
 *BOOM_IN_ATTENDANCE_EVENT: extra money added to player account for increased
 *attendance at the zoo 
 ****************************************************************************/

void Zoo::boomInAttendanceEvent()
{
	for(int i=0; i<numOfTigers; i++)
	{
		//a random amount of money between 0 and 250, plus 250
		playerMoney += ((rand() % 251)+250);
	}
}




/*****************************************************************************
 *BABIES_ARE_BORN_EVENT: adds baby animals to the zoo 
 ****************************************************************************/

void Zoo::babiesAreBornEvent()
{
	bool animalWasBorn = false;
	bool adultTiger = false;
	bool adultPenguin = false;
	bool adultTurtle = false;

	for(int i=0; i<numOfTigers; i++)
	{
		if(arrayOfTigers[i]->getAge() >= 3)
		{
			adultTiger = true;
		}
	}

	for(int i=0; i<numOfPenguins; i++)
	{
		if(arrayOfPenguins[i]->getAge() >= 3)
		{
			adultPenguin = true;
		}
	}

	for(int i=0; i<numOfTurtles; i++)
	{
		if(arrayOfTurtles[i]->getAge() >= 3)
		{
			adultTurtle = true;
		}
	}

	if(adultTiger || adultPenguin || adultTurtle)
	{
		while(!animalWasBorn)
		{
			int animalBorn = rand() % 3;
			if(animalBorn == 0)
			{
				if(adultTiger)
				{
					cout << "It was a tiger!" << endl;
					//add tiger age 0 to the zoo
					addTiger(0);
					animalWasBorn = true;
				}
			}

			if(animalBorn == 1)
			{
				if(adultPenguin)
				{
					cout << "It was a bunch of penguins!" 
					<< endl;
					//add 5 penguins age 0 to the zoo
					for(int i=0; i<5; i++)
					{
						addPenguin(0);
					}
					animalWasBorn = true;
				}
			}

			if(animalBorn == 2)
			{
				if(adultTurtle)
				{
					cout << "It was a bunch of turtles!" 
					<< endl;
					for(int i=0; i<10; i++)
					{
						addTurtle(0);
					}
					animalWasBorn = true;
				}
			}
		}
	}
	else
	{
		cout << "False alarm! No animals old enough to have "
		<< "babies." << endl;
	}
}
/*****************************************************************************
 *ADD_TIGER: Build a Tiger object and add a pointer to it to the array
 ****************************************************************************/

void Zoo::addTiger(int ageArg)
{
	if(numOfTigers == tigerArrayCapacity)
	{
		int copiedTigerAge = 0;
		//at capacity, beginning copy and double
		copyOfTigers = new Tiger*[tigerArrayCapacity];
		for(int i=0; i<numOfTigers; i++)
		{
			copiedTigerAge = arrayOfTigers[i]->getAge();
			copyOfTigers[i] = new Tiger(copiedTigerAge);
			delete arrayOfTigers[i];
		}
		delete[] arrayOfTigers;
		tigerArrayCapacity*=2;
		arrayOfTigers = new Tiger*[tigerArrayCapacity];

		//copy the array back
		for(int i=0; i<numOfTigers; i++)
		{
			copiedTigerAge = copyOfTigers[i]->getAge();
			arrayOfTigers[i] = new Tiger(copiedTigerAge);
			delete copyOfTigers[i];
		}
		delete[] copyOfTigers;
	} 
	arrayOfTigers[numOfTigers] = new Tiger(ageArg);
	numOfTigers++;
}




/*****************************************************************************
 *ADD_PENGUIN: Build a Penguin object and add a pointer to it to the array
 ****************************************************************************/

void Zoo::addPenguin(int ageArg)
{
	if(numOfPenguins == penguinArrayCapacity)
	{
		int copiedPenguinAge = 0;
		//at capacity, beginning copy and double
		copyOfPenguins = new Penguin*[penguinArrayCapacity];
		for(int i=0; i<numOfPenguins; i++)
		{
			copiedPenguinAge = arrayOfPenguins[i]->getAge();
			copyOfPenguins[i] = new Penguin(copiedPenguinAge);
			delete arrayOfPenguins[i];
		}
		delete[] arrayOfPenguins;
		penguinArrayCapacity*=2;
		arrayOfPenguins = new Penguin*[penguinArrayCapacity];

		//copy the array back
		for(int i=0; i<numOfPenguins; i++)
		{
			copiedPenguinAge = copyOfPenguins[i]->getAge();
			arrayOfPenguins[i] = new Penguin(copiedPenguinAge);
			delete copyOfPenguins[i];
		}
		delete[] copyOfPenguins;

	} 
	arrayOfPenguins[numOfPenguins] = new Penguin(ageArg);
	numOfPenguins++;
}



/*****************************************************************************
 *ADD_TURTLE: Build a Turtle object and add a pointer to it to the array
 ****************************************************************************/

void Zoo::addTurtle(int ageArg)
{
	if(numOfTurtles == turtleArrayCapacity)
	{
		int copiedTurtleAge = 0;
		//at capacity, beginning copy and double
		copyOfTurtles = new Turtle*[turtleArrayCapacity];
		for(int i=0; i<numOfTurtles; i++)
		{
			copiedTurtleAge = arrayOfTurtles[i]->getAge();
			copyOfTurtles[i] = new Turtle(copiedTurtleAge);
			delete arrayOfTurtles[i];
		}
		delete[] arrayOfTurtles;
		turtleArrayCapacity*=2;
		arrayOfTurtles = new Turtle*[turtleArrayCapacity];

		//copy the array back
		for(int i=0; i<numOfTurtles; i++)
		{
			copiedTurtleAge = copyOfTurtles[i]->getAge();
			arrayOfTurtles[i] = new Turtle(copiedTurtleAge);
			delete copyOfTurtles[i];
		}
		delete[] copyOfTurtles;
	} 
	arrayOfTurtles[numOfTurtles] = new Turtle(ageArg);
	numOfTurtles++;
}


/*****************************************************************************
 *GAME_SETUP_PHASE: prompts player with setup menu for each type of animal
 ****************************************************************************/

void Zoo::gameSetupPhase()
{
	int choice = 0;

	cout << "Please choose a number of tigers to start with. ($10000 each)"
	<< endl;
	choice = gameStartMenuPrompt();
	for(int i=0; i<choice; i++)
	{
		this->addTiger(1);
		playerMoney-=10000;
	}
	
	cout << "Please choose a number of penguins to start with. ($1000 each)"
	<< endl;
	choice = gameStartMenuPrompt();
	for(int i=0; i<choice; i++)
	{
		this->addPenguin(1);
		playerMoney-=1000;
	}

	cout << "Please choose a number of turtles to start with. ($100 each)"
	<< endl;

	choice = gameStartMenuPrompt();
	for(int i=0; i<choice; i++)
	{
		this->addTurtle(1);
		playerMoney-=100;
	}
}


/*****************************************************************************
 *INCOME_FOR_DAY: adds base income to player's account for each animal 
 ****************************************************************************/

void Zoo::incomeForDay()
{
	for(int i=0; i<numOfTigers; i++)
	{
		playerMoney+= arrayOfTigers[i]->getPayoff();
	}
	for(int i=0; i<numOfPenguins; i++)
	{
		playerMoney+= arrayOfPenguins[i]->getPayoff();
	}
	for(int i=0; i<numOfTurtles; i++)
	{
		playerMoney+= arrayOfTurtles[i]->getPayoff();
	}
}


/*****************************************************************************
 *SHOW_STATS: displays amount of money in player bank, and number of animals
 ****************************************************************************/

void Zoo::showStats()
{
	cout << endl << "Player has $" << playerMoney << endl;
	cout << numOfTigers << " tigers in the zoo." << endl;
	for(int i=0; i<numOfTigers; i++)
	{
		cout << "Age of tiger " << i + 1 << ":" 
		<< arrayOfTigers[i]->getAge() << endl;;
	}
	cout << numOfPenguins << " penguins in the zoo." << endl;
	for(int i=0; i<numOfPenguins; i++)
	{
		cout << "Age of penguin " << i + 1 << ":"
		<< arrayOfPenguins[i]->getAge() << endl;
	}
	cout << numOfTurtles << " turtles in the zoo." << endl;
	for(int i=0; i<numOfTurtles; i++)
	{
		cout << "Age of turtle " << i + 1 << ":"
		<< arrayOfTurtles[i]->getAge() << endl;
	}
}

/*****************************************************************************
 *END_OF_DAY_BUY_OPTION: player may elect to buy an animal at the end of the day 
 ****************************************************************************/

void Zoo::endOfDayBuyOption()
{
	int choice = 0;
	buyOptionMenu.displayMenu();
	choice = buyOptionMenu.enforceValidInput();

	if(choice == 1)
	{
		playerMoney -= 10000;
		this->addTiger(3);
	}
	if(choice == 2)
	{
		playerMoney -= 1000;
		this->addPenguin(3);
	}
	if(choice == 3)
	{
		playerMoney -= 100;
		this->addTurtle(3);
	}
	if(choice == 4)
	{
		//nothing happens; no animals added
	}
}



/*****************************************************************************
 *QUIT_GAME_PROMPT: asks if player would like to continue, or quit playing
 *also quits the game if the player has run out of money
 ****************************************************************************/

int Zoo::quitGamePrompt()
{
	int choice = 0;
	if(playerMoney <= 0)
	{
		cout << endl << endl << "GAME OVER" << endl << endl;
		choice = 2;
	}
	else
	{
		quitMenu.displayMenu();
		choice = quitMenu.enforceValidInput();
	}
	return choice;
}



/*****************************************************************************
 *GAME_START_MENU_PROMPT: asks players if they would like to buy one or two
 *of an animal to start the game with 
 ****************************************************************************/

int Zoo::gameStartMenuPrompt()
{
	int choice = 0;
	gameStartMenu.displayMenu();
	choice = gameStartMenu.enforceValidInput();
	return choice;
}
