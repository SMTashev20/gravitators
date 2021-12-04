#pragma once

#include <iostream>
#include <string>

using namespace std;

void outputOptions(string question, string option1, string option2, string option3);

int outputTotalPoints(int& pointsTotal);

void printUser(int& pointsTotal, int correctRow);

void printTutorialUser();

void QuizRecap();