#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void loadScores(int* score, string* name);
void updateScores(int* score, string* name);
void printScores(int* score, string* name);
void sortArray(int* score);

struct name_score
{
    int score;
    string name;
};
bool CustomSort(name_score lhs, name_score rhs);
int main()
{
    name_score place1, place2, place3, place4, place5, place6, place7, place8, place9, place10;
    // int scores[10] = {place1.score, place2.score, place3.score, place4.score, place5.score, place6.score, place7.score, place8.score, place9.score, place10.score };
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
            cin.ignore();
            getline(cin, name);

            cout << "Please input a score." << endl;
            cin >> score;

            for (int i = 0; i < 10; i++)
            {
                if (places[i].score < score);
                {
                    
                    places[i].score = score;
                    places[i].name = name;
                    i = 10;
                }
            }
            if (score > (places[9]).score)
            {
                
                (places[9]).score = score;
                (places[9]).name = name;
                sort(places, places + 10, &CustomSort);
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < 1; i++)
            {
                cout << (places[i]).name << endl;
                cout << (places[i]).score << endl;
            }
        }
    }

}

bool CustomSort(name_score lhs, name_score rhs)
{
    return lhs.score > rhs.score;

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

void sortArray(int* score)
{
    
}