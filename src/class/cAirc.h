#ifndef CAIRC_H
#define CAIRC_H

class CAirc
{
	//Base Attributes
	char* mAircName;
	char* mAircModel;
	char* mManufacturer;
	char* mDescription;
	//Combat Attributes
	float mAtkVal;
	float mDefVal;

	//Maneuverability
	float mAgility;

	float mClimbRate;
	float mVelocMax;
	float mCeilMax;

	//Attack
	float* mArmament;

	//Defense
	float* mArmour;
 public:
	float getAtkVal();
	float getDefVal();
	float getManVal();
};

//Testing with inheritance for a new aircraft type
class CAirc_TESTTYPE : private CAirc
{
	mAircName
};
#endif
