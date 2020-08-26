/**********************************************************************************************************
 * * Program Name: 	Penguin.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Declaration of the Penguin class, inherits from Animal, has a function that
 * * 			returns its food cost
***********************************************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal
{ public:

   Penguin(int);

   Penguin(); 				//initialize all penguins to cost = 1,000
   					//and numberOfBabies = 5
   ~Penguin();

   /*********************************
    * * getFoodCost()
    * * returns an integer 
    * * describing the cost of 
    * * feeding a single penguin
   *********************************/
   virtual int getFoodCost();

   virtual int getPayoff();
};

#endif
