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
    bool validInput = false;
    int guess1;
    int guess2;

    while (playing == true)
    {
        board();
        validInput = false;

        do
        {
            cout << "Pick a card" << endl;
            cin >> guess1;
            while (!(cin.good()))
            {
                cin.clear();
                cin.ignore();
                cout << "Please input the number of the card you wish to check:" << endl;
                cin >> guess1;
            }
            cout << "Pick another card" << endl;
            cin >> guess2;
            while (!(cin.good()))
            {
                cin.clear();
                cin.ignore();
                cout << "Please input the number on the card you wish to check:" << endl;
                cin >> guess1;
            }

            if (guess1 < 1 || guess1 > 10 || guess2 < 1 || guess2 > 10)
            {
                cout << "Please select from the available cards." << endl;
                system("pause");
            }
            else if (found[guess1 - 1] == 1 || found[guess2 - 1] == 1)
            {
                cout << "You need to pick cards that haven't been matched yet." << endl;
                system("pause");
            }
            else if (guess1 == guess2)
            {
                cout << "You need to pick two different cards." << endl;
            }
            else
            {
                validInput = true;

                if (cardFaces[(guess1 - 1)] == cardFaces[(guess2 - 1)])
                {
                    score++;
                    found[guess1 - 1] = 1;
                    found[guess2 - 1] = 1;
                }
            }
        } while (!validInput);
        
        guessCount++;

        guess(guess1, guess2);

        if (cardFaces[(guess1 - 1)] == cardFaces[(guess2 - 1)])
        {
            cout << "That's a match!" << endl;
        }
        else
        {
            cout << "Not a match." << endl;
        }

        if (score == 5)
        {
            cout << "You win!" << endl;
            playing = false;
        }

        system("pause");
    }

}

void board()
{
    system("cls");

    string guessAmount = " guesses";

    if (guessCount == 1)
    {
        guessAmount = " guess.";
    }

    cout << "You have made " << guessCount << guessAmount << endl;

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
    string guessAmount = " guesses";

    if (guessCount == 1)
    {
        guessAmount = " guess.";
    }

    cout << "You have made " << guessCount << guessAmount << endl;

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