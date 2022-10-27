#include <iostream>
using namespace std;

bool IsEven(int a);
void outputResults(int numOfOdd, int oddTotal, int numofEven, int evenTotal);

int main()
{
    int oddCount = 0, evenCount = 0, oddSum = 0, evenSum = 0;
    for (int i = 0; i < 10; i++)
    {
        int inputNum;
        cout << "Please input a number: ";
        cin >> inputNum;
        if (IsEven(inputNum))
        {
            evenCount++;
            evenSum += inputNum;
        }
        else
        {
            oddCount++;
            oddSum += inputNum;
        }

    }
    outputResults(oddCount, oddSum, evenCount, evenSum);
}

bool IsEven(int a)
{
    if (a % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void outputResults(int numOfOdd, int oddTotal, int numOfEven, int evenTotal)
{
    cout << "You entered " << numOfOdd << " odd numbers, which total " << oddTotal << "." << endl;
    cout << "You entered " << numOfEven << " even numbers, which total " << evenTotal << "." << endl;
}