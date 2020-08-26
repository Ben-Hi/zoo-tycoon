/**********************************************************************************************************
 * * Program Name: 	Penguin.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Definition of the Penguin class, full description found in the Penguin.hpp file
***********************************************************************************************************/

#include "Animal.hpp"
#include "Penguin.hpp"
#include <iostream>

#define PENGUIN_COST 1000

Penguin::Penguin(int inputAge)
{
   const int PENGUIN_BABIES = 5;

   cost = PENGUIN_COST;

   numberOfBabies = PENGUIN_BABIES;

   age = inputAge;
}

Penguin::~Penguin()
{
   std::cout << "Destroying penguin...";
}

Penguin::Penguin()
{
   const int PENGUIN_BABIES = 5;

   cost = PENGUIN_COST;

   numberOfBabies = PENGUIN_BABIES;
}

int Penguin::getPayoff()
{
   return cost / 10;
}

int Penguin::getFoodCost()
{
   return baseFoodCost;
}
