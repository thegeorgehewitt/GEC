#include <iostream>
using namespace std;

void SmallestNumber(int a, int b);
float Multiply(int c);
void Divide(float d);

int main()
{
    int num1, num2;
    for (int i = 0; i < 3; i++)
    {
        cout << "Please input your first number." << endl;
        cin >> num1;
        cout << "Please input your second number." << endl;
        cin >> num2;
        SmallestNumber(num1, num2);
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Please input 1 number to be multiplied." << endl;
        cin >> num1;
        float num3 = Multiply(num1);
        Divide(num3);
        
    }
}

void SmallestNumber(int a, int b)
{
    if (a < b)
    {
        cout << "The smallest number is " << a << endl;
    }
    else
    {
        cout << "The smallest number is " << b << endl;
    }
}

float Multiply(int c)
{
    return c * 10;
}

void Divide(float d)
{
    cout << d << " divided by 3 = " << d / 3 << endl;
}