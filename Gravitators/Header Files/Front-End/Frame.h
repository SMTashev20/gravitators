#pragma once

#include <iostream>

//Define the color that are used in frame
#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6

using namespace std;

//Set position and hide the coursor
void setOutputPosition1(short x, short y);
void setCursor(bool shown);

//Set the color
void setColor(int color);

//Print the main menu frame
void printPhysicsLogo();
void printGameFrame_mainMenu();
void printStars_mainMenu();

//Print the exercise frame
void printGameFrame_Exercises();
void printStars_Exercises();

//Print the small frame
void printGameFrame_small();
void printStars_small();

