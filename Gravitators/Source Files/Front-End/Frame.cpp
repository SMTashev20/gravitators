#include <iostream>
#include <Windows.h>
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
	cout << "      _______________________________________" << endl;
	cout << "     |  ___________________________________  |" << endl;

	for (int i = 0; i < 16; i++)
	{
		cout << "     | |                                   | |" << endl;
	}
	cout << "     | |___________________________________| |" << endl;
	cout << "     |_______________________________________|" << endl;


	setOutputPosition(27, 3);
	setColor(COLOR_GRAY);
	cout << "TEAM GRAVITATORS" << endl;
}

void printStars()
{

	setColor(COLOR_GRAY);
	setOutputPosition(8, 4);
	cout << " *        '      ";
	setOutputPosition(8, 5);
	cout << "   *         '       +       *";
	setOutputPosition(8, 6);
	cout << "    .         .         *   " << endl;
	setOutputPosition(8, 8);
	cout << "                   *        '     *" << endl;
	setOutputPosition(8, 9);
	cout << "                  *         * " << endl;
	setOutputPosition(8, 11);
	cout << "        '         " << endl;
	setOutputPosition(8, 12);
	cout << "   *       *              ." << endl;
	setOutputPosition(8, 14);
	cout << "    .       .  " << endl;
	setOutputPosition(8, 15);
	cout << "            +                  ." << endl;
	setOutputPosition(8, 16);
	cout << "            '         '     * " << endl;
	setOutputPosition(8, 17);
	cout << "   +            +     " << endl;
	setOutputPosition(8, 18);
	cout << "       .          +  " << endl;
}
