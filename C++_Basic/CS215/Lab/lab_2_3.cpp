/*
Course: CS215_401
Project: Lab2
Purpose: This program shows changes for payments
Author: Anthony(Zijian) Wang
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    
    // declear and input amout should be paid and the money user gives
    double totalAmount;
    double receivedAmount;

    cout << "Enter the amount due : $ ";
    cin >> totalAmount;
    cout << "Enter the amount received : $ ";
    cin >> receivedAmount;

    // creat a constant variable for amount of changes
    const int changeAmount = round((receivedAmount - totalAmount) * 100);

    // end the program if user didn't pay enough
    if (changeAmount < 0) {
        cout << "You didn't pay enough." << endl;
        cout << "You shoule pay another " << totalAmount - receivedAmount
        << " dollar(s)." << endl;
        return 0;
    }

    // end the program if user's pay same as required
    if (changeAmount == 0) {
        cout << "the amount you paid is same amount as the price." << endl;
        return 0;
    }

    // calcualte changes if user's pay are bigger than amount should paid
    if (changeAmount > 0) {
        // creat variables for all the changes
        int changeLeft = changeAmount;
        int dollarReturn = 0;
        int quarterReturn = 0;
        int dimeReturn = 0;
        int nickelReturn = 0;
        int pennyReturn = 0;
        
        /*
        calculate different changes, For example: 
        Change in US dollars = total changes / (dollar * 100)
        because the price difference was converted into cents by * 100
        */
        dollarReturn = changeLeft / 100;
        changeLeft = changeLeft - (dollarReturn * 100);

        quarterReturn = changeLeft / 25;
        changeLeft = changeLeft - (quarterReturn * 25);

        dimeReturn = changeLeft / 10;
        changeLeft = changeLeft - (dimeReturn * 10);

        nickelReturn = changeLeft / 5;
        changeLeft = changeLeft - (nickelReturn * 5);

        pennyReturn = changeLeft / 1;
        changeLeft = changeLeft - (pennyReturn * 1);

        cout << endl;
        
        // cout all the changes should gives
        cout << fixed << setprecision(2) << "Change amount : " << changeAmount/100.0 << "\n";
        cout << setfill('_') << right 
            << "Dollar : " << setw(7)  << dollarReturn << "\n"
            << "Quarter : " << setw(6) << quarterReturn << "\n"
            << "Dime : " << setw(9) << dimeReturn << "\n"
            << "Nickel : " << setw(7) << nickelReturn << "\n"
            << "Penny : " << setw(8) << pennyReturn << endl;
        cout << "change left :  " << changeLeft/100.0 << " dollars" << endl;
    }
    
return 0;
}