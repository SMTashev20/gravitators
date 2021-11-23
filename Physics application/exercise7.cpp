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

void hydrostaticPressureCalculator()
{
    double rho;
    double height;
    // F = m * a

    cout << "Enter the rho of the object (p):" << endl;
    inputNumber(rho);
    cout << "Enter the height of the contaner (h):" << endl;
    inputNumber(height);
    cout << "Our formula is P = p * g * h" << endl;
    cout << "First we replace the values:" << endl;
    cout << "P " << rho << " * " << "10" << height << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << rho * 10 * height << " Pa" << endl;
}

void HeightCalculator()
{
    double hydrostaticPressure;
    double rho;
    // h = P / p * g

    cout << "Enter the Hydrostatic Pressure of the object (P):" << endl;
    inputNumber(hydrostaticPressure);
    cout << "Enter the rho of the object (p):" << endl;
    inputNumber(rho);

    while (rho == 0)
    {
        cout << "You can't devide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(rho);
    }

    cout << "Our formula is h = P / p * g" << endl;
    cout << "First we replace the values:" << endl;
    cout << "h = " << hydrostaticPressure << " / " << rho << " * 10" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "h = " << hydrostaticPressure / rho * 10 << " m" << endl;
}

void heightHydrostaticPleasureCalculator(char symbol)
{
    if (symbol == 'h')
    {
        HeightCalculator();
    }
    else
    {
        hydrostaticPressureCalculator();
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
        heightHydrostaticPleasureCalculator(symbol);
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
        cout << "Enter the unit we are searching (h/P)" << endl;
        cin >> symbol;
        while (symbol != 'h' && symbol != 'P')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculator(symbol);
    }
}
