/**********************************************************************************************************
 * * Program Name: 	Zoo.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Declaration of the Zoo class, holds data members for the Tiger, Penguin, and 
 * * 			Turtle arrays, as well as array sizes, amount of money, and days passed.
 * * 			Public methods are used to control the game flow of Zoo Tycoon, as play() makes a
 * * 			call to setUp() at the start and then enters the day-loop until the user chooses
 * * 			to quit the game. Within the day loop, the other methods are called as needed
 * * 			to change the number of animals, money, and cause random events.
**********************************************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "validateInt.hpp"

class Zoo
{ private:

   //Animal subclass arrays of pointers
   Tiger **tigPtr;

   Penguin **penPtr;

   Turtle **turtPtr;

   //data members describing the current max size of each array
   int tigSize,
       penSize,
       turtSize;
   //data members holding the number of each animal that should exist in the corresponding array
   int numTig,
       numPen,
       numTurt;

   //data members for the money the player has and the days that have elapsed
   int money,
       days;

  public:

   Zoo();				//creates the dynamic arrays of pointers to each animal subclass

   ~Zoo();				//deallocates memory at the end of the Zoo object lifespan to avoid
					//memory leaks

   /****************************************************
    * * setUp()
    * * called at the beginning of play(), asks user
    * * if they want to play or quit, then sets up
    * * the starting money value and asks user to 
    * * choose how many of each animal they want to 
    * * buy (1 or 2 of each). 
    * * Returns false if user quits, true if not.
   ****************************************************/
   bool setUp();			

   /***********************************************************
    * * play()
    * * Contains the game flow of Zoo Tycoon, makes a call
    * * to setUp() to initialize settings then starts the
    * * day loop where animals are aged and fed one of three
    * * feed types, then a random event occurs with RNG
    * * dependent on feed type. Finally, the user is asked
    * * if they want to buy one new adult and if they would
    * * like to keep playing.
    * * Returns false if the user quits, true otherwise.
   **********************************************************/
   bool play();	

   /***********************************************************
    * * payFood()
    * * Presents the user with a choice between Cheap, 
    * * Normal, and Expensive feed, then calculates the cost
    * * of feeding each animal based on that choice. Cheap
    * * halves cost, Expensive doubles cost.
    * * Returns 1 for cheap, 2 for normal, or 3 for expensive.
    * * This output is then passed to the randomEvent(int)
    * * function to skew RNG.
   ************************************************************/   
   int payFood();

   /************************************************************
    * * randomEvent(int)
    * * Is passed an integer describing the type of feed chosen,
    * * skews RNG appropriately depending on that. Four possible
    * * events: sickness, baby born, bonus tiger profit, and
    * * nothing.
    * * Returns an integer representing the amount of bonus
    * * tiger profit between 250 and 500.
   *************************************************************/  
   int randomEvent(int);

   /************************************************************
    * * calculateProfit(int)
    * * Passed an integer representing the amount of bonus tiger
    * * profit, uses that to calculate the total profit by
    * * summing the profits of each animal in each array. 
    * * Returns an integer representing the profit received.
   *************************************************************/
   int calculateProfit(int);

   /************************************************************
    * * addAnimalBabies()
    * * The addAnimalBabies series adds the appropriate amount
    * * of animal babies to the correct array.
   *************************************************************/
   void addTigerBabies(),
	addPenguinBabies(),
	addTurtleBabies();

   /*****************************************
    * * addAnimalAdult()
    * * used to add a single adult
    * * (age = 3) animal to the appropriate
    * * array.
   *****************************************/
   void addTigerAdult(),
	addPenguinAdult(),
	addTurtleAdult();

   /*****************************************
    * * expandAnimal()
    * * called by the corresponding
    * * addAnimalAdult() function if the
    * * addition of another animal would 
    * * cause the array to be accessed out
    * * of bounds, accomplished by doubling
    * * the appropriate animalSize member
   *****************************************/
   void expandTiger(),		
	expandPenguin(),		
	expandTurtle();

   //mutators
   void setDays(int),
	setMoney(int),
	setNumTurt(int),
	setNumPen(int),
	setNumTig(int);
};

#endif
