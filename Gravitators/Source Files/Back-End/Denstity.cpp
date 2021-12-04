#include <iostream>

#include "../../Header Files/Back-End/Density.h"
#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Front-End/MainFront-EndFunctions.h"
#include "../../Header Files/Front-End/Frame.h"

using namespace std;

void densityCalculatorDensity()
{
    double mass; // declare variables
    double volume;
    string opening;
    // p = m / V

    // enter values for m and a
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the mass of the object (m):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 8);
    inputNumber(mass);

    setOutputPosition(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the volume of the object (V):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 10);
    inputNumber(volume);

    setColor(COLOR_WHITE);

    while (volume == 0) // check for dividing by zero
    {
        setOutputPosition(14, 10);
        cout << "You can't divide by 0! Enter new value!" << endl;
        setColor(COLOR_YELLOW);

        setOutputPosition(78, 10);
        inputNumber(volume);
        setColor(COLOR_WHITE);
    }

    setOutputPosition(14, 12);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "p = m / V") << endl;

    setOutputPosition(14, 13);
    cout << "First we replace the values:" << endl; // print detailed solution with values set by user

    setOutputPosition(14, 14);
    cout << "p = " << mass << " / " << volume << endl;

    setOutputPosition(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition(14, 16);
    cout << "p = " << mass / volume << " kg/m2" << endl;
}

void massCalculatorDensity()
{
    double density; // declare variables
    double volume;
    string opening;
    // p = m / V

    // enter values for F and m
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the density of the object (p):" << endl;

    setOutputPosition(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(density);

    setOutputPosition(14, 10);
    setColor(COLOR_WHITE);
    cout << "Enter the volume of the object (V):" << endl;

    setOutputPosition(78, 10);
    setColor(COLOR_YELLOW);
    inputNumber(volume);
    setColor(COLOR_WHITE);

    setOutputPosition(14, 12);
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "m = p * V") << endl;

    setOutputPosition(14, 13);
    cout << "First we replace the values:" << endl;    // calculate using values entered by user
    setOutputPosition(14, 14);
    cout << "m = " << density << " * " << volume << endl;
    setOutputPosition(14, 15);
    cout << "Then we calculate our equation:" << endl;
    setOutputPosition(14, 16);
    cout << "m = " << density * volume << " kg" << endl;
}

// check if user wants to calculate force or acceleration
void densityMassCalculatorDensity(string symbol)
{
    if (symbol == "p")
    {
        densityCalculatorDensity();
    }
    else
    {
        massCalculatorDensity();
    }
}

// problem 1
void exerciseOneDensity(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "If the volume of a metal shpere of 200g mass is 20 cm^3,\n"
                      "             what is the density of the metal? s = ?m (example input: 122)\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question);  // output the problem
    cout << opening;

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question);

    setOutputPosition(14, 8);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
    // the right answer is 10, if user inputs 10
    // then it is correct and if returns true
    if (answer == 10)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwoDensity(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "You have a rock with a volume of 15cm3 and a mass of 45 g.\n"
                      "               What is its density?\n";

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


void Density()
{
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    string sym;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 4);
    cin >> sym; // input symbol to answer the question

    int correctExerciseCount = 0; // count user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not

    while (sym != "c" && sym != "p") // check if input is valid
    {
        setOutputPosition(14, 4);
        cout << "                                                                ";
        setOutputPosition(14, 4);
        cout << "Please enter a valid input!" << endl;
        setOutputPosition(78, 4);
        cin >> sym;
    }

    setColor(COLOR_WHITE);

    if (sym == "c") // user is using calculator
    {
        setOutputPosition(14, 6);
        cout << "Enter the unit we are searching (p/m)" << endl;

        setOutputPosition(78, 6);
        setColor(COLOR_YELLOW);
        cin >> sym;

        while (sym != "p" && sym != "m") // check if input is valid
        {
            setOutputPosition(14, 6);
            cout << "                                                                ";
            setOutputPosition(14, 6);
            cout << "Please enter a valid input!" << endl;

            setOutputPosition(78, 6);
            cin >> sym;
        }
        densityMassCalculatorDensity(sym);
    }
    else if (sym == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneDensity(isCorrect); // check if problem 1 is answered correctly
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
    cin >> sym; // input symbol to answer the question
    setColor(COLOR_WHITE);

    while (sym != "y" && sym != "n") // check if input is valid
    {
        setOutputPosition(14, 18);
        cout << "                                                ";

        setOutputPosition(14, 18);
        cout << "Please enter a valid input!" << endl;

        setColor(COLOR_YELLOW);
        cin >> sym;
        setColor(COLOR_WHITE);
    }
    if (sym == "n")
    {
    }
    else if (sym == "y") // output problem 2
    {
        exerciseCounter++;
        exerciseTwoDensity(isCorrect); // check if problem 2 is answered correctly
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
    cin >> sym; // input symbol to answer the question
    setOutputPosition(14, 4);
    setColor(COLOR_WHITE);

    while (sym != "c" && sym != "p") // check if input is valid
    {
        setOutputPosition(14, 18);
        cout << "                                                               ";

        setOutputPosition(14, 18);
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "c") // user is using calculator
    {
        ClearScreen();
        printGameFrame_Exercises();
        printStars_Exercises();

        setOutputPosition(14, 6);
        cout << "Enter the unit we are searching (p/m)" << endl;

        setOutputPosition(78, 6);
        setColor(COLOR_YELLOW);
        cin >> sym;

        while (sym != "p" && sym != "m") // check if input is valid
        {
            setOutputPosition(14, 6);
            cout << "                                                                ";
            setOutputPosition(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition(78, 6);
            cin >> sym;
        }
        densityMassCalculatorDensity(sym);
    }
    else if (sym == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoDensity(isCorrect); // check if problem 2 is answered correctly
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
            exerciseOneDensity(isCorrect); // check if problem 1 is answered correctly
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