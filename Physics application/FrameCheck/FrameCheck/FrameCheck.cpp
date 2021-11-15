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
	color(5);
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
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |                                                                            | |" << endl;
	cout << "     | |____________________________________________________________________________| |" << endl;
	cout << "     |________________________________________________________________________________|" << endl;
}

int main()
{
	printMap();
	outputPosition(29, 12);
	cout << "Welcome! Please pick your game." << endl;
	outputPosition(38, 14);
	cout << "1. Option 1" << endl;
	outputPosition(38, 16);
	cout << "2. Option 2" << endl;
	outputPosition(38, 18);
	cout << "3. Option 3" << endl;

	int game;
	outputPosition(43, 20);
	cin >> game;
	switch (game)
	{
	case 1:
	{
	}
	}
}
