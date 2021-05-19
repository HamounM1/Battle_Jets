#include "game.h"

void drawBoard()
{
	for(int row = 0; row < currentGameBoard.getDimRw; row++)
	{
		for(int col = 0; col < currentGameBoard.getDimCl; col++)
		{
			if(currentGameBoard.getTile(row, col) == TILE_PILOT_P)
			{
				std::cout << "<P>";
			}
			else if(currentGameBoard.getTile(row, col) == TILE_PILOT_E)
			{
				std::cout << "<E>";
			}
			else if(currentGameBoard.getTile(row, col) == TILE_EMPTY)
			{
				std::cout << "   ";
			}
			else
			{
				std::cout << "<\>";
			}
		}

		std::cout << std::endl;
	}
}

void gameInit()
{
	for(int row = 0; row < currentGameBoard.getDimRw; row++)
	{
		for(int col = 0; col < currentGameBoard.getDimCl; col++)
		{
			currentGameBoard.setTile(TILE_EMPTY, row, col);
		}
	}

	//POSITIONING THE PLAYER AND ENEMY IN THIS WAY IS NOT PERMANENT
	//POSITIONING WILL BE DONE VIA THE PILOT CLASS!
	currentGameBoard.setTile(TILE_PILOT_P, 5, 1);
	currentGameBoard.setTile(TILE_PILOT_E, 5, 9);
}

void gameStateUpdate()
{
	std::cout << "Player options will be displayed";
	std::cin >> gameInputPlayer;
	std::cout << "Game will do that option" << std::endl;
}
