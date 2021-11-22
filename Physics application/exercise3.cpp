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
    double m;

    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(m);

    cout << "Our formula is G = m * g" << endl;
    cout << "First we replace the values:" << endl;
    cout << "G = " << m << " * " << 10 << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "G = " << 10 * m << " N" << endl;
}

void massCalculator()
{
    double G;

    cout << "Enter the gravity force of the object (G):" << endl;
    inputNumber(G);

    cout << "Our formula is m = G / g" << endl;
    cout << "First we replace the values:" << endl;
    cout << "m = " << G << " / " << 10 << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "m = " << G / 10 << " kg" << endl;
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





int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    char sym;
    cin >> sym;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseChecker = 0;

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