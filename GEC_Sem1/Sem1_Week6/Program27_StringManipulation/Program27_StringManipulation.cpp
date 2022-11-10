#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userName;
    string userLongName;
    string testString = "Do you know who loves C++ XX does!";

    cout << "Please input your name" << endl;
    getline(cin, userName);

    testString.insert(27, userName, 0, userName.length());

    cout << testString << endl;

    testString.erase(testString.find('X'), 1);
    testString.erase(testString.rfind('X'), 1);

    cout << testString << endl;

    cout << "Please input another name, longer than yours" << endl;
    getline(cin, userLongName);

    testString.replace(testString.find(userName), userLongName.length(), userLongName);

    cout << testString << endl;
}