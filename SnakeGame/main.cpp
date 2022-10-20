#include <iostream>
#include <cstdlib>
#include <conio.h> 
#include <chrono>
#include <thread>
/*
      Include the two header files
      to use the variables and methods
      from classes Snake and Food.
*/

#include "Snake.h"
#include "Food.h"


// we have to use this because using namespace std causes errors in the program
using std::cout;
using std::endl;

const int width = 60;
const int height = 30;
int score = 0;

// divide the width and height 2 so the snake spawns in the center of the board.
Snake naagin({ width / 2, height / 2 }, 1);

// make an object of class Food named apple
Food apple;

void Intro()
{
    cout << "\x1B[31m\n\n\t\t\t\t\t\t\t\t******************************************\n\t\t\t\t\t\t\t\t*\033[0m";
    cout << " ====================================== " << "\x1B[31m*\n\t\t\t\t\t\t\t\t*\033[0m";
    cout << "\x1B[93m               SNAKE GAME               \033[0m" << "\x1B[31m*\n\t\t\t\t\t\t\t\t*\033[0m";
    cout << " ====================================== " << "\x1B[31m*\n\033[0m";
    cout << "\x1B[31m\t\t\t\t\t\t\t\t******************************************\n\n\n\033[0m";
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "\t\t\t\t\t\t\t\t------------------------------------------\n";
    //Used // to print / because its a special character.
    cout << "\t\t\t\t\t\t\t\t\x1B[35m/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[32m           	Programmer:           	\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[93m            	Deep Patel           	\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[93m            	Darsh Patel          	\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[93m            	Dev Patel            	\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[34m       	Penn State Abington       	\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[34m             	COMPSC121           	\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\x1B[35m\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------------------";

    this_thread::sleep_for(chrono::milliseconds(3500));

    cout << "\n\n\n\t\t\t\t\t\t\t\t\t          " << "\x1B[36mLoading....\033[0m" << endl;

    cout << "\t\t\t\t\t\t\t\t\t        Please wait....\n\n\n\n\n\n" << endl;

    this_thread::sleep_for(chrono::milliseconds(3500));
}


void makeBoard()
{
    COORD snakesPosition = naagin.getSnakePosition();
    COORD foodsPosition = apple.getSnakePosition();
    vector<COORD> snake_body = naagin.getSnakeBody();

    cout << "\t\tSCORE : " << score << endl;

    /*
                Write a nested for loops to print the
                the board
    */

    for (int x = 0; x < height; x++)
    {
        // print the boundary for the left wall
        cout << "\x1B[33m\t\t|";
        for (int c = 0; c < width - 2; c++)
        {
            if (x == 0 || x == height - 1)
            {
                // print the boundary for the top and bottom walls.
                cout << "-";
            }

            else if (x == snakesPosition.Y && c + 1 == snakesPosition.X)
            {
                // print the snake's head
                cout << "\x1B[32mO\033[0m";
            }

            else if (x == foodsPosition.Y && c + 1 == foodsPosition.X)
            {
                // print the apple
                cout << "\x1B[31m\u2022\033[0m";
            }

            else
            {
                bool bodyPart = false;
                for (int t = 0; t < snake_body.size() - 1; t++)
                {
                    if (x == snake_body[t].Y && c + 1 == snake_body[t].X)
                    {
                        // add the snake's tail at the end
                        cout << "o";
                        bodyPart = true;
                        break;
                    }
                }

                if (!bodyPart)
                {
                    //Print nothing because the middle of board should be empty
                    cout << ' ';
                }
            }
        }
        // print the boundary for the right wall.
        cout << "\x1B[33m|\n";
    }
}

// make a getter method to recieve the score
int getScore()
{
    return score;
}

void userInput()
{
    /* kbhit stands for keyboard hit
                so if the user presses WASD,
                then we will set the direction.
    */
    if (_kbhit())
    {
        /* getch method is used to catch
          character from the keyboard
          so we will pass that in to
          switch parameter.
        */
        switch (_getch())
        {
        case 'w': naagin.setDirection('u'); break;
        case 'a': naagin.setDirection('l'); break;
        case 's': naagin.setDirection('d'); break;
        case 'd': naagin.setDirection('r'); break;
        }
    }
}

int main()
{
    Intro();
    system("cls");

    // this will generate the apple on start of the game
    apple.generateFood();

    bool game_over = false;

    // while game is not over
    while (!game_over)
    {
        /* While the game is not over
                    call the three methods listed below
                    Using sleep function to add delay on the snake
        */
        makeBoard();
        userInput();
        Sleep(20);

        if (naagin.ifCollided())
        {
            /* If the snake hits something
            * then, set game over to true
            * and clear the screen.
            */

            game_over = true;
            system("cls");
            cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t    \x1B[31mGAME OVER\033[0m";
            cout << "\n\n\t\t\t\t\t\t\t\t\t\x1B[34mYour Score was: \033[0m" << getScore();
        }

        if (naagin.appleEaten(apple.getSnakePosition()))
        {
            /* If the snake eats the apple
            then, generate food at random place,
            grow body, and increase score.
            */

            apple.generateFood();
            naagin.growBody();
            score = score + 10;
        }

        naagin.moveSnake();

        /* We have to use this function in order to
        set cursor position. So every frame it will
        * set the cursor to the same position.
        */
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

    return 0;
}
