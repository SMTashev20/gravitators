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





int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    char sym;
    cin >> sym;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseCounter = 0;

    while (sym != 'c' && sym != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == 'c')
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> sym;
        gravityMassCalculator(sym);
    }
    else if (sym == 'p')
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
    }





    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> sym;

    while (sym != 'c' && sym != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == 'c')
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> sym;
        gravityMassCalculator(sym);
    }

    cout << "You got " << correctExerciseCount << " out of 2 points!";
}