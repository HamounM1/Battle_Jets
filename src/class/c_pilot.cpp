#include "c_pilot.h"

c_pilot::c_pilot()
{
    pAirc = 0;

    mTileType = 0;
    mPosX = 0;
    mPosY = 0;
}

c_pilot::~c_pilot()
{
	delete pAirc;
	pAirc = 0;
}

void c_pilot::setAirc(int target)
{
	switch(target)
	{
	 case AIRC_SUPERMARINE_SPITFIRE:
		pAirc = new supermarine_spitfire;
		break;
	 case AIRC_HAWKER_TYPHOON:
		pAirc = new hawker_typhoon;
		break;

	 case AIRC_WESTLAND_WHIRLWIND:
		pAirc = new westland_whirlwind;
		break;

	case AIRC_JUNKER_JU288:
		pAirc = new junker_ju288;
		break;

	case AIRC_ARADO_AR240:
		pAirc = new arado_ar240;
		break;

	case AIRC_FOCKERWULF_FW190:
		pAirc = new fockerWulf_fw190;
		break;
	}
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
