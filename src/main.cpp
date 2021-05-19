#include "main.h"

int main()
{
	//Promt the user
	std::cout << "Welcome to the game!" << std::endl;

	//Run the game loop
	gameInit();
	while(gameStateActive == true)
	{
		gameStateUpdate();
	}

	return 0;
}
