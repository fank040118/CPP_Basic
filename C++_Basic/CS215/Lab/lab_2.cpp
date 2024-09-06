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

    const double changeAmount = receivedAmount - totalAmount + 0.008;

    if (changeAmount < 0) {
        cout << "You didn't pay enough." << endl;
        cout << "You shoule pay another " << totalAmount - receivedAmount << " dollar(s)." << endl;
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

        if ((changeLeft / 1) >= 1) {
            dollarReturn = changeLeft / 1;
            changeLeft = changeLeft - dollarReturn;
        }

        if((changeLeft / 0.25) >= 1) {
            quarterReturn = changeLeft / 0.25;
            changeLeft = changeLeft - (quarterReturn*0.25);
        }

        if((changeLeft / 0.1) >= 1) {
            dimeReturn = changeLeft / 0.1;
            changeLeft = changeLeft - (dimeReturn*0.1);
        }

        if((changeLeft / 0.05) >= 1) {
            nickelReturn = changeLeft / 0.05;
            changeLeft = changeLeft - (nickelReturn * 0.05);
        }

        if ((changeLeft / 0.01) >= 1) {
            pennyReturn = changeLeft / 0.01;
            changeLeft = changeLeft - (pennyReturn * 0.01);

            if (changeLeft > 0.007) {
                changeLeft = 0;
                pennyReturn = pennyReturn + 1;
            }
        }
        cout << fixed << setprecision(2) << "Change amount : " << changeAmount << "\n";
        cout << setfill('_') << right 
            << "Dollar : " << setw(7)  << dollarReturn << "\n"
            << "Quarter : " << setw(6) << quarterReturn << "\n"
            << "Dime : " << setw(9) << dimeReturn << "\n"
            << "Nickel : " << setw(7) << nickelReturn << "\n"
            << "Penny : " << setw(8) << pennyReturn << endl;
        cout << "change left :  " << changeLeft << " dollars" << endl;
    }

cout << "\n";
return 0;
}