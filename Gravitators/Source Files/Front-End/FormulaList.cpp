#include <iostream>
#include "../../Header Files/Back-End/mainMenuControl.h"

using namespace std;

void Checker()
{
	cout << "Whould you like to continue";

	char sym;
	cin >> sym;

	while (sym != 'Y' && sym != 'N')
	{
		cout << "Please enter a valid input!" << endl;
		cin >> sym;
	}
	if (sym == 'Y')
	{
		start();
	}
	else
	{
	}
}

void FormulaList()
{
	cout <<"1. Uniform acceleration" << endl;
	cout << "s = v0 * t + (a * t * t) / 2" << endl;
	cout << "V = v0 + a * t" << endl;

	cout << endl;

	cout << "2.Free Fall" << endl;
	cout << "s = (g * t * t) / 2" << endl;
	cout << "V = g * t" << endl;

	cout << endl;
	
	cout << "3.Gravity" << endl;
	cout << "G = m * g" << endl;

	cout << endl;

	cout << "4.Density" << endl;
	cout << "p = m / V" << endl;
	
	cout << endl;

	cout << "5. Newton's Second Law" << endl;
	cout << "F = m * a" << endl;

	cout << endl;

	cout << "Pressure" << endl;
	cout << "P = F / S" << endl;
	cout << "F = P * S" << endl;

	cout << endl;

	cout << "7. Hydrostatic Pressure" << endl;
	cout << "P = rho * g * h" << endl;

	Checker();
}

