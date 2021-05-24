#ifndef GAME_H
#define GAME_H

/** GAME HEADER FILE
 *
 * Contains declarations for functions, variables and macros which are defined in game.cpp
 *
 * The game header and source file (game.h, game.cpp) are where the elements of the gameplay
 * and user interface are defined.
 *	-initialising
 *	-displaying info
 *	-taking input from user
 *	-updating the state
 **/

//C/C++ Standard Libraries
#include <iostream>

//Local includes
#include "class/c_board.h"
#include "class/c_pilot.h"
#include "class/c_airc.h"

//Tile codes
//Each code is prefixed with a 0xF followed by the tile code
//This allows the game to support as many as 16 tiles (0 to F)

#define TILE_EMPTY 0x0		//An empty tile
#define TILE_PILOT_P 0xA	//Tile code for a player's pilot
#define TILE_PILOT_E 0xB	//Tile code for an enemy pilot

//Action codes


#define ACTION_NOACTION 0xA0	//An action code assigned when no action is taken
#define ACTION_EXIT 0xAE       //Code to exit the game

#define ACTION_ATTACK 0xA1	    //An action code for primary attack
#define ACTION_ATTACKSEC 0xA2   //An action code for secondary attack
#define ACTION_ASCEND 0xAA		//Action for up
#define ACTION_DESCEND 0xAD		//Action for down


//Variables
bool stateInit(c_board* target);	//Creates the initial state, returns true on successful initialisation
//WIP
//c_pilot pilotPlayer;
//c_pilot pilotEnemy;

void boardInit();	//Creates the initial board state (sets all tiles to TILE_EMPTY)
void boardUpdate();	//Updates/draws/prints the current state of the board to STDOUT

int userGenActionCode();	//Returns an action code based on user input from STDIN
int compGenActionCode();	//Hamoun will program this...

void pilotOffset(c_pilot* pilotTarget, int offsetRw, int offsetCl);
void pilotPosition(c_pilot* pilotTarget, int posRw, int posCl);

void perfAction(int code, c_pilot* pilotTarget);	//Programs an action with target (an instance of c_pilot) based on the code

void stateUpdate();	//Contains instructions to achieve a game state, run multiple times on each interation of the game loop
#endif
