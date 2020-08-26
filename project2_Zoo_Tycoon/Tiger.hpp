/**********************************************************************************************************
 * * Program Name: 	Tiger.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Definition of the Tiger class, inherits from Animal, member functions are used
 * * 			to calculate the cost of it's food and provide a message when a tiger dies. 
***********************************************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{ public:

   Tiger(int ageIn);

   Tiger(); 				//initialize all tigers with cost = 10,000
   					//and numberOfBabies = 1
   ~Tiger();

   /******************************
    * * getFoodCost()
    * * returns the integer
    * * representing the cost of
    * * feeding a single tiger
   *****************************/
   virtual int getFoodCost();

   /*****************************
    * * getPayoff()
    * * returns an integer
    * * describing the revenue
    * * a single tiger produces.
   *****************************/
   virtual int getPayoff();
};

#endif
