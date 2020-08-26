/**********************************************************************************************************
 * * Program Name: 	Animal.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Definition of the abstract Animal class, publicly inherited by Tiger, Penguin,
 * * 			Turtle, and Custom. Data members describe the animal's age (adult >= 3 days), cost
 * * 			to purchase, number of babies produced in a litter, the base food cost, and the 
 * * 			payoff amount. Public methods are getters and setters, including an ageUp() 
 * * 			function that increments the age member by 1.
***********************************************************************************************************/

#include "Animal.hpp"
#include <iostream>

/*******************************************
 * * ~Animal()
 * * Virtual destructor prevents undefined
 * * behavior when derived classes are
 * * deleted in Zoo
******************************************/
Animal::~Animal()
{
   std::cout << "Deleting animal...";
}

void Animal::setAge(int inputAge)
{
   age = inputAge;
}

void Animal::setCost(int inputCost)
{
   cost = inputCost;
}

void Animal::setPayoff(int inputPayoff)
{
   payoff = inputPayoff;
}

int Animal::getFoodCost()
{
   return baseFoodCost;
}

int Animal::getAge()
{
   return age;
}

int Animal::getCost()
{
   return cost;
}

int Animal::getNumberOfBabies()
{
   return numberOfBabies;
}

int Animal::getPayoff()
{
   return payoff;
}

/**************************************
 * * ageUp()
 * * trivial function that increments
 * * age by 1
**************************************/
void Animal::ageUp()
{
   age++;
}
