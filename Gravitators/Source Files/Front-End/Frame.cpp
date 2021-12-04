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

void printPhysicsLogo() {
	setColor(COLOR_YELLOW);
	setOutputPosition(16, 3);
	cout << " __   __                    _               _          _ ";
	setOutputPosition(16, 4);
	cout << " \\ \\ / /_ _ _   _     _ __ | |__  _   _ ___(_) ___ ___| |";
	setOutputPosition(16, 5);
	cout << "  \\ V / _` | | | |   | '_ \\| '_ \\| | | / __| |/ __/ __| |";
	setOutputPosition(16, 6);
	cout << "   | | (_| | |_| |_  | |_) | | | | |_| \\__ \\ | (__\\__ \\_|";
	setOutputPosition(16, 7);
	cout << "   |_|\\__,_|\\__, ( ) | .__/|_| |_|\\__, |___/_|\\___|___(_)";
	setOutputPosition(16, 8);
	cout << "            |___/|/  |_|          |___/                 ";
}

void printGameFrame_mainMenu() {
	setOutputPosition(0, 1);
	setColor(COLOR_AQUA);
	cout << "      ___________________________________________________________________________" << endl;
	cout << "     |  _______________________________________________________________________  |" << endl;

	for (int i = 0; i < 22; i++)
	{
		cout << "     | |                                                                       | |" << endl;
	}
	cout << "     | |_______________________________________________________________________| |" << endl;
	cout << "     |___________________________________________________________________________|" << endl;

	setColor(COLOR_GRAY);
	setOutputPosition(8, 24);
	cout << "TEAM GRAVITATORS" << endl;
	setColor(COLOR_WHITE);
}

void printGameFrame_Exercises() {
	setOutputPosition(0, 1);
	setColor(COLOR_AQUA);
	cout << "      _________________________________________________________________________________________" << endl;
	cout << "     |  _____________________________________________________________________________________  |" << endl;

	for (int i = 0; i < 18; i++)
	{
		cout << "     | |                                                                                     | |" << endl;
	}
	cout << "     | |_____________________________________________________________________________________| |" << endl;
	cout << "     |_________________________________________________________________________________________|" << endl;

	setColor(COLOR_GRAY);
	setOutputPosition(8, 20);
	cout << "TEAM GRAVITATORS" << endl;
	setColor(COLOR_WHITE);
}

void printGameFrame_small() {
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
	setColor(COLOR_WHITE);
}

void printStars_mainMenu()
{
	setColor(COLOR_GRAY);
	setOutputPosition(8, 4);
	cout << "                      *        '      ";
	setColor(COLOR_YELLOW);
	cout << "     .      " << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 5);
	cout << "   *         '       +       *";
	cout << "             .         '              ";
	setColor(COLOR_YELLOW);
	cout << "*" << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 6);
	cout << "    .                 .         *                          '       " << endl;
	setOutputPosition(8, 8);
	cout << "                     *        '                *                   " << endl;
	setOutputPosition(8, 9);
	cout << "    *                                                      *     " << endl;
	setOutputPosition(8, 11);
	cout << "                                          '                         " << endl;
	setOutputPosition(8, 12);
	cout << "   *            *          .                        +               " << endl;
	setOutputPosition(8, 14);
	cout << "    .                 .                           .             " << endl;
	setOutputPosition(8, 15);
	cout << "           +                                              .    " << endl;
	setOutputPosition(8, 16);
	cout << "                           '               '     *                  " << endl;
	setColor(COLOR_YELLOW);
	setOutputPosition(8, 21);
	cout << "   +                                                      +     " << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 22);
	cout << "    .                 .         *                          '       " << endl;
}

void printStars_Exercises()
{
	setColor(COLOR_GRAY);
	setOutputPosition(8, 4);
	cout << "                      *        '      ";
	setColor(COLOR_YELLOW);
	cout << "     .      " << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 5);
	cout << "   *          '            +            *";
	cout << "            .            '               ";
	setColor(COLOR_YELLOW);
	cout << "*" << endl;
	setColor(COLOR_GRAY);
	setOutputPosition(8, 6);
	cout << "      .                   .            *                                   '       " << endl;
	setOutputPosition(8, 8);
	cout << "                           *          '                        *                   " << endl;
	setOutputPosition(8, 9);
	cout << "       *                                                             *     " << endl;
	setOutputPosition(8, 11);
	cout << "                                                 '                         " << endl;
	setOutputPosition(8, 12);
	cout << "   *                  *           .                                +               " << endl;
	setOutputPosition(8, 14);  
	cout << "    .                     .                                        .             " << endl;
	setOutputPosition(8, 15);
	cout << "           +                                                                   .    " << endl;
	setOutputPosition(8, 16); 
	cout << "                             '                         '     *                  " << endl;
	setOutputPosition(8, 17);
	cout << "                           *          '                        *                   " << endl;
	setOutputPosition(8, 18);
	cout << "   *                  *           .                                +               " << endl;
}

void printStars_small()
{

	setColor(COLOR_GRAY);
	setOutputPosition(8, 4);
	cout << " *        '      ";
	setOutputPosition(8, 5);
	cout << "   *         '       +      *";
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

