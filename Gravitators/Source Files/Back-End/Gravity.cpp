//Include header files
#include "../../Header Files/Back-End/MainFunctions.h"
#include "../../Header Files/Back-End/Gravity.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/Quiz.h"

//Insert gravity Calculator
void gravityCalculatorGravity()
{
    double mass; // declare variable
    string opening;

    // enter value for m
    setOutputPosition1(14, 8);
    cout << "Enter the mass of the object (m):" << endl;

    setColor(COLOR_YELLOW);
    setOutputPosition1(78, 8);
    inputNumber(mass, 14, 8);

    setOutputPosition1(14, 10);
    setColor(COLOR_WHITE);
    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "G = m * g") << endl;

    setOutputPosition1(14, 12);
    cout << "First we replace the values:" << endl;  // calculate using the formula

    setOutputPosition1(14, 13);
    cout << "G = " << mass << " * " << 10 << endl;

    setOutputPosition1(14, 14);
    cout << "Then we calculate our equation:" << endl;
    setOutputPosition1(14, 15);
    cout << "G = " << 10 * mass << " N" << endl;
}

//Insert mass Calculator
void massCalculatorGravity()
{
    double gravityForce; // declare variable
    string opening;

    // enter value for G
    setOutputPosition1(14, 8);
    setColor(COLOR_WHITE);
    cout << "Enter the gravity force of the object (G):" << endl;

    setOutputPosition1(78, 8);
    setColor(COLOR_YELLOW);
    inputNumber(gravityForce, 14, 8);

    setOutputPosition1(14, 10);
    setColor(COLOR_WHITE);
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "m = G / g") << endl;

    setOutputPosition1(14, 12);
    cout << "First we replace the values:" << endl;  // calculate using the formula

    setOutputPosition1(14, 13);
    cout << "m = " << gravityForce << " / " << 10 << endl;

    setOutputPosition1(14, 14);
    cout << "Then we calculate our equation:" << endl;

    setOutputPosition1(14, 15);
    cout << "m = " << gravityForce / 10 << " kg" << endl;
}

// check if user wants to calculate gravity or mass
void gravityMassCalculatorGravity(string symbol)
{
    if (symbol == "G")
    {
        gravityCalculatorGravity();
    }
    else
    {
        massCalculatorGravity();
    }
}

// problem 1
void exerciseOneGravity(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "Estimate the gravitational force of a sumo wrestler with mass 220 kg.\n"
                       "             s = ?m (example input: 122)\n";

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
    string question = "Evaluate the mass of a spherical steel ball with a magnitude 50 N.\n"
                        "               m = ? kg(example input : 122)\n";

    ClearScreen();
    printGameFrame_Exercises();
    printStars_Exercises();

    setOutputPosition1(14, 4);
    outputProblem(opening, question);  // output the problem
    cout << opening;

    setOutputPosition1(14, 6);
    cout << outputProblem(opening, question);

    setOutputPosition1(14, 8);
    setColor(COLOR_YELLOW);
    cin >> answer;
    setColor(COLOR_WHITE);
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

//print option menu for Gravity
void optionMenuGravity()
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
            Gravity();
            break;
        }
        case '2':
        {
            ClearScreen();
            QuizGravity();
            break;
        }
        }
    }
}

//print Gravity Calculator + exercise
void Gravity()
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

    while (symbol != "c" && symbol != "p")  // check if input is valid
    {
        setOutputPosition1(14, 4);
        cout << "                                                                ";
        setOutputPosition1(14, 4);
        cout << "Please enter a valid input!" << endl;
        setOutputPosition1(78, 4);
        cin >> symbol;
    }
    if (symbol == "c")  // user is using calculator
    {
        setOutputPosition1(14, 6);
        cout << "Enter the unit we are searching (G/m)" << endl;
        setOutputPosition1(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;
        while (symbol != "G" && symbol != "m") // check if input is valid
        {
            setOutputPosition1(14, 6);
            cout << "                                                                ";
            setOutputPosition1(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition1(78, 6);
            cin >> symbol;
        }
        gravityMassCalculatorGravity(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOneChecker = 1;
        exerciseOneGravity(isCorrect); // check if problem 1 is answered correctly
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
        exerciseTwoGravity(isCorrect); // check if problem 2 is answered correctly
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
        setOutputPosition1(78, 6);
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        ClearScreen();
        printGameFrame_Exercises();
        printStars_Exercises();

        setOutputPosition1(14, 6);
        cout << "Enter the unit we are searching (G/m)" << endl;
        setOutputPosition1(78, 6);
        setColor(COLOR_YELLOW);
        cin >> symbol;
        while (symbol != "G" && symbol != "m") // check if input is valid
        {
            setOutputPosition1(14, 6);
            cout << "                                                                ";
            setOutputPosition1(14, 6);
            cout << "Please enter a valid input!" << endl;
            setOutputPosition1(78, 6);
            cin >> symbol;
        }
        gravityMassCalculatorGravity(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwoGravity(isCorrect); // check if problem 2 is answered correctly
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
        else if (exerciseCounter < 2 && exerciseOneChecker == 0)
        {
            exerciseOneGravity(isCorrect); // check if problem 1 is answered correctly
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