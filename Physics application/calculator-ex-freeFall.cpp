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

void distanceCalculator()
{
    double time;
    string opening;

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);
	
	outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "s = (g * t * t ) / 2") << endl;
    cout << "First we replace the values:" << endl;
    cout << "s = " << "(" << 10 << " * " << time << " * " << time << ")" << " / 2" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << (10 * time * time) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double time;
    string opening;

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);
	
	outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "V = g * t") << endl;
    cout << "First we replace the values:" << endl;
    cout << "V = " << 10 << " * " << time << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << 10 * time << " m/s" << endl;
}

void velocityDistanceCalculator(string symbol)
{
    if (symbol == "s")
    {
        distanceCalculator();
    }
    else
    {
        velocityCalculator();
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
    string question = "A construction worker accidentally drops a brick from a high scaffold. If you know the gravitational \n"
                      "acceleration g is ~10 m/s2 and the brick falls 4 seconds, how far does the brick fall during this time?\n";

    outputProblem(opening, question);
    cout << opening << '\n';
    cout << outputProblem(opening, question);
    cin >> answer;
    if (answer == 80)
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
    string question = "A stone that starts at rest is in free fall for 6 s. What is the \n"
                      "velocity of the stone after these 6 seconds? s = ?m (example input: 122)\n";
    
    outputProblem(opening, question);
    cout << opening << '\n';
    cout << outputProblem(opening, question);
    cin >> answer;
    if (answer == 60)
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
        cout << "Enter the unit we are searching (V/s)" << endl;
        cin >> symbol;
        while (symbol != "V" && symbol != "s")
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        velocityDistanceCalculator(symbol);
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

    cout << "Would you like to do the next exercise? (y/n)" << endl;
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
        cout << "Enter the unit we are searching (V/s)" << endl;
        cin >> symbol;
        while (symbol != "V" && symbol != "s")
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == "p")
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
           cout << "Oops! You've finished all of the exercises!" << endl;
        }

        cout << "You got " << correctExerciseCount << " out of 2 points!";
    }
}