/*
Course: CS215_401
Project: Lab1_HelloWorld
Purpose: This program prints "Hallo World!" massage on computer screen
Author: Anthony(Zijian) Wang
*/

#include <iostream>

using namespace std;

int main()
{
    // Prints "Hello, world!" to the screen.
    cout << "Hello, Mr.Jeremiah Davis and Mr.Willow Jordan!" << endl;
    cout << "My name is Anthony Wang, Nice to meet you!" << endl;

    cout << "   -------   "<< endl;
    cout << "  -       -  "<< endl;
    cout << " -  *   *  - "<< endl;
    cout << " -         - "<< endl;
    cout << "  -  \\_/  -  "<< endl;
    cout << "   -------2   "<< endl;
    
    cout << endl;
    // Returning 0 (zero) means the program ended without problems.

    double hours = 0.0;
    cout << "how many hours are you going to spend on CS215 every week?" << endl;
    cin >> hours;

    const int HOUR_TO_MIN = 60;
    const int MIN_TO_SEC = 60;

    double seconds = hours * HOUR_TO_MIN * MIN_TO_SEC;
    
    cout << "Good luck! You will spend " << seconds << " seconds each week on CS215" << endl;

    cout << endl;

    return 0;
}