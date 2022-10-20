#include "Food.h"

/*
  make a getter method to get the
  snake position and return the
  position value.
 */


 // method to get snakes position
COORD Food::getSnakePosition()
{
    return position;
}

void Food::generateFood()
{
    /* I used the rand function
    * to generate the food at a random
    * position after it has been eaten.
    */

    position.X = (rand() % _Width - 2) + 2;
    position.Y = (rand() % _Height - 2) + 2;

    /*Subtract width and height by 2
    so the food does not spawn outside the board.
    */
}
