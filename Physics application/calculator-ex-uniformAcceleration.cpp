#include <iostream>
using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

// check if input is valid
string outputErrorMessage()
{
    return "Please enter a valid input!\n";
}

void inputNumber(double& number)
{
    cin >> number;

    while (cin.fail())
    {
        ignoreUserInput();
        cout << outputErrorMessage();
        cin >> number;
    }
}

string outputFormula(string& openingSentence, string formula)
{
    openingSentence = "Our formula is ";
    return formula;
}

void distanceCalculator()
{
    double initialVelocity, time, acceleration; // declare variables
    string opening;

    // enter values for Vo, a, t
    cout << "Enter the initial velocity of the body (Vo):" << endl;
    inputNumber(initialVelocity);

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    cout << "Enter the acceleration of the body (a):" << endl;
    inputNumber(acceleration);

    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "s = Vo * t + (a * t * t) / 2") << endl;
    cout << "First we replace the values:" << endl;
    cout << "s = " << initialVelocity << " * " << time << " + " << "(" << acceleration << " * " << time * time << ")" << " / 2" << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "s = " << initialVelocity * time << " + " << (acceleration * time * time) / 2 << endl; // calculate using the formula
    cout << "s = " << initialVelocity * time + (acceleration * time * time) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double initialVelocity, time, acceleration; // declare variables
    string opening;

    // enter values for Vo, a, t
    cout << "Enter the initial velocity of the body (Vo):" << endl;
    inputNumber(initialVelocity);

    cout << "Enter the acceleration of the body (a):" << endl;
    inputNumber(acceleration);

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "V = Vo + a * t") << endl;
    cout << "First we replace the values:" << endl;
    cout << "V = " << initialVelocity << " + " << acceleration << " * " << time << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "V = " << initialVelocity << " + " << acceleration * time << endl; // calculate using the formula
    cout << "V = " << initialVelocity + acceleration * time << " m/s" << endl;
}

void velocityDistanceCalculator(string symbol) // check if user wants to calculate velosity or distance
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

string outputProblem(string& openingSentence, string problem)
{
    openingSentence = "Now, try to solve this problem!\n";
    return problem;
}

// problem 1
void exerciseOne(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A car was driving with speed of 5m/s. The car accelerated at 10 m/s2 for 12 seconds.\n"
        "What is the position of the car at the end of the 12 seconds? s = ?m (example input: 122)\n"; 

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cout << "Hint: 15cm = 0,15m, F = m * g and g = 10" << endl;
    cin >> answer;
    if (answer == 780) // the right answer is 780, if user inputs 780, then it is correct and if returns true
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwo(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "With an initial velocity of 36 km/h, a car accelerated at 8 m/s2 for 10 seconds.\n"
        "What is the position of the car at the end of the 10 seconds? s = ?m (example input: 122)\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cout << "Hint: 36 km/h = 10 m/s\n" << endl;
    cin >> answer;
    if (answer == 500) // the right answer is 500, if user inputs 500, then it is correct and if returns true
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
        exerciseOne(isCorrect); // check if problem 1 is answered correctly
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
        exerciseTwo(isCorrect); // check if problem 2 is answered correctly
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
        if (exerciseCounter < 2 && exerciseOneChecker != 0) // if problem 1 is already done, output problem 2
        {
            exerciseTwo(isCorrect); // check if problem 2 is answered correctly
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
        if (exerciseCounter < 2 && exerciseOneChecker == 0) // if problem 1 is not already done, output problem 1
        {
            exerciseOne(isCorrect); // check if problem 1 is answered correctly
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
            cout << "Oops! You've done all of the exercises!" << endl;
        }
    }

    cout << "You got " << correctExerciseCount << " out of 2 points!"; // output user's score
}
