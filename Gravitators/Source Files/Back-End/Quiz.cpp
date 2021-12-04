#include <iostream>
using namespace std;

#include <iostream>
#include <cstring> 
#include <ctime>
#include <windows.h>
#include <conio.h>

#include "../../Header Files/Front-End/TowerOfPizza.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/MainFunctions.h"

#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6

using namespace std;

void outputOptions(string question, string option1, string option2, string option3)
{
	setColor(COLOR_WHITE);
	setOutputPosition(36, 6);
	cout << question;

	setOutputPosition(34, 9);
	cout << option1;
	setOutputPosition(34, 11);
	cout << option2;
	setOutputPosition(34, 13);
	cout << option3;
}

void outputTotalPoints(int& pointsTotal)
{
	setColor(COLOR_WHITE);
	setOutputPosition(30, 10);
	cout << "Congratulations! You have finished the quiz!" << endl;
	setOutputPosition(34, 11);
	cout << "Your total points are: ";
	setColor(COLOR_YELLOW);
	cout << pointsTotal;
}

void printUser(int& pointsTotal, int correctRow)
{
	string user = "-->";
	setColor(COLOR_YELLOW);
	int userRow = 9, userCol = 28;
	{
		for (int moves = 100; moves >= 0; moves--)
		{
			switch (_getch())
			{
			case 'w':
			case 'W':
			{
				setOutputPosition(userCol, userRow);
				cout << "    ";
				userRow--;
				setOutputPosition(userCol, userRow);
				cout << user;
			}
			break;
			case 's':
			case 'S':
			{
				setOutputPosition(userCol, userRow);
				cout << "    ";
				userRow++;
				setOutputPosition(userCol, userRow);

				cout << user;
			}
			break;
			case 'z':
			case 'Z':
			{
				if (userRow == correctRow)
				{
					ClearScreen();
					printGameFrame_Exercises();
					printStars_Exercises();

					setColor(COLOR_YELLOW);
					setOutputPosition(35, 10);
					cout << "+1pt! Press N to continue.";
					pointsTotal++;
					moves = 1;
				}
				else
				{
					ClearScreen();
					printGameFrame_Exercises();
					printStars_Exercises();

					setColor(COLOR_YELLOW);
					setOutputPosition(35, 10);
					cout << "+0pt, press N to continue." << endl;
					moves = 1;
				}
			}
			break;
			case 'n':
			case 'N':
			{
				ClearScreen();
				printGameFrame_Exercises();
				printStars_Exercises();
				cout << 0;

			}
			default:
			{
			}
			}
		}
	}
}

void printTutorialUser()
{
	string user = "-->";
	setColor(COLOR_YELLOW);
	int userRow = 9, userCol = 28;
	{
		for (int moves = 100; moves >= 0; moves--)
		{
			switch (_getch())
			{
			case 'w':
			case 'W':
			{
				setOutputPosition(userCol, userRow);
				cout << "    ";
				userRow--;
				setOutputPosition(userCol, userRow);
				cout << user;
			}
			break;
			case 's':
			case 'S':
			{
				setOutputPosition(userCol, userRow);
				cout << "    ";
				userRow++;
				setOutputPosition(userCol, userRow);

				cout << user;
			}
			break;
			case 'z':
			case 'Z':
			{

					ClearScreen();
					printGameFrame_Exercises();
					printStars_Exercises();

					setColor(COLOR_YELLOW);
					setOutputPosition(35, 10);
					cout << "Great! Press N to continue.";
					moves = 1;
			}
			break;
			case 'n':
			case 'N':
			{
				ClearScreen();
				printGameFrame_Exercises();
				printStars_Exercises();
				cout << 0;

			}
			default:
			{
			}
			}
		}
	}
}

void QuizRecap()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("The change in velocity in a given time period is?", "Vi", "Vf", "a"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 13);

    outputOptions("When the velocity of an object does not change, \n what happens to its acceleration?", "Nothing, it does accelerate", "It is a constant acceleration", "It is a changing acceleration");
	printUser(pointsTotal, 9);

	outputOptions("When an object falls in physics world, what happens?", "It accelerates at a non-constant rate until it hits the ground", "It accelerates at a constant rate until it hits the ground", "It accelerates at a constant rate until it reaches terminal velocity");
	printUser(pointsTotal, 11);

	outputOptions("Which would hit the ground first if dropped from the same height in a vacuum—a feather or a metal bolt?", "the feather", "the metal bolt", "They would hit the ground at the same time.");
	printUser(pointsTotal, 13);

	outputOptions("How is displacement different from distance?", "displacement is a vector, it must have magnitude and direction", "displacement is a vector, it must have magnitude only", "displacement is a scalar, it must have magnitude and direction");
	printUser(pointsTotal, 9);

	outputOptions("The SI unit for acceleration is?", "mph", "ft/sec2", "m/s2");
	printUser(pointsTotal, 13);

	outputOptions("What is the SI unit used to measure force ? ", "pounds ", "newtons  ", "grams");
	printUser(pointsTotal, 11);

	outputOptions("What's the formula for Newton's second law of motion (Force)?", "F = m - a", "F = a / m", "F= m * a");
	printUser(pointsTotal, 13);

	outputOptions("Which is the unit for pressure", "Pascal", "Newton", "Gram");
	printUser(pointsTotal, 9);


	outputOptions("When force increases...", "pressure increases", "pressure decreases", "pressure stays the same");
	printUser(pointsTotal, 9);

	outputOptions("Density is defined as", "mass/volume", "volume * mass", "volume + mass");
	printUser(pointsTotal, 9);


	outputTotalPoints(pointsTotal);

	setOutputPosition(11, 32);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}

void QuizDensity()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("What two types of measurements make up DENSITY?", "Mass and volume", "Temperature and mass", "Grams and Centimetres"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 9);

	outputOptions("Jack has a rock. The rock has a mass of 14g and a volume of 2cm3. What is the density of the rock?", "7mL", "7 g/cm^3", "1/7 g/cm^3");
	printUser(pointsTotal, 11);

	outputOptions("If an object has a density of .6 g/mL and you put it into water, will it sink or float?", "sink", "float", "none of them is correct");
	printUser(pointsTotal, 11);

	outputOptions("If an object has a density of 3.6 g/mL and you put it into water, will it sink or float?", "sink", "float", "none of them is correct");
	printUser(pointsTotal, 13);

	outputOptions("Frank has an eraser. It has a mass of 4g, and a volume of 2cm^3. What is its density?", "8 g/cm^3", "2 g/cm^3", "24 g/cm^3");
	printUser(pointsTotal, 9);

	outputOptions("What units are used to measure mass?", "g", "cm^3", "g/cm");
	printUser(pointsTotal, 9);

	outputOptions("What is the formula for density? ", "density = mass * volume ", "density = mass / volume – correct  ", "density = mass + volume");
	printUser(pointsTotal, 11);

	outputOptions("Helium balloons rise on earth because:", "helium is less dense than air.", "helium is denser than air.", "helium is denser than air.");
	printUser(pointsTotal, 9);

	outputOptions("The density of a specific type of material never changes. ", "True", "False", "None of them");
	printUser(pointsTotal, 9);

	outputOptions("Why do ice cubes float in a glass of water", "the ice cubes are more dense than the water", "the water is more dense than the glass", "the water is more dense than the ice cubes");
	printUser(pointsTotal, 13);

	outputOptions("Why do objects sink or float in H2O?", "Because their densities are higher or lower than compared to water", " Because their densities are using gravity to pull down", "Because their densities are heavier or lighter");
	printUser(pointsTotal, 9);


	outputTotalPoints(pointsTotal);

	setOutputPosition(11, 32);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}

void QuizFreeFall()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("In free fall, where does an object have the slowest speed?", "Vi", "Vf", "Vtop"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 13);

	outputOptions("What is terminal velocity?", "The highest speed an object reaches because of unbalanced forces", "The highest speed an object reaches because air resistance offsets gravity in the real world ", "When an object reaches its final velocity of zero");
	printUser(pointsTotal, 11);

	outputOptions("If you know the time an object is in the air, can you find the Vf of the object?", "Yes, you would have to halve the time since the Ttotal is for both rise and fall and you would have to calculate the height the object rose before finding the Vf ", "No, you are not given enough information", "When an object reaches its final velocity of zero");
	printUser(pointsTotal, 9);

	outputOptions("How does the Vi compare to the Vf in a free fall problem?", "Vi and Vf are exactly the same, this is because of symmetry", "Vi and Vf are close but Vf is larger because you would fall faster than you would rise, since you are slowing down", "Vi and Vf are the same in magnitude, but different in vector");
	printUser(pointsTotal, 13);

	outputOptions("The change in velocity in a given time period is?", "Vi", "Vf", "a");
	printUser(pointsTotal, 13);

	outputOptions("When the velocity of an object does not change, what happens to its acceleration?", "Nothing, it does accelerate", "It is a constant acceleration", "It is a changing acceleration");
	printUser(pointsTotal, 9);

	outputTotalPoints(pointsTotal);

	setOutputPosition(11, 32);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}

void QuizGravity()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("What unit does the U.S use to measure gravity force?", "Ounces", "Newtons","Pounds"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 13);

	outputOptions("Every object in the universe attracts every other object.", "True ", "False", "None of them are correct");
	printUser(pointsTotal, 9);

	outputOptions("Gravity attract all objects to towards one another.", "False", "True ", "It depends");
	printUser(pointsTotal, 11);

	outputOptions("Two factors effecting the magnitude of the force of gravity between 2 objects are...", "mass and distance", "mass and matter", "distance and weight");
	printUser(pointsTotal, 9);

	outputOptions("A person would weigh less on on the Moon than on the Earth because . . .", "Moon has more mass, and therefore more gravity", "Moon has less mass, and therefore less gravity", "Moon has more mass, and therefore less gravity");
	printUser(pointsTotal, 11);

	outputOptions("Which of the following never changes no matter where in the universe?", "weight", "force", "mass");
	printUser(pointsTotal, 13);

	outputOptions("The amount of matter in a object is? ", "pressure ", "weight", "mass");
	printUser(pointsTotal, 13);

	outputOptions("The law of universal gravitation is credited to who ? ", "Einstein", "Galileo", "Newton");
	printUser(pointsTotal, 13);

	outputOptions("The force of gravity acting on an object is the object's __.", "mass", "matter", "weight");
	printUser(pointsTotal, 13);

	outputOptions("Any object with mass has gravity.", "True ", "Sometimes", "False");
	printUser(pointsTotal, 9);

	outputOptions("What is the SI unit used to measure force? ", "pounds", "grams", "newtons");
	printUser(pointsTotal, 13);


	outputTotalPoints(pointsTotal);

	setOutputPosition(11, 32);
	cout << endl << endl;
	setColor(COLOR_BLACK);
}
