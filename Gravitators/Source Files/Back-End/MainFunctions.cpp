#include <iostream>
#include <conio.h>

//include header files
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/mainMenuControl.h"

using namespace std;

void ignoreUserInput()
{
    cin.clear(); // removes cin error flag
    cin.ignore(INT_MAX, '\n');  // ignore last input
}

//clear console
void ClearScreen()
{
    system("cls");
}

//print error message
string outputErrorMessage()
{
    return "Please enter a valid input!\n";
}

//input number
void inputNumber(double& number, int x = -1, int y = -1)
{
    cin >> number;

    while (cin.fail())
    {
        ignoreUserInput();
        if (x != -1 && y != -1)
        {
            setOutputPosition1(x, y);
            cout << "                                                                ";
            setOutputPosition1(x, y);
        }
        cout << outputErrorMessage();
        if (y != -1)
        {
            setOutputPosition1(78, y);
            cout << "          ";
            setOutputPosition1(78, y);
        }
        cin >> number;
    }
}

//function to return to main menu
void returnToMainMenu1(int x, int y)
{
    setOutputPosition1(x, y);
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

//function to print the first half of opening question
string outputFormula(string& openingSentence, string formula)
{
    openingSentence = "Our formula is ";
    return formula;
}

//function to print "Now, try to slove this problem"
string outputProblem(string& openingSentence, string problem)
{
    openingSentence = "Now, try to solve this problem!\n";
    return problem;
}