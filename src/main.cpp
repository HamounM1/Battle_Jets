//C and C++ Standard libraries
#include <iostream>
#include <cstdlib>
//Local
#include "game.h"

bool stateActive = false;
c_board mainBoard(10, 20);

int main()
{
	std::system("clear");

	std::cout << "Welcome to the game!" << std::endl;
	std::cout << "The premise of this game is simple, chose two aircraft for you and the AI opponent." << std::endl;
	std::cout << "Your aircraft is represented by a <P> while the enemy aircraft is represented by a <E>. " << std::endl;
	std::cout << std::endl;
	std::cout << "In each round you will choose a course of action... be wary, you can lose very quickly!" << std::endl;
	std::cout << "Each round, you are presented with four actions... Primary/Secondary attack, Ascend or Descend." << std::endl;
	std::cout << std::endl;
	std::cout << "Damage from attacks are affected by the difference in distance between you and the enemy." << std::endl;
	std::cout << std::endl;
	std::cout << "Ascending or descending allows you to avoid more damage." << std::endl;
	std::cout << "Primary Attack uses your machine guns and secondary attack uses your cannons." << std::endl;
	std::cout << std::endl;
	std::cout << "Ensure to keep an eye on your health! Goodluck." << std::endl;


	std::cout << "\n\n\nAre you ready to begin? Yes [Y] | No [N] ";

	char choice;
	std::cin >> choice;

	if(choice == 'Y' || choice == 'y')
	{
		stateActive = stateInit(&mainBoard);
		while(stateActive == true)
		{
			stateUpdate();
		}
	}

	return 0;
}
