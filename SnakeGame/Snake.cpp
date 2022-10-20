#include "Snake.h"

/*Constructor of class Snake
            and pass the position and
            velocity
*/
Snake::Snake(COORD position, int velocity)
{
    /*using pointers to pass value address of
    position to the parameters position.
    */
    this->position = position;
    this->velocity = velocity;

    initialDirection = 'x';
    snakesLength = 1;

    // push back the position of the head
    snakeBody.push_back(position);
}

void Snake::moveSnake()
{
    switch (initialDirection)
    {
    case 'u':
        position.Y -= velocity;
        break;

    case 'l':
        position.X -= velocity;
        break;

    case 'd':
        position.Y += velocity;
        break;

    case 'r':
        position.X += velocity;
        break;
    }

    snakeBody.push_back(position);

    /* If the body size is the less than
    number of elements in the vector that is greater
    * than the length, then erase body and
    * bring it to beginning of the body.
    */
    if (snakeBody.size() > snakesLength)
    {
        snakeBody.erase(snakeBody.begin());
    }
}

// make a setter method to set the direction of the snake
void Snake::setDirection(char dir)
{
    this->initialDirection = dir;
}

void Snake::growBody()
{
    snakesLength++;
}

bool Snake::appleEaten(COORD food)
{
    /* If the snake's x&y position is same as
    * food's x&y position, then we know that
    * the food was eaten.
    */

    if (position.X == food.X && position.Y == food.Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Snake::ifCollided()
{
    // this if statement will check if the snake hits the boundaries and returns true.
    if (position.X < 1 || position.X > Width - 2 || position.Y < 1 || position.Y > Height - 2)
    {
        return true;
    }

    for (int i = 0; i < snakesLength - 1; i++)
    {
        // for loop and if statement to check if the snake hits it own tail and returns true.
        if (position.X == snakeBody[i].X && position.Y == snakeBody[i].Y)
            return true;
    }
    return false;
}

// make a getter method to get the Snake's Body on the board
vector<COORD> Snake::getSnakeBody()
{
    return snakeBody;
}

// make a getter method to get the Snake's position on the board.
COORD Snake::getSnakePosition()
{
    return position;
}
