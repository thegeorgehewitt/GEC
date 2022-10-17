#include <iostream>
using namespace std;

int main()
{
    char status;
    int game;

    cout << "Are you a student (input s), a teacher (input t), or something else (input o)? " << endl;
    cin >> status;
    cout << "Which game would you like, 1 or 2? " << endl;
    cin >> game;

    if ((status == 's' || status == 't') && (game == 1))
        cout << "You are entitled to a 20% discount." << endl;
    else if ((status == 's' || status == 't') && (game == 2))
        cout << "You are entitled to a 10% discount." << endl;
    else
        cout << "You are not entitled to a discount." << endl;
}
