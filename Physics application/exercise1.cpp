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

void distanceCalculator()
{
    double initialVelocity, time, acceleration;
    cout << "Enter the initial velocity of the body (Vo):" << endl;
    inputNumber(initialVelocity);

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    cout << "Enter the acceleration of the body (a):" << endl;
    inputNumber(acceleration);

    cout << "Our formula is s = Vo * t + (a * t * t) / 2" << endl;
    cout << "First we replace the values:" << endl;
    cout << "s = " << initialVelocity << " * " << time << " + " << "(" << acceleration << " * " << time * time << ")" << " / 2" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << initialVelocity * time << " + " << (acceleration * time * time) / 2 << endl;
    cout << "s = " << initialVelocity * time + (acceleration * time * time) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double initialVelocity, time, acceleration;
    cout << "Enter the initial velocity of the body (Vo):" << endl;
    inputNumber(initialVelocity);

    cout << "Enter the acceleration of the body (a):" << endl;
    inputNumber(acceleration);

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    cout << "Our formula is V = Vo + a * t" << endl;
    cout << "First we replace the values:" << endl;
    cout << "V = " << initialVelocity << " + " << acceleration << " * " << time << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "V = " << initialVelocity << " + " << acceleration * time << endl;
    cout << "V = " << initialVelocity + acceleration * time << " m/s" << endl;
}

void velocityDistanceCalculator(char symbol)
{
    if (symbol == 's')
    {
        distanceCalculator();
    }
    else
    {
        velocityCalculator();
    }
}

void exerciseOne(bool& pointAdd)
{
    double answer;
    cout << "Now, try to solve this problem!" << endl;
    cout << "A car was driving with speed of 5m/s. The car accelerated at 10 m/s2 for 12 seconds. What is the position of the car at the end of the 12 seconds?" << endl;
    cout << "s = ?m (example input: 122)" << endl;
    cin >> answer;
    if (answer == 780)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

void exerciseTwo(bool& pointAdd)
{
    double answer;
    cout << "Try to solve this problem!" << endl;
    cout << "With an initial velocity of 36 km/h, a car accelerated at 8 m/s2 for 10 seconds. What is the position of the car at the end of the 10 seconds?" << endl;
    cout << "hint: 36 km/h = 10 m/s" << endl;
    cout << "s = ?m (example input: 122)" << endl;
    cin >> answer;
    if (answer == 500)
    {
        pointAdd = true;
    }
    else
    {
        pointAdd = false;
    }
}

int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    char symbol;
    cin >> symbol;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseCounter = 0;
    bool exerciseOneChecker = 0;

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;

    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (V/s)" << endl;
        cin >> symbol;
        while (symbol != 'V' && symbol != 's')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        exerciseCounter++;
        exerciseOne(isCorrect);
        if (isCorrect == true)
        {
            cout << "That's correct!";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            cout << "That's wrong!";
        }
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
    else if (symbol == 'y')
    {
        exerciseCounter++;
        exerciseTwo(isCorrect);
        if (isCorrect == true)
        {
            cout << "That's correct!";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            cout << "That's wrong!";
        }
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
        cout << "Enter the unit we are searching (V/s)" << endl;
        cin >> symbol;
        while (symbol != 'V' && symbol != 's')
        {
            cout << "Please enter a valid input!" << endl;
            cin >> symbol;
        }
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        if (exerciseCounter < 2 and exerciseOneChecker != 0)
        {
            exerciseTwo(isCorrect);
            if (isCorrect == true)
            {
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                cout << "That's wrong! ";
            }
        }
        if (exerciseCounter < 2 and exerciseOneChecker == 0)
        {
            exerciseOne(isCorrect);
            if (isCorrect == true)
            {
                cout << "That's correct! ";
                correctExerciseCount++;
            }
            else if (isCorrect == false)
            {
                cout << "That's wrong! ";
            }
        }
        else
        {
            cout << "Ops! You've done 2 out of 2 exercises!" << endl;
        }
    }

    cout << "You got " << correctExerciseCount << " out of 2 points!";
}