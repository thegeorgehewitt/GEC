#include <iostream>
using namespace std;

int main()
{
    int playerLife = 100;
    int damage = 0;
    cout << playerLife << endl;

    
    for (int i = 1; i < 11; i++)
    {
        cout << "Question " << i << ": How much damage shall I deal?" << endl;
        cin >> damage;
        playerLife -= damage;
        if (playerLife < 1)
        {
            cout << "Early end. Player Died!" << endl;
            break;
        }
    }
    
    if (playerLife > 0)
    {
        cout << "All questions asked. Player survived!" << endl;
    }

}
