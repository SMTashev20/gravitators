#include <iostream>
#include <cstring> 
#include <ctime>
#include<windows.h>

using namespace std;

void typewriter(string msg)
{
	for (int i = 0; msg[i] != '\0'; i++) {
		Sleep(100);
		cout << msg[i];
		if (msg[i] == ' ')
			Sleep(70);
	}
}
	int main()
	{
		typewriter("Loading...");
		Sleep(500);
		cout << "Done!" << endl;
		Sleep(1000);
		system("Color 05");
		typewriter("Welcome! Please pick your game.");
		cout << endl;
		Sleep(1000);
		cout << "1. Option 1" << endl;
		Sleep(500);
		cout << "2. Option 2" << endl;
		Sleep(500);
		cout << "3. Option 3" << endl;
		Sleep(500);
		int game;
		cin >> game;
		switch (game)
		{
		case 1:
			{
			}
		}
	}