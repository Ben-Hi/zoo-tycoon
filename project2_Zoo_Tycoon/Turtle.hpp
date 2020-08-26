/**********************************************************************************************************
 * * Program Name: 	Turtle.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Declaration of the Turtle class, inherits from Animal and has a function that
 * * 			returns the cost of feeding a single turtle.
**********************************************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal
{ public:

   Turtle(int);

   Turtle();

   ~Turtle();

   /***************************************
    * * getFoodCost()
    * * returns an integer describing the
    * * cost of feeding a single
    * * turtle.
   ***************************************/
   virtual int getFoodCost();

   virtual int getPayoff();
};

#endif
