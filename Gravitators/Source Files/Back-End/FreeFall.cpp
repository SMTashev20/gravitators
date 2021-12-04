#include <iostream>

#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Back-End/FreeFall.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Front-End/MainFront-EndFunctions.h"
#include "../../Header Files/Back-End/Quiz.h"

using namespace std;

void distanceCalculatorFreeFall()
{
    double time; // declare variable
    string opening;

    // enter value for t
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the time interval (t):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition(78, 8);
    inputNumber(time, 14, 8);

    setOutputPosition(14, 10);
    setColor(COLOR_WHITE);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "s = (g * t * t ) / 2") << endl;

    setOutputPosition(14, 12);
    cout << "First we replace the values:" << endl;  // calculate using the formula

    setOutputPosition(14, 13);
    cout << "s = " << "(" << 10 << " * ";

    setOutputPosition(14, 14);
    cout << time << " * " << time << ")" << " / 2" << endl;

    setOutputPosition(14, 15);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition(14, 16);
    cout << "s = " << (10 * time * time) / 2 << " m" << endl;
}

void velocityCalculatorFreeFall()
{
    double time; // declare variable
    string opening;

    // enter value for t
    setOutputPosition(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the time interval (t):" << endl;

    setOutputPosition(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(time, 14, 8);

    setOutputPosition(14, 10);
    setColor(COLOR_WHITE);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "V = g * t") << endl;

    setOutputPosition(14, 12);
    cout << "First we replace the values:" << endl;  // calculate using the formula

    setOutputPosition(14, 13);
    cout << "V = " << 10 << " * " << time << endl;

    setOutputPosition(14, 14);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition(14, 15);
    cout << "V = " << 10 * time << " m/s" << endl;
}

// check if user wants to calculate velosity or distance
void velocityDistanceCalculatorFreeFall(string symbol)
{
    if (symbol == "s")
    {
        distanceCalculatorFreeFall();
    }
    else
    {
        velocityCalculatorFreeFall();
    }
}

// problem 1
void exerciseOneFreeFall(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A construction worker accidentally drops a brick from a high scaffold. If \n"
        "              you know g is ~10 m/s2 and the brick falls 4 sec, how far does the brick fall?\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question);
    cout << opening << '\n';

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question); // output the problem

    setOutputPosition(14, 8);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
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
        "               velocity of the stone after these 6 seconds? s = ?m (example input: 122)\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    outputProblem(opening, question);
    cout << opening << '\n';

    setOutputPosition(14, 6);
    cout << outputProblem(opening, question); // output the problem

    setOutputPosition(14, 8);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
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

void optionMenuFreeFall()
{
    printGameFrame_small();
    printStars_small();

    setColor(COLOR_YELLOW);
    setOutputPosition(14, 9);
    cout << "1.";
    setColor(COLOR_WHITE);
    cout << "Exercise - calculator";

    setColor(COLOR_YELLOW);
    setOutputPosition(14, 14);
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
            FreeFall();
            break;
        }
        case '2':
        {
            ClearScreen();
            QuizFreeFall();
            break;
        }
        }
    }
}

void FreeFall()
{
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition(14, 4);
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    setColor(COLOR_YELLOW);
    setOutputPosition(78, 4);
    string symbol;
    cin >> symbol; // input symbol to answer the question

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

    setColor(COLOR_WHITE);

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
        velocityDistanceCalculatorFreeFall(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneFreeFall (isCorrect); // check if problem 1 is answered correctly
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
    cout << "Would you like to do the next exercise? (y/n)" << endl;

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
        exerciseTwoFreeFall(isCorrect); // check if problem 2 is answered correctly
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
        velocityDistanceCalculatorFreeFall(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 and exerciseOneChecker != 0)
        {
            exerciseTwoFreeFall(isCorrect); // check if problem 2 is answered correctly
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
        else if (exerciseCounter < 2 and exerciseOneChecker == 0)
        {
            exerciseOneFreeFall(isCorrect); // check if problem 1 is answered correctly
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