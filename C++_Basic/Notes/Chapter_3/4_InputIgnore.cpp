#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    char firstName, lastName;

    cout << "please enter you first and last name." << endl;
    /*
    
    */
    firstName = cin.get();
    cin.ignore(1000,' ');
    lastName = cin.get();

    cout << "your initial is " << firstName << " " << lastName << endl;

    return(0);
}