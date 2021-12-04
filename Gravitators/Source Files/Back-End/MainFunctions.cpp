#include <iostream>
#include "../../Header Files/Front-End/MainFront-EndFunctions.h"

using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

void ClearScreen()
{
    setOutputPosition(0, 1);
    string EmptySpace = "                                                                                                                   ";
    for (int i = 0; i < 50; i++)
    {
        cout << EmptySpace << endl;
    }
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

string outputProblem(string& openingSentence, string problem)
{
    openingSentence = "Now, try to solve this problem!\n";
    return problem;
}