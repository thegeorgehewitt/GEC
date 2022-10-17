#include <iostream>
using namespace std;

int main()
{
    int rain = 1;
    int snow = 2;
    float temp;
    int currentWeather;

    cout << "Hey is it raining (input 1) or snowing (input 2)? ";
    cin >> (currentWeather);
    cout << "And what's the temperature in degrees Celsius? ";
    cin >> (temp);

    if (currentWeather == 1)
        if (temp > 15)
            cout << "Wear a raincoat." << endl;
        else
            cout << "Wear a thick coat." << endl;
    else if (currentWeather == 2)
        if (temp > 5)
            cout << "Wear something warm." << endl;
        else if (temp > 0)
            cout << "Wrap up well." << endl;
        else
            cout << "Stay indoors." << endl;
    else
        cout << "Have a nice day." << endl;
}

