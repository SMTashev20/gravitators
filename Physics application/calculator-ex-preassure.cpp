#include <iostream>
using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

// check if input is valid
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

void forceCalculator()
{
    double pressure; // declare variables
    double area;
    string opening;
    //F = P * S

    // enter values for P and S
    cout << "Enter the pressure of the object (P):" << endl;
    inputNumber(pressure);
    cout << "Enter the area of the object (S):" << endl;
    inputNumber(area);

    outputFormula(opening, ""); // output formula
    cout << opening;
    cout << outputFormula(opening, "F = P * S") << endl;
    cout << "First we replace the values:" << endl;
    cout << "F = " << pressure << " * " << area << endl; // calculate using the formula
    cout << "Then we calculate our eqalation:" << endl;
    cout << "F = " << pressure * area << " N" << endl;
}

void pressureCalculator()
{
    double force; // declare variables
    double area;
    string opening;
    // P = F / S

    // enter values for F and S
    cout << "Enter the force of the object (F):" << endl;
    inputNumber(force);
    cout << "Enter the area of the object (S):" << endl;
    inputNumber(area);

    while (area == 0) // check for dividing by zero
    {
        cout << "You can't devide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(area);
    }

    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "a = F / m") << endl;
    cout << "First we replace the values:" << endl;
    cout << "P = " << force << " / " << area << endl; // calculate using the formula
    cout << "Then we calculate our equation:" << endl;
    cout << "P = " << force / area << " Pa" << endl;
}

void forcePressureCalculator(string symbol) // check if user wants to calculate force or pressure
{
    if (symbol == "F")
    {
        forceCalculator();
    }
    else
    {
        pressureCalculator();
    }
}

string outputProblem(string& openingSentence, string problem)
{
    openingSentence = "Now, try to solve this problem!\n";
    return problem;
}

// problem 1
void exerciseOne(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "If your mass is 80kg and the total area of the soles of your feet is 0.2 m2,\n"
        "what pressure would you exert on the ground? P = ?N (example input: 122)\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cout << "Hints: 15cm = 0,15m, F = m * g and g = 10" << endl;
    cin >> answer;
    if (answer == 4000) // the right answer is 4000, if user inputs 4000, then it is correct and if returns true
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

// problem 2
void exerciseTwo(bool& pointAdd)
{
    double answer; // declare variable
    string opening;
    string question = "A force of 15N is applied to a 5kg object in space. \n"
        "What is the acceleration of the object?\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cin >> answer;

    if (answer == 3) // the right answer is 3, if user inputs 3, then it is correct and if returns true
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
    cin >> symbol; // input symbol to answer the question

    int correctExerciseCount = 0; // counts user's points
    bool isCorrect; // check if the exercise is answered correctly

    int exerciseCounter = 0; // count how many problems the user has answered
    bool exerciseOneChecker = 0; // check if problem 1 is already done or not

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (F/S)" << endl;
        cin >> symbol;
        while (symbol != "F" && symbol != "S") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        forcePressureCalculator(symbol);
    }
    else if (symbol == "p") // output problem 1
    {
        exerciseCounter++;
        exerciseOne(isCorrect); // check if problem 1 is answered correctly
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
    cin >> symbol; // input symbol to answer the question
    while (symbol != "y" && symbol != "n") // check if input is valid
    { 
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "n")
    {

    }
    else if (symbol == "y") // output problem 2
    {
        exerciseCounter++;
        exerciseTwo(isCorrect); // check if problem 2 is answered correctly
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
    cout << "Would you like to use the calculator or solve a problem? (c/p) " << endl;
    cin >> symbol; // input symbol to answer the question

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (F/a)" << endl;
        cin >> symbol;
        while (symbol != "F" && symbol != "a") // check if input is valid
        {
            cout << "Please enter a valid input! " << endl;
            cin >> symbol;
        }
        forcePressureCalculator(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        if (exerciseCounter < 2 && exerciseOneChecker != 0) // if problem 1 is already done, output problem 2
        {
            exerciseTwo(isCorrect); // check if problem 2 is answered correctly
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
        if (exerciseCounter < 2 && exerciseOneChecker == 0) // if problem 1 is not already done, output problem 1
        {
            exerciseOne(isCorrect); // check if problem 1 is answered correctly
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
        else // output this if user has done problem 1 and problem 2
        {
            cout << "Oops! You've finished all of the exercises!" << endl;
        }
    }


    cout << "You got " << correctExerciseCount << " out of 2 points!"; // output user's score
}