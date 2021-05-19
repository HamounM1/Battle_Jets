#include "c_board.h"

c_board::c_board()
{
	//Default constructor assigns all to null/zero
	mDimRw = 0;
	mDimCl = 0;

	mBoard = nullptr;
}

c_board::c_board(int dimX, int dimY)
{
	//Take the parameters and assign them to the private class variables
	mDimRw = dimX;
	mDimCl = dimY;

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
	mBoard[(posX*mDimCl) + posY] = nTileValue;
}

int c_board::getTile(int posX, int posY)
{
	//returns desired board position (posX, posY)
	return mBoard[(posX*mDimCl) + posY];
}

int c_board::getDimRw()
{
	//return the size of the X dimension which is assigned to mDimX by the constructor
	return mDimRw;
}

int c_board::getDimCl()
{
	//return the size of the Y dimension which is assigned to mDimY by the constructor
	return mDimCl;
}
