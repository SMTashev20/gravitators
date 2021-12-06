//include front-end header files
#include "../../Header Files/Back-End/mainMenuControl.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Front-End/FormulaList.h"

//include back-end header files
#include "../../Header Files/Back-End/Density.h"
#include "../../Header Files/Back-End/FreeFall.h"
#include "../../Header Files/Back-End/Gravity.h"
#include "../../Header Files/Back-End/HydrostaticPressure.h"
#include "../../Header Files/Back-End/Newton'sSecondLaw.h"
#include "../../Header Files/Back-End/Pressure.h"
#include "../../Header Files/Back-End/uniformAcceleration.h"
#include "../../Header Files/Back-End/Quiz.h"
#include "../../Header Files/Back-End/MainFunctions.h"

//Main start the main menu
void start()
{
	printGameFrame_mainMenu();
	printStars_mainMenu();
	printPhysicsLogo();
	setColor(COLOR_WHITE);
    setCursor(0);

	setOutputPosition1(27, 10);
	cout << "Welcome! Please pick your game." << endl;
	setOutputPosition1(10, 13);
	cout << "1. Density" << endl;
	setOutputPosition1(37, 13);
	cout << "2. Free Fall" << endl;
	setOutputPosition1(62, 13);
	cout << "3. Gravity" << endl;
	setOutputPosition1(10, 16);
	cout << "4. Hydrostatic Pressure" << endl;
	setOutputPosition1(37, 16);
	cout << "5. Newton's Second Law" << endl;
	setOutputPosition1(62, 16);
	cout << "6. Pressure" << endl;
	setOutputPosition1(10, 19);
	cout << "7. Uniforms Acceleration" << endl;
	setOutputPosition1(37, 19);
	cout << "8. Formula list" << endl;
	setOutputPosition1(62, 19);
	cout << "9. Recap Quiz" << endl;

	setColor(COLOR_YELLOW);
    setOutputPosition1(41, 22);

    while (true)
    {
        switch (_getch())
        {
        case '1':
        {
            ClearScreen();
            optionMenuDensity();
            break;
        }
        case '2':
        {
            ClearScreen();
            optionMenuFreeFall();
            break;
        }
        case '3':
        {
            ClearScreen();
            optionMenuGravity();
            break;
        }
        case '4':
        {
            ClearScreen();
            optionMenuHydrostaticPressure();
            break;
        }
        case '5':
        {
            ClearScreen();
           optionMenuNewtonLaws();
            break;
        }
        case '6':
        {
            ClearScreen();
            optionMenuPressure();
            break;
        }
        case '7':
        {
            ClearScreen();
            optionMenuUniformAcceleration();
            break;
        }
        case '8':
        {
            ClearScreen();
            FormulaList();
            break;
        }
        case '9':
        {
            ClearScreen();
            QuizRecap();
            break;
        }
        }
    }

}
