#pragma once

#include <windows.h>
#include <cstdlib>

const int _Width = 60;
const int _Height = 30;

/* Make a Class named Food
   and include the necessary variables and methods.
*/

class Food
{
public:
    void generateFood();
    COORD getSnakePosition();

    COORD position;
};
