#include <iostream>
using namespace std;

#include <iostream>
#include <cstring> 
#include <ctime>
#include <windows.h>
#include <conio.h>

//include header files
#include "../../Header Files/Front-End/TowerOfPizza.h"
#include "../../Header Files/Front-End/Frame.h"
#include "../../Header Files/Back-End/MainFunctions.h"

//defines colors that are used in the application
#define COLOR_BLACK 0
#define COLOR_AQUA 3
#define COLOR_GRAY 8
#define COLOR_WHITE 7
#define COLOR_YELLOW 6

using namespace std;

//defines the position of the output option in the quiz
void outputOptions(string question, string option1, string option2, string option3)
{
	setColor(COLOR_WHITE);
	setOutputPosition1(20, 6);
	cout << question;

	setOutputPosition1(20, 9);
	cout << option1;
	setOutputPosition1(20, 11);
	cout << option2;
	setOutputPosition1(20, 13);
	cout << option3;
}

//defines the position of the output for total points
void outputTotalPoints(int& pointsTotal)
{
	setColor(COLOR_WHITE);
	setOutputPosition1(30, 10);
	cout << "Congratulations! You have finished the quiz!" << endl;
	setOutputPosition1(34, 11);
	cout << "Your total points are: ";
	setColor(COLOR_YELLOW);
	cout << pointsTotal;
}

//print arrow to help user navigate through the application
void printUser(int& pointsTotal, int correctRow)
{
	string user = "-->";
	setColor(COLOR_YELLOW);
	int userRow = 9, userCol = 16;
	{
		for (int moves = 100; moves >= 0; moves--)
		{
			switch (_getch())
			{
			case 'w':
			case 'W':
			{
				setOutputPosition1(userCol, userRow);
				cout << "    ";
				userRow--;
				setOutputPosition1(userCol, userRow);
				cout << user;
			}
			break;
			case 's':
			case 'S':
			{
				setOutputPosition1(userCol, userRow);
				cout << "    ";
				userRow++;
				setOutputPosition1(userCol, userRow);

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
					setOutputPosition1(35, 10);
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
					setOutputPosition1(35, 10);
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
	int userRow = 9, userCol = 16;
	{
		for (int moves = 100; moves >= 0; moves--)
		{
			switch (_getch())
			{
			case 'w':
			case 'W':
			{
				setOutputPosition1(userCol, userRow);
				cout << "    ";
				userRow--;
				setOutputPosition1(userCol, userRow);
				cout << user;
			}
			break;
			case 's':
			case 'S':
			{
				setOutputPosition1(userCol, userRow);
				cout << "    ";
				userRow++;
				setOutputPosition1(userCol, userRow);

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
					setOutputPosition1(35, 10);
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

//storage for recap quiz questions
void QuizRecap()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("The change in velocity in a given time period is?", "Vi", "Vf", "a"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 13);

    outputOptions("When the velocity of an object does not change,\n		    what happens to its acceleration?",
				"Nothing, it does accelerate", "It is a constant acceleration", "It is a changing acceleration");
	printUser(pointsTotal, 9);

	outputOptions("When an object falls in physics world, what happens?", "It accelerates at a non-constant rate until it hits the ground",
		"It accelerates at a constant rate until it hits the ground", "It accelerates at a constant rate until it reaches terminal velocity");
	printUser(pointsTotal, 11);

	outputOptions("Which would hit the ground first if dropped from the same\n		    height in a vacuum - a feather or a metal bolt?",
											"the feather", "the metal bolt", "They would hit the ground at the same time.");
	printUser(pointsTotal, 13);

	outputOptions("How is displacement different from distance?", "displacement is a vector, it must have magnitude and direction", 
		"displacement is a vector, it must have magnitude only", "displacement is a scalar, it must have magnitude and direction");
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

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for Density quiz questions
void QuizDensity()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("What two types of measurements make up DENSITY?",
		"Mass and volume", "Temperature and mass", "Grams and Centimetres"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 9);

	outputOptions("A rock has a mass of 14g and a volume of 2cm^3. What is its density?",
				"7mL", "7 g/cm^3", "1/7 g/cm^3");
	printUser(pointsTotal, 11);

	outputOptions("If an object has a density of .6 g/mL and you put it into water,\n		    will it sink or float?",
				"sink", "float", "none of them is correct");
	printUser(pointsTotal, 11);

	outputOptions("If an object has a density of 3.6 g/mL and you put it into water,\n		    will it sink or float?",
				"sink", "float", "none of them is correct");
	printUser(pointsTotal, 13);

	outputOptions("An eraser has a mass of 4g, and a volume of 2cm^3. What is its density?", 
				"8 g/cm^3", "2 g/cm^3", "24 g/cm^3");
	printUser(pointsTotal, 9);

	outputOptions("What units are used to measure mass?", "g", "cm^3", "g/cm");
	printUser(pointsTotal, 9);

	outputOptions("What is the formula for density? ", 
		"density = mass * volume ", "density = mass / volume – correct  ", "density = mass + volume");
	printUser(pointsTotal, 11);

	outputOptions("Helium balloons rise on earth because:", 
		"helium is less dense than air.", "helium is denser than air.", "helium is denser than air.");
	printUser(pointsTotal, 9);

	outputOptions("The density of a specific type of material never changes. ",
				"True", "False", "None of them");
	printUser(pointsTotal, 9);

	outputOptions("Why do ice cubes float in a glass of water", "the ice cubes are more dense than the water",
		"the water is more dense than the glass", "the water is more dense than the ice cubes");
	printUser(pointsTotal, 13);

	outputOptions("Why do objects sink or float in H2O?", "Because their densities are higher or lower than compared to water",
		" Because their densities are using gravity to pull down", "Because their densities are heavier or lighter");
	printUser(pointsTotal, 9);


	outputTotalPoints(pointsTotal);

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for FreeFall quiz questions
void QuizFreeFall()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("In free fall, where does an object have the slowest speed?", "Vi", "Vf", "Vtop"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 13);

	outputOptions("What is terminal velocity?", "The highest speed an object reaches because of unbalanced forces", 
		"The highest speed an object reaches because of air resistance", "When an object reaches its final velocity of zero");
	printUser(pointsTotal, 11);

	outputOptions("If you know the time an object is in the air, can you find its Vf?", 
		"Yes, but you would have to halve the time", 
		"No, you are not given enough information", "When an object reaches its final velocity of zero");
	printUser(pointsTotal, 9);

	outputOptions("How does the Vi compare to the Vf in a free fall problem?", "Vi and Vf are exactly the same, this is because of symmetry",
		"Vi and Vf are close but Vf is larger", 
		"Vi and Vf are the same in magnitude, but different in vector");
	printUser(pointsTotal, 13);

	outputOptions("The change in velocity in a given time period is?", "Vi", "Vf", "a");
	printUser(pointsTotal, 13);

	outputOptions("When the \"V\" of an object doesn't change, what happens to its \"a\"?", 
		"Nothing, it does accelerate", "It is a constant acceleration", "It is a changing acceleration");
	printUser(pointsTotal, 9);

	outputTotalPoints(pointsTotal);

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for Gravity quiz questions
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

	outputOptions("Two factors effecting the magnitude of the force of gravity\n		    between 2 objects are...",
				"mass and distance", "mass and matter", "distance and weight");
	printUser(pointsTotal, 9);

	outputOptions("A person would weigh less on on the Moon than on the Earth because . . .",
		"Moon has more mass, and therefore more gravity", "Moon has less mass, and therefore less gravity", 
		"Moon has more mass, and therefore less gravity");
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

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for Hydristatic Pressure quiz questions
void QuizHydrostaticPressure()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("Assuming constant temperature condition and air to be an ideal gas,\n		    the variation in atmospheric pressure with height from fluid statics is",
		"liner", "exponetial", "quadratic"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 9);

	outputOptions("The piezometric head in a static liquid:", "remains constant at all points in the liquid ",
		"increases linearly with depth below a free surface ", "decreases linearly with depth below a free surface");
	printUser(pointsTotal, 13);

	outputOptions("Choose the correct answer statement: A static fluid can have : ", "on-zero normal and shear stress", 
		"zero egative normal stress and zero shear stress ", "non-zero normal stress and zero shear stress");
	printUser(pointsTotal, 13);

	outputOptions("The center of pressure of a liquid on a plane surface immersed\n 		    in a static liquid, always lies below the centroid of the surface:",
		"because there is no shear stress in liquids at rest", "because in liquids the pressure acting is same in all directions", "because the liquid pressure increases linearly with depth");
	printUser(pointsTotal, 13);

	outputOptions("The line of action of buoyancy force acts through the:", "centre of gravity of any submerged body",
		"centroid of the volume of any floating body", "centroid of the displaced volume of fluid");
	printUser(pointsTotal, 13);

	outputOptions("At sea level, the value of atmospheric pressure is close to:", "1 metre of water column",
		"100 metre of water column", "10.33 metre of water column");
	printUser(pointsTotal, 13);

	outputOptions("For a 2 m deep swimming pool, pressure difference between the top\n		     and the bottom of the pool is ___ kPa. ", "22 ", "12", "19.63");
	printUser(pointsTotal, 13);

	outputOptions("For a static fluid, the increase of pressure inside the fluid,\n		     in a downward direction, must be equal to the product"
				"of _____ and depth.", "density", "viscosity", "specific weight");
	printUser(pointsTotal, 13);

	outputOptions("A tank is containing water up to a height of 2 m. Calculate the pressure\n		    at the bottom of the tank in N/m2", "19.62", "1.962", "19620");
	printUser(pointsTotal, 13);

	outputOptions("The pressure at a point inside a liquid does not depend on\n		    which of the following?", "The acceleration due to gravity at that point ",
				" The shape of containing vessel", "The nature of the liquid");
	printUser(pointsTotal, 11);

	outputTotalPoints(pointsTotal);

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for Newtons Laws quiz questions
void QuizNewtonLaws()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("The relationship between an object's mass (m), its \"a\", and F is F=ma.\n		    "
		"The direction of \"a\" is in the same direction as the force vector.",
		"Newton First law", "Newton Second law", "Newton Third law"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 11);

	outputOptions("Which of Newton's Three Laws does the following statement satisfy?\n		     "
		"For every action there is an equal and opposite reaction.", "Newton First law", "Newton Second law", "Newton Third law");
	printUser(pointsTotal, 13);

	outputOptions("Every object in a state of uniform motion remains \n		    "
		"in that state unless an external force is applied.",
		"Newton First law", "Newton Second law", "Newton Third law");
	printUser(pointsTotal, 9);

	outputOptions("If you have a hockey puck sliding, it'll eventually stop.", 
		"Newton First law", "Newton Second law", "Newton Third law");
	printUser(pointsTotal, 9);

	outputOptions("If a ball is thrown in the air, it will keep going the same velocity\n		    "
		"unless a force changes the velocity (speed and direction).", "air friction ", "gravity", "mass the ball");
	printUser(pointsTotal, 9);

	outputOptions("Which law states the need to wear seatbelts?", "Newton First law", "Newton Second law", "Newton Third law");
	printUser(pointsTotal, 9);

	outputOptions("________ was the scientist who gave us the Laws of Motion.", "Isaac Newton ", "Albert Einstein", "Stephen Hawking");
	printUser(pointsTotal, 9);

	outputOptions("What is another name for the Newton's first law of motion?", "Law of Acceleration", "Law of velocity", "Law of Inertia");
	printUser(pointsTotal, 13);

	outputOptions("The blood in your head rushes to your feet when riding on an elevator."
				"\n		    This is descending and abruptly stops.", "Newton First law", "Newton Second law", "Newton Third law");
	printUser(pointsTotal, 9);

	outputTotalPoints(pointsTotal);

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for Pressure quiz questions
void QuizPressure()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("Related to the word press", "Pressure", "Force", "Friction"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 9);

	outputOptions("The formula for pressure", "Pressure = Force / area", "Pressure = Force * area" , "Pressure = area / Force");
	printUser(pointsTotal, 9);

	outputOptions("The unit for pressure", "Pascal", "Newton", "Gram");
	printUser(pointsTotal, 9);

	outputOptions("When force increase...", "pressure increase", "pressure decrease", "pressure stays the same");
	printUser(pointsTotal, 9);

	outputOptions("When the area increase......", "pressure increase", "pressure decrease ", "pressure stays the same");
	printUser(pointsTotal, 11);

	outputOptions("As elevation increase,", "pressure decrease ", "pressure increase", "pressure stays the same");
	printUser(pointsTotal, 9);

	outputOptions("As depth decrease", "pressure decrease", "pressure increase ", "pressure stays the same");
	printUser(pointsTotal, 9);

	outputOptions("As depth increase", "pressure decrease", "pressure increase", "pressure stays the same");
	printUser(pointsTotal, 11);

	outputTotalPoints(pointsTotal);

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}

//storage for Uniform Acceleration quiz questions
void QuizUniformAcceleration()
{
	printGameFrame_Exercises();
	printStars_Exercises();

	int pointsTotal = 0;
	outputOptions("Controls:", "W, D - up, down", "Z - confirm", "N - continue");
	printTutorialUser();

	outputOptions("How is displacement different from distance?", "displacement is a vector, it must have magnitude and direction ",
		"displacement is a vector, it must have magnitude only", "displacement is a scalar, it must have magnitude and direction"); //Correct rows: 9, 11 and 13
	printUser(pointsTotal, 9);

	outputOptions("A man walks 10 meters east and 5 meters west. What was his displacement?", "15 meters east", "15 meters west", "5 meters east");
	printUser(pointsTotal, 13);

	outputOptions("A golf ball accelerates off a tee at 15 m/s2, changing its velocity from \n 	    0 m/s to 50 m/s. How long did it take the golf ball to accelerate?", 
				"750 s", "35 s", "3.3 s");
	printUser(pointsTotal, 13);

	outputOptions("A drag racer accelerated from 0 m/s to 200 m/s in 5 s.\n		    What was the acceleration?", "0 m/s^2", "40 m/s^2", "40m/s^2");
	printUser(pointsTotal, 11);

	outputOptions("The SI unit for acceleration", "mPh", "ft/s^2", "m/s^");
	printUser(pointsTotal, 13);

	outputTotalPoints(pointsTotal);

	setColor(COLOR_YELLOW);
	returnToMainMenu1(34, 13);
}
