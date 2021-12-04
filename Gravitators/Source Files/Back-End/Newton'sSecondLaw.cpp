#include <iostream>

#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Back-End/Newton'sSecondLaw.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Front-End/MainFront-EndFunctions.h"

using namespace std;

void forceCalculatorNewtonSSecondLaw()
{
    double acceleration; // declare variables
    double mass;
    string opening;
    // F = m * a

    // enter values for m and a
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the mass of the object (m):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 8);
    inputNumber(mass, 14, 8);

    setOutputPosition(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the acceleration of the object (a):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 10);
    inputNumber(acceleration, 14, 10);
    setColor(COLOR_WHITE);

    setOutputPosition(14, 12);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "F = m * a") << endl;

    setOutputPosition(14, 13);
    cout << "First we replace the values:" << endl; // calculate using the formula
    
    setOutputPosition(14, 14);
    cout << "F = " << mass << " * " << acceleration << endl;

    setOutputPosition(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition(14, 16);
    cout << "F = " << mass * acceleration << " N" << endl;
}

void accelerationCalculatorNewtonSSecondLaw()
{
    double force; // declare variables
    double mass;
    string opening;
    // a = F / m

    // enter values for F and m
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the force of the object (F):" << endl;


    setOutputPosition(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(force, 14, 8);

    setOutputPosition(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);

    while (mass == 0) // check for dividing by zero
    {
        setOutputPosition(14, 10);
        cout << "You can't divide by 0! Enter new value!" << endl;
        setColor(COLOR_YELLOW);

        setOutputPosition(78, 10);
        inputNumber(mass);
        setColor(COLOR_WHITE);
    }

    setOutputPosition(14, 12);
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "a = F / m") << endl;

    setOutputPosition(14, 13);
    cout << "First we replace the values:" << endl; // calculate using the formula

    setOutputPosition(14, 14);
    cout << "a = " << force << " / " << mass << endl;

    setOutputPosition(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition(14, 16);
    cout << "a = " << force / mass << " m/s^2" << endl;
}

// check if user wants to calculate force or acceleration
void forceAccelerationCalculatorNewtonSSecondLaw(string symbol)
{
    if (symbol == "F")
    {
        forceCalculatorNewtonSSecondLaw();
    }
    else
    {
        accelerationCalculatorNewtonSSecondLaw();
    }
}


// problem 1
void exerciseOneNSL(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A 4kg block is pushed across a frictionless surface with a force of 8N for 3s. \n"
        "             v = ? m / s(example input : 122)";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question);
    cout << opening;

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question); // output the problem
    setOutputPosition(14, 8);
    cout << "Hint: 15cm = 0,15m" << endl;

    setOutputPosition(14, 9);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 6, if user inputs 6
    // then it is correct and if returns true
    if (answer == 6)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }


}

// problem 2
void exerciseTwoNSL(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A force of 15N is applied to a 5kg object in space.\n"
        "               What is the acceleration of the object?\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question); // output the problem
    cout << opening;

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question);

    setOutputPosition(14, 8);
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


void newtonSecondLaw()
{
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    cout << "Would you like to use the calculator or solve a problem? (c/p) " << endl;
    string symbol;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 4);
    cin >> symbol; // input symbol to answer the question
    setColor(COLOR_WHITE);

    int correctExerciseCount = 0; // count user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        setOutputPosition(14, 4);
        cout << "                                                                ";
        setOutputPosition(14, 4);
        cout << "Please enter a valid input!" << endl;
        setOutputPosition(78, 4);
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        setOutputPosition(14, 6);
        cout << "Enter the unit we are searching (F/a) " << endl;

        setOutputPosition(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;
        while (symbol != "F" && symbol != "a") // check if input is valid
        {
            setOutputPosition(14, 6);
            cout << "                                                                ";
            setOutputPosition(14, 6);
            cout << "Please enter a valid input!" << endl;

            setColor(COLOR_YELLOW);
            cin >> symbol;
            setColor(COLOR_WHITE);
        }
        forceAccelerationCalculatorNewtonSSecondLaw(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneNSL(isCorrect); // check if problem 1 is answered correctly
        if (isCorrect == true)
        {
            setOutputPosition(14, 10);
            cout << "That's correct! ";
            correctExerciseCount++;

        }
        else if (isCorrect == false)
        {
            setOutputPosition(14, 10);
            cout << "That's wrong! ";
        }
        exerciseOneChecker = 1;
    }

    setOutputPosition(14, 18);
    cout << "Would you like to go to the next exercise? (y/n) " << endl;
   
    setOutputPosition(71, 18);
    setColor(COLOR_YELLOW);
    cin >> symbol; // input symbol to answer the question
    setColor(COLOR_WHITE);

    while (symbol != "y" && symbol != "n") // check if input is valid
    {
        setOutputPosition(14, 6);
        cout << "                                                                ";
        setOutputPosition(14, 6);
        cout << "Please enter a valid input!" << endl;
        setOutputPosition(78, 6);
        cin >> symbol;
    }
    if (symbol == "n")
    {
    }
    else if (symbol == "y") // output problem 2
    {
        exerciseCounter++;
        exerciseTwoNSL(isCorrect); // check if problem 2 is answered correctly
        if (isCorrect == true)
        {
            setOutputPosition(14, 10);
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            setOutputPosition(14, 10);
            cout << "That's wrong! ";
        }

    }

    setOutputPosition(14, 18);
    cout << "Would you like to use the calculator or solve a problem? (c/p) " << endl;
    setOutputPosition(78, 18);
    setColor(COLOR_YELLOW);
    cin >> symbol; // input symbol to answer the question
    setOutputPosition(14, 4);
    setColor(COLOR_WHITE);

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        setOutputPosition(14, 18);
        cout << "                                                               ";

        setOutputPosition(14, 18);
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        ClearScreen();
        printGameFrame_Exercises();
        printStars_Exercises();

        setOutputPosition(14, 6);
        cout << "Enter the unit we are searching (F/a)" << endl;

        setOutputPosition(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;

        while (symbol != "F" && symbol != "a") // check if input is valid
        {
            setOutputPosition(14, 6);
            cout << "                                                                ";
            setOutputPosition(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition(78, 6);
            cin >> symbol;
        }
        forceAccelerationCalculatorNewtonSSecondLaw(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoNSL(isCorrect); // check if problem 2 is answered correctly
            if (isCorrect == true)
            {
                setOutputPosition(14, 10);
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                setOutputPosition(14, 10);
                cout << "That's wrong! ";
            }
        }
        // if problem 1 is not already done, output problem 1
        if (exerciseCounter < 2 && exerciseOneChecker == 0)
        {
            exerciseOneNSL(isCorrect); // check if problem 1 is answered correctly
            if (isCorrect == true)
            {
                setOutputPosition(14, 10);
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                setOutputPosition(14, 10);
                cout << "That's wrong! ";
            }
        }
        else // output this if user has done problem 1 and problem 2
        {
            ClearScreen();
            printGameFrame_Exercises();
            printStars_Exercises();

            setOutputPosition(14, 6);
            cout << "Oops! You've finished all of the exercises!" << endl;
        }
    }

    // output user's score
    setOutputPosition(14, 8);
    cout << "You got " << correctExerciseCount << " out of 2 points!";

    setColor(COLOR_BLACK);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}