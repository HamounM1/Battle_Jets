#include "c_pilot.h"

c_pilot::c_pilot()
{
    pAirc = 0;

    mTileType = 0;
    mPosX = 0;
    mPosY = 0;
}

c_pilot::c_pilot(c_airc* target, int type)
{
    pAirc = target;

    mTileType = type;
    mPosX = 0;
    mPosY = 0;
}

void c_pilot::setType(int type)
{
    mTileType = type;
}

void c_pilot::setPosition(int posRw, int posCl)
{
    mPosX = posCl;
    mPosY = posRw;
}

int c_pilot::getType()
{
    return mTileType;
}

int c_pilot::getRw()
{
    return mPosY;
}

int c_pilot::getCl()
{
    return mPosX;
}