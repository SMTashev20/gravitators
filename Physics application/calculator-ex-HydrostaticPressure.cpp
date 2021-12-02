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

void hydrostaticPressureCalculator()
{
    double rho; // declare variables
    double height;
    string opening;
    // F = m * a

    // enter values for rho and h
    cout << "Enter the rho of the object (p):" << endl;
    inputNumber(rho);
    cout << "Enter the height of the contaner (h):" << endl;
    inputNumber(height);

    cout << outputFormula(opening, "P = p * g * h") << endl;
    cout << "First we replace the values:" << endl;
    cout << "P " << rho << " * " << "10" << height << endl;
    cout << "Then we calculate our equation:" << endl;
    cout << "F = " << rho * 10 * height << " Pa" << endl;
}

void HeightCalculator()
{
    double hydrostaticPressure; // declare variables
    double rho;
    string opening;
    // h = P / p * g

    // enter values for P and rho
    cout << "Enter the Hydrostatic Pressure of the object (P):" << endl;
    inputNumber(hydrostaticPressure);
    cout << "Enter the rho of the object (p):" << endl;
    inputNumber(rho);

    while (rho == 0) // check for dividing by zero
    {
        cout << "You can't devide by 0!" << endl;
        cout << "Enter new value!" << endl;
        inputNumber(rho);
    }
    outputFormula(opening, "");
    cout << opening;
    cout << outputFormula(opening, "h = P / p * g") << endl;
    cout << "First we replace the values:" << endl;
    // calculate using the formula
    cout << "h = " << hydrostaticPressure << " / " << rho << " * 10" << endl; 
    cout << "Then we calculate our equation:" << endl;
    cout << "h = " << hydrostaticPressure / (rho * 10) << " m" << endl;
}

// check if user wants to calculate height or hydrostatic pressure
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

// problem 1
void exerciseOne(bool& pointAdd)
{
    double answer;  // declare variable
    string opening;
    string question = "A jar of water with 15 cm of height. Find the pressure of water at the bottom of the jar,\n"
                      "ignore the atmospheric pressure and use the acceleration due to gravity g = 10 m/s2 and \n"
                      "the density of water 1000 kg/m3. P = ? Pa (example input: 122)\n";

    outputProblem(opening, question);
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cout << "Hint: 15cm = 0,15m" << endl;
    cin >> answer;
    // the right answer is 1500, if user inputs 1500
    //then it is correct and if returns true
    if (answer == 1500) 
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
    double answer;  // declare variable
    string opening;
    string question = "What is the hydrostatic pressure at a depth of 0.5 meters in an alcohol solution?\n"
                      "The alcohol's density is 790 kg/m^3.\n";

    outputProblem(opening, question); 
    cout << opening;
    cout << outputProblem(opening, question); // output the problem
    cin >> answer;
    // the right answer is 3950, if user inputs 3950
    //then it is correct and if returns true
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
    cin >> symbol; // input symbol to answer the question

    int correctExerciseCount = 0; // count user's points
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
        cout << "Enter the unit we are searching (h/P)" << endl;
        cin >> symbol;
        while (symbol != "h" && symbol != "P") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculator(symbol);
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


    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> symbol; // input symbol to answer the question

    while (symbol != "c" && symbol != "p") // check if input is valid
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;
    }
    if (symbol == "c") // user is using calculator
    {
        cout << "Enter the unit we are searching (h/P)" << endl;
        cin >> symbol;
        while (symbol != "h" && symbol != "P") // check if input is valid
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        heightHydrostaticPleasureCalculator(symbol);
    }
    else if (symbol == "p") // user wants to solve another problem
    {
        // if problem 1 is already done, output problem 2
        if (exerciseCounter < 2 && exerciseOneChecker != 0) 
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
        // if problem 1 is not already done, output problem 1
        if (exerciseCounter < 2 && exerciseOneChecker == 0) 
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

    // output user's score
    cout << "You got " << correctExerciseCount << " out of 2 points!"; 
}
