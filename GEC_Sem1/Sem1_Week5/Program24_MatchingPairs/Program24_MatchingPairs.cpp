#include <iostream>
#include <stdlib.h>
using namespace std;

void board();
void guess(int a, int b);

bool found[5] = { false };
int count = 0;

int main()
{
    char cardFaces[] = { 'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e' };
    string cards[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]", "[10]" };
    int score;
    bool playing = true;

    while (playing == true)
    {
        int guess1;
        int guess2;

        cout << cards[0, 4] << "\n" << cards[5, 9] << endl;

        cout << "Pick a card" << endl;
        cin >> guess1;
        cout << "Pick another card" << endl;
        cin >> guess2;




    }

}

void board()
{
    system("cls");
    cout << "You have made " << count << " guesses." << endl;


}

void guess(int a, int b)
{

}