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

void hydrostaticPressureCalculator()
{
    double rho;
    double height;
    string opening;
    // F = m * a

    cout << "Enter the rho of the object (p):" << endl;
    inputNumber(rho);
    cout << "Enter the height of the contaner (h):" << endl;
    inputNumber(height);

    cout << outputFormula(opening, "P = p * g * h") << endl;
    cout << "First we replace the values:" << endl;
    cout << "P " << rho << " * " << "10" << height << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << rho * 10 * height << " Pa" << endl;
}

void HeightCalculator()
{
    double hydrostaticPressure;
    double rho;
    string opening;
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
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "h = P / p * g") << endl;
    cout << "First we replace the values:" << endl;
    cout << "h = " << hydrostaticPressure << " / " << rho << " * 10" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "h = " << hydrostaticPressure / (rho * 10) << " m" << endl;
}

void heightHydrostaticPleasureCalculator(string symbol)
{
    if (symbol == "h")
    {
        HeightCalculator();
    }
    else
    {
        hydrostaticPressureCalculator();
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
    string question = "A jar of water with 15 cm of height. Find the pressure of water at the bottom of the jar,\n"
                      "ignore the atmospheric pressure and use the acceleration due to gravity g = 10 m/s2 and \n"
                      "the density of water 1000 kg/m3. P = ? Pa (example input: 122)\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question);
    cout << "Hint: 15cm = 0,15m" << endl;
    cin >> answer;
    if (answer == 1500)
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
    string question = "What is the hydrostatic pressure at a depth of 0.5 meters in an alcohol solution?\n"
                      "The alcohol's density is 790 kg/m^3.\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question);
    cin >> answer;

    if (answer == 3950)
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
    cin >> symbol;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseCounter = 0;
    bool exerciseOneChecker = 0;


    while (symbol != "c" && symbol != "p")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c")
    {
        cout << "Enter the unit we are searching (h/P)" << endl;
        cin >> symbol;
        while (symbol != "h" && symbol != "P")
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculator(symbol);
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

    cout << "Would you like to go to the next exercise? (y/n)" << endl;
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


    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> symbol;

    while (symbol != "c" && symbol != "p")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c")
    {
        cout << "Enter the unit we are searching (h/P)" << endl;
        cin >> symbol;
        while (symbol != "h" && symbol != "P")
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculator(symbol);
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
