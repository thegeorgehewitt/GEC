#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    struct Details
    {
        string name;
        int age;
        string phoneNum;

        void PrintDetails(string name, int age, string phoneNum)
        {
            cout << "Your name is " << name << ", your age is " << age << " and your phone number is " << phoneNum << "." << endl;
        }
    }userDetails;

    cout << "What is your name?" << endl;
    getline(cin, userDetails.name);

    cout << "What is your age?" << endl;
    cin >> userDetails.age;

    cout << "What is your phone number?" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userDetails.phoneNum);

    userDetails.PrintDetails(userDetails.name, userDetails.age, userDetails.phoneNum);
}