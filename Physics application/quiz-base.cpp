#include <iostream>
using namespace std;

#include <iostream>
#include <cstring> 
#include <ctime>
#include <windows.h>
#include <conio.h>

#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6

using namespace std;

void setOutputPosition(short x, short y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (SetConsoleCursorPosition(handle, position))
	{
		return;
	}
	else {}
}

void setColor(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else {}
}

void printGameFrame() {
	setOutputPosition(0, 1);
	setColor(COLOR_AQUA);
	cout << "      ________________________________________________________________________________" << endl;
	cout << "     |  ____________________________________________________________________________  |" << endl;

	for (int i = 0; i < 15; i++)
	{
		cout << "     | |                                                                            | |" << endl;
	}
	cout << "     | |____________________________________________________________________________| |" << endl;
	cout << "     |________________________________________________________________________________|" << endl;

}

void printStars()
{

	setColor(COLOR_GRAY);
	setOutputPosition(8, 4);
	cout << "                         *        '      ";
	setColor(COLOR_YELLOW);
	cout << "     .      " << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 5);
	cout << "   *         '       +         *";
	cout << "             .         '                ";
	setColor(COLOR_YELLOW);
	cout << "*" << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 6);
	cout << "    .                 .         *                                   '       " << endl;
	setOutputPosition(8, 8);
	cout << "                         *        '                     *                   " << endl;
	setOutputPosition(8, 9);
	cout << "    *                                                                *     " << endl;
	setOutputPosition(8, 11);
	cout << "                                          '                                " << endl;
	setOutputPosition(8, 12);
	cout << "   *            *          .                                +               " << endl;
	setOutputPosition(8, 14);
	cout << "    .                 .                                    .             " << endl;
	setOutputPosition(8, 15);
	cout << "           +                                                         .    " << endl;
	setOutputPosition(8, 16);
	cout << "                                 '                '     *                  " << endl;
	setColor(COLOR_YELLOW);
	setOutputPosition(8, 17);
	cout << "   +                                                                 +     " << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 17);
	cout << "TEAM GRAVITATORS" << endl;
}

string ClearScreen()
{
	return string(100, '\n');
}

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

int outputTotalPoints(int &pointsTotal)
{
	setColor(COLOR_WHITE);
	setOutputPosition(25, 10);
	cout << "Congratulations on finishing the quiz!" << endl;
	setOutputPosition(34, 11);
	cout << "Your total points are: ";
	setColor(COLOR_YELLOW);
	return pointsTotal;
}
int printUser(int& pointsTotal, int correctRow)
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
				cout << ClearScreen();
				printGameFrame();
				printStars();
				return 0;

			}
			default:
			{
			}
			}
		}
	}
}
int main()
{
	printGameFrame();
	printStars();

	int pointsTotal = 0;
	 cout << outputOptions("Question?", "Answer" , "no" , "no");
	 cout << printUser(pointsTotal, 10);

	 cout << outputOptions("Question?", "no", "no", "Answer");
	cout << printUser(pointsTotal, 12);

	cout << outputTotalPoints(pointsTotal);

	setOutputPosition(11, 19);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}