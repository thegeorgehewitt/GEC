#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    const int MAX_ITEMS = 4;
    int numItems = 0;
    char swap;
    string inventory[MAX_ITEMS] = { "sword", "battle axe", "healing potion", "dagger"};

    cout << "You have found a wizard's staff, would you like to swap it for your dagger? (y/n)" << endl;
    cin >> swap;

    if (swap == 'y')
    {
        inventory[3] = "wizard's staff";
        cout << "You have now aquired a wizard's staff. Your inventory contains:\n" << endl;
    }
    else
    {
        cout << "You leave the wizard's staff behind. Your inventory contains:\n" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << inventory[i] << "\n" << endl;
    }
}