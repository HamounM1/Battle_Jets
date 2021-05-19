#include "game.h"

void drawBoard(c_board c_boardCurrent)
{
    for(int x = 0; rw < 15; rw++)
    {
        for(int y = 0; cl < 15; cl++)
        {
            std::cout << c_boardCurrent.getTile(rw, cl);
        }
        std::cout << std::endl;
    }
}