#include "c_pilot.h"

c_pilot::c_pilot()
{
    pAirc = 0;

    mTileType = 0;
    mPosX = 0;
    mPosY = 0;
}
void c_pilot::setAirc(c_airc* target)
{
    pAirc = target;
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

c_airc* c_pilot::getAirc()
{
    return pAirc;
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