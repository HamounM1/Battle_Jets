#include "game.h"
//Global Variables
c_board* boardTarget;

c_pilot pilotPlayer;
c_pilot pilotEnemy;

//Aircraft Selection

bool stateInit(c_board* target)
{
	std::system("clear");

	boardTarget = target;
	boardInit();

	//A bad fix for something
	pilotPlayer.setType(TILE_PILOT_P);
	pilotEnemy.setType(TILE_PILOT_E);

	//Promt the user to chose which aircraft they would like to use
	int choicePlayer;
	int playerAirc;
	std::cout << "Player's Aircraft: " << std::endl;
	std::cout << "\nUnited Kingdom\n-Supermarine Spitfire [1]\n-Hawker Typhoon [2]\n-Westland Whatever [3]" << std::endl;
	std::cout << "\nGermany\n-Junker Ju288 [4]\n-Arado Ar240 [5]\n-Focke-Wulf Fw190 [6]" << std::endl;
	std::cin >> choicePlayer;

	switch(choicePlayer)
	{
	 case 1:
		playerAirc = AIRC_SUPERMARINE_SPITFIRE;
		break;
	 case 2:
		playerAirc = AIRC_HAWKER_TYPHOON;
		break;
	 case 3:
		playerAirc = AIRC_WESTLAND_WHIRLWIND;
		break;
	 case 4:
		playerAirc = AIRC_JUNKER_JU288;
		break;
	 case 5:
		playerAirc = AIRC_ARADO_AR240;
		break;
	 case 6:
		playerAirc = AIRC_FOCKERWULF_FW190;
		break;
	}

	pilotPlayer.setAirc(playerAirc);

	std::system("clear");

	//Promt the user to choose an opponent
	int choiceEnemy;
	int enemyAirc;
	std::cout << "Opponent's Aircraft: " << std::endl;
	std::cout << "\nUnited Kingdom\n-Supermarine Spitfire [1]\n-Hawker Typhoon [2]\n-Westland Whatever [3]" << std::endl;
	std::cout << "\nGermany\n-Junker Ju288 [4]\n-Arado Ar240 [5]\n-Focke-Wulf Fw190 [6]" << std::endl;
	std::cin >> choiceEnemy;

	switch(choiceEnemy)
	{
	 case 1:
		enemyAirc = AIRC_SUPERMARINE_SPITFIRE;
		break;
	 case 2:
		enemyAirc = AIRC_HAWKER_TYPHOON;
		break;
	 case 3:
		enemyAirc = AIRC_WESTLAND_WHIRLWIND;
		break;
	 case 4:
		enemyAirc = AIRC_JUNKER_JU288;
		break;
	 case 5:
		enemyAirc = AIRC_ARADO_AR240;
		break;
	 case 6:
		enemyAirc = AIRC_FOCKERWULF_FW190;
		break;
	}

	pilotEnemy.setAirc(enemyAirc);

	//Position the two planes at opposing ends of the board
	pilotPosition(&pilotPlayer, boardTarget->getDimRw() / 2, 0);
	pilotPosition(&pilotEnemy, boardTarget->getDimRw() / 2, boardTarget->getDimCl() - 1);

	std::system("clear");

	boardUpdate();
	std::cout << "Player Health: " << (pilotPlayer.getAirc())->getHealth() << std::endl;
	std::cout << "Enemy Health: " << (pilotEnemy.getAirc())->getHealth() << std::endl;
	std::cout << "------------------------------------" << std::endl;

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
	if((pilotPlayer.getAirc())->getHealth() <= 0)
	{
		return ACTION_DESTROYED;
	}

	char option;
	std::cout << "Primary Attack [1]:\nSecondary Attack [2]:\n\nAscend [W]:\nDescend [S]:\nAction: ";
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
	if((pilotEnemy.getAirc())->getHealth() <= 0)
	{
		return ACTION_DESTROYED;
	}

	srand(time(0));
	int randNum = rand()%100;

	if (pilotEnemy.getRw() > pilotPlayer.getRw())
	{
		if (0 <= randNum && randNum > 70)
		{
			return ACTION_ASCEND;//ascend
		}
		else if (70 <= randNum && randNum < 85)
		{
			return ACTION_DESCEND;//descend
		}
		else if (85 <= randNum && randNum < 100)
		{
			return ACTION_ATTACK;//attack
		}
	}
	else if (pilotEnemy.getRw() < pilotPlayer.getRw())
	{
		if (0 <= randNum && randNum < 70)
		{
			return ACTION_DESCEND;//descend
		}
		else if (70 <= randNum && randNum < 85)
		{
			return ACTION_ASCEND;//ascend
		}
		else if (85 <= randNum && randNum < 100)
		{
			return ACTION_ATTACK;//attack
		}
	}
	else if (pilotEnemy.getRw() == pilotPlayer.getRw())
	{
		if (0 <= randNum && randNum < 50)
		{
			return ACTION_ATTACK;//attack;
		}
		else if( 50 <= randNum && randNum < 70)
		{
			return ACTION_ATTACKSEC;//attack sec
		}
		else if (70 <= randNum && randNum < 85)
		{
			return ACTION_ASCEND;//ascend
		}
		else if (85 <= randNum && randNum < 100)
		{
			return ACTION_DESCEND;//descend
		}
	}
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

	 case ACTION_DESTROYED:
		boardTarget->setTile(TILE_EMPTY, pilotTarget->getRw(), pilotTarget->getCl());
		stateActive = false;
		break;

	 case ACTION_ATTACK:
		if(pilotTarget->getType() == TILE_PILOT_P)
		{
			float calcDamageE = (pilotEnemy.getAirc())->getDamage() / abs(pilotPlayer.getCl() - pilotEnemy.getCl()) * (pilotPlayer.getRw()/pilotPlayer.getRw());
			(pilotEnemy.getAirc())->setHealthOffset(calcDamageE);
			break;
		}

		if(pilotTarget->getType() == TILE_PILOT_E)
		{
			float calcDamageP = (pilotPlayer.getAirc())->getDamage() / abs(pilotPlayer.getCl() - pilotEnemy.getCl()) * (pilotPlayer.getRw()/pilotPlayer.getRw());
			(pilotPlayer.getAirc())->setHealthOffset(calcDamageP);
			break;
		}

	 case ACTION_ATTACKSEC:
		if(pilotTarget->getType() == TILE_PILOT_P)
		{
			(pilotEnemy.getAirc())->setHealthOffset((pilotPlayer.getAirc())->getDamageSec());
			break;
		}

		if(pilotTarget->getType() == TILE_PILOT_E)
		{
			(pilotPlayer.getAirc())->setHealthOffset((pilotEnemy.getAirc())->getDamageSec());
			break;
		}
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
	//Check to see if the player and the enemy have flown past each other
	//If so, then reset their column back to the initial
	if (pilotPlayer.getCl() - pilotEnemy.getCl() >= 1)
	{
		pilotPosition(&pilotEnemy, pilotEnemy.getRw(), boardTarget->getDimCl());
		pilotPosition(&pilotPlayer, pilotPlayer.getRw(), 0);
	}


	//Make the aircraft fly towards each other
	pilotOffset(&pilotPlayer, 0, 1);
	pilotOffset(&pilotEnemy, 0, -1);

	//Generate the action code of the user and the enemy
	int userActionCode = userGenActionCode();
	perfAction(userActionCode, &pilotPlayer);
	boardUpdate();

	std::system("clear");
	int compActionCode = compGenActionCode();
	perfAction(compActionCode, &pilotEnemy);
	boardUpdate();

	std::cout << "Player Health: " << (pilotPlayer.getAirc())->getHealth() << std::endl;
	std::cout << "Enemy Health: " << (pilotEnemy.getAirc())->getHealth() << std::endl;
	std::cout << "------------------------------------" << std::endl;
}
