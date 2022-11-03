#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myNumbers;

    myNumbers.push_back(18);
    myNumbers.push_back(22);
    myNumbers.push_back(12);

    for (int i = 0; i < myNumbers.size(); i++)
    {
        cout << myNumbers[i] << endl;
    }

    cout << "\nPosition 2 in the vector holds: " << myNumbers[1] << endl;

    myNumbers.pop_back();
    cout << "\nVector now contains:" << endl;
    for (int i = 0; i < myNumbers.size(); i++)
    {
        cout << myNumbers[i] << endl;
    }

    myNumbers.clear();

    if (myNumbers.empty())
        cout << "Vector is empty" << endl;
}