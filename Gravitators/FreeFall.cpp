#include <iostream>

#include "MainFunctions.h"
#include "FreeFall.h"

using namespace std;

void distanceCalculator()
{
    double time; // declare variable
    string opening;

    // enter value for t
    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "s = (g * t * t ) / 2") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "s = " << "(" << 10 << " * ";
    cout << time << " * " << time << ")" << " / 2" << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "s = " << (10 * time * time) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double time; // declare variable
    string opening;

    // enter value for t
    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "V = g * t") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "V = " << 10 << " * " << time << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "V = " << 10 * time << " m/s" << endl;
}

// check if user wants to calculate velosity or distance
void velocityDistanceCalculator(string symbol)
{
    if (symbol == "s")
    {
        distanceCalculator();
    }
    else
    {
        velocityCalculator();
    }
}

// problem 1
void exerciseOneFreeFall(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A construction worker accidentally drops a brick from a high scaffold. If you know the gravitational \n"
        "acceleration g is ~10 m/s2 and the brick falls 4 seconds, how far does the brick fall during this time?\n";

    outputProblem(opening, question);
    cout << opening << '\n';
    cout << outputProblem(opening, question); // output the problem
    cin >> answer;
    // the right answer is 80, if user inputs 80
    // then it is correct and if returns true
    if (answer == 80)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwoFreeFall(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A stone that starts at rest is in free fall for 6 s. What is the \n"
        "velocity of the stone after these 6 seconds? s = ?m (example input: 122)\n";

    outputProblem(opening, question);
    cout << opening << '\n';
    cout << outputProblem(opening, question); // output the problem
    cin >> answer;
    // the right answer is 60, if user inputs 60
    // then it is correct and if returns true
    if (answer == 60)
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

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (V/s)" << endl;
        cin >> symbol;
        while (symbol != "V" && symbol != "s") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneFreeFall (isCorrect); // check if problem 1 is answered correctly
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

    cout << "Would you like to do the next exercise? (y/n)" << endl;
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
        exerciseTwoFreeFall(isCorrect); // check if problem 2 is answered correctly
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
        cout << "Enter the unit we are searching (V/s)" << endl;
        cin >> symbol;
        while (symbol != "V" && symbol != "s") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 and exerciseOneChecker != 0)
        {
            exerciseTwoFreeFall(isCorrect); // check if problem 2 is answered correctly
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
        else if (exerciseCounter < 2 and exerciseOneChecker == 0)
        {
            exerciseOneFreeFall(isCorrect); // check if problem 1 is answered correctly
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