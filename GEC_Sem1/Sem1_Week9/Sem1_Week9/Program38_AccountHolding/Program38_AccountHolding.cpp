#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct AccountDetails
{
    string name;
    int accountNum;
    double balance;
};

int main()
{
    AccountDetails userInput;
    AccountDetails fromFile;

    bool accountFound;

    int choice = 0;
    char again;

    ofstream outFile;
    ifstream inFile;

    while (true)
    {
        while (choice < 1 || choice > 4)
        {
            cout << "\nPlease make a selection:\n1 Enter new details\n2 Display file contents\n3 Display accounts with balance over 10,000\n4 Exit program" << endl;
            cin >> choice;        }

        if (choice == 1)
        {
            outFile.open("Accounts.txt", ios::app);

            if (outFile)
            {
                do
                {
                    cout << "Please input your name." << endl;
                    cin.ignore();
                    getline(cin, userInput.name);
                    cout << "Please input your account number." << endl;
                    cin >> userInput.accountNum;
                    cout << "Please input your balance." << endl;
                    cin >> userInput.balance;

                    outFile << userInput.name << endl;
                    outFile << userInput.accountNum << endl;
                    outFile << userInput.balance << endl;

                    do
                    {
                        again = ' ';
                        cout << "Would you like to enter more user details? (y/n)";
                        cin >> again;

                       if (again != 'y' && again != 'n')
                        {
                            cout << "That doesn't seem right, please enter 'y' or 'n'." << endl;
                            cin >> again;
                        }
                    } while (again != 'y' && again != 'n');
                } while (again == 'y');
            }

            outFile.close();
        }
        else if (choice == 2 || choice == 3)
        {
            inFile.open("Accounts.txt");

            if (inFile)
            {
                string line1;
                string line2;
                string line3;

                accountFound = false;

                getline(inFile, line1);
                fromFile.name = line1;
                getline(inFile, line2);
                fromFile.accountNum = stoi(line2);
                getline(inFile, line3);
                fromFile.balance = stof(line3);

                do
                {
                    if (fromFile.balance > 10000 || choice == 2)
                    {
                        cout << "\nName: " << fromFile.name << endl;
                        cout << "Account Number: " << fromFile.accountNum << endl;
                        cout << "Balance: " << fromFile.balance << endl;
                        accountFound = true;
                    }

                    getline(inFile, line1);
                    fromFile.name = line1;
                    getline(inFile, line2);
                    fromFile.accountNum = stoi(line2);
                    getline(inFile, line3);
                    fromFile.balance = stof(line3);

                }while (inFile);

                if (!accountFound)
                {
                    cout << "There are no accounts." << endl;
                }
            }

            inFile.close();
        }
        else
        {
            return 0;
        }

        choice = 0;
    }


}