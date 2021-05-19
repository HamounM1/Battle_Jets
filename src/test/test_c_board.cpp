#include <iostream>
#include "../class/c_board.h"

int main()
{
	{
		c_board board(10, 10);
		for(int x = 0; x < board.getDimX(); x++)
		{
			for(int y = 0; y < board.getDimY(); y++)
			{
				std::cout << board.getTile(x, y) << " ";
			}

			std::cout << std::endl;
		}
	}
}
