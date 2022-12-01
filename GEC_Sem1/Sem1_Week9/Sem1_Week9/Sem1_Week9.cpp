#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char character;
    int number = 51;
    int count = 0;
    ofstream out_stream;
    ifstream in_stream1;
    ifstream in_stream2;

    out_stream.open("Integers.txt", ios_base::out);
    for (count = 1; count <= 5; count++)
    {
        out_stream << number++ << " ";
    }
    out_stream.close();

    in_stream1.open("Integers.txt", ios_base::in);

    count = 0;
    in_stream1 >> number;

    do
    {
        count++;
        in_stream1 >> number;
    }
    while (!in_stream1.eof());
    
    in_stream1.close();

    cout << "There are " << count << " intgers in the file,\n";

    in_stream2.open("Integers.txt");
    count = 0;
    in_stream2 >> character;
    while (!in_stream2.eof())
    {
        count++;
        in_stream2 >> character;
    }
    in_stream2.close();
    cout << "represented using " << count << " characters." << endl;

    cin.get();

    return 0;
}