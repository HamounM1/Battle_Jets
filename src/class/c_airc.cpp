#include "c_airc.h"

void c_airc::setHealthOffset(float offset)
{
    mHealth = mHealth - offset;
}

float c_airc::getHealth()
{
    return mHealth;
}

float c_airc::getDamage()
{
    return mWeap * mWeapNum;
}

float c_airc::getDamageSec()
{
    return mWeapSec * mWeapNum;
}

float c_airc::getManeuverability()
{
    return mVelocityMax * mClimbRate;
}


supermarine_spitfire::supermarine_spitfire()
{
    mHealth = 70 ;

    mVelocityMax = 320.0;
    mClimbRate = 13;

    mWeap = 7.69f;
    mWeapNum = 8;

    mWeapSec = 0.0;
    mWeapSecNum = 0;
}


hawker_typhoon::hawker_typhoon()
{
    mHealth = 70;

    mVelocityMax = 358.0;
    mClimbRate = 13.9f;

    mWeap = 20;
    mWeapNum = 4;

    mWeapSec = 00.0;
    mWeapSecNum = 0;
}


westland_whirlwind::westland_whirlwind()
{
    mHealth = 70;

    mVelocityMax = 310.0;
    mClimbRate = 8.2f;

    mWeap = 20.0;
    mWeapNum = 4;

    mWeapSec = 00.0;
    mWeapSecNum = 0;
}


junker_ju288::junker_ju288()
{
    mHealth = 70;

    mVelocityMax = 354.0;
    mClimbRate = 8.2f;

    mWeap = 13.0;
    mWeapNum = 4;

    mWeapSec = 15.0;
    mWeapSecNum = 1;
}


arado_ar240:: arado_ar240()
{
    mHealth = 70;

    mVelocityMax = 334.0;
    mClimbRate = 9.1f;

    mWeap = 7.92f;
    mWeapNum = 2;

    mWeapSec = 00.0;
    mWeapSecNum = 0;
}


fockerWulf_fw190::fockerWulf_fw190()
{
    mHealth = 70;

    mVelocityMax = 352.0;
    mClimbRate = 15.0;

    mWeap = 13.0;
    mWeapNum = 2;

    mWeapSec = 20.0;
    mWeapSecNum = 4;
}

