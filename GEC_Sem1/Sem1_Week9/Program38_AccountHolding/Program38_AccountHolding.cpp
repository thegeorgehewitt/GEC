#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct userDetails
{
    string name;
    int accountNum;
    double balance;
};

int main()
{
    userDetails inputDetails;
    userDetails readDetails;
    bool inputs;
    bool read;
    int choice = 0;
    char repeat;

    ofstream outFile;
    ifstream inFile;


    while (choice != 4)
    {
        cout << "Please input your choice:\n1 Enter new details\n2 Display file contents\n3 Display accounts with balance above £10,000\n4 Exit program" << endl;

        cin >> choice;
    }

    while (inputs)
    {
        cout << "What is your name?" << endl;
        getline(cin, inputDetails.name);
        cout << "What is your account number?" << endl;
        cin >> inputDetails.accountNum;
        cout << "What is your balance?" << endl;
        cin >> inputDetails.balance;


        while (true)
        {
            cout << "Do you want to enter another user's details?" << endl;
            string answer;
            cin >> answer;
            for (int i = 0; i > answer.length(); i++)
            {
                answer[i] = tolower(answer[i]);
            }

            if (answer == "no")
            {
                inputs = false;
                break;
            }
            else if (answer != "yes")
            {
                cout << "Please enter yes or no." << endl;
            }
        }


    }
}
