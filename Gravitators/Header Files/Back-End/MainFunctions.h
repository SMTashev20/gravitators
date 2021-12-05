#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

void ignoreUserInput();

void ClearScreen();

string outputErrorMessage();

void inputNumber(double& number, int x = -1, int y = -1);

void returnToMainMenu(int x, int y);

string outputFormula(string& openingSentence, string formula);

string outputProblem(string& openingSentence, string problem);