#include <iostream>
#include "MainFunctions.h"
#include "Density.h"

using namespace std;

void densityCalculator()
{
    double mass; // declare variables
    double volume;
    string opening;
    // p = m / V

    // enter values for m and a
    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);
    cout << "Enter the volume of the object (V):" << endl;
    inputNumber(volume);

    while (volume == 0) // check for dividing by zero
    {
        cout << "You can't divide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(volume);
    }
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "p = m / V") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "p = " << mass << " / " << volume << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "p = " << mass / volume << " kg/m2" << endl;
}

void massCalculator()
{
    double density; // declare variables
    double volume;
    string opening;
    // p = m / V

    // enter values for F and m
    cout << "Enter the density of the object (p):" << endl;
    inputNumber(density);
    cout << "Enter the volume of the object (V):" << endl;
    inputNumber(volume);

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "m = p * V") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "m = " << density << " * " << volume << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "m = " << density * volume << " kg" << endl;
}

// check if user wants to calculate force or acceleration
void densityMassCalculator(string symbol)
{
    if (symbol == "p")
    {
        densityCalculator();
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
    string question = "If the volume of a metal shpere of 200g mass is 20 cm3 what is the density of the metal? s = ?m (example input: 122)\n";

    outputProblem(opening, question);  // output the problem
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;
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
void exerciseTwoHP(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "You have a rock with a volume of 15cm3 and a mass of 45 g. What is its density?\n";

    outputProblem(opening, question); // output the problem
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;
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


int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    string sym;
    cin >> sym; // input symbol to answer the question

    int correctExerciseCount = 0; // count user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not

    while (sym != "c" && sym != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (p/m)" << endl;
        cin >> sym;
        while (sym != "p" && sym != "m") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> sym;
        }
        densityMassCalculator(sym);
    }
    else if (sym == "p") // output problem 1
    {
        exerciseCounter++;
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
        exerciseOneChecker = 1;
    }

    cout << "Would you like to go to the next exercise? (y/n)" << endl;
    cin >> sym; // input symbol to answer the question
    while (sym != "y" && sym != "n") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "n")
    {
    }
    else if (sym == "y") // output problem 2
    {
        exerciseCounter++;
        exerciseTwoHP(isCorrect); // check if problem 2 is answered correctly
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
    cin >> sym; // input symbol to answer the question

    while (sym != "c" && sym != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> sym;
        while (sym != "G" && sym != "m") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> sym;
        }
        densityMassCalculator(sym);
    }
    else if (sym == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoHP(isCorrect); // check if problem 2 is answered correctly
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
        if (exerciseCounter < 2 && exerciseOneChecker == 0)
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