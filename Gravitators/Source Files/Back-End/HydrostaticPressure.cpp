#include <iostream>

//include header files
#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Back-End/HydrostaticPressure.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/Quiz.h"

using namespace std;

//Insert HydrostaticPressure Calculator
void hydrostaticPressureCalculatorHydrostaticPressure()
{
    double rho; // declare variables
    double height;
    string opening;
    // F = m * a

    // enter values for rho and h
    setOutputPosition1(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the rho of the object (p):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 8);
    inputNumber(rho, 14, 8);

    setOutputPosition1(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the height of the contaner (h):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 10);
    inputNumber(height, 14, 10);

    setOutputPosition1(14, 12);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "P = p * g * h") << endl;

    setOutputPosition1(14, 13);
    cout << "First we replace the values:" << endl;

    setOutputPosition1(14, 14);
    cout << "P " << rho << " * " << "10" << height << endl;

    setOutputPosition1(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition1(14, 16);
    cout << "F = " << rho * 10 * height << " Pa" << endl;
}

//Insert height Calculator
void HeightCalculatorHydrostaticPressure()
{
    double hydrostaticPressure; // declare variables
    double rho;
    string opening;
    // h = P / p * g

    // enter values for P and rho
    setOutputPosition1(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the Hydrostatic Pressure of the object (P):" << endl;

    setOutputPosition1(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(hydrostaticPressure, 14, 8);

    setOutputPosition1(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the rho of the object (p):" << endl;

    setOutputPosition1(78, 10);
    setColor(COLOR_YELLOW);
    inputNumber(rho, 14, 10);

    setColor(COLOR_WHITE);

    while (rho == 0) // check for dividing by zero
    {
        setOutputPosition1(14, 10);
        cout << "You can't divide by 0! Enter new value!" << endl;
        setColor(COLOR_YELLOW);

        setOutputPosition1(78, 10);
        inputNumber(rho, 14, 10);
        setColor(COLOR_WHITE);
    }

    setOutputPosition1(14, 12);
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "h = P / p * g") << endl;

    setOutputPosition1(14, 13);
    cout << "First we replace the values:" << endl; // calculate using the formula

    setOutputPosition1(14, 14);
    cout << "h = " << hydrostaticPressure << " / " << rho << " * 10" << endl;

    setOutputPosition1(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition1(14, 16);
    cout << "h = " << hydrostaticPressure / (rho * 10) << " m" << endl;
}

// check if user wants to calculate height or hydrostatic pressure
void heightHydrostaticPleasureCalculatorHydrostaticPressure(string symbol)
{
    if (symbol == "h")
    {
        HeightCalculatorHydrostaticPressure();
    }
    else
    {
        hydrostaticPressureCalculatorHydrostaticPressure();
    }
}

// problem 1
void exerciseOneHP(bool& pointAdd)
{
    double answer;  // declare variable
    string opening;
    string question = "A jar of water is 15 cm. Find \"P" " at the bottom of the jar,\n"
        "             ignore \"P\" and use \"a\" due to g = 10 m/s2 and \n"
        "             the density of water 1000 kg/m3. P = ? Pa\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition1(14, 4);
    outputProblem(opening, question);
    cout << opening;

    setOutputPosition1(14, 7);
    cout << outputProblem(opening, question); // output the problem
    setOutputPosition1(14, 10);
    cout << "Hint: 15cm = 0,15m" << endl;

    setOutputPosition1(14, 11);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 1500, if user inputs 1500
    //then it is correct and if returns true
    if (answer == 1500)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }


}

// problem 2
void exerciseTwoHP(bool& pointAdd)
{
    double answer;  // declare variable
    string opening;
    string question = "What is the hydrostatic pressure at a depth of 0.5m in an alcohol solution?\n"
        "               The alcohol's density is 790 kg/m^3.\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition1(14, 4);
    outputProblem(opening, question); // output the problem
    cout << opening;

    setOutputPosition1(14, 6);
    cout << outputProblem(opening, question);

    setOutputPosition1(14, 8);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 3950, if user inputs 3950
    //then it is correct and if returns true
    if (answer == 3950)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

//print option menu for Hydrostatic Pressure
void optionMenuHydrostaticPressure()
{
    printGameFrame_small();
    printStars_small();

    setColor(COLOR_YELLOW);
    setOutputPosition1(14, 9);
    cout << "1.";
    setColor(COLOR_WHITE);
    cout << "Exercise - calculator";

    setColor(COLOR_YELLOW);
    setOutputPosition1(14, 14);
    cout << "2.";
    setColor(COLOR_WHITE);
    cout << "Quiz";

    while (true)
    {
        switch (_getch())
        {
        case '1':
        {
            ClearScreen();
            hydrostaticPressure();
            break;
        }
        case '2':
        {
            ClearScreen();
            QuizHydrostaticPressure();
            break;
        }
        }
    }
}

//Print calculator + exercise for Hydrostatic Pressure
void hydrostaticPressure()
{
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition1(14, 4);
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    string symbol;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 4);
    cin >> symbol; // input symbol to answer the question

    int correctExerciseCount = 0; // count user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not


    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        setOutputPosition1(14, 4);
        cout << "                                                                ";
        setOutputPosition1(14, 4);
        cout << "Please enter a valid input!" << endl;
        setOutputPosition1(78, 4);
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        setOutputPosition1(14, 6);
        cout << "Enter the unit we are searching (h/P)" << endl;

        setOutputPosition1(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;
        while (symbol != "h" && symbol != "P") // check if input is valid
        {
            setOutputPosition1(14, 6);
            cout << "                                                                ";
            setOutputPosition1(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition1(78, 6);
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculatorHydrostaticPressure(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneHP(isCorrect); // check if problem 1 is answered correctly
        if (isCorrect == true)
        {
            setOutputPosition1(14, 13);
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            setOutputPosition1(14, 13);
            cout << "That's wrong! ";
        }
        exerciseOneChecker = 1;
    }

    setOutputPosition1(14, 18);
    cout << "Would you like to go to the next exercise? (y/n)" << endl;

    setOutputPosition1(71, 18);
    setColor(COLOR_YELLOW);
    cin >> symbol; // input symbol to answer the question
    setColor(COLOR_WHITE);

    while (symbol != "y" && symbol != "n") // check if input is valid
    {
        setOutputPosition1(14, 18);
        cout << "                                                ";

        setOutputPosition1(14, 18);
        cout << "Please enter a valid input!" << endl;

        setColor(COLOR_YELLOW);
        cin >> symbol;
        setColor(COLOR_WHITE);
    }
    if (symbol == "n")
    {

    }
    else if (symbol == "y") // output problem 2
    {
        exerciseCounter++;
        exerciseTwoHP(isCorrect); // check if problem 2 is answered correctly
        if (isCorrect == true)
        {
            setOutputPosition1(14, 13);
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            setOutputPosition1(14, 13);
            cout << "That's wrong! ";
        }

    }

    setOutputPosition1(14, 18);
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;

    setOutputPosition1(78, 18);
    setColor(COLOR_YELLOW);
    cin >> symbol; // input symbol to answer the question
    setOutputPosition1(14, 4);
    setColor(COLOR_WHITE);

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        setOutputPosition1(14, 18);
        cout << "                                                               ";

        setOutputPosition1(14, 18);
        cout << "Please enter a valid input!" << endl;

        setOutputPosition1(78, 6);
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        ClearScreen();
        printGameFrame_Exercises();
        printStars_Exercises();

        setOutputPosition1(14, 6);
        cout << "Enter the unit we are searching (h/P)" << endl;
        setOutputPosition1(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;
        while (symbol != "h" && symbol != "P") // check if input is valid
        {
            setOutputPosition1(14, 6);
            cout << "                                                                ";
            setOutputPosition1(14, 6);
            cout << "Please enter a valid input!" << endl;

            setOutputPosition1(78, 6);
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculatorHydrostaticPressure(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoHP(isCorrect); // check if problem 2 is answered correctly
            if (isCorrect == true)
            {
                setOutputPosition1(14, 13);
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                setOutputPosition1(14, 13);
                cout << "That's wrong! ";
            }
        }
        // if problem 1 is not already done, output problem 1
        if (exerciseCounter < 2 && exerciseOneChecker == 0)
        {
            exerciseOneHP(isCorrect); // check if problem 1 is answered correctly
            if (isCorrect == true)
            {
                setOutputPosition1(14, 13);
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                setOutputPosition1(14, 13);
                cout << "That's wrong! ";
            }
            else // output this if user has done problem 1 and problem 2
            {
                ClearScreen();
                printGameFrame_Exercises();
                printStars_Exercises();

                setOutputPosition1(14, 6);
                cout << "Oops! You've finished all of the exercises!" << endl;
            }
        }

        // output user's score
        setOutputPosition1(14, 8);
        cout << "You got " << correctExerciseCount << " out of 2 points!";


        setColor(COLOR_YELLOW);
        returnToMainMenu1(14, 10);
    }
}