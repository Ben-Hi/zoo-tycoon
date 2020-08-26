/**********************************************************************************************************
 * * Program Name: 	Turtle.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Definition of the Turtle class
**********************************************************************************************************/

#include "Turtle.hpp"
#include <iostream>

#define TURTLE_COST 100

Turtle::Turtle(int inputAge)
{
   const int TURTLE_BABIES = 10;

   cost = TURTLE_COST;

   numberOfBabies = TURTLE_BABIES;

   age = inputAge;
}

Turtle::~Turtle()
{
   std::cout << "Destroying turtle...";
}

Turtle::Turtle()
{
   const int TURTLE_BABIES = 10;

   cost = TURTLE_COST;

   numberOfBabies = TURTLE_BABIES;
}

int Turtle::getPayoff()
{
   return cost / 20;			//turtles are 5% payoff of their cost
}

int Turtle::getFoodCost()
{
   return baseFoodCost / 2;
}
