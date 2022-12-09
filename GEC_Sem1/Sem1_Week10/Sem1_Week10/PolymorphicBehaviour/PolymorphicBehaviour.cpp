#include "Mammals.h"
#include <iostream>

using namespace std;

int main()
{
    Mammal* mammalPtr;
    int choice;

    cout << "1.Dog 2.Cat 3.Horse 4.Pig" << endl << "Enter choice: ";
    cin >> choice;

    cin.clear();
    cin.ignore(numeric_limits <streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
        mammalPtr = new Dog;
        break;
    case 2:
        mammalPtr = new Cat;
        break;
    case 3:
        mammalPtr = new Horse;
        break;
    case 4:
        mammalPtr = new Pig;
        break;
    default:
        mammalPtr = new Mammal();
    }

    mammalPtr->Speak();

    cin.get();
    return 0;
}