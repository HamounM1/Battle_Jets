#include <iostream>
#include "../class/c_board.h"

#define TILE_EMPTY 0
#define TILE_PILOT_PLAYER 1
#define TILE_PILOT_ENEMY 2

int main()
{
	//Test displaying a board, changing values and then displaying the updated version
	std::cout << "\nDisplaying a board, changing it and then displaying an updated board" << std::endl;
	{
		c_board board(10, 10);
		for(int rw = 0; rw < board.getDimRw(); rw++)
		{
			for(int cl = 0; cl < board.getDimCl(); cl++)
			{
				std::cout << board.getTile(rw, cl) << " ";
			}

			std::cout << std::endl;
		}

		std::cout << "\nUpdated" << std::endl;
		board.setTile(1, 0, 0);
		board.setTile(2, 2, 0);
		board.setTile(3, 0, 3);

		for(int rw = 0; rw < board.getDimRw(); rw++)
		{
			for(int cl = 0; cl < board.getDimCl(); cl++)
			{
				std::cout << board.getTile(rw, cl) << " ";
			}

			std::cout << std::endl;
		}
	}

	//Test displaying a Player or Enemy indicator based on the value at a tle (VALUES FROM MACROS)

	std::cout << "\nPlayer and Enemy indicators" << std::endl;
	{
		c_board board(10, 30);
		board.setTile(TILE_PILOT_PLAYER, 5, 1);
		board.setTile(TILE_PILOT_ENEMY, 5, 29);

		for(int rw = 0; rw < board.getDimRw(); rw++)
		{
			for(int cl = 0; cl < board.getDimCl(); cl++)
			{
				if(board.getTile(rw, cl) == TILE_PILOT_ENEMY)
				{
					std::cout << "<E";
				}
				else if(board.getTile(rw, cl) == TILE_PILOT_PLAYER)
				{
					std::cout << "P>";
				}
				else
				{
					std::cout << " ";
				}
			}

			std::cout << std::endl;
		}

	}
}
