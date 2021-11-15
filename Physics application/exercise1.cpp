#include <iostream>

using namespace std;

int main()
{
    float V, a, t;
    float V0, s;

    int arr[26];
    int arr1[26] = { 0 * 10 + (8 * 10 * 10) / 2 };

    bool flag = true;

    char sym, sym2;

    while (flag == true)
    {
        cout << "Enter the unit we are searching: (s/V)" << endl;

    jump:
        cin >> sym;
        if (sym == 's')
        {
            // s = V0 * t + (a * t * t) / 2;

            cout << "Enter the initial velocity of the body (Vo):" << endl;
            cin >> V0;

            cout << "Enter the time interval (t):" << endl;
            cin >> t;

            cout << "Enter the acceleration of the body (a):" << endl;
            cin >> a;

            cout << "Our formula is s = Vo * t + (a * t * t) / 2" << endl;

            cout << "First we replace the values:" << endl;

            cout << "s = " << V0 << "*" << t << " + " << "(" << a << "*" << t * t << ")" << "/2" << endl;

            cout << "Then we calculate our eqalation:" << endl;

            cout << "s = " << V0 * t << " + " << (a * t * t) / 2 << endl;

            cout << "s = " << V0 * t + (a * t * t) / 2 << " m" << endl;
            flag = false;
        }

        else if (sym == 'V')
        {

            // V = V0 + a * t;

            cout << "Enter the initial velocity of the body (Vo):" << endl;
            cin >> V0;

            cout << "Enter the acceleration of the body (a):" << endl;
            cin >> a;

            cout << "Enter the time interval (t):" << endl;
            cin >> t;

            cout << "Our formula is V = Vo + a * t" << endl;

            cout << "First we replace the values:" << endl;

            cout << "V = " << V0 << " + " << a << "*" << t << endl;

            cout << "Then we calculate our eqalation:" << endl;

            cout << "V = " << V0 << " + " << a * t << endl;

            cout << "V = " << V0 + a * t << " m/s" << endl;
            flag = false;
        }
        else
        {
            cout << "Enter right unit." << endl;
            goto jump;
        }
    }

    t = 0;
    V0 = 0;
    s = 0;
    a = 0;
    V = 0;

    cout << "Do you want to do another exercise or slove a problem? (e/p)" << endl;
    cin >> sym2;

    if (sym2 == 'e')
    {
        goto jump;
    }
    else
    {
        cout << "Now, try to slove this problem!" << endl;

        cout << "From rest, a car accelerated at 8 m/s2 for 10 seconds. What is the position of the car at the end of the 10 seconds? (s)" << endl;

    wrong:
        cout << "V0 = ";
        cin >> V0;
        if (V0 == 0)
        {
            cout << "a = ";
            cin >> a;
            if (a == 8)
            {
                cout << "t = ";
                cin >> t;
                if (t == 10)
                {
                    cout << "We have the formula ";
                    cout << "s = V0 * t + (a * t * t) / 2" << endl;
                    cout << "s = ";
                    for (int i = 0; i < 26; i++)
                    {
                        cin >> arr[i];
                    }

                    for (int i = 0; i < 26; i++)
                    {
                        if (arr[i] == arr1[i])
                        {
                            cout << "bravo be";
                            break;
                        }
                        else
                        {
                            cout << "NE";
                        }

                    }


                }
                else
                {
                    goto wrongAgain;
                }

            }
            else
            {
                goto wrongAgain;;
            }
        }

        else
        {
        wrongAgain:
            cout << "Wrong. Try again." << endl;
            goto wrong;
        }



    }

}