#pragma once

#include <iostream>
using namespace std;

#include <iostream>
#include <cstring> 
#include <ctime>
#include <windows.h>
#include <conio.h>

void outputOptions(string question, string option1, string option2, string option3);

void outputTotalPoints(int& pointsTotal);

void printUser(int& pointsTotal, int correctRow);

void printTutorialUser();

void QuizRecap();

void QuizDensity();

void QuizFreeFall();

void QuizGravity();

void QuizHydrostaticPressure();

void QuizNewtonLaws();

void QuizPressure();

void QuizUniformAcceleration();

