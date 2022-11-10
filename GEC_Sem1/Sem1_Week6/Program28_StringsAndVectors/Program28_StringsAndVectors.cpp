#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getInput(string option1, string option2);
void outputInventory();
vector<string> inventory;

int main()
{
    int numberChoice;
    string pickups[] = { "staff", "knife", "health potion", "fire spell"};
    int inventMax = 3;

    inventory.push_back("sword");

    int rounds = 0;
    while (inventory.size() < inventMax)
    {
        inventory.push_back(getInput(pickups[2 * rounds], pickups[(2 * rounds) + 1]));
        cout << "Your inventory holds:" << endl;
        outputInventory();
        rounds++;
    }

    cout << "\nYour inventory is full!" << endl;

    cout << "\nYou found a magic ring, what would you like to replace in your inventory?\nChoices:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ": " << inventory[i] << endl;
    }

    cout << "" << endl;

    cin >> numberChoice;

    while (!(cin.good()) || numberChoice < 1 || numberChoice > 3)
    {
        cout << "That doesn't look right, make sure to enter 1, 2 or 3." << endl;
        cin.clear();
        cin.ignore(200, '\n');
        cin >> numberChoice;
    }

    inventory[numberChoice-1] = "magic ring";

    cout << "\nInventory is now:" << endl;
    outputInventory();

    cout << "\nYou've been robbed!!" << endl;

    inventory.clear();

    cout << "Inventory is now:" << endl;
    outputInventory();
}

string getInput(string option1, string option2)
{
    string choice;

    while (choice != option1 && choice != option2)
    {
        cout << "Type which item you wish to keep: " << option1 << " or " << option2 << "?" << endl;
        getline (cin, choice);

        for (int i = 0; i < choice.length(); i++)
        {
            choice[i] = tolower(choice[i]);
        }

        if (choice != option1 && choice != option2)
        {
            cout << "That wasn't right, try again." << endl;
        }
        else
        {
            return choice;
        }
    }
}

void outputInventory()
{
    if (inventory.size() == 0)
        cout << "Empty!";
    else
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << endl;
        }
    }
}