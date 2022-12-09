#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Hamster.h"

int main()
{
    Pet* petPtr;
    int choice;

    cout << "1.Dog 2.Cat 3.Hamster" << endl << "Enter choice: ";
    cin >> choice;

    cin.clear();
    cin.ignore(numeric_limits <streamsize>::max(), '\n');

    if (choice == 1) { petPtr = new Dog(0,0); }
    else if (choice == 2) { petPtr = new Cat(0,0); }
    else if (choice == 3) { petPtr = new Hamster(0,0); }
    else { petPtr = new Pet(0,0); }

    petPtr->Talk();

    choice = 1;
    while (choice != 0)
    {
        cout << "0. Quit\n1. Listen to your Pet\n2. Feed your Pet\n3. Play with your pet" << endl << "Enter choice: ";
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');

        switch (choice)
        {
        case 0:
            cout << "thank you, bye :)";
            system("PAUSE");
            break;
        case 1:
            petPtr->Talk();
            break;
        case 2:
            petPtr->Feed();
            break;
        case 3:
            petPtr->Play();
            break;
        default:
            cout << "You need to enter 0, 1, 2 or 3." << endl;
        }
    }
}
