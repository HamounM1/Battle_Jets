#include "game.h"

c_board* boardTarget;

bool stateInit(c_board* target)
{
	boardTarget = target;

	boardInit();
	//TODO
	//Set the position of the player
	//Set the position of the enemy
	return true;
}

void boardInit()
{
	for(int row = 0; row < boardTarget->getDimRw(); row++)
	{
		for(int col = 0; col < boardTarget->getDimCl(); col++)
		{
			boardTarget->setTile(TILE_EMPTY, row, col);
		}
	}
}

void boardUpdate()
{
	for(int row = 0; row < boardTarget->getDimRw(); row++)
	{
		for(int col = 0; col < boardTarget->getDimCl(); col++)
		{
			if(boardTarget->getTile(row, col) == TILE_PILOT_P)
			{
				std::cout << "<P>";
			}
			else if(boardTarget->getTile(row, col) == TILE_PILOT_E)
			{
				std::cout << "<E>";
			}
			else if(boardTarget->getTile(row, col) == TILE_EMPTY)
			{
				std::cout << "   ";
			}
			else
			{
				std::cout << "TILE_ERROR";
			}
		}

		std::cout << std::endl;
	}
}

int userGenActionCode()
{
	char option;
	std::cout << "Ascend [W]:\nDescend [S]:\n ATTACK [A]\n\nAction: ";
	std::cin >> option;

	if(option == 'W' || option == 'w')
	{
		return PLAYER_ACTION_ASCEND;
	}
	else if(option == 'S' || option == 's')
	{
		return PLAYER_ACTION_DESCEND;
	}
	else if(option == 'A' || option == 'a')
	{
		return PLAYER_ACTION_ATTACK;
	}
	else
	{
		return PLAYER_ACTION_NOACTION;
	}
}

int compGenActionCode()
{
	//TODO Hamoun's AI code goes here
	return PLAYER_ACTION_NOACTION;	//For now return no action
}

void perfAction(int code)
{
	switch(code)
	{
	 case PLAYER_ACTION_ASCEND:
		std::cout << "Ascend" << std::endl;
		//TODO code for ascending
		break;

	 case PLAYER_ACTION_DSCEND:
		std::cout << "Descend" << std::endl;
		//TODO code for descending
		break;

	 case PLAYER_ACTION_ATTACK:
		std::cout << "Attack" << std:: endl;
		//TODO code for attacking
		break;

	 case PLAYER_ACTION_NOACTION:
		std::cout << "No action" << std::endl;
		break;
	}
}

void stateUpdate()
{
	//Generate the action code of the user and the enemy
	int userActionCode = userGenActionCode();
	int compActionCode = compGenActionCode();

	//Perform said actions
	perfAction(userActionCode);
	perfAction(compActionCode);

	//Show those actions on an updated board
	boardUpdate();
}
