#include <iostream>
#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Back-End/uniformAcceleration.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/Quiz.h"
#include "../../Header Files/Front-End/TowerOfPizza.h"

using namespace std;

void distanceCalculatorUniformAcceleration()
{
    double initialVelocity, time, acceleration; // declare variables
    string opening;

    // enter values for Vo, a, t
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the initial velocity of the body (Vo):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 8);
    inputNumber(initialVelocity, 14, 8);

    setOutputPosition(14, 9);
    setColor(COLOR_WHITE);
    cout << "Enter the time interval (t):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 9);
    inputNumber(time, 14, 9);

    setColor(COLOR_WHITE);
    setOutputPosition(14, 10);
    cout << "Enter the acceleration of the body (a):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 10);
    inputNumber(acceleration, 14, 10);

    setColor(COLOR_WHITE);

    setOutputPosition(14, 12);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "s = Vo * t + (a * t * t) / 2") << endl;

    setOutputPosition(14, 13);
    cout << "First we replace the values:" << endl; // print detailed solution with values set by user

    setOutputPosition(14, 14);
    cout << "s = " << initialVelocity << " * " << time << " + ";

    setOutputPosition(14, 15);
    cout << "(" << acceleration << " * " << time * time << ")" << " / 2" << endl;

    setOutputPosition(14, 16);
    cout << "Then we calculate our equation:" << endl;  // calculate using the formula

    setOutputPosition(14, 17);
    cout << "s = " << initialVelocity * time << " + " << (acceleration * time * time) / 2 << endl;

    setOutputPosition(14, 18);
    cout << "s = " << initialVelocity * time + (acceleration * time * time) / 2 << " m" << endl;
}

void velocityCalculatorUniformAcceleration()
{
    double initialVelocity, time, acceleration; // declare variables
    string opening;

    // enter values for Vo, a, t
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the initial velocity of the body (Vo):" << endl;

    setOutputPosition(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(initialVelocity, 14, 8);

    setOutputPosition(14, 9);
    setColor(COLOR_WHITE);
    cout << "Enter the acceleration of the body (a):" << endl;

    setOutputPosition(78, 9);
    setColor(COLOR_YELLOW);
    inputNumber(acceleration, 14, 9);
     setColor(COLOR_WHITE);

     setOutputPosition(14, 10);
    cout << "Enter the time interval (t):" << endl;

    setOutputPosition(78, 10);
    setColor(COLOR_YELLOW);
    inputNumber(time, 14, 10);
    setColor(COLOR_WHITE);

    setOutputPosition(14, 12);
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "V = Vo + a * t") << endl;

    setOutputPosition(14, 13);
    cout << "First we replace the values:" << endl;
    setOutputPosition(14, 14);
    cout << "V = " << initialVelocity << " + " << acceleration << " * " << time << endl;
    setOutputPosition(14, 15);
    cout << "Then we calculate our equation:" << endl;
    // calculate using the formula
    setOutputPosition(14, 16);
    cout << "V = " << initialVelocity << " + " << acceleration * time << endl;
    setOutputPosition(14, 17);
    cout << "V = " << initialVelocity + acceleration * time << " m/s" << endl;
}

// check if user wants to calculate velosity or distance
void velocityDistanceCalculatorUniformAcceleration(string symbol)
{
    if (symbol == "s")
    {
        distanceCalculatorUniformAcceleration();
    }
    else
    {
        velocityCalculatorUniformAcceleration();
    }
}

// problem 1
void exerciseOneUA(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A car was driving at 5m/s and accelerated at 10 m/s^2 for 12 sec.\n"
                     "             What is the position of the car at the end of the 12 sec? s = ?m \n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question);  // output the problem
    cout << opening;

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question);
    setOutputPosition(14, 8);
    cout << "Hint: 15cm = 0,15m, F = m * g and g = 10" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(14, 9);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 780, if user inputs 780
    // then it is correct and if returns true
    if (answer == 780)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwoUA(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "With an initial \"v\" of 36 km/h, a car accelerated at 8 m/s^2 for 10 sec.\n"
        "               What is the position of the car at the end of the 10 sec? s = ?m\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question);
    cout << opening;

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question); // output the problem

    setOutputPosition(14, 8);
    cout << "Hint: 36 km/h = 10 m/s\n" << endl;

    setOutputPosition(14, 9);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 500, if user inputs 500
    // then it is correct and if returns true
    if (answer == 500)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

void optionMenuUniformAcceleration()
{
    printGameFrame_small();
    printStars_small();

    setColor(COLOR_YELLOW);
    setOutputPosition(14, 6);
    cout << "1.";
    setColor(COLOR_WHITE);
    cout << "Exercise - calculator";

    setColor(COLOR_YELLOW);
    setOutputPosition(14, 11);
    cout << "2.";
    setColor(COLOR_WHITE);
    cout << "Quiz";

    setColor(COLOR_YELLOW);
    setOutputPosition(14, 16);
    cout << "3.";
    setColor(COLOR_WHITE);
    cout << "Tower of Pisa";
    while (true)
    {
        switch (_getch())
        {
        case '1':
        {
            ClearScreen();
            uniformAcceleration();
            break;
        }
        case '2':
        {
            ClearScreen();
            QuizUniformAcceleration();
            break;
        }
        case '3':
        {
            ClearScreen();
            towerOfPizza();
            break;
        }
        }
    }
}

void uniformAcceleration()
{
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
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
        setColor(COLOR_WHITE);
    }

    if (symbol == "c") // user is using calculator
    {
        setOutputPosition(14, 6);
        cout << "Enter the unit we are searching (V/s)" << endl;

        setOutputPosition(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;

        while (symbol != "V" && symbol != "s") // check if input is valid
        {
            setOutputPosition(14, 6);
            cout << "                                                                ";
            setOutputPosition(14, 6);
            cout << "Please enter a valid input!" << endl;

            setOutputPosition(78, 6);
            cin >> symbol;
        }
        velocityDistanceCalculatorUniformAcceleration(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneUA(isCorrect); // check if problem 1 is answered correctly
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
    cout << "Would you like to go to the next exercise? (y/n)" << endl;

    setOutputPosition(71, 18);
    setColor(COLOR_YELLOW);
    cin >> symbol; // input symbol to answer the question
    setColor(COLOR_WHITE);

    while (symbol != "y" && symbol != "n") // check if input is valid
    {
        setOutputPosition(14, 18);
        cout << "                                                ";

        setOutputPosition(14, 18);
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
        exerciseTwoUA(isCorrect); // check if problem 2 is answered correctly
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
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;

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
        cout << "Enter the unit we are searching (V/s)" << endl;

        setOutputPosition(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;

        while (symbol != "V" && symbol != "s") // check if input is valid
        {
            setOutputPosition(14, 6);
            cout << "                                                                ";
            setOutputPosition(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition(78, 6);
            cin >> symbol;
        }
        velocityDistanceCalculatorUniformAcceleration(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoUA(isCorrect); // check if problem 2 is answered correctly
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
            exerciseOneUA(isCorrect); // check if problem 1 is answered correctly
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
            setOutputPosition(14, 12); // output user's score
            cout << "You got " << correctExerciseCount << " out of 2 points!";
        }
    }

    // output user's score

    setColor(COLOR_BLACK);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
