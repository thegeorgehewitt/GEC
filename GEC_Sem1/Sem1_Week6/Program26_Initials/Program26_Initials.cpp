#include <iostream>
#include<string>
using namespace std;

char name[50];

int main()
{
    cout << "Please input your name in the format F M Surname" << endl;
    cin.getline(name, 50);

    char firstInitial = name[0];
    cout << firstInitial << endl;

    char middleInitial;
    char surname[100] = {};
    int captured = 0;

    for (int i = 0; i < size(name); i++)
    {
        if (name[i] == ' ')
        {
            if (captured < 1)
            {
                middleInitial = name[i + 1];
                cout << middleInitial << endl;
            }
            else
            {
                strcat_s(surname, sizeof(surname), name + (i + 1));
                cout << surname << endl;
            }
            captured++;
        }
    }
}