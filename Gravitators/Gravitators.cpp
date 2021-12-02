#include <iostream>
#include <cstring> 
#include <ctime>
#include<windows.h>

#include "Frame.h"

using namespace std;

int main()
{
	printMap();
	color(7);
	outputPosition(28, 12);
	cout << "Welcome! Please pick your game." << endl;
	outputPosition(22, 14);
	cout << "1. Option" << endl;
	outputPosition(38, 14);
	cout << "2. Option" << endl;
	outputPosition(54, 14);
	cout << "3. Option" << endl;
	outputPosition(22, 16);
	cout << "4. Option" << endl;
	outputPosition(38, 16);
	cout << "5. Option" << endl;
	outputPosition(54, 16);
	cout << "6. Option" << endl;
	outputPosition(22, 18);
	cout << "7. Option" << endl;
	outputPosition(38, 18);
	cout << "8. Option" << endl;
	outputPosition(54, 18);
	cout << "9. Option" << endl;

	color(6);
	int game;
	outputPosition(41, 20);
	cin >> game;
	switch (game)
	{
	case 1:
	{

	}
	}
}

