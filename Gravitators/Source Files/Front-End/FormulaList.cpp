#include <iostream>
#include "../../Header Files/Back-End/mainMenuControl.h"
#include "../../Header Files/Back-End/MainFunctions.h"

using namespace std;

void FormulaList()
{
	printGameFrame_mainMenu();
	printStars_mainMenu();
	setColor(COLOR_WHITE);

	setOutputPosition(12, 6);
	cout << "1. Uniform acceleration" << endl;
	setOutputPosition(12, 7);
	cout << "s = v0 * t + (a * t * t) / 2" << endl;
	setOutputPosition(12, 8);
	cout << "V = v0 + a * t" << endl;

	setOutputPosition(50, 6);
	cout << "2. Free Fall" << endl;
	setOutputPosition(50, 7);
	cout << "s = (g * t * t) / 2" << endl;
	setOutputPosition(50, 8);
	cout << "V = g * t" << endl;

	setOutputPosition(12, 12);
	cout << "3. Gravity" << endl;
	setOutputPosition(12, 13);
	cout << "G = m * g" << endl;

	setOutputPosition(50, 12);
	cout << "4. Density" << endl;
	setOutputPosition(50, 13);
	cout << "p = m / V" << endl;

	setOutputPosition(12, 17);
	cout << "5. Newton's Second Law" << endl;
	setOutputPosition(12, 18);
	cout << "F = m * a" << endl;

	setOutputPosition(50, 17);
	cout << "6. Pressure" << endl;
	setOutputPosition(50, 18);
	cout << "P = F / S" << endl;
	setOutputPosition(50, 19);
	cout << "F = P * S" << endl;

	setOutputPosition(12, 21);
	cout << "7. Hydrostatic Pressure" << endl;
	setOutputPosition(12, 22);
	cout << "P = rho * g * h" << endl;

	setOutputPosition(50, 22);
	setColor(COLOR_YELLOW);
	cout << "Press N to go back.";

	switch (_getch())
	{
	case 'N':
	case 'n':
	{
		ClearScreen();
		start();
		break;
	}
	}
}

