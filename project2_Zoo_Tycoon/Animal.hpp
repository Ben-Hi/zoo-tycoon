/**********************************************************************************************************
 * * Program Name: 	Animal.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		26 October 2019
 * * Description: 	Declaration of the abstract Animal class, publicly inherited by Tiger, Penguin,
 * * 			Turtle, and Custom. Data members describe the animal's age (adult >= 3 days), cost
 * * 			to purchase, number of babies produced in a litter, the base food cost, and the 
 * * 			payoff amount. Public methods are getters and setters, including an ageUp() 
 * * 			function that increments the age member by 1.
***********************************************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define FEED_COST 100

class Animal
{ protected:

   int age,
       cost,
       numberOfBabies,
       payoff;

   int baseFoodCost = FEED_COST;

  public:

   virtual ~Animal();

   virtual void setAge(int),
	        setCost(int),
	        setPayoff(int);

   virtual int getAge(),
	       getCost(),
	       getFoodCost(),
	       getNumberOfBabies(),
	       getPayoff();

   virtual void ageUp();
};

#endif
