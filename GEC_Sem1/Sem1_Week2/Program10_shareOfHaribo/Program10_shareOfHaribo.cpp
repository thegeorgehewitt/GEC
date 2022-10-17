#include <iostream>
using namespace std;

int main()
{
    int numberOfHaribos = 40;
    int numberOfStudents = 14;
    int perStudent = numberOfHaribos / numberOfStudents;
    int leftOver = numberOfHaribos % numberOfStudents;

    cout << "Each student will receive " << perStudent << " packs each, and the remainging " << leftOver << " packs will go to you." << endl;

}
