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
    double V0, t, a;
    cout << "Enter the initial velocity of the body (Vo):" << endl;
    inputNumber(V0);

    cout << "Enter the time interval (t):" << endl;
    inputNumber(t);

    cout << "Enter the acceleration of the body (a):" << endl;
    inputNumber(a);

    cout << "Our formula is s = Vo * t + (a * t * t) / 2" << endl;
    cout << "First we replace the values:" << endl;
    cout << "s = " << V0 << " * " << t << " + " << "(" << a << " * " << t * t << ")" << " / 2" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << V0 * t << " + " << (a * t * t) / 2 << endl;
    cout << "s = " << V0 * t + (a * t * t) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double V0, t, a;
    cout << "Enter the initial velocity of the body (Vo):" << endl;
    inputNumber(V0);

    cout << "Enter the acceleration of the body (a):" << endl;
    inputNumber(a);

    cout << "Enter the time interval (t):" << endl;
    inputNumber(t);

    cout << "Our formula is V = Vo + a * t" << endl;
    cout << "First we replace the values:" << endl;
    cout << "V = " << V0 << " + " << a << " * " << t << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "V = " << V0 << " + " << a * t << endl;
    cout << "V = " << V0 + a * t << " m/s" << endl;
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

int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    char sym;
    cin >> sym;

    int correctExerciseCount = 0;
    bool isCorrect;

    if (sym == 'c')
    {
        cout << "Enter the unit we are searching (s/V)" << endl;
        cin >> sym;
        velocityDistanceCalculator(sym);
    }
    else if (sym == 'p')
    {
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
    cout << "Would you like to go to the next exercise? (y/n)";
    cin >> sym;

    while (sym != 'c' && sym != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
        cin >> sym;
    }


    if (sym == 'c')
    {
        cout << "Enter the unit we are searching (s/V)" << endl;
        cin >> sym;
        velocityDistanceCalculator(sym);
    }
    else if (sym == 'p')
    {
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

    cout << "You got " << correctExerciseCount << " out of *total exercises* points!";
}