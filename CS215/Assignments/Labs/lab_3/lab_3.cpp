/*
Course: CS215_401
Project: Lab3
Purpose: This program shows Roman numerals of user input
Author: Anthony(Zijian) Wang
*/
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

    // end program if user input is bigger than 99 or smaller than 1
    if(userInput > 99 || userInput < 1){
        cout << "Your input number is not in the correct range." << endl;
        return(0);
    }

    // convert input to roman numerals if input are between 99 to 1
    if(userInput<=99 && userInput >=1){
        
        cout << "the number you entered is: " << userInput << endl;
        cout << "The Roman Numeral is: ";

        /*
        If the input as an int variable can be divided by 90 and the result 
        is not equal to 0, it means that it can be converted to XC.
        same as below
        */
        if(userInput/90 != 0){
            cout << "XC";
            userInput = userInput - 90;
        }

        if(userInput/50 != 0){
            cout << "L";
            userInput = userInput - 50;
        }

        if(userInput/40 != 0){
            cout << "XL";
            userInput = userInput - 40;
        }

        while(userInput/10 != 0){
            cout << "X";
            userInput = userInput - 10;
        }

        if(userInput/9 != 0){
            cout << "IX";
            userInput = userInput - 9;
        }

        if(userInput/5 != 0){
            cout << "V";
            userInput = userInput - 5;
        }

        if(userInput/4 != 0){
            cout << "IV";
            userInput = userInput - 4;
        }

        while(userInput/1 != 0){
            cout << "I";
            userInput = userInput - 1;
        }
    }
    cout << endl;
    return(0);
}