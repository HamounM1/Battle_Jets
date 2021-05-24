#include "game.h"

c_board* boardTarget;

c_pilot pilotPlayer;
c_pilot pilotEnemy;

bool stateInit(c_board* target)
{
	boardTarget = target;
	boardInit();

	pilotPlayer.setType(TILE_PILOT_P);
	pilotPosition(&pilotPlayer, 5, 0);

	pilotEnemy.setType(TILE_PILOT_E);
	pilotPosition(&pilotEnemy, 5, 9);

	boardUpdate();
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
	std::cout << "Ascend [W]:\nDescend [S]:\n Primary Attack [1]:\nSecondary Attack [2]:\nAction: ";
	std::cin >> option;

	if(option == 'W' || option == 'w')
	{
		return ACTION_ASCEND;
	}
	else if(option == 'S' || option == 's')
	{
		return ACTION_DESCEND;
	}
	else if(option == '1')
	{
		return ACTION_ATTACK;
	}
	else if(option == '2')
	{
		return ACTION_ATTACKSEC;
	}
	else
	{
		return ACTION_NOACTION;
	}
}

int compGenActionCode()
{
	//HAMOUN CODE HERE
	//MAKE SURE TO USE NEW ACTIONS CODES
	//ENEMY_ACTION_XXXXX
	return ACTION_NOACTION;	//For now return no action
}

void pilotOffset(c_pilot* pilotTarget, int offsetRw, int offsetCl)
{
	boardTarget->setTile(TILE_EMPTY, pilotTarget->getRw(), pilotTarget->getCl());
	pilotTarget->setPosition(pilotTarget->getRw() + offsetRw, pilotTarget->getCl() + offsetCl);

	boardTarget->setTile(pilotTarget->getType(), pilotTarget->getRw(), pilotTarget->getCl());
}

void pilotPosition(c_pilot* pilotTarget, int posRw, int posCl)
{
	boardTarget->setTile(TILE_EMPTY, pilotTarget->getRw(), pilotTarget->getCl());
	pilotTarget->setPosition(posRw, posCl);

	boardTarget->setTile(pilotTarget->getType(), pilotTarget->getRw(), pilotTarget->getCl());
}

void perfAction(int code, c_pilot* pilotTarget)
{
	switch(code)
	{
	 case ACTION_NOACTION:
		break;

	 case ACTION_ATTACK:
		std::cout << "Attack" << std:: endl;
		//TODO code for attacking
		break;

	 case ACTION_ATTACKSEC:
		std::cout << "Attack Sec" << std::endl;
		break;

	 case ACTION_ASCEND:
		pilotOffset(pilotTarget, -1, 0);
		break;

	 case ACTION_DESCEND:
		pilotOffset(pilotTarget, 1, 0);
		break;
	}
}

void stateUpdate()
{

	pilotOffset(&pilotPlayer, 0, 1);
	pilotOffset(&pilotEnemy, 0, -1);

	//Generate the action code of the user and the enemy
	int userActionCode = userGenActionCode();
	int compActionCode = compGenActionCode();

	//Perform said actions
	perfAction(userActionCode, &pilotPlayer);
	perfAction(compActionCode, &pilotEnemy);

	//Show those actions on an updated board
	boardUpdate();
}
