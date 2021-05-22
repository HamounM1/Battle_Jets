//C and C++ Standard libraries
#include <iostream>

//Local
#include "game.h"

bool stateActive = false;
c_board mainBoard(10, 10);

int main()
{
	std::cout << "Welcome to the game!" << std::endl;

	stateActive = stateInit(&mainBoard);
	while(stateActive == true)
	{
		stateUpdate();
	}

	return 0;
}
