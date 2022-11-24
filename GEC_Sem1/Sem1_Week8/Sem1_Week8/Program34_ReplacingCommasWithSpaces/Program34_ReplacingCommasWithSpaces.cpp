#include <iostream>
using namespace std;

void comma2blank(char* textToChange);

int main()
{
    char inputText[50];

    cout << "Please input a sentance, but use a comma in place of any spaces." << endl;
    cin >> inputText;

    char* pInputText = inputText;

    comma2blank(pInputText);

    cout << inputText;
}

void comma2blank(char* textToChange)
{
    for (int i = 0; i < 50; i++)
    {
        if (*(textToChange + i) == ',')
        {
            *(textToChange + i) = ' ';
        }
    }
}