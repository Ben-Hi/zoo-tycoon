/******************************************************************************
 * * Program Name: 	main.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		27 October 2019
 * * Description: 	Creates a Zoo object after seeding RNG and then
 * * 			calls the play() function on the Zoo object. Continues
 * * 			to play game until user chooses to quit
*****************************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
   srand(time(NULL));

   Zoo game;

   bool playGame = true;

   std::cout << "\n\nEXTRA CREDIT IMPLEMENTATIONS\n";

   std::cout << "Hello, please be aware that this program implements the ";
   std::cout << "'Different Feed Types' Extra Credit Option. Enjoy!\n\n";

   //loop until the user chooses to quit the game
   while (playGame == true)
   {
      playGame = game.play();
   }

   return 0;
}
