#pragma once

#include <iostream>
#include <string>

using namespace std;

void ignoreUserInput();

string outputErrorMessage();

void inputNumber(double& number);

string outputFormula(string& openingSentence, string formula);

string outputProblem(string& openingSentence, string problem);