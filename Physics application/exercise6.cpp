#include <iostream>
using namespace std;

void ignoreUserInput()
{
	cin.clear(); // removes cin error flag
	cin.ignore(INT_MAX, '\n');  // ignore last input
}

void inputNumber(double& number)
{
	cin >> number;

	while (cin.fail())
	{
		ignoreUserInput();
		cout << "Please enter a valid input :)\n";
		cout << "Enter a number.\n";
		cin >> number;
	}
}

void forceCalculator()
{
	double pressure;
	double area;
	//F = P * S

	cout << "Enter the pressure of the object (P):" << endl;
	inputNumber(pressure);
	cout << "Enter the area of the object (S):" << endl;
	inputNumber(area);
	cout << "Our formula is F = P * S" << endl;
	cout << "First we replace the values:" << endl;
	cout << "F = " << pressure << " * " << area << endl;
	cout << "Then we calculate our eqalation:" << endl;
	cout << "F = " << pressure * area << " N" << endl;
}

void pressureCalculator()
{
	double force;
	double area;
	// P = F / S

	cout << "Enter the force of the object (F):" << endl;
	inputNumber(force);
	cout << "Enter the area of the object (S):" << endl;
	inputNumber(area);

	while (area == 0)
	{
		cout << "You can't devide by 0!" << endl;
		cout << "Enter new value!" << endl;
		inputNumber(area);
	}

	cout << "Our formula is a = F / m" << endl;
	cout << "First we replace the values:" << endl;
	cout << "P = " << force << " / " << area << endl;
	cout << "Then we calculate our eqalation:" << endl;
	cout << "P = " << force / area << " Pa" << endl;
}

void forcePressureCalculator(char symbol)
{
	if (symbol == 'F')
	{
		forceCalculator();
	}
	else
	{
		pressureCalculator();
	}
}

int main()
{
	cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
	char symbol;
	cin >> symbol;

	while (symbol != 'c' && symbol != 'p')
	{
		cout << "Please enter a valid input!" << endl;
		cin >> symbol;
	}
	if (symbol == 'c')
	{
		cout << "Enter the unit we are searching (F/S)" << endl;
		cin >> symbol;
		while (symbol != 'F' && symbol != 'S')
		{
			cout << "Please enter a valid input!" << endl;
			cin >> symbol;
		}
		forcePressureCalculator(symbol);
	}

	cout << "Would you like to go to the next exercise? (y/n)" << endl;
	cin >> symbol;
	while (symbol != 'y' && symbol != 'n')
	{
		cout << "Please enter a valid input!" << endl;
		cin >> symbol;
	}
	if (symbol == 'n')
	{
	}


	cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
	cin >> symbol;

	while (symbol != 'c' && symbol != 'p')
	{
		cout << "Please enter a valid input!" << endl;
		cin >> symbol;
	}
	if (symbol == 'c')
	{
		cout << "Enter the unit we are searching (F/S)" << endl;
		cin >> symbol;
		while (symbol != 'F' && symbol != 'S')
		{
			cout << "Please enter a valid input!" << endl;
			cin >> symbol;
		}
		forcePressureCalculator(symbol);
	}
}