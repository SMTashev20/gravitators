#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6
using namespace std;

void setOutputPosition(short x, short y);

void setColor(int color);

void printGameFrame();

void printStars();

void printTower();

void towerOfPizza();


