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
    double time;

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    cout << "Our formula is s = (g * t * t ) / 2" << endl;
    cout << "First we replace the values:" << endl;
    cout << "s = " << "(" << 10 << " * " << time << " * " << time << ")" << " / 2" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << (10 * time * time) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double time;

    cout << "Enter the time interval (t):" << endl;
    inputNumber(time);

    cout << "Our formula is V = g * t" << endl;
    cout << "First we replace the values:" << endl;
    cout << "V = " << 10 << " * " << time << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << 10 * time << " m/s" << endl;
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
    cout << "A construction worker accidentally drops a brick from a high scaffold. If you know the gravitational acceleration g is ~10 m/s2 and the brick falls 4 seconds, how far does the brick fall during this time?" << endl;
    cout << "s = ?m (example input: 122)" << endl;
    cin >> answer;
    if (answer == 80)
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
    cout << "A stone that starts at rest is in free fall for 6 s. What is the stone’s velocity after these 6 seconds?" << endl;
    cout << "s = ?m (example input: 122)" << endl;
    cin >> answer;
    if (answer == 60)
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

    while (symbol != 'c' && symbol != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> symbol;

    }
    if (symbol == 'c')
    {
        cout << "Enter the unit we are searching (s/V)" << endl;
        cin >> symbol;
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        exerciseCounter++;
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

    cout << "Would you like to do the next exercise? (y/n)" << endl;
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
            cout << "That's correct! ";
            correctExerciseCount++;
        }
        else if (isCorrect == false)
        {
            cout << "That's wrong! ";
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
        cout << "Enter the unit we are searching (s/V)" << endl;
        cin >> symbol;
        velocityDistanceCalculator(symbol);
    }
    else if (symbol == 'p')
    {
        if (exerciseCounter < 2)
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
        else
        {
            cout << "Ops! You've done 2 out of two exercises!" << endl;
        }


        cout << "You got " << correctExerciseCount << " out of 2 points!";
    }
}