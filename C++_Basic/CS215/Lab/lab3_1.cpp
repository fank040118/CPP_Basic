#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Welcome to the CS 215 Roman Numeral Converter \n" <<
    "Please input the number you want to convert to Roman numerals" << endl;
    cout << "(in the range of [1, 99]): ";
    int userInput;
    cin >> userInput;

    if(userInput > 99 || userInput < 1){
        cout << "Your input number is not in the correct range.";
    }

    if(userInput<=99 || userInput >=1){
        
        cout << "the number you entered is: " << userInput << endl;

        while(userInput/90 != 1)
    }



    return(0);
}