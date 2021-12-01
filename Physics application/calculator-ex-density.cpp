#include <iostream>

using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

string outputErrorMessage()
{
    return "Please enter a valid input!";
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

void densityCalculator()
{
    double mass;
    double volume;
    string opening;
    // p = m / V

    cout << "Enter the mass of the object (m):" << endl;
    inputNumber(mass);
    cout << "Enter the volume of the object (V):" << endl;
    inputNumber(volume);
    while (volume == 0)
    {
        cout << "You can't divide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(volume);
    }
	outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "p = m / V") << endl;
    cout << "First we replace the values:" << endl;
    cout << "p = " << mass << " / " << volume << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "p = " << mass / volume << " kg/m2" << endl;
}

void massCalculator()
{
    double density;
    double volume;
    string opening;
    // p = m / V

    cout << "Enter the density of the object (p):" << endl;
    inputNumber(density);
    cout << "Enter the volume of the object (V):" << endl;
    inputNumber(volume);

	outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "m = p * V") << endl;
    cout << "m = " << density << " * " << volume << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "m = " << density * volume << " kg" << endl;
}

void densityMassCalculator(string symbol)
{
    if (symbol == "p")
    {
        densityCalculator();
    }
    else
    {
        massCalculator();
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
    string question = "If the volume of a metal shpere of 200g mass is 20 cm3 what is the density of the metal? s = ?m (example input: 122)\n";

    outputProblem(opening, question);
    cout << opening;

    cout << outputProblem(opening, question);
    cin >> answer;
    if (answer == 10)
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
    string question = "You have a rock with a volume of 15cm^3 and a mass of 45 g. What is its density?\n";

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
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    string sym;
    cin >> sym;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseCounter = 0;
    bool exerciseOneChecker = 0;

    while (sym != "c" && sym != "p")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "c")
    {
        cout << "Enter the unit we are searching (p/m)" << endl;
        cin >> sym;
        while (sym != "p" && sym != "m")
        {
            cout << "Please enter a valid input!" << endl;
            cin >> sym;
        }
        densityMassCalculator(sym);
    }
    else if (sym == "p")
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
    cin >> sym;
    while (sym != "y" && sym != "n")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "n")
    {

    }
    else if (sym == "y")
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
    cin >> sym;

    while (sym != "c" && sym != "p")
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == "c")
    {
        cout << "Enter the unit we are searching (G/m)" << endl;
        cin >> sym;
        while (sym != "G" && sym != "m")
        {
            cout << "Please enter a valid input!" << endl;
            cin >> sym;
        }
        densityMassCalculator(sym);
    }
    else if (sym == "p")
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