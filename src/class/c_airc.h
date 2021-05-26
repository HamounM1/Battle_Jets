#ifndef C_AIRC_H
#define C_AIRC_H

#define AIRC_SUPERMARINE_SPITFIRE 0xC0
#define AIRC_HAWKER_TYPHOON 0xC1
#define AIRC_WESTLAND_WHIRLWIND 0xC2
#define AIRC_JUNKER_JU288 0xC3
#define AIRC_ARADO_AR240 0xC4
#define AIRC_FOCKERWULF_FW190 0xC5

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

        //The same as before but for any secondary weapons
        //If there are no secondary weapons just leave both values as zero
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
struct supermarine_spitfire : public c_airc
{
        supermarine_spitfire();
};


struct hawker_typhoon : public c_airc
{
        hawker_typhoon();
};


struct westland_whirlwind : public c_airc
{
        westland_whirlwind();
};


struct junker_ju288 : public c_airc
{
        junker_ju288();
};


struct arado_ar240 : public c_airc
{
        arado_ar240();
};


struct fockerWulf_fw190 : public c_airc
{
        fockerWulf_fw190();
};

//For Tharane! You can now create your various aircraft types usin the stats you gathered
//Follow the template i've given here with the test_aircraft_type
//You only need to declare a struct (same as class but by default public) with a default constructor
//THEN go into c_airc.cpp and then define the relevent stats in its default constructor and voila, new aircraft type!
//The stats you need to define are above in the base class c_airc under the 'protected:'' specificer
#endif
