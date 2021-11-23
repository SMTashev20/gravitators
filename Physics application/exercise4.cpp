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

void densityCalculator()
{
    double mass;
    double volume;
    // p = m / V

    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);
    cout << "Enter the volume of the object (V):" << endl;
    inputNumber(volume);

    cout << "Our formula is p = m / V" << endl;
    cout << "First we replace the values:" << endl;
    cout << "p = " << mass << " / " << volume << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "p = " << mass / volume << " kg/m2" << endl;
}

void massCalculator()
{
    double density;
    double volume;
    // p = m / V

    cout << "Enter the density of the object (p):" << endl;
    inputNumber(density);
    cout << "Enter the volume of the object (V):" << endl;
    inputNumber(volume);

    cout << "Our formula is m = p * V" << endl;
    cout << "First we replace the values:" << endl;
    cout << "m = " << density << " * " << volume << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "m = " << density * volume << " kg" << endl;
}

void densityMassCalculator(char symbol)
{
    if (symbol == 'p')
    {
        densityCalculator();
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
        cout << "Enter the unit we are searching (p/m)" << endl;
        cin >> sym;
        densityMassCalculator(sym);
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
        densityMassCalculator(sym);
    }

    cout << "You got " << correctExerciseCount << " out of 2 points!";
}