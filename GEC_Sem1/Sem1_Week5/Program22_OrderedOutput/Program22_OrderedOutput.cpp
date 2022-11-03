#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int userNums[5];
    int currentNum;

    for (int i = 0; i < 5; i++)
    {
        cout << "Please input a number: " << endl;
        cin >> userNums[i];
    }

    int largestNum = userNums[0];
    int largestPos = 0;

    for (int i = 1; i < 10; i++)
    {
        currentNum = userNums[i];
        currentNum = userNums[i];
        if (currentNum > largestNum)
        {
            largestNum = currentNum;
            largestPos = i + 1;
        }
    }

    sort(userNums, userNums + 5);
    cout << "\nIn ascending order: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << userNums[i] << " " << endl;
    }
    sort(userNums, userNums + 5, greater<int>());
    cout << "\nIn descending order: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << userNums[i] << " " << endl;
    }

    cout << "\nThe largest number is " << largestNum << " and it is in position " << largestPos << "." << endl;
}
