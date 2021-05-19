#include "c_board.h"

c_board::c_board()
{
	//Default constructor assigns all to null/zero
	mDimX = 0;
	mDimY = 0;

	mBoard = nullptr;
}

c_board::c_board(int dimX, int dimY)
{
	//Take the parameters and assign them to the private class variables
	mDimY = dimY;
	mDimX = dimX;

	mBoard = new int[dimX*dimY];	//Solution for allocating dynamic two dimensional memory from stackoverflow (Kevin Loney)
					//This method allocates a single block of memory which is accessed by mBoard[y*dimY + x]
}

c_board::~c_board()
{
	//Free the memory allocated on the heap to store the board
	//Assign the pointer to nullptr
	delete[] mBoard;
	mBoard = nullptr;
}

void c_board::setTile(int nTileValue, int posX, int posY)
{
	//Sets the desired board position (posX, posY) to nTileValue
	mBoard[(posY*mDimY) + posX] = nTileValue;
}

int c_board::getTile(int posX, int posY)
{
	//returns desired board position (posX, posY)
	return mBoard[(posY*mDimY) + posX];
}

int c_board::getDimX()
{
	//return the size of the X dimension which is assigned to mDimX by the constructor
	return mDimX;
}

int c_board::getDimY()
{
	//return the size of the Y dimension which is assigned to mDimY by the constructor
	return mDimY;
}
