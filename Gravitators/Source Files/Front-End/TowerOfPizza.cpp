#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "../../Header Files/Front-End/Frame.h"

#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6
using namespace std;

void printTower() {
	setColor(COLOR_WHITE);
	setOutputPosition(11, 5);
	cout << " _________" << endl;
	setOutputPosition(11, 6);
	cout << "* \\       \\" << endl;
	setOutputPosition(11, 7);
	cout << "|  \\       \\" << endl;
	setOutputPosition(11, 8);
	cout << "*   \\       \\" << endl;
	setOutputPosition(11, 9);
	cout << "|    \\       \\" << endl;
	setOutputPosition(11, 10);
	cout << "*     \\       \\" << endl;
	setOutputPosition(11, 11);
	cout << "|      \\       \\" << endl;
	setOutputPosition(11, 12);
	cout << "*       \\       \\" << endl;
	setOutputPosition(11, 13);
	cout << "|        \\       \\" << endl;
	setOutputPosition(11, 14);
	cout << "*         \\       \\" << endl;
	setOutputPosition(11, 15);
	cout << "|          \\       \\" << endl;
	setOutputPosition(11, 16);
	cout << "*           \\       \\" << endl;
	setOutputPosition(11, 17);
	cout << "|            \\       \\" << endl;
	setOutputPosition(11, 18);
	cout << "*             \\       \\" << endl;
}

void towerOfPizza()
{
	printGameFrame_small();
	printStars_small();
	printTower();
	setColor(COLOR_YELLOW);
	char user = 'O';
	int userCol = 22, userRow = 5;

	setOutputPosition(userCol, userRow);
	cout << user;

	{
		for (int moves = 13; moves > 0; moves--)
		{
			switch (_getch())
			{
			case 'd':
			case 'D':
			{
				setOutputPosition(userCol, userRow);
				cout << " ";
				userCol++;
				userRow++;
				setOutputPosition(userCol, userRow);
				cout << user;
			}
			break;
			default:
			{
				userCol--;
				userRow++;
			}
			}
		}
	}
	setOutputPosition(11, 19);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}

