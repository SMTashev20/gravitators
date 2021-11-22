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
    double t;
    
    cout << "Enter the time interval (t):" << endl;
    inputNumber(t);

    cout << "Our formula is s = (g * t * t ) / 2" << endl;
    cout << "First we replace the values:" << endl;
    cout << "s = "<< "(" << 10 << " * "  << t << " * " << t << ")" << " / 2" << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << (10 * t * t) / 2 << " m" << endl;
}

void velocityCalculator()
{
    double t;

    cout << "Enter the time interval (t):" << endl;
    inputNumber(t);

    cout << "Our formula is V = g * t" << endl;
    cout << "First we replace the values:" << endl;
    cout << "V = " << 10 << " * " << t << endl;
    cout << "Then we calculate our eqalation:" << endl;
    cout << "s = " << 10 * t << " m/s" << endl;
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



int main()
{
    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    char sym;
    cin >> sym;

    int correctExerciseCount = 0;
    bool isCorrect;

    int exerciseChecker = 0;

    while (sym != 'c' && sym != 'p')
    {
        cout << "Please enter a valid input!" << endl;
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
        exerciseChecker++;
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


    


    cout << "Would you like to use the calculator or solve a problem? (c/p)" << endl;
    cin >> sym;

    while (sym != 'c' && sym != 'p')
    {
        cout << "Please enter a valid input!" << endl;
        cin >> sym;
    }
    if (sym == 'c')
    {
        cout << "Enter the unit we are searching (s/V)" << endl;
        cin >> sym;
        velocityDistanceCalculator(sym);
    }
    
    cout << "You got " << correctExerciseCount << " out of 2 points!";
}