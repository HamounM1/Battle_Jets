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

test_aircraft_type1::test_aircraft_type1()
{
    mHealth = 70;

    mVelocityMax = 150.0;
    mClimbRate = 11.0;

    mWeap = 12.7f;
    mWeapNum = 4;

    mWeapSec = 20.0;
    mWeapSecNum = 0;
}

test_aircraft_type2::test_aircraft_type2()
{
    mHealth = 75;

    mVelocityMax = 200.0;
    mClimbRate = 12.2;

    mWeap = 12.7f;
    mWeapNum = 4;

    mWeapSec = 20.0;
    mWeapSecNum = 2;
}