/**********************************************************************************************************
 * * Program Name: 	Zoo.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Definition of the Zoo class, for full description of the class and function
 * * 			comments/descriptors, see Zoo.hpp
**********************************************************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "validateInt.hpp"
//#include "Custom.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

Zoo::Zoo()
{
   tigPtr = NULL;

   penPtr = NULL;

   turtPtr = NULL;

   tigSize = 10;

   penSize = 10;

   turtSize = 10;

   numTig = 0;

   numPen = 0;

   numTurt = 0;

   days = 0;

   money = 0;
}

Zoo::~Zoo()
{
   delete [] tigPtr;

   delete [] penPtr;

   delete [] turtPtr;

}
/*********************************************
 * * set function series
*********************************************/
void Zoo::setDays(int inputDays)
{
   days = inputDays;
}

void Zoo::setMoney(int inputMoney)
{
   money = inputMoney;
}

void Zoo::setNumTig(int inputTigers)
{
   numTig = inputTigers;
}

void Zoo::setNumPen(int inputPenguins)
{
   numPen = inputPenguins;
}

void Zoo::setNumTurt(int inputTurtles)
{
   numTurt = inputTurtles;
}

/************************************************
 * * addAnimal and expandAnimal function series
************************************************/
void Zoo::addTigerAdult()
{
   //check if the animal array will be accessed out of bounds
   //and expand it if it will be
   if (numTig + 1 > tigSize)
   {
      expandTiger();
   }

   tigPtr[numTig] = new Tiger(3);

   numTig++;
}

void Zoo::addTigerBabies()
{
   if (numTig + 1 > tigSize)
   {
      expandTiger();
   }

   tigPtr[numTig] = new Tiger(0);

   numTig++;
}

void Zoo::expandTiger()
{
   Tiger **temp = new Tiger*[tigSize * 2];

   //copy the existing tiger pointers into the temporary array
   for (int i = 0; i < tigSize; i++)
   {
      temp[i] = tigPtr[i];
   }

   delete [] tigPtr; 			//delete the tiger pointer array

   tigPtr = NULL;

   //initialize the rest of the temporary array to be null pointers
   for (int i = tigSize; i < (tigSize * 2); i++)
   {
      temp[i] = NULL;
   }

   tigSize *= 2;			//double the size of the tiger array

   tigPtr = temp;			//change the address of the tiger array to the new array
}

void Zoo::addPenguinAdult()
{
   if (numPen + 1 > penSize)
   {
      expandPenguin();
   }

   penPtr[numPen] = new Penguin(3);

   numPen++;
}

void Zoo::addPenguinBabies()
{
   while (numPen + 10 > penSize)
   {
      expandPenguin();
   }

   for (int i = numPen; i < numPen + 5; i++)
   {
      penPtr[i] = new Penguin(0);
   }

   numPen += 5;
}

void Zoo::expandPenguin()
{
   Penguin **temp = new Penguin*[penSize * 2];

   for (int i = 0; i < penSize; i++)
   {
      temp[i] = penPtr[i];
   }

   delete [] penPtr; 		

   penPtr = NULL;

   for (int i = penSize; i < (penSize * 2); i++)
   {
      temp[i] = NULL;
   }

   penSize *= 2;			

   penPtr = temp;		
}

void Zoo::addTurtleAdult()
{
   if (numTurt + 1 > turtSize)
   {
      expandTurtle();
   }

   turtPtr[numTurt] = new Turtle(3);

   numTurt++;
}

void Zoo::addTurtleBabies()
{
   while (numTurt + 10 > turtSize)
   {
      expandTurtle();
   }

  for (int i = numTurt; i < numTurt + 10; i++)
  {
    turtPtr[i] = new Turtle(0);
  } 

   numTurt += 10;
}

void Zoo::expandTurtle()
{
   Turtle **temp = new Turtle*[turtSize * 2];

   for (int i = 0; i < turtSize; i++)
   {
      temp[i] = turtPtr[i];
   }

   delete [] turtPtr; 

   turtPtr = NULL;

   for (int i = turtSize; i < (turtSize * 2); i++)
   {
      temp[i] = NULL;
   }

   turtSize *= 2;			

   turtPtr = temp;			
}

/************************************************************
 * * setUp() 
 * * Full function declaration in Zoo.hpp
************************************************************/
bool Zoo::setUp()
{
   const int STARTING_SIZE = 10;

   const int PLAY = 1;

   const int QUIT = 2;

   const int COST_OF_TIGER = 10000;

   const int COST_OF_PENGUIN = 1000;

   const int COST_OF_TURTLE = 100;

   std::string userInput = "";

   int expense = 0;

   int choice = 0;

   cout << "Welcome to ZOO TYCOON, before we begin, would you like to play the game or quit?\n";

   //loop asking user to enter 1 to play or 2 to quit
   do
   {
      cout << "1. Play Game\n2. Quit\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2")
      {
	 cout << "Error: Enter 1 to play or 2 to quit\n";
      }
   } while (userInput != "1" && userInput != "2");

   choice = stoi(userInput);

   //return the false value if the user chooses to quit program
   if (choice == QUIT)
   {
      return false;
   }

   cout << "\n\n\n\nZOO TYCOON - GAME SETTINGS\n\n";				//present settings to user

   cout << "Enter in the amount of money you want to start with, don't worry, I'll loan it to you!: ";

   getline(cin, userInput);

   validateInt(userInput);

   money = stoi(userInput);							//user defines starting money value

   cout << "Woah, greedy little zoo owner aren't we? Well you'd best pay me back in full later. On to the zoo!\n";

   cout << "\nYou've got a stack of $" << money << " to spend, let's start up a zoo!\n";
   cout << "You'll need some animals to really rake in the dough, let's see...\n";

   cout << "Oh! We've got tigers, penguins, and turtles, oh my! Since we want to have a booming business,\n";
   cout << "you should buy 1 or 2 of each! No more no less. Go ahead moneybags, get some babies!\n";

   //loop asking user to buy 1 or 2 tigers
   do
   {
      cout << "\nSTARTING ANIMALS - TIGERS\n\n";

      cout << "Tigers: buy 1 or 2?\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2")
      {
	 cout << "\nCome on, you can only buy 1 or 2 tigers to start with, so enter 1 or 2!\n";
      }
   } while (userInput != "1" && userInput != "2");

   numTig = stoi(userInput);

   //loop asking user to buy 1 or 2 penguins
   do
   {
      cout << "\nSTARTING ANIMALS - PENGUINS\n\n";

      cout << "Penguins: buy 1 or 2?\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2")
      {
	 cout << "\nCome on, you can only buy 1 or 2 penguins to start with, so enter 1 or 2!\n";
      }
   } while (userInput != "1" && userInput != "2");

   numPen = stoi(userInput);

   //loop asking user to buy 1 or 2 turtles
   do
   {
      cout << "\nSTARTING ANIMALS - TURTLES\n\n";

      cout << "Turtles: buy 1 or 2?\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2")
      {
	 cout << "\nCome on, you can only buy 1 or 2 turtles to start with, so enter 1 or 2!\n";
      }
   } while (userInput != "1" && userInput != "2");

   numTurt = stoi(userInput);

   tigSize = STARTING_SIZE;				//set all array sizes to 10 to begin with

   penSize = STARTING_SIZE;

   turtSize = STARTING_SIZE;

   //initialize all animal arrays with pointers and set the pointers to new Animal objects with 
   //age = 1
   tigPtr = new Tiger*[tigSize];

   for (int i = 0; i < numTig; i++)
   {
      tigPtr[i] = new Tiger(1);
   }

   penPtr = new Penguin*[penSize];

   for (int i = 0; i < numPen; i++)
   {
      penPtr[i] = new Penguin(1);
   }

   turtPtr = new Turtle*[turtSize];

   for (int i = 0; i < numTurt; i++)
   {
      turtPtr[i] = new Turtle(1);
   }

   //calculate the money the player spent on starting animals and subtract that from their total money
   expense = numTig * COST_OF_TIGER + numPen * COST_OF_PENGUIN + numTurt * COST_OF_TURTLE;

   money -= expense;

   cout << "\n\nZOO TYCOON STARTING STATS\n\n";
   cout << "Tigers: " << numTig << "\nPenguins: " << numPen << "\nTurtles: " << numTurt << "\nMoney: " << money << endl;

   return true;
}

/*********************************************************
 * * payFood()
 * * Full description found in Zoo.hpp
*********************************************************/
int Zoo::payFood()
{
   const int CHEAP = 1;					//Feed Type Legend

   const int NORMAL = 2;

   const int EXPENSIVE = 3;

   int feedType = 0;

   int expense = 0;

   std::string userInput = "";

   //loop asking user to choose between normal, cheap, or expensive feed
   do
   {
      cout << "\nWhat type of feed do you want to buy for your animals?\n\n";
      cout << "1. Cheap - Half as much for each animal, doubles chance of sickness\n";
      cout << "2. Normal - Base cost of food is $100, chance of sickness is 25%\n";
      cout << "3. Expensive - Double cost for each animal, halves chance of sickness\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2" && userInput != "3")
      {
	 cout << "Error: enter in 1, 2, or 3 only\n";
      }
   } while (userInput != "1" && userInput != "2" && userInput != "3");

   feedType = stoi(userInput);

   //halve the cost of upkeep if the user picks cheap feed
   if (feedType == CHEAP)
   {
      for (int i = 0; i < numTig; i++)
      {
         expense += tigPtr[i]->getFoodCost() / 2;
      }

      for (int i = 0; i < numPen; i++)
      {
         expense += penPtr[i]->getFoodCost() / 2;
      }

      for (int i = 0; i < numTurt; i++)
      {
         expense += turtPtr[i]->getFoodCost() / 2;
      }
   }

   //don't do anything to the cost of upkeep if the user picks normal feed
   else if (feedType == NORMAL)
   {
      for (int i = 0; i < numTig; i++)
      {
         expense += tigPtr[i]->getFoodCost();
      }

      for (int i = 0; i < numPen; i++)
      {
         expense += penPtr[i]->getFoodCost();
      }

      for (int i = 0; i < numTurt; i++)
      {
         expense += turtPtr[i]->getFoodCost();
      }
   }

   //double the upkeep if the user picks expensive feed
   else if (feedType == EXPENSIVE)
   {
      for (int i = 0; i < numTig; i++)
      {
         expense += tigPtr[i]->getFoodCost() * 2;
      }

      for (int i = 0; i < numPen; i++)
      {
         expense += penPtr[i]->getFoodCost() * 2;
      }

      for (int i = 0; i < numTurt; i++)
      {
         expense += turtPtr[i]->getFoodCost() * 2;
      }
   }

   cout << "\nHere are the feed costs for today: $" << expense << endl;

   money -= expense;

   return feedType;
}

/*********************************************************************
 * * randomEvent()
 * * Full description in Zoo.hpp
*********************************************************************/
int Zoo::randomEvent(int feedType)
{
   const int CHEAP = 1;

   const int NORMAL = 2;

   const int EXPENSIVE = 3;

   int bonus = 0;

   int eventRoll = 0;

   bool hasDied = false;

   switch (feedType)
   {
      /**************************************
       * * User buys cheap feed, sickness
       * * chance is doubled
      **************************************/
      case CHEAP:
      {
	 eventRoll = rand() % 100;

	 //sickness event chance - 50%
	 if (eventRoll <= 49)
	 {
	    int animalToDie = 0;

	    cout << "\nOh no, there's a sickness at the zoo!\n";

	    animalToDie = rand() % 3; 			//randomly select the animal to die
							//0 = tiger
	    if (animalToDie == 0)			//1 = penguin
	    {						//2 = turtle
	       cout << "One of your Tigers has died!!\n";

	       //starting at the end of the array, check each element to see if it
	       //contains an animal. If it does, then delete that animal and 
	       //mark hasDied as true so the loop stops checking the rest of the
	       //array, thus deleting only one animal
	       for (int i = tigSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (tigPtr[i] != NULL)
		     {
			delete tigPtr[i];

			tigPtr[i] = NULL;

			hasDied = true;

			numTig--;
		     }
		  }
	       }
	    }

	    if (animalToDie == 1)
	    {
	       cout << "One of your Penguins has died!!\n";

	       for (int i = penSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (penPtr[i] != NULL)
		     {
			delete penPtr[i];

			penPtr[i] = NULL;

			hasDied = true;

			numPen--;
		     }
		  }
	       }
	    }

	    if (animalToDie == 2)
	    {
	       cout << "One of your Turtles has died!!\n";

	       for (int i = turtSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (turtPtr[i] != NULL)
		     {
			delete turtPtr[i];

			turtPtr[i] = NULL;

			hasDied = true;

			numTurt--;
		     }
		  }
	       }
	    }

	    return 0;
	 }

	 //Bonus to Tiger payoff chance - 16%
	 if (eventRoll <= 65 && eventRoll > 49)
	 {
	    cout << "\nHey hey, it's national Tiger Day! ";

	    bonus = rand() % 250 + 251;

	    cout << "You get an extra $" << bonus << " for every tiger in the zoo for today!\n";

	    return bonus;
	 }

	 //baby animal is born chance - 16%
	 if (eventRoll <= 81 && eventRoll > 65)
	 {
	    bool tigerViable = false;

	    bool penguinViable = false;

	    bool turtleViable = false;

	    int babyType = 0;

	    //check each animal array to see if there are any animals with age above or equal to 3
	    for (int i = 0; i < numTig; i++)
	    {
	       if (tigPtr[i]->getAge() >= 3)
	       {
		  tigerViable = true;
	       }
	    }

	    for (int i = 0; i < numPen; i++)
	    {
	       if (penPtr[i]->getAge() >= 3)
	       {
		  penguinViable = true;
	       }
	    }

	    for (int i = 0; i < numTurt; i++)
	    {
	       if (turtPtr[i]->getAge() >= 3)
	       {
		  turtleViable = true;
	       }
	    }

	    bool canHaveBabies = false;

	    int count = 0;

	    //randomly choose the type of animal to have babies, check to see if there are any adults that
	    //can have babies and choose another type if there are not
	    while (canHaveBabies == false)
	    {
	       babyType = rand() % 3;

	       if (babyType == 0)
	       {
		  canHaveBabies = tigerViable;
	       }

	       else if (babyType == 1)
	       {
		  canHaveBabies = penguinViable;
	       }

	       else if (babyType == 2)
	       {
		  canHaveBabies = turtleViable;
	       }

	       //let the random number generator randomly check all three types, if no types can have babies,
	       //exit the while loop and let the next if statement return 0
	       if (count >= 20)
	       {
		  canHaveBabies = true;
	       }

	       else
	       {
		  count++;
	       }
	    }

	    //if there were no eligible parents, pass the day as normal
	    if (count >= 20)
	    {
	       cout << "\nThe day passes as usual, nothing out of the ordinary.\n";

	       return 0;
	    }

	    //if a baby can be born, do so to the randomly selected animal type
	    else if (canHaveBabies == true)
	    {
	       cout << "A baby is born in the zoo!\n";

	       if (babyType == 0)
	       {
		  cout << "Looks like a tiger had a baby!\n";

		  addTigerBabies();

		  return 0;
	       }

	       else if (babyType == 1)
	       {
		  cout << "Looks like a penguin had a litter of 5 babies!\n";

		  addPenguinBabies();

		  return 0;
	       }

	       if (babyType == 2)
	       {
		  cout << "Looks like a Turtle had a litter of 10 babies!\n";

		  addTurtleBabies();

		  return 0;
	       }
	    }
	 }

	 //chance that nothing happens - 18%
	 if (eventRoll <= 99 && eventRoll > 81)
	 {
	    cout << "\nHmm, not much happened today. At least the animals are still happy!\n";

	    return 0;
	 }
      }

      /*******************************************
       * * User buys normal feed, all chances
       * * for random events are 25%
      *******************************************/
      case NORMAL:
      {
	 eventRoll = rand() % 100;

	 //sickness event chance - 25%
	 if (eventRoll <= 24)
	 {
	    int animalToDie = 0;

	    cout << "\nOh no, there's a sickness at the zoo!\n";

	    animalToDie = rand() % 3;

	    if (animalToDie == 0)
	    {
	       cout << "One of your Tigers has died!!\n";

	       for (int i = tigSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (tigPtr[i] != NULL)
		     {
			delete tigPtr[i];

			tigPtr[i] = NULL;

			hasDied = true;

			numTig--;
		     }
		  }
	       }
	    }

	    if (animalToDie == 1)
	    {
	       cout << "One of your Penguins has died!!\n";

	       for (int i = penSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (penPtr[i] != NULL)
		     {
			delete penPtr[i];

			penPtr[i] = NULL;

			hasDied = true;

			numPen--;
		     }
		  }
	       }
	    }

	    if (animalToDie == 2)
	    {
	       cout << "One of your Turtles has died!!\n";

	       for (int i = turtSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (turtPtr[i] != NULL)
		     {
			delete turtPtr[i];

			turtPtr[i] = NULL;

			hasDied = true;

			numTurt--;
		     }
		  }
	       }
	    }

	    return 0;
	 }

	 //Bonus to Tiger payoff chance - 25%
	 if (eventRoll <= 49 && eventRoll > 24)
	 {
	    cout << "\nHey hey, it's national Tiger Day! ";

	    bonus = rand() % 250 + 251;

	    cout << "You get an extra $" << bonus << " for every tiger in the zoo for today!\n";

	    return bonus;
	 }

	 //baby animal is born chance - 25%
	 if (eventRoll <= 74 && eventRoll > 49)
	 {
	    bool tigerViable = false;

	    bool penguinViable = false;

	    bool turtleViable = false;

	    int babyType = 0;

	    //check each animal array to see if there are any animals with age above or equal to 3
	    for (int i = 0; i < numTig; i++)
	    {
	       if (tigPtr[i]->getAge() >= 3)
	       {
		  tigerViable = true;
	       }
	    }

	    for (int i = 0; i < numPen; i++)
	    {
	       if (penPtr[i]->getAge() >= 3)
	       {
		  penguinViable = true;
	       }
	    }

	    for (int i = 0; i < numTurt; i++)
	    {
	       if (turtPtr[i]->getAge() >= 3)
	       {
		  turtleViable = true;
	       }
	    }

	    bool canHaveBabies = false;

	    int count = 0;

	    //randomly choose the type of animal to have babies, check to see if there are any adults that
	    //can have babies and choose another type if there are not

	    while (canHaveBabies == false)
	    {
	       babyType = rand() % 3;

	       if (babyType == 0)
	       {
		  canHaveBabies = tigerViable;
	       }

	       else if (babyType == 1)
	       {
		  canHaveBabies = penguinViable;
	       }

	       else if (babyType == 2)
	       {
		  canHaveBabies = turtleViable;
	       }

	       //let the random number generator randomly check all three types, if no types can have babies,
	       //exit the while loop and let the next if statement return 0
	       if (count >= 20)
	       {
		  canHaveBabies = true;
	       }

	       else
	       {
		  count++;
	       }
	    }

	    if (count >= 20)
	    {
	       cout << "\nThe day passes as usual, nothing out of the ordinary.\n";

	       return 0;
	    }

	    //if a baby can be born, do so to the randomly selected animal type
	    else if (canHaveBabies == true)
	    {
	       cout << "A baby is born in the zoo!\n";

	       if (babyType == 0)
	       {
		  cout << "Looks like a tiger had a baby!\n";

		  addTigerBabies();

		  return 0;
	       }

	       else if (babyType == 1)
	       {
		  cout << "Looks like a penguin had a litter of 5 babies!\n";

		  addPenguinBabies();

		  return 0;
	       }

	       if (babyType == 2)
	       {
		  cout << "Looks like a Turtle had a litter of 10 babies!\n";

		  addTurtleBabies();

		  return 0;
	       }
	    }
	 }

	 //chance that nothing happens - 25%
	 if (eventRoll <= 99 && eventRoll > 74)
	 {
	    cout << "\nHmm, not much happened today. At least the animals are still happy!\n";

	    return 0;
	 }

	 break;
      }

      /******************************
       * * User buys expensive feed,
       * * halves sickness chance
      ******************************/
      case EXPENSIVE:
      {
	 eventRoll = rand() % 100;

	 //sickness event chance - 12%
	 if (eventRoll <= 11)
	 {
	    int animalToDie = 0;

	    cout << "\nOh no, there's a sickness at the zoo!\n";

	    animalToDie = rand() % 3;

	    if (animalToDie == 0)
	    {
	       cout << "One of your Tigers has died!!\n";

	       for (int i = tigSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (tigPtr[i] != NULL)
		     {
			delete tigPtr[i];

			tigPtr[i] = NULL;

			hasDied = true;

			numTig--;
		     }
		  }
	       }
	    }

	    if (animalToDie == 1)
	    {
	       cout << "One of your Penguins has died!!\n";

	       for (int i = penSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (penPtr[i] != NULL)
		     {
			delete penPtr[i];

			penPtr[i] = NULL;

			hasDied = true;

			numPen--;
		     }
		  }
	       }
	    }

	    if (animalToDie == 2)
	    {
	       cout << "One of your Turtles has died!!\n";

	       for (int i = turtSize; i >= 0; i--)
	       {
		  if (hasDied == false)
		  {
		     if (turtPtr[i] != NULL)
		     {
			delete turtPtr[i];

			turtPtr[i] = NULL;

			hasDied = true;

			numTurt--;
		     }
		  }
	       }
	    }


	    return 0;
	 }

	 //Bonus to Tiger payoff chance - 29%
	 if (eventRoll <= 40 && eventRoll > 11)
	 {
	    cout << "\nHey hey, it's national Tiger Day! ";

	    bonus = rand() % 250 + 251;

	    cout << "You get an extra $" << bonus << " for every tiger in the zoo for today!\n";

	    return bonus;
	 }

	 //baby animal is born chance - 29%
	 if (eventRoll <= 69 && eventRoll > 40)
	 {
	    bool tigerViable = false;

	    bool penguinViable = false;

	    bool turtleViable = false;

	    int babyType = 0;

	    //check each animal array to see if there are any animals with age above or equal to 3
	    for (int i = 0; i < numTig; i++)
	    {
	       if (tigPtr[i]->getAge() >= 3)
	       {
		  tigerViable = true;
	       }
	    }

	    for (int i = 0; i < numPen; i++)
	    {
	       if (penPtr[i]->getAge() >= 3)
	       {
		  penguinViable = true;
	       }
	    }

	    for (int i = 0; i < numTurt; i++)
	    {
	       if (turtPtr[i]->getAge() >= 3)
	       {
		  turtleViable = true;
	       }
	    }

	    bool canHaveBabies = false;

	    int count = 0;

	    //randomly choose the type of animal to have babies, check to see if there are any adults that
	    //can have babies and choose another type if there are not

	    while (canHaveBabies == false)
	    {
	       babyType = rand() % 3;

	       if (babyType == 0)
	       {
		  canHaveBabies = tigerViable;
	       }

	       else if (babyType == 1)
	       {
		  canHaveBabies = penguinViable;
	       }

	       else if (babyType == 2)
	       {
		  canHaveBabies = turtleViable;
	       }

	       //let the random number generator randomly check all three types, if no types can have babies,
	       //exit the while loop and let the next if statement return 0
	       if (count >= 20)
	       {
		  canHaveBabies = true;
	       }

	       else
	       {
		  count++;
	       }
	    }

	    if (count >= 20)
	    {
	       cout << "\nThe day passes as usual, nothing out of the ordinary.\n";

	       return 0;
	    }

	    //if a baby can be born, do so to the randomly selected animal type
	    else if (canHaveBabies == true)
	    {
	       cout << "A baby is born in the zoo!\n";

	       if (babyType == 0)
	       {
		  cout << "Looks like a tiger had a baby!\n";

		  addTigerBabies();

		  return 0;
	       }

	       else if (babyType == 1)
	       {
		  cout << "Looks like a penguin had a litter of 5 babies!\n";

		  addPenguinBabies();

		  return 0;
	       }

	       if (babyType == 2)
	       {
		  cout << "Looks like a Turtle had a litter of 10 babies!\n";

		  addTurtleBabies();

		  return 0;
	       }
	    }
	 }

	 //chance that nothing happens - 30%
	 if (eventRoll <= 99 && eventRoll > 69)
	 {
	    cout << "\nHmm, not much happened today. At least the animals are still happy!\n";

	    return 0;
	 }

	 break;
      }
   }

   return 0;
}

/*************************************************************
 * * calculateProfit(int bonusTigerPay)
 * * full description in Zoo.hpp
*************************************************************/
int Zoo::calculateProfit(int bonusTigerPay)
{
   int profit = 0;

   //iterate through all the animals in each array, calling
   //the getPayoff function to calculate the amount each animal
   //produces, adding the bonusTigerPay amount to the payout
   //of each tiger
   for (int i = 0; i < numTig; i++)
   {
      profit += tigPtr[i]->getPayoff() + bonusTigerPay;
   }

   for (int i = 0; i < numPen; i++)
   {
      profit += penPtr[i]->getPayoff();
   }

   for (int i = 0; i < numTurt; i++)
   {
      profit += turtPtr[i]->getPayoff();
   }

   return profit;
}

/************************************************************
 * * play()
 * * full description in Zoo.hpp
************************************************************/
bool Zoo::play()
{
   int feedType = 0;							//1 = cheap, 2 = normal, 3 = expensive

   int buyAnimal = 0;

   int bonusTigerPay = 0;

   bool keepPlaying = true;

   std::string userInput = "";

   keepPlaying = setUp();						//setUp returns false if the user quits

   //contains the day-loop cycle, all animals are aged up and must have their costs be payed,
   //followed by a random event, calculation of profit, and the user's choice to keep playing
   //or quit
   while (keepPlaying)
   {
      cout << "\n\nHere are the ages of your animals:\n";

      //at the start of the day, increase all animal ages by one
      if (numTig > 0)
      {
         for (int i = 0; i < numTig; i++)
         {
	    tigPtr[i]->ageUp();

	    cout << "Tiger " << i + 1 << "'s age: ";

	    cout << tigPtr[i]->getAge();

	    cout << endl;
         }
      }

      //increment penguin age
      if (numPen > 0)
      {
         for (int i = 0; i < numPen; i++)
         {
	    penPtr[i]->ageUp();

	    cout << "Penguin " << i + 1 << "'s age: ";

	    cout << penPtr[i]->getAge();

	    cout << endl;

         }
      }

      //increment turtle age
      if (numTurt > 0)
      {
         for (int i = 0; i < numTurt; i++)
         {
	    turtPtr[i]->ageUp();

	    cout << "Turtle " << i + 1 << "'s age: ";

	    cout << turtPtr[i]->getAge();

	    cout << endl;
         }
      }

      cout << "\n\nZOO TYCOON - NEW DAY\n\n";
      cout << "Tigers: " << numTig << endl;
      cout << "Penguins: " << numPen << endl;
      cout << "Turtles: " << numTurt << endl;
      cout << "Funds: $" << money << endl;

      feedType = payFood();

      //print game over if user lost all money paying for feed
      if (money <= 0)
      {
	 cout << "\n\nZOO TYCOON - GAME OVER\n";
	 cout << "It looks like you ran out of money trying to feed your animals. Sorry, I'll have to close your zoo down.\n";

	 return false;
      }

      bonusTigerPay = randomEvent(feedType);

      money += calculateProfit(bonusTigerPay);					//add profit to total money

      cout << "\n\nZOO TYCOON - DAILY PROFITS\n\n";

      cout << "You made $" << calculateProfit(bonusTigerPay) << " today, bringing your total money in the bank up to\n";
      cout << "$" << money << ". Do you want to buy an adult animal before the day ends?\n";

      //loop asking user to choose to buy an animal or not   
      do
      {
	 cout << "1. Buy one adult animal of my choice\n2. Don't buy an adult animal\n";
	 cout << "Your money: $" << money << endl;

	 getline(cin, userInput);

	 if (userInput != "1" && userInput != "2")
	 {
	    cout << "\nError: enter 1 to buy an animal or 2 to not.\n";
	 }
      } while (userInput != "1" && userInput != "2");

      //if the user chooses to buy an animal, prompt them to choose what type and then
      //add one of that animal to the appropriate array and subtract their cost from the user bank
      if (userInput == "1")
      {
	 cout << "\nAlright, what type of animal do you want to buy?\n";

	 do
	 {
	    cout << "1. Tiger - $10,000\n2. Penguin - $1,000\n3. Turtle - $100\n";

	    getline(cin, userInput);

	    if (userInput != "1" && userInput != "2" && userInput != "3")
	    {
	       cout << "Error: enter 1 for a tiger, 2 for a penguin, or 3 for a turtle.\n";
	    }
	 } while (userInput != "1" && userInput != "2" && userInput != "3");

	 buyAnimal = stoi(userInput);

	 //user buys a tiger
	 if (buyAnimal == 1)
	 {
	    addTigerAdult();

	    money -= 10000;
	 }

	 //user buys a penguin
	 else if (buyAnimal == 2)
	 {
	    addPenguinAdult();

	    money -= 1000;
	 }

	 //user buys a turtle
	 else if (buyAnimal == 3)
	 {
	    addTurtleAdult();

	    money -= 100;
	 }
      }

      //if the user has no money left, print a game over message
      if (money <= 0)
      {
	 cout << "Looks like your broke, I'll be taking the keys to the zoo now. Goodbye!\n";
	 cout << "\nGAME OVER\n\n";

	 return false;
      }

      cout << "Here are your animals: " << numTig << " tigers, " << numPen << " penguins, and " << numTurt << " turtles.\n";

      cout << "\n\nZOO TYCOON - END OF DAY " << days;

      cout << "\n\nAnother successful(?) day at the zoo! You have $" << money << " in your bank, way to go!";

      cout << "As for your magnificent animal collection, here are the current counts.\n";
      cout << "Tigers: " << numTig << endl;
      cout << "Penguins: " << numPen << endl;
      cout << "Turtles: " << numTurt << endl;
      cout << "Funds: $" << money << endl;

      days++;

      cout << "\nDo you want to keep playing or quit while your ahead?\n";

      //ask the user if they want to play for another day or quit, return false if they quit
      do
      {
	 cout << "1. Keep playing\n2. Quit\n";

	 getline(cin, userInput);

	 if (userInput != "1" && userInput != "2")
	 {
	    cout << "Error: enter 1 to play another day or 2 to quit\n";
	 }
      } while (userInput != "1" && userInput != "2");

      if (userInput == "2")
      {
	 keepPlaying = false;

	 return false;
      }
   }

   cout << "Thank you for playing Zoo Tycoon! Now exiting the program...\n";

   return false;
}
