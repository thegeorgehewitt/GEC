#include <iostream>
using namespace std;

int main()
{
    int userNumbers[10];
    int currentNum;

    for (int i = 0; i < 10; i++)
    {
        cout << "Please input a number: " << endl;
        cin >> userNumbers[i];
    }

    int smallestNum = userNumbers[0];
    int smallestPos = 0;

    for (int i = 1; i < 10; i++)
    {
        currentNum = userNumbers[i];
        if (currentNum < smallestNum)
        {
            smallestNum = currentNum;
            smallestPos = i + 1;
        }
    }

    cout << "The smallest number is " << smallestNum << " and it is in position " << smallestPos << "." << endl;
}