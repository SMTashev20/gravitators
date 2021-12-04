#pragma once

#include <iostream>

#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6

using namespace std;

void setOutputPosition(short x, short y);
void setCursor(bool shown);

void setColor(int color);

void printPhysicsLogo();
void printGameFrame_mainMenu();
void printStars_mainMenu();

void printGameFrame_Exercises();
void printStars_Exercises();

void printGameFrame_small();
void printStars_small();

