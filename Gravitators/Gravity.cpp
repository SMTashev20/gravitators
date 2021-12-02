#include <iostream>
#include "MainFunctions.h"
#include "Gravity.h"

using namespace std;

void gravityCalculator()
{
    double mass; // declare variable
    string opening;

    // enter value for m
    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);

    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "G = m * g") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "G = " << mass << " * " << 10 << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "G = " << 10 * mass << " N" << endl;
}

void massCalculator()
{
    double gravityForce; // declare variable
    string opening;

    // enter value for G
    cout << "Enter the gravity force of the object (G):" << endl;
    inputNumber(gravityForce);

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "m = G / g") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "m = " << gravityForce << " / " << 10 << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "m = " << gravityForce / 10 << " kg" << endl;
}

// check if user wants to calculate gravity or mass
void gravityMassCalculator(string symbol)
{
    if (symbol == "G")
    {
        gravityCalculator();
    }
    else
    {
        massCalculator();
    }
}

// problem 1
void exerciseOneGravity(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "Estimate the gravitational force of a sumo wrestler with mass 220 kg.\ns = ?m (example input: 122)\n";

    outputProblem(opening, question); // output the problem
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;
    // the right answer is 2200, if user inputs 2200
    // then it is correct and if returns true
    if (answer == 2200)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwoGravity(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "Evaluate the mass of a spherical steel ball with a magnitude of gravitational force 50 N.\nm = ? kg(example input : 122)\n";

    outputProblem(opening, question);  // output the problem
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;
    // the right answer is 5, if user inputs 5
    // then it is correct and if returns true
    if (answer == 5)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}


int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    string symbol;
    cin >> symbol; // input symbol to answer the question

    int correctExerciseCount = 0; // count user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not

    while (symbol != "c" && symbol != "p")  // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c")  // user is using calculator
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> symbol;
        while (symbol != "G" && symbol != "m") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        gravityMassCalculator(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneChecker = 1;
        exerciseOneGravity(isCorrect); // check if problem 1 is answered correctly
        if (isCorrect == true)
        {
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            cout << "That's wrong! ";
        }
    }

    cout << "Would you like to go to the next exercise? (y/n)" << endl;
    cin >> symbol; // input symbol to answer the question
    while (symbol != "y" && symbol != "n") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "n")
    {
    }
    else if (symbol == "y") // output problem 2
    {
        exerciseCounter++;
        exerciseTwoGravity(isCorrect); // check if problem 2 is answered correctly
        if (isCorrect == true)
        {
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            cout << "That's wrong! ";
        }
    }

    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> symbol; // input symbol to answer the question

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> symbol;
        while (symbol != "G" && symbol != "m") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        gravityMassCalculator(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoGravity(isCorrect); // check if problem 2 is answered correctly
            if (isCorrect == true)
            {
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                cout << "That's wrong! ";
            }
        }
        // if problem 1 is not already done, output problem 1
        else if (exerciseCounter < 2 && exerciseOneChecker == 0)
        {
            exerciseOneGravity(isCorrect); // check if problem 1 is answered correctly
            if (isCorrect == true)
            {
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                cout << "That's wrong! ";
            }
        }
        else // output this if user has done problem 1 and problem 2
        {
            cout << "Oops! You've finished all of the exercises!" << endl;
        }
    }

    // output user's score
    cout << "You got " << correctExerciseCount << " out of 2 points!";
}