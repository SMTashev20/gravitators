#include <iostream>

//Include header files
#include "../../Header Files/Back-End/mainMenuControl.h"
#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Front-End/Frame.h"
#include <conio.h>

using namespace std;

//print Formula list
void FormulaList()
{
	printGameFrame_mainMenu();
	printStars_mainMenu();
	setColor(COLOR_WHITE);

	setOutputPosition1(12, 6);
	cout << "1. Uniform acceleration" << endl;
	setOutputPosition1(12, 7);
	cout << "s = v0 * t + (a * t * t) / 2" << endl;
	setOutputPosition1(12, 8);
	cout << "V = v0 + a * t" << endl;

	setOutputPosition1(50, 6);
	cout << "2. Free Fall" << endl;
	setOutputPosition1(50, 7);
	cout << "s = (g * t * t) / 2" << endl;
	setOutputPosition1(50, 8);
	cout << "V = g * t" << endl;

	setOutputPosition1(12, 12);
	cout << "3. Gravity" << endl;
	setOutputPosition1(12, 13);
	cout << "G = m * g" << endl;

	setOutputPosition1(50, 12);
	cout << "4. Density" << endl;
	setOutputPosition1(50, 13);
	cout << "p = m / V" << endl;

	setOutputPosition1(12, 17);
	cout << "5. Newton's Second Law" << endl;
	setOutputPosition1(12, 18);
	cout << "F = m * a" << endl;

	setOutputPosition1(50, 17);
	cout << "6. Pressure" << endl;
	setOutputPosition1(50, 18);
	cout << "P = F / S" << endl;
	setOutputPosition1(50, 19);
	cout << "F = P * S" << endl;

	setOutputPosition1(12, 21);
	cout << "7. Hydrostatic Pressure" << endl;
	setOutputPosition1(12, 22);
	cout << "P = rho * g * h" << endl;

	setColor(COLOR_YELLOW);
	returnToMainMenu1(50, 22);
}

