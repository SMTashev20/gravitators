#include <iostream>
#include <conio.h>

#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/mainMenuControl.h"

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

void inputNumber(double& number, int x = -1, int y = -1)
{
    cin >> number;

    while (cin.fail())
    {
        ignoreUserInput();
        if (x != -1 && y != -1)
        {
            setOutputPosition(x, y);
            cout << "                                                                ";
            setOutputPosition(x, y);
        }
        cout << outputErrorMessage();
        if (y != -1)
        {
            setOutputPosition(78, y);
            cout << "          ";
            setOutputPosition(78, y);
        }
        cin >> number;
    }
}

void returnToMainMenu(int x, int y)
{
    setOutputPosition(x, y);
    cout << "Press N to go back.";

    while (true)
    {
        switch (_getch())
        {
        case 'N':
        case 'n':
        {
            ClearScreen();
            start();
            break;
        }
        }
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