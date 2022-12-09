#include <iostream>
#include "ChildClass.h"

int main()
{
    cout << "\nCreating child class on the HEAP" << endl;
    ChildClass* pChild = new ChildClass();

    cout << "Deleting child class from HEAP" << endl;
    delete pChild;

    cout << "Creating child class on the STACK" << endl;
    ChildClass child;

    cin.get();

    cout << "\nExiting program - stack will be cleared" << endl;

    return 0;
}