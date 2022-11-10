#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userChoice;
    string compChoice;
    string options[] = { "rock", "paper", "scissors" };
    int userWins = 0;
    int compWins = 0;
    srand((unsigned)time(NULL));


    while (userWins < 3 && compWins < 3)
    {
        cout << "You need " << (3 - userWins) << " to win the game." << endl;
        cout << "The computer needs " << (3 - compWins) << " to win the game." << endl;
        cout << "" << endl;

        while (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors")
        {
            cout << "Rock, paper or scissors?" << endl;
            cin >> userChoice;

            for (int i = 0; i < userChoice.length(); i++)
            {
                userChoice[i] = tolower(userChoice[i]);
            }
        }

        compChoice = options[(rand() % 2)];

        cout << "You chose: " << userChoice << "\nThe computer chose: " << compChoice << endl;

        if (userChoice.compare(compChoice) == 0)
        {
            cout << "Draw! Try again." << endl;
        }
        else if (userChoice == "paper")
        {
            if (compChoice == "rock")
            {
                cout << "You win!" << endl;
                userWins++;
            }
            else
            {
                cout << "You lose." << endl;
                compWins++;
            }
        }
        else if (userChoice == "rock")
        {
            if (compChoice == "paper")
            {
                cout << "You lose." << endl;
                compWins++;
            }
            else
            {
                cout << "You win!" << endl;
                userWins++;
            }
        }
        else
        {
            if (compChoice == "rock")
            {
                cout << "You lose." << endl;
                compWins++;
            }
            else
            {
                cout << "You win!" << endl;
                userWins++;
            }
        }

        userChoice = "";

    }

    if (userWins > compWins)
    {
        cout << "Congratulations, you won!\nGame Over" << endl;
    }
    else
    {
        cout << "You lose.\nGame over" << endl;
    }
    
}