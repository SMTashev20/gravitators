#include <iostream>
using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

string outputErrorMessage()
{
    return "Please enter a valid input :)\n";
    return "Enter a number.\n";
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

string outputFormula(string formula)
{
    string text = "Our formula is ";
    cout << text;
    return formula;
}

void forceCalculator()
{
    double pressure;
    double area;
    //F = P * S

    cout << "Enter the pressure of the object (P):" << endl;
    inputNumber(pressure);
    cout << "Enter the area of the object (S):" << endl;
    inputNumber(area);

    cout << outputFormula("F = P * S") << endl;
    cout << "First we replace the values:" << endl;
    cout << "F = " << pressure << " * " << area << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << pressure * area << " N" << endl;
}

void pressureCalculator()
{
    double force;
    double area;
    // P = F / S

    cout << "Enter the force of the object (F):" << endl;
    inputNumber(force);
    cout << "Enter the area of the object (S):" << endl;
    inputNumber(area);

    while (area == 0)
    {
        cout << "You can't devide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(area);
    }

    cout << outputFormula("a = F / m") << endl;
    cout << "First we replace the values:" << endl;
    cout << "P = " << force << " / " << area << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "P = " << force / area << " Pa" << endl;
}

void forcePressureCalculator(char symbol)
{
    if (symbol == 'F')
    {
        forceCalculator();
    }
    else
    {
        pressureCalculator();
    }
}

string outputProblem(string problem, string lookingFor)
{
    string text = "Now, try to solve this problem!";
    cout << endl;
    return text;
    cout << endl;
    return problem;
    cout << endl;
    return problem;
}

void exerciseOne(bool& pointAdd)
{
    double answer;
    outputProblem("If your mass is 80kg and the total area of the soles of your feet is 0.2 m2, what pressure would you exert on the ground ?", "P = ?N (example input: 122)");
    cout << "Hint: 15cm = 0,15m" << endl;
    cout << "hint : F = m * g and g = 10" << endl;
    cin >> answer;
    if (answer == 4000)
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

    int exerciseChecker = 0;
    bool exerciseOneChecker = 0;

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (F/S)" << endl;
        cin >> symbol;
        while (symbol != 'F' && symbol != 'S')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        forcePressureCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        exerciseChecker++;
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
        cout << "Enter the unit we are searching (F/S)" << endl;
        cin >> symbol;
        while (symbol != 'F' && symbol != 'S')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        forcePressureCalculator(symbol);
    }
}