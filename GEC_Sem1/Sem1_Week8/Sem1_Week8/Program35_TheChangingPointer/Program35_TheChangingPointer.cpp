#include <iostream>
using namespace std;

void inputDetails(int* n1, int* n2);
void outputDetails(int& integer1, int& integer2, int* pointer);

int main()
{
    int* pNum;
    int num1;
    pNum = &num1;

    int num2;

    inputDetails(&num1, &num2);

    outputDetails(num1, num2, pNum);

    pNum = NULL;

    return 0;
}

void inputDetails(int* n1, int* n2)
{
    cout << "Please input a number:" << endl;
    cin >> *n1;

    cout << "Please input another number:" << endl;
    cin >> *n2;
}

void outputDetails(int& integer1, int& integer2, int* pointer)
{
    cout << "num1 = " << integer1 << endl;
    cout << "address of num1 = " << &integer1 << endl;
    cout << "num2 = " << integer2 << endl;
    cout << "address of num2 = " << &integer2 << endl;
    cout << "pNum = " << pointer << endl;
    cout << "value of variable at pNum = " << *pointer << endl;
    cout << "address of pNum = " << &pointer << endl;
}
