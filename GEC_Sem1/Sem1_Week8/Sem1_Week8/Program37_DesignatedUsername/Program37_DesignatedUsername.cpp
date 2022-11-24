#include <iostream>
#include <string>
using namespace std;

void newName(string& userName);

int main()
{
    string name;

    cout << "Please input your name: " << endl;
    getline(cin, name);

    string& rName = name;

    cout << "That username has been taken." << endl;

    newName(rName);

    cout << "Here's an alternative: " << name;
}

void newName(string& userName)
{
    srand(time(NULL));
    int num = rand();
    userName = userName + to_string(num);
}