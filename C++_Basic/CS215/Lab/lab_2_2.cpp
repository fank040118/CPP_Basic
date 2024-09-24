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
    double totalAmount;
    double receivedAmount;

    cout << "Enter the amount due : $ ";
    cin >> totalAmount;

    cout << "Enter the amount received : $ ";
    cin >> receivedAmount;

    const int changeAmount = round((receivedAmount - totalAmount) * 100);

    if (changeAmount < 0) {
        cout << "You didn't pay enough." << endl;
        cout << "You shoule pay another " << totalAmount - receivedAmount
        << " dollar(s)." << endl;
        return 0;
    }

    if (changeAmount == 0) {
        cout << "the amount you paid is same amount as the price." << endl;
        return 0;
    }

    if (changeAmount > 0) {
        double changeLeft = changeAmount;
        int dollarReturn = 0;
        int quarterReturn = 0;
        int dimeReturn = 0;
        int nickelReturn = 0;
        int pennyReturn = 0;

        if ((changeLeft / 100) >= 1) {
            dollarReturn = changeLeft / 100;
            changeLeft = changeLeft - dollarReturn;
        }

        if((changeLeft / 25) >= 1) {
            quarterReturn = changeLeft / 25;
            changeLeft = changeLeft - (quarterReturn*25);
        }

        if((changeLeft / 10) >= 1) {
            dimeReturn = changeLeft / 10;
            changeLeft = changeLeft - (dimeReturn*10);
        }

        if((changeLeft / 5) >= 1) {
            nickelReturn = changeLeft / 5;
            changeLeft = changeLeft - (nickelReturn * 5);
        }

        if ((changeLeft / 1) >= 1) {
            pennyReturn = changeLeft / 1;
            changeLeft = changeLeft - (pennyReturn * 1);

            if (changeLeft > 0.007) {
                changeLeft = 0;
                pennyReturn = pennyReturn + 1;
            }
        }
        cout << fixed << setprecision(2) << "Change amount : " << changeAmount/100.0 << "\n";
        cout << setfill('_') << right 
            << "Dollar : " << setw(7)  << dollarReturn << "\n"
            << "Quarter : " << setw(6) << quarterReturn << "\n"
            << "Dime : " << setw(9) << dimeReturn << "\n"
            << "Nickel : " << setw(7) << nickelReturn << "\n"
            << "Penny : " << setw(8) << pennyReturn << endl;
        cout << "change left :  " << changeLeft/100.0 << " dollars" << endl;
    }

cout << "\n";
return 0;
}