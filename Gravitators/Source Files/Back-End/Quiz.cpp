#include <iostream>
using namespace std;

#include <iostream>
#include <cstring> 
#include <ctime>
#include <windows.h>
#include <conio.h>

#include "../../Header Files/Front-End/TowerOfPizza.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/MainFunctions.h"

#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6

using namespace std;

string outputOptions(string question, string option1, string option2, string option3)
{
	setColor(COLOR_WHITE);
	setOutputPosition(40, 9);
	cout << question;

	setOutputPosition(35, 10);
	cout << option1;
	setOutputPosition(35, 11);
	cout << option2;
	setOutputPosition(35, 12);
	return option3;
}

int outputTotalPoints(int& pointsTotal)
{
	setColor(COLOR_WHITE);
	setOutputPosition(25, 10);
	cout << "Congratulations on finishing the quiz!" << endl;
	setOutputPosition(34, 11);
	cout << "Your total points are: ";
	setColor(COLOR_YELLOW);
	return pointsTotal;
}

void printUser(int& pointsTotal, int correctRow)
{
	string user = "-->";
	setColor(COLOR_YELLOW);
	int userRow = 10, userCol = 25;
	{
		for (int moves = 100; moves >= 0; moves--)
		{
			switch (_getch())
			{
			case 'w':
			case 'W':
			{
				setOutputPosition(userCol, userRow);
				cout << "    ";
				userRow--;
				setOutputPosition(userCol, userRow);
				cout << user;
			}
			break;
			case 's':
			case 'S':
			{
				setOutputPosition(userCol, userRow);
				cout << "    ";
				userRow++;
				setOutputPosition(userCol, userRow);

				cout << user;
			}
			break;
			case 'z':
			case 'Z':
			{
				if (userRow == correctRow)
				{
					setColor(COLOR_YELLOW);
					setOutputPosition(30, 15);
					cout << "+1pt! Press N to continue.";
					pointsTotal++;
					moves = 1;
				}
				else
				{
					setColor(COLOR_YELLOW);
					setOutputPosition(30, 15);
					cout << "+0pt, press N to continue." << endl;
					setOutputPosition(30, 16);
					moves = 1;
				}
			}
			break;
			case 'n':
			case 'N':
			{
				ClearScreen();
				printGameFrame_TowerOfPisa();
				printStars_TowerOfPisa();
				cout << 0;

			}
			default:
			{
			}
			}
		}
	}
}

void Quiz()
{
	printGameFrame_TowerOfPisa();
	printStars_TowerOfPisa();

	int pointsTotal = 0;
	cout << outputOptions("Question?", "Answer", "no", "no");
	printUser(pointsTotal, 10);

	cout << outputOptions("Question?", "no", "no", "Answer");
	printUser(pointsTotal, 12);

	cout << outputTotalPoints(pointsTotal);

	setOutputPosition(11, 19);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}