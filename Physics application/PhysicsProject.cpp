#include <iostream>
#include <string> 
#include <ctime>
#include <windows.h>
#include <conio.h>

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

setOutputPosition(8, 24);
cout << "   *            *          .                                  +           " << endl;
setOutputPosition(8, 25);
cout << "                    '                        ";
setConsoleColor(6);
cout << "+                         ";
setConsoleColor(8);
cout << "+   " << endl;
setConsoleColor(6);
setOutputPosition(16, 5);
cout << " __   __                    _               _          _ ";
setOutputPosition(16, 6);
cout << " \\ \\ / /_ _ _   _     _ __ | |__  _   _ ___(_) ___ ___| |";
setOutputPosition(16, 7);
cout << "  \\ V / _` | | | |   | '_ \\| '_ \\| | | / __| |/ __/ __| |";
setOutputPosition(16, 8);
cout << "   | | (_| | |_| |_  | |_) | | | | |_| \\__ \\ | (__\\__ \\_|";
setOutputPosition(16, 9);
cout << "   |_|\\__,_|\\__, ( ) | .__/|_| |_|\\__, |___/_|\\___|___(_)";
setOutputPosition(16, 10);
cout << "            |___/|/  |_|          |___/                 ";
setOutputPosition(8, 25);
cout << "TEAM GRAVITATORS" << endl;
}

int main()
{
    printMap();
    setConsoleColor(7);
    setOutputPosition(28, 12);
    cout << "Welcome! Please pick your game." << endl;
    setOutputPosition(22, 14);
    cout << "1. Option" << endl;
    setOutputPosition(38, 14);
    cout << "2. Option" << endl;
    setOutputPosition(54, 14);
    cout << "3. Option" << endl;
    setOutputPosition(22, 16);
    cout << "4. Option" << endl;
    setOutputPosition(38, 16);
    cout << "5. Option" << endl;
    setOutputPosition(54, 16);
    cout << "6. Option" << endl;
    setOutputPosition(22, 18);
    cout << "7. Option" << endl;
    setOutputPosition(38, 18);
    cout << "8. Option" << endl;
    setOutputPosition(54, 18);
    cout << "9. Option" << endl;

    setConsoleColor(6);
    int game;
    setOutputPosition(41, 20);
    cin >> game;
    switch (game)
    {
    case 1:
    {
    }
    }
}