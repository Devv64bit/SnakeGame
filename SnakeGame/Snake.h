#pragma once

#include <windows.h>
#include <cstdlib>
#include <vector>

const int Width = 60;
const int Height = 30;
using namespace std;

/*
	Make a class named Snake and
	add all the necessary variables
	and methods that associate with Snake.
	For example: how to move the snake,
	how to set its direction, and etc.
*/

class Snake
{
public:
	COORD position;
	int velocity;
	int  snakesLength;
	char initialDirection;
	vector <COORD> snakeBody;


	//constructor
	Snake(COORD position, int velocity);

	// all methods associated with Snake
	void growBody();
	void moveSnake();
	void setDirection(char dir);
	vector<COORD> getSnakeBody();
	bool ifCollided();
	bool appleEaten(COORD food);
	COORD getSnakePosition();
};
