#ifndef C_PILOT_H
#define C_PILOT_H

#include "c_airc.h"

class c_pilot
{
	int mTileType;
	int mPosX;
	int mPosY;

	c_airc* pAirc;

 public:
	c_pilot();
	~c_pilot();

	void setAirc(int target);
	void setType(int type);
	void setPosition(int posRw, int posCl);

	c_airc* getAirc();
	int getType();
	int getRw();
	int getCl();
};
#endif
