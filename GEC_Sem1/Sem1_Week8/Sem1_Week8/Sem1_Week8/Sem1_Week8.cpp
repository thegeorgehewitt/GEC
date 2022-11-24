#include <iostream>
using namespace std;

void swap(int& rNum1, int& rNum2);

int main()
{
    int num1 = 5, num2 = 10;

    cout << "Main: Before swap." << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    
    swap(num1, num2);

    cout << "Main: After swap." << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    cin.get();

    return 0;
}

void swap(int& rNum1, int& rNum2)
{
    int temp;

    cout << "Swap: Before swap." << endl;
    cout << "pNum1 = " << rNum1 << endl;
    cout << "pNum2 = " << rNum2 << endl;

    temp = rNum1;
    rNum1 = rNum2;
    rNum2 = temp;

    cout << "Swap: After swap." << endl;
    cout << "pNum1 = " << rNum1 << endl;
    cout << "pNum2 = " << rNum2 << endl;
}