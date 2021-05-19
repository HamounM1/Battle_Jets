#ifndef GAME_H
#define GAME_H

//Global definitions

//Tile definitions
//Defintions relating to the tiles will be defined by hexadecimal values in the form 0xF followed by a number from 0 - F

#define TILE_EMPTY 0xF0		//An empty tile can be identified if the value 0xF0 is in a board tile
#define TILE_PILOT_P 0xFA	//A tile with a player can be identified by the value 0xFA in a board tile
#define TILE_PILOT_E 0xFB	//A tile with an enemy cna be identified by the value 0xFB in a board tile

#define PLAYER_ACTION_NOACTION 0xA0
#define PLAYER_ACTION_ATTACK 0xAA
#define PLAYER_ACTION_DEFEND 0xAD

//Variables
bool gameStateActive;
c_board currentGameBoard(10, 10);

int gameInputPlayer;
//Functions
void drawBoard();

void gameInit();
void gameStateUpdate();
#endif
