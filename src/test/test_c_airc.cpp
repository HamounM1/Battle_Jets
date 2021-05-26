#include "../class/c_airc.h"
#include <iostream>

int main()
{
    {
        //Test that the stats can be displayed
        test_aircraft_type1 test;
        std::cout << " " << test.getHealth() << " " << test.getDamage() << " " << test.getDamageSec() << " " << test.getManeuverability() << std::endl;
    }

    {
        //Testing that aircraft can interact with each other
        test_aircraft_type1 enemy;
        test_aircraft_type2 player;

        //Should be default values 70, 75
        std::cout << "Health\n\nEnemy: " << enemy.getHealth() << "\nPlayer: " << player.getHealth() << std::endl;

        player.setHealthOffset(enemy.getDamage());
        enemy.setHealthOffset(player.getDamage());
        //Should be damaged 19.2, 24.2
        std::cout << "Health\n\nEnemy: " << enemy.getHealth() << "\nPlayer: " << player.getHealth() << std::endl;
    }

    return 0;
}