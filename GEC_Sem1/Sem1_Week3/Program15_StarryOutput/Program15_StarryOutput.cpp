#include <iostream>
#include <cctype>
#include <Windows.h>
#include <cstdlib>
using namespace std;

int main()
{
    int numLines = 0;
    char playAgain = 'Y';

    do
    {
        do
        {
            cout << "Please enter a number between 1 and 10: " << endl;
            cin >> numLines;
        } while (numLines > 10 || numLines < 1);

        for (int i = 1; i <= numLines; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }

        do
        {
            cout << "Do you want to go again? (Y or N) " << endl;
            cin >> playAgain;
            playAgain = toupper(playAgain);
        } while (playAgain != 'Y' && playAgain != 'N');
        

    } while (playAgain != 'N');

    cout << "Thanks for playing!" << endl;
    Sleep(2000);
}