#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void loadScores(int* score, string* name);
void updateScores(int* score, string* name);
void printScores(int* score, string* name);

struct name_score
{
    int score;
    string name;
};

int main()
{
    name_score place1;
    name_score place2;
    name_score place3;
    name_score place4;
    name_score place5;
    name_score place6;
    name_score place7;
    name_score place8;
    name_score place9;
    name_score place10;
    int scores[10] = {place1.score, place2.score, place3.score, place4.score, place5.score, place6.score, place7.score, place8.score, place9.score, place10.score };
    name_score places[10] = { place1, place2, place3, place4, place5, place6, place7, place8, place9, place10 };


    while (true)
    {
        string name;
        int score;
        int choice = 0;

        while (choice < 1 || choice > 3)
        {
            cout << "Menu\n1. Enter a Score\n2. Display Scores\n3. Exit" << endl;
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 3)
            {
                cin.clear();
                cin.ignore();
                cout << "Please input 1, 2 or 3.";
            }
        }

        if (choice == 1)
        {
            cout << "Please input a name." << endl;
            getline(cin, name);

            cout << "Please input a score." << endl;
            cin >> score;

            if (score > (places[9]).score)
            {
                
                (places[9]).score = score;
                sort(places, places + 10), greater<int>();
            }
        }
    }

}

void loadScores(int* score, string* name)
{
    ifstream inFile;
    int count = 0;

    inFile.open("Scores.txt");

    while (inFile >> *(name + count))
    {
        inFile >> *(score + count);
        count++;
    }
    
    inFile.close();
}

void updateScores(int* score, string* name)
{
    ofstream outFile;

    for (int i = 0; i < 10; i++)
    {
        outFile << (name + i);
        outFile << (score + i);
    }

    outFile.close();
}

void printScores(int* score, string* name)
{
    for (int i = 0; i < 10; i++)
    {
        cout << (name + i) << endl;
        cout << (score + i) << endl;
    }
}