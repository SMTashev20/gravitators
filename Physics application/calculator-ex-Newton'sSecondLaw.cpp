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

void forceCalculator()
{
    double acceleration; // declare variables
    double mass;
    string opening;
    // F = m * a

    // enter values for m and a
    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);
    cout << "Enter the acceleration of the object (a):" << endl;
    inputNumber(acceleration);

    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "F = m * a") << endl;
    cout << "First we replace the values:" << endl;
    cout << "F = " << mass << " * " << acceleration << endl; // calculate using the formula
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << mass * acceleration << " N" << endl;
}

void accelerationCalculator()
{
    double force; // declare variables
    double mass;
    string opening;
    // a = F / m

    // enter values for F and m
    cout << "Enter the force of the object (F):" << endl;
    inputNumber(force);
    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);

    while (mass == 0) // check for dividing by zero
    {
        cout << "You can't devide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(mass);
    }

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "a = F / m") << endl;
    cout << "First we replace the values:" << endl;
    cout << "a = " << force << " / " << mass << endl; // calculate using the formula
    cout << "Then we calculate our eqalation:" << endl;
    cout << "a = " << force / mass << " m/s^2" << endl;
}

void forceAccelerationCalculator(string symbol) // check if user wants to calculate force or acceleration
{
    if (symbol == "F")
    {
        forceCalculator();
    }
    else
    {
        accelerationCalculator();
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
    string question = "A block with a mass of 4kg is pushed across a frictionless surface with a force of 8N for a time of 3s. \n"
        "v = ? m / s(example input : 122)";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cout << "Hint: 15cm = 0,15m" << endl;
    cin >> answer;
    if (answer == 6) // the right answer is 6, if user inputs 6, then it is correct and if returns
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
    string question = "A force of 15N is applied to a 5kg object in space.\n"
        "What is the acceleration of the object?\n";

    outputProblem(opening, question); // output the problem
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;

    if (answer == 3) // the right answer is 3, if user inputs 3, then it is correct and if returns true
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
    cout << "Would you like to use the calculator or solve a problem? (c/p) " << endl;
    string symbol;
    cin >> symbol; // input symbol to answer the question

    int correctExerciseCount = 0; // count user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input! " << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (F/a) " << endl;
        cin >> symbol;
        while (symbol != "F" && symbol != "a") // check if input is valid
        {
            cout << "Please enter a valid input! " << endl;
            cin >> symbol;
        }
        forceAccelerationCalculator(symbol);
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

    cout << "Would you like to go to the next exercise? (y/n) " << endl;
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


    cout << "Would you like to use the calculator or solve a problem? (c/p) " << endl;
    cin >> symbol; // input symbol to answer the question

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (F/a)" << endl;
        cin >> symbol;
        while (symbol != "F" && symbol != "a") // check if input is valid
        {
            cout << "Please enter a valid input! " << endl;
            cin >> symbol;
        }
        forceAccelerationCalculator(symbol);
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
            cout << "Oops! You've finished all of the exercises!" << endl;
        }
    }


    cout << "You got " << correctExerciseCount << " out of 2 points!"; // output user's score
}