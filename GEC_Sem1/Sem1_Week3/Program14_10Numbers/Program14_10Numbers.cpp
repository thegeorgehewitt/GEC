#include <iostream>
using namespace std;

int main()
{
    int inputNum = 0;
    int sum = 0;
    float mean = 0.0f;
    int numCount = 1;

    cout << "Please enter a number: " << endl;
    cin >> inputNum;
    sum += inputNum;
    mean = (float)sum / numCount;

    cout << "The sum of your numbers is " << sum << " and their average is " << mean << "." << endl;

    do
    {
        cout << "Please enter a number: " << endl;
        cin >> inputNum;

        if (inputNum != 0 || numCount < 3)
        {
            numCount++;
            sum += inputNum;
            mean = (float)sum / numCount;
            cout << "The sum of your numbers is " << sum << " and their average is " << mean << "." << endl;
        }
    } while (inputNum != 0);
    cout << "exit" << endl;
}