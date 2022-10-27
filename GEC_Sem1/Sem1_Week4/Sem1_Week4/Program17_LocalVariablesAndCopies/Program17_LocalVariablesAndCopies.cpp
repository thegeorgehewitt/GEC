#include <iostream>
using namespace std;

void addTwo(int num);

int main()
{
    int myNum = 6;
    cout << "MAIN [before]: nyNum = " << myNum << endl;
    addTwo(myNum);
    cout << "MAIN [after]: nyNum = " << myNum << endl;
}

void addTwo(int num)
{
    num += 2;
    cout << "FUNCTION: num = " << num << endl;
}