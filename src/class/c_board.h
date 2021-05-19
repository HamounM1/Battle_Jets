#ifndef C_BOARD_H
#define C_BOARD_H

/**BOARD CLASS
 * The board class will contain a two-dimensional array represnting positions
 * of the two aircraft.
 * The board is presented such that the rows represent horizontal distance, and
 * the columns represent altitude.
 *
 * Private Members:
 *
 * int mDimX        - X dimensions ^
 * int mDimY        - Y dimensions >
 *
 * int* mBoard      - this points to a dynamic array of size mDimX x mDimY
 *
 * Public Members:
 *
 * c_board();                                       - default constructor (initialises mBoard to 0)
 * c_board(int dimX, int dimY)                      - specifies dimensions in the constructor
 * void setTile(int nTileValue, int posx, int posy) - accesses mBoard[posx][posy] and set's it to nTileValue
 *
 * int getTile(int posX, int posY)                  - returns the value stored in the array element [posX][posY]
 **/

class c_board
{
	int mDimRw;
	int mDimCl;
	int* mBoard;

 public:
	c_board();
	c_board(int dimX, int dimY);

	~c_board();

	void setTile(int nTileValue, int posX, int posY);

	int getTile(int posX, int posY);
	int getDimRw();
	int getDimCl();
};
#endif
