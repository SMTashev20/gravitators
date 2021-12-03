#include <iostream>
#include <cstring> 
#include <ctime>
#include<windows.h>

#include "../../Header Files/Back-End/mainMenuControl.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Front-End/FormulaList.h"

#include "../../Header Files/Back-End/Density.h"
#include "../../Header Files/Back-End/FreeFall.h"
#include "../../Header Files/Back-End/Gravity.h"
#include "../../Header Files/Back-End/HydrostaticPressure.h"
#include "../../Header Files/Back-End/Newton'sSecondLaw.h"
#include "../../Header Files/Back-End/Pressure.h"
#include "../../Header Files/Back-End/uniformAcceleration.h"

using namespace std;

void start()
{
	setColor(7);
	setOutputPosition(28, 12);
	cout << "Welcome! Please pick your game." << endl;
	setOutputPosition(22, 14);
	cout << "1. Density" << endl;
	setOutputPosition(38, 14);
	cout << "2. FreeFall" << endl;
	setOutputPosition(54, 14);
	cout << "3. Gravity" << endl;
	setOutputPosition(22, 16);
	cout << "4. Hydrostatic Pressure" << endl;
	setOutputPosition(38, 16);
	cout << "5. Newton's Second Law" << endl;
	setOutputPosition(54, 16);
	cout << "6. Pressure" << endl;
	setOutputPosition(22, 18);
	cout << "7. Uniforms Acceleration" << endl;
	setOutputPosition(38, 18);
	cout << "8. Formula list" << endl;
	setOutputPosition(54, 18);
	cout << "9. Recap Quiz" << endl;

	setColor(6);
	int game;
	setOutputPosition(41, 20);
	cin >> game;
	switch (game)
	{
		case 1:
		{
			Denisty();
			break;
		}
		case 2:
		{
			FreeFall();
			break;
		}
		case 3:
		{
			Gravity();
			break;
		}
		case 4:
		{
			hydrostaticPressure();
			break;
		}
		case 5:
		{
			newtonSecondLaw();
			break;
		}
		case 6:
		{
			Pressure();
			break;
		}
		case 7:
		{
			uniformAcceleration();
			break;
		}
		case 8:
		{
			FormulaList();
			break;
		}
		case 9:
		{
			break;
		}
	}
}
