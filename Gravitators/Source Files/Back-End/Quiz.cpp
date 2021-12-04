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

void outputOptions(string question, string option1, string option2, string option3)
{
	setColor(COLOR_WHITE);
	setOutputPosition(36, 6);
	cout << question;

	setOutputPosition(34, 9);
	cout << option1;
	setOutputPosition(34, 11);
	cout << option2;
	setOutputPosition(34, 13);
	cout << option3;
}

void outputTotalPoints(int& pointsTotal)
{
	setColor(COLOR_WHITE);
	setOutputPosition(30, 10);
	cout << "Congratulations! You have finished the quiz!" << endl;
	setOutputPosition(34, 11);
	cout << "Your total points are: ";
	setColor(COLOR_YELLOW);
	cout << pointsTotal;
}

void printUser(int& pointsTotal, int correctRow)
{
	string user = "-->";
	setColor(COLOR_YELLOW);
	int userRow = 9, userCol = 28;
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
					ClearScreen();
					printGameFrame_Exercises();
					printStars_Exercises();

					setColor(COLOR_YELLOW);
					setOutputPosition(35, 10);
					cout << "+1pt! Press N to continue.";
					pointsTotal++;
					moves = 1;
				}
				else
				{
					ClearScreen();
					printGameFrame_Exercises();
					printStars_Exercises();

					setColor(COLOR_YELLOW);
					setOutputPosition(35, 10);
					cout << "+0pt, press N to continue." << endl;
					moves = 1;
				}
			}
			break;
			case 'n':
			case 'N':
			{
				ClearScreen();
				printGameFrame_Exercises();
				printStars_Exercises();
				cout << 0;

			}
			default:
			{
			}
			}
		}
	}
}

void printTutorialUser()
{
	string user = "-->";
	setColor(COLOR_YELLOW);
	int userRow = 9, userCol = 28;
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

					ClearScreen();
					printGameFrame_Exercises();
					printStars_Exercises();

					setColor(COLOR_YELLOW);
					setOutputPosition(35, 10);
					cout << "Great! Press N to continue.";
					moves = 1;
			}
			break;
			case 'n':
			case 'N':
			{
				ClearScreen();
				printGameFrame_Exercises();
				printStars_Exercises();
				cout << 0;

			}
			default:
			{
			}
			}
		}
	}
}

void QuizRecap()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("Question?", "Answer", "no", "no"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 9);

    outputOptions("Question?", "no", "Answer", "no");
	printUser(pointsTotal, 11);

	outputOptions("Question?", "no", "no", "Answer");
	printUser(pointsTotal, 13);

	outputTotalPoints(pointsTotal);

	setOutputPosition(11, 32);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}