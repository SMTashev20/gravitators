#pragma once

#include <iostream>
using namespace std;

//Set the output position of the options in the Quiz
void outputOptions(string question, string option1, string option2, string option3);

//Set the output position of the points
void outputTotalPoints(int& pointsTotal);

//Print the User choice
void printUser(int& pointsTotal, int correctRow);

//Print toutorial
void printTutorialUser();

//Add Questions of Recap Quiz
void QuizRecap();

//Add Questions of Density quiz
void QuizDensity();

//Add Questions of FreeFall quiz
void QuizFreeFall();

//Add questions of Gravity quiz
void QuizGravity();

//Add questions of Hydristatic Pressure quiz
void QuizHydrostaticPressure();

//Add questions of Newtons Law quiz
void QuizNewtonLaws();

//Add questions of Pressure quiz
void QuizPressure();

//Add questions of Uniform acceleration quiz
void QuizUniformAcceleration();

