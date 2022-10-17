#include <iostream>
using namespace std;

int main()
{
    int difficulty;

    cout << "Please choose your difficulty:\n1. I'm too young to die!\n2. Hey not too rough!\n3. Hurt me plently.\n4. Ultra-violance.\n5. Nightmare..." << endl;
    cin >> (difficulty);

    switch (difficulty)
    {
        case 1:
            cout << "Then die you shall not! Maybe..." << endl;
            break;
        case 2:
            cout << "Hmm okay... *zombiemen approach*" << endl;
            break;
        case 3:
            cout << "My pleasure! *unleashes the imps*" << endl;
            break;
        case 4:
            cout << "Activating Ultra-violence!" << endl;
            break;
        case 5:
            cout << "Let the nightmare begin!" << endl;
            break;
        default:
            cout << "Did you not wanna play or..." << endl;
            break;
    }
}
