#include <iostream>
using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

void inputNumber(double& number)
{
    cin >> number;

    while (cin.fail())
    {
        ignoreUserInput();
        cout << "Please enter a valid input :)\n";
        cout << "Enter a number.\n";
        cin >> number;
    }
}

void gravityCalculator()
{
    double mass;

    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);

    cout << "Our formula is G = m * g" << endl;
    cout << "First we replace the values:" << endl;
    cout << "G = " << mass << " * " << 10 << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "G = " << 10 * mass << " N" << endl;
}

void massCalculator()
{
    double gravityForce;

    cout << "Enter the gravity force of the object (G):" << endl;
    inputNumber(gravityForce);

    cout << "Our formula is m = G / g" << endl;
    cout << "First we replace the values:" << endl;
    cout << "m = " << gravityForce << " / " << 10 << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "m = " << gravityForce / 10 << " kg" << endl;
}

void gravityMassCalculator(char symbol)
{
    if (symbol == 'G')
    {
        gravityCalculator();
    }
    else
    {
        massCalculator();
    }
}

void exerciseOne(bool& pointAdd)
{
    double answer;
    cout << "Try to solve this problem!" << endl;
    cout << "Estimate the gravitational force of a sumo wrestler with mass 220 kg." << endl;
    cout << "G = ?N (example input: 122)" << endl;
    cin >> answer;
    if (answer == 2200)
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
    cout << "Try to solve this problem!" << endl;
    cout << "Evaluate the mass of a spherical steel ball with a magnitude of gravitational force 50 N." << endl;
    cout << "m = ?kg (example input: 122)" << endl;
    cin >> answer;
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
    char symbol;
    cin >> symbol;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseCounter = 0;
    bool exerciseOneChecker = 0;

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> symbol;
        while (symbol != 'G' && symbol != 'm')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        gravityMassCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        exerciseCounter++;
        exerciseOneChecker = 1;
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

    cout << "Would you like to go to the next exercise? (y/n)" << endl;
    cin >> symbol;
    while (symbol != 'y' && symbol != 'n')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == 'n')
    {
    }
    else if (symbol == 'y')
    {
        exerciseCounter++;
        exerciseTwo(isCorrect);
        if (isCorrect == true)
        {
            cout << "That's correct!";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            cout << "That's wrong!";
        }
    }

    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> symbol;

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> symbol;
        while (symbol != 'G' && symbol != 'm')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        gravityMassCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        if (exerciseCounter < 2 and exerciseOneChecker != 0)
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
        else if (exerciseCounter < 2 and exerciseOneChecker == 0)
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
            cout << "Ops! You've done 2 out of two exercises!" << endl;
        }
    }


    cout << "You got " << correctExerciseCount << " out of 2 points!";
}