#include <iostream>
#include <stdlib.h>
using namespace std;

void board();
void guess(int a, int b);

bool found[10] = { false };
int guessCount = 0;
char cardFaces[] = { 'B', 'D', 'C', 'A', 'E', 'B', 'A', 'D', 'C', 'E' };

int main()
{
    
    int score = 0;
    bool playing = true;
    int guess1;
    int guess2;

    while (playing == true)
    {
        board();

        do
        {
            cout << "Pick a card" << endl;
            cin >> guess1;
            cout << "Pick another card" << endl;
            cin >> guess2;

            if (guess1 == guess2)
                cout << "You need to pick two different cards." << endl;
        } while (guess1 == guess2);
        
        if (cardFaces[(guess1-1)] == cardFaces[(guess2-1)])
        {
            score++;
            found[guess1 - 1] = true;
            found[guess2 - 1] = true;
        }

        if (cardFaces[(guess1 - 1)] != cardFaces[(guess2 - 1)])
        {
            guess(guess1, guess2);
            system("pause");
        }

        if (score == 5)
        {
            cout << "You win!" << endl;
            playing = false;
        }
        else
        {
            guessCount++;
        }
                
    }

}

void board()
{
    system("cls");
    cout << "You have made " << guessCount << " guess(es)." << endl;

    for (int i = 0; i < 10; i++)
    {
        if (found[i])
        {
            cout << "[" << cardFaces[i] << "]";
        }
        else
        {
            cout << "[" << i + 1 << "]";
        }

        if ((i == 4) || (i == 9))
        {
            cout << endl;
        }
    }
}

void guess(int a, int b)
{
    system("cls");
    cout << "You have made " << guessCount << " guess(es)." << endl;

    for (int i = 0; i < 10; i++)
    {
        if ((found[i]) || ((i == a - 1) || (i == b - 1)))
        {
            cout << "[" << cardFaces[i] << "]";
        }
        else
        {
            cout << "[" << i + 1 << "]";
        }

        if ((i == 4) || (i == 9))
        {
            cout << endl;
        }
    }

}