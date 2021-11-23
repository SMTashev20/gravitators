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

void forceCalculator()
{
    double acceleration;
    double mass;
    // F = m * a

    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);
    cout << "Enter the acceleration of the object (a):" << endl;
    inputNumber(acceleration);
    cout << "Our formula is F = m * a" << endl;
    cout << "First we replace the values:" << endl;
    cout << "F = " << mass << " * " << acceleration << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << mass * acceleration << " N" << endl;
}

void accelerationCalculator()
{
    double force;
    double mass;
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

    cout << "Our formula is a = F / m" << endl;
    cout << "First we replace the values:" << endl;
    cout << "a = " << force << " / " << mass << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "a = " << force / mass << " m/s^2" << endl;
}

void forceAccelerationCalculator(char symbol)
{
    if (symbol == 'F')
    {
        forceCalculator();
    }
    else
    {
        accelerationCalculator();
    }
}

int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    char symbol;
    cin >> symbol;

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (F/a)" << endl;
        cin >> symbol;
        while (symbol != 'F' && symbol != 'a')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        forceAccelerationCalculator(symbol);
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


    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> symbol;

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (F/a)" << endl;
        cin >> symbol;
        while (symbol != 'F' && symbol != 'a')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        forceAccelerationCalculator(symbol);
    }
}
}