#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct name_score
{
    int score;
    string name;
};

void loadScores(name_score* pPlaces);
void updateScores(name_score* pPlaces);

int main()
{
    name_score place1, place2, place3, place4, place5, place6, place7, place8, place9, place10;
    name_score places[10] = { place1, place2, place3, place4, place5, place6, place7, place8, place9, place10 };

    name_score* pPlaces = &places[0];

    while (true)
    {
        string name;
        string scoreStr;
        int score;
        int choice = 0;

        loadScores(pPlaces);

        cout << endl;
        cout << setfill('-') << setw(16) << "Menu" << setw(12) << "\n" << endl;
        cout << setfill(' ') << setw(21) << "1. Enter a Score" << endl;
        cout << setw(21) << "2. Top 10 Scores" << endl;
        cout << setw(13) << "3. Exit\n" << endl;

        while (choice < 1 || choice > 3)
        {
            cout << setw(13) << " ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 3)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << setw(26) << "Please input 1, 2 or 3." << endl;
            }
        }

        system("cls");
        cout << endl;

        if (choice == 1)
        {
            cout << setw(24) << "Please input a name." << endl;
            cout << endl;
            cin.ignore();
            getline(cin, name);

            score = 0;

            cout << endl;
            cout << setw(24) << "Please input a score." << endl;
            cout << endl;
            cin >> score;
            while (score == 0)
            {
                cout << endl;
                cout << setw(25) << "Please enter a number." << endl;
                cout << endl;
                cin.clear();
                cin.ignore(100, '\n');
                cin >> score;
            }

            for (int i = 0; i < 10; i++)
            {
                if (places[i].score < score)
                {
                    for (int j = 9; j > i; j--)
                    {
                        (places[j]).score = (places[j - 1]).score;
                        (places[j]).name = (places[j - 1]).name;
                    }
                    (places[i]).score = score;
                    (places[i]).name = name;
                    i = 10;
                }
            }
            updateScores(pPlaces);
        }

        else if (choice == 2)
        {
            bool scoreFound = false;

            cout << setfill('-') << setw(20) << "Top 10 Scores" << setw(8) << "\n" << endl;

            for (int i = 0; i < 10; i++)
            {
                if ((places[i]).score > 0)
                {
                    name = places[i].name;
                    scoreStr = to_string((places[i]).score);

                    cout << setfill(' ') << setw( ( (28 - name.length() ) / 2 ) + name.length() ) << name << endl;
                    cout << setw( ( (28 - scoreStr.length() ) / 2 ) + scoreStr.length() ) << scoreStr << endl;

                    cout << endl;

                    scoreFound = true;
                }
            }
            if (!scoreFound)
            {
                cout << "No scores currently held." << endl;
            }
            system("PAUSE");
        }
        else
        {
            cout << "Thank you, goodbye." << endl;
            system("PAUSE");
            exit(1);
        }
        system("cls");
    }
}

void loadScores(name_score* pPlaces)
{
    ifstream inFile;
    int count = 0;

    inFile.open("Scores.txt");

    if (inFile.is_open())
    {
        string line;

        while (getline(inFile, line))
        {
            (*(pPlaces + count)).name = line;

            getline(inFile, line);
            ((*(pPlaces + count)).score) = stoi(line, 0);

            count++;
        }
    }
    
    inFile.close();
}

void updateScores(name_score* pPlaces)
{
    ofstream outFile;

    outFile.open("Scores.txt");

    if (outFile.is_open())
    {
        for (int i = 0; i < 10; i++)
        {
            outFile << (*(pPlaces + i)).name << endl;
            outFile << (*(pPlaces + i)).score << endl;
        }
    }
    else
    {
        cout << "There was an issue with accessing the file.";
    }

    outFile.close();
}