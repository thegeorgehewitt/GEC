#include <iostream>
#include "cat.h"

using namespace std;

int main()
{
    cat button(5);

    cat* pDaisy = new cat(10);

    cout << "Button is " << button.GetAge() << " years old." << endl;
    cout << "Daisy is " << pDaisy->GetAge() << " years old." << endl;

    cin.get();

    delete pDaisy;

    return 0;
}
