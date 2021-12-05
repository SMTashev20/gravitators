#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

void ignoreUserInput();

//clear console
void ClearScreen();

//print the output message
string outputErrorMessage();

//Input number
void inputNumber(double& number, int x = -1, int y = -1);

//Return to the main menu
void returnToMainMenu1(int x, int y);

string outputFormula(string& openingSentence, string formula);

string outputProblem(string& openingSentence, string problem);