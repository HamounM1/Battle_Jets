#ifndef C_AIRC_H
#define C_AIRC_H

class c_airc
{
 protected:
        //Characteristics
        float mHealth;

        //The product of these two values is equal to the maneuverabiliy
        float mVelocityMax;
        float mClimbRate;

        //The product of these two values is equal to the damage
        float mWeap;    //Ammunition size (in mm)
        int mWeapNum;   //Number of weapons

        float mWeapSec;         //Ammunition size (in mm)
        int mWeapSecNum;        //Number of secondary weapons
 public:
        //Functions to access these values
        void setHealthOffset(float offset);

        float getHealth();
        float getDamage();
        float getDamageSec();
        float getManeuverability();
};

//These are different aircraft with different stats
struct test_aircraft_type1 : public c_airc
{
        test_aircraft_type1();
};

struct test_aircraft_type2 : public c_airc
{
        test_aircraft_type2();
};

//For Tharane! You can now create your various aircraft types usin the stats you gathered
//Follow the template i've given here with the test_aircraft_type
//You only need to declare a struct (same as class but by default public) with a default constructor
//THEN go into c_airc.cpp and then define the relevent stats in its default constructor and voila, new aircraft type!

#endif