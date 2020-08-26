/**********************************************************************************************************
 * * Program Name: 	Tiger.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Definition of the Tiger class, description found within Tiger.hpp 
***********************************************************************************************************/

#include "Animal.hpp"
#include "Tiger.hpp"
#include <iostream>

#define TIGER_COST 10000

Tiger::Tiger(int ageIn)
{
   const int TIGER_BABIES = 1;

   cost = TIGER_COST;

   numberOfBabies = TIGER_BABIES;

   age = ageIn;				//allows for the initialization of an age
}

Tiger::Tiger()
{
   const int TIGER_BABIES = 1;

   cost = TIGER_COST;

   numberOfBabies = TIGER_BABIES;
}

Tiger::~Tiger()
{
   std::cout << "Destroying Tiger...";
}

int Tiger::getPayoff()
{
   return cost / 5;
}

int Tiger::getFoodCost()
{
   return baseFoodCost * 5;
}
