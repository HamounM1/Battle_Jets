#include "c_board.h"

c_board::c_board()
{
    nDimX = 0;
    nDimY = 0;

    mBoard = nullptr;
}

c_board::c_board(int dimX, int dimY)
{
    mDimY = dimY;
    mDimX = dimX;

    mBoard = new int[nDimX][nDimY];
}

void c_board::setTile(int nTileValue, int posX, int posY)
{
    mBoard[posX][posY] = nTitleValue;
}

int getTile(int posX, int posY)
{
    return mBoard[posX][posY];
}