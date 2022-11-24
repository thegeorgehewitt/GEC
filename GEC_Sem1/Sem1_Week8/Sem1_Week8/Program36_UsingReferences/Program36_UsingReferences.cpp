#include <iostream>
using namespace std;

void plus25(int& rNumber);
void minus25(int& rNumber);

int main()
{
    int num;
    int& rNum = num;

    cout << "Please input a number:" << endl;
    cin >> num;
    cout << "The value of num is " << num << endl;

    plus25(rNum);

    cout << "The value of num is " << num << endl;

    cout << "Please input another number:" << endl;
    cin >> num;
    cout << "The value of num is " << num << endl;

    minus25(rNum);

    cout << "The value of num is " << num << endl;
}

void plus25(int& rNumber)
{
    rNumber += 25;
}

void minus25(int& rNumber)
{
    rNumber -= 25;
}