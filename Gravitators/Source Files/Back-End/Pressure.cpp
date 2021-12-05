#include <iostream>

//include header files  
#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Back-End/Pressure.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/Quiz.h"

using namespace std;

//calculator for force
void forceCalculatorPressure()
{
    double pressure; // declare variables
    double area;
    string opening;
    //F = P * S

    // enter values for P and S
    setOutputPosition1(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the pressure of the object (P):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 8);
    inputNumber(pressure, 14, 8);

    setOutputPosition1(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the area of the object (S):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 10);
    inputNumber(area, 14, 10);
    setColor(COLOR_WHITE);

    setOutputPosition1(14, 12);
    outputFormula(opening, ""); // output formula
    cout << opening;

    setOutputPosition1(14, 13);
    cout << outputFormula(opening, "F = P * S") << endl;

    setOutputPosition1(14, 14);
    cout << "First we replace the values:" << endl;  // calculate using the formula
    
    setOutputPosition1(14, 15);
    cout << "F = " << pressure << " * " << area << endl;

    setOutputPosition1(14, 16);
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << pressure * area << " N" << endl;
}

//calculator for Pressure
void pressureCalculatorPressure()
{
    double force; // declare variables
    double area;
    string opening;
    // P = F / S

    // enter values for F and S
    setOutputPosition1(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the force of the object (F):" << endl;

    setOutputPosition1(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(force, 14, 8);

    setOutputPosition1(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the area of the object (S):" << endl;

    setOutputPosition1(78, 10);
    setColor(COLOR_YELLOW);
    inputNumber(area, 14, 10);
    setColor(COLOR_WHITE);

    while (area == 0) // check for dividing by zero
    {
        setOutputPosition1(14, 10);
        cout << "You can't divide by 0! Enter new value!" << endl;
        setColor(COLOR_YELLOW);

        setOutputPosition1(78, 10);
        inputNumber(area, 14, 10);
        setColor(COLOR_WHITE);
    }

    setOutputPosition1(14, 12);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "a = F / m") << endl;

    setOutputPosition1(14, 13);
    cout << "First we replace the values:" << endl; // print detailed solution with values set by user

    setOutputPosition1(14, 14);
    cout << "P = " << force << " / " << area << endl;

    setOutputPosition1(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition1(14, 16);
    cout << "P = " << force / area << " Pa" << endl;
}

// check if user wants to calculate force or pressure
void forcePressureCalculatorPressure(string symbol)
{
    if (symbol == "F")
    {
        forceCalculatorPressure();
    }
    else
    {
        pressureCalculatorPressure();
    }
}

// problem 1
void exerciseOnePressure(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "If your mass is 80kg and \"A\" of your feet is 0.2 m^2,\n"
        "             what pressure would you exert on the ground? P = ?N (example input: 122)\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition1(14, 4);
    outputProblem(opening, question);
    cout << opening;

    setOutputPosition1(14, 6);
    cout << outputProblem(opening, question); // output the problem
    setOutputPosition1(14, 8);
    cout << "Hints: 15cm = 0,15m, F = m * g and g = 10" << endl;

    setOutputPosition1(14, 9);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 4000, if user inputs 4000
    // then it is correct and if returns true
    if (answer == 4000)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwoPressure(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A force of 15N is applied to a 5kg object in space. \n"
        "               What is the acceleration of the object?\n";

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
    // the right answer is 3, if user inputs 3
    // then it is correct and if returns true
    if (answer == 3)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

//option menu 
void optionMenuPressure()
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
            Pressure();
            break;
        }
        case '2':
        {
            ClearScreen();
            QuizPressure();
            break;
        }
        }
    }
}

//Calculator + problems
void Pressure()
{
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition1(14, 4);
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    string symbol;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 4);
    cin >> symbol; // input symbol to answer the question

    int correctExerciseCount = 0; // counts user's points
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

    setColor(COLOR_WHITE);

    if (symbol == "c") // user is using calculator
    {
        setOutputPosition1(14, 6);
        cout << "Enter the unit we are searching (F/S)" << endl;

        setOutputPosition1(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;

        while (symbol != "F" && symbol != "S") // check if input is valid
        {
            setOutputPosition1(14, 6);
            cout << "                                                                ";
            setOutputPosition1(14, 6);
            cout << "Please enter a valid input!" << endl;

            setOutputPosition1(78, 6);
            cin >> symbol;
        }
        forcePressureCalculatorPressure(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOnePressure(isCorrect); // check if problem 1 is answered correctly
        if (isCorrect == true)
        {
            setOutputPosition1(14, 10);
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            setOutputPosition1(14, 10);
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
        exerciseTwoPressure(isCorrect); // check if problem 2 is answered correctly
        if (isCorrect == true)
        {
            setOutputPosition1(14, 10);
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            setOutputPosition1(14, 10);
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
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        ClearScreen();
        printGameFrame_Exercises();
        printStars_Exercises();

        setOutputPosition1(14, 6);
        cout << "Enter the unit we are searching (F/a)" << endl;

        setOutputPosition1(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;
        while (symbol != "F" && symbol != "a") // check if input is valid
        {
            setOutputPosition1(14, 6);
            cout << "                                                                ";
            setOutputPosition1(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition1(78, 6);
            cin >> symbol;
        }
        forcePressureCalculatorPressure(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoPressure(isCorrect); // check if problem 2 is answered correctly
            if (isCorrect == true)
            {
                setOutputPosition1(14, 10);
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                setOutputPosition1(14, 10);
                cout << "That's wrong! ";
            }
        }
        // if problem 1 is not already done, output problem 1
        if (exerciseCounter < 2 && exerciseOneChecker == 0)
        {
            exerciseOnePressure(isCorrect); // check if problem 1 is answered correctly
            if (isCorrect == true)
            {
                setOutputPosition1(14, 10);
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                setOutputPosition1(14, 10);
                cout << "That's wrong! ";
            }
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