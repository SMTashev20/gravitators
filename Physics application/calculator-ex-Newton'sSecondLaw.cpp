#include <iostream>
using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

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
    double acceleration;
    double mass;
    string opening;
    // F = m * a

    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);
    cout << "Enter the acceleration of the object (a):" << endl;
    inputNumber(acceleration);

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "F = m * a") << endl;
    cout << "First we replace the values:" << endl;
    cout << "F = " << mass << " * " << acceleration << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << mass * acceleration << " N" << endl;
}

void accelerationCalculator()
{
    double force;
    double mass;
    string opening;
    // a = F / m

    cout << "Enter the force of the object (F):" << endl;
    inputNumber(force);
    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);

    while (mass == 0)
    {
        cout << "You can't devide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(mass);
    }

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "a = F / m") << endl;
    cout << "First we replace the values:" << endl;
    cout << "a = " << force << " / " << mass << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "a = " << force / mass << " m/s^2" << endl;
}

void forceAccelerationCalculator(string symbol)
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


void exerciseOne(bool& pointAdd)
{
    double answer;
    string opening;
    string question = "A block with a mass of 4kg is pushed across a frictionless surface with a force of 8N for a time of 3s. \n"
        "v = ? m / s(example input : 122)";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question);
    cout << "Hint: 15cm = 0,15m" << endl;
    cin >> answer;
    if (answer == 6)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }


}

void exerciseTwo(bool& pointAdd)
{
    double answer;
    string opening;
    string question = "A force of 15N is applied to a 5kg object in space.\n"
        "What is the acceleration of the object?\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;

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
    cout << "Would you like to use the calculator or solve a problem? (c/p) " << endl;
    string symbol;
    cin >> symbol;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseCounter = 0;
    bool exerciseOneChecker = 0;

    while (symbol != "c" && symbol != "p")
    {
        cout << "Please enter a valid input! " << endl;
        cin >> symbol;
    }
    if (symbol == "c")
    {
        cout << "Enter the unit we are searching (F/a) " << endl;
        cin >> symbol;
        while (symbol != "F" && symbol != "a")
        {
            cout << "Please enter a valid input! " << endl;
            cin >> symbol;
        }
        forceAccelerationCalculator(symbol);
    }
    else if (symbol == "p")
    {
        exerciseCounter++;
        exerciseOne(isCorrect);
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
    cin >> symbol;
    while (symbol != "y" && symbol != "n")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "n")
    {

    }
    else if (symbol == "y")
    {
        exerciseCounter++;
        exerciseTwo(isCorrect);
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
    cin >> symbol;

    while (symbol != "c" && symbol != "p")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c")
    {
        cout << "Enter the unit we are searching (F/a)" << endl;
        cin >> symbol;
        while (symbol != "F" && symbol != "a")
        {
            cout << "Please enter a valid input! " << endl;
            cin >> symbol;
        }
        forceAccelerationCalculator(symbol);
    }
    else if (symbol == "p")
    {
        if (exerciseCounter < 2 && exerciseOneChecker != 0)
        {
            exerciseTwo(isCorrect);
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
        if (exerciseCounter < 2 && exerciseOneChecker == 0)
        {
            exerciseOne(isCorrect);
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
        else
        {
            cout << "Oops! You've finished all of the exercises!" << endl;
        }
    }


    cout << "You got " << correctExerciseCount << " out of 2 points!";
}