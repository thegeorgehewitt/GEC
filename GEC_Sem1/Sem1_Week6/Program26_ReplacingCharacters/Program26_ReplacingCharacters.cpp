#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    cout << "Please input a sentence." << endl;
    getline(cin, sentence);

    while (sentence.find("e") >= 0 && sentence.find("e") <= sentence.length())
    {
        sentence.replace(sentence.find("e"), 1, "x");
    }

    cout << sentence << endl;
}