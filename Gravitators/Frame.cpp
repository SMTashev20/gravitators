#include <iostream>
#include <cstring> 
#include <ctime>
#include<windows.h>

using namespace std;

void outputPosition(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position))
	{
		return;
	}
	else {}
}

void color(int color)
{
	if (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color))
	{
		return;
	}
	else {}
}

void printMap() {
	outputPosition(0, 1);
	color(3);
	cout << "      ________________________________________________________________________________" << endl;
	cout << "     |  ____________________________________________________________________________  |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |____________________________________________________________________________| |" << endl;
	cout << "     |________________________________________________________________________________|" << endl;

	color(8);
	outputPosition(8, 4);
	cout << "                         *        '      ";
	color(6);
	cout << "     .      " << endl;
	color(8);
	outputPosition(8, 5);
	cout << "   *         '       +         *";
	cout << "             .         '                ";
	color(6);
	cout << "*" << endl;
	color(8);
	outputPosition(8, 6);
	cout << "    .                 .         *                                   '       " << endl;
	outputPosition(8, 8);
	cout << "                         *        '                     *                   " << endl;
	outputPosition(8, 9);
	cout << "    *                                                                *     " << endl;
	outputPosition(8, 11);
	cout << "                                          '                                " << endl;
	outputPosition(8, 12);
	cout << "   *            *          .                                +               " << endl;
	outputPosition(8, 14);
	cout << "    .                 .                                    .             " << endl;
	outputPosition(8, 15);
	cout << "           +                                                         .    " << endl;
	outputPosition(8, 16);
	cout << "                                 '                '     *                  " << endl;
	color(6);
	outputPosition(8, 17);
	cout << "   +                                                                 +     " << endl;
	color(8);
	outputPosition(8, 18);
	cout << "      .          +                                                         " << endl;
	outputPosition(8, 19);
	cout << "                              +                               *          " << endl;
	outputPosition(8, 20);
	cout << "           +                                                              " << endl;
	outputPosition(8, 21);
	cout << "                      '                                *                  " << endl;
	outputPosition(8, 22);
	cout << "         +         *             .         '         *                 '  " << endl;
	outputPosition(8, 23);
	cout << "                                                                   *      " << endl;
	outputPosition(8, 24);
	cout << "   *            *          .                                  +           " << endl;
	outputPosition(8, 25);
	cout << "                    '                        ";
	color(6);
	cout << "+                         ";
	color(8);
	cout << "+   " << endl;
	color(6);
	outputPosition(16, 5);
	cout << " __   __                    _               _          _ ";
	outputPosition(16, 6);
	cout << " \\ \\ / /_ _ _   _     _ __ | |__  _   _ ___(_) ___ ___| |";
	outputPosition(16, 7);
	cout << "  \\ V / _` | | | |   | '_ \\| '_ \\| | | / __| |/ __/ __| |";
	outputPosition(16, 8);
	cout << "   | | (_| | |_| |_  | |_) | | | | |_| \\__ \\ | (__\\__ \\_|";
	outputPosition(16, 9);
	cout << "   |_|\\__,_|\\__, ( ) | .__/|_| |_|\\__, |___/_|\\___|___(_)";
	outputPosition(16, 10);
	cout << "            |___/|/  |_|          |___/                 ";
	outputPosition(8, 25);
	cout << "TEAM GRAVITATORS" << endl;
}
