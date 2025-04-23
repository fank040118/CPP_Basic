/*
Course: CS215_401
Project: Project1
Purpose: print superbowl season by roman numeral
Author: Anthony(Zijian) Wang
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
I = 1
IV = 4
V = 5
IX = 9
X = 10
XL = 40
L = 50
XC = 90
C = 100
CD = 400
D = 500
CM = 900
M = 1000
*/

string roman_numeral(int n){
    /*
    there is another way to do this is set two array for store number vs roman numerals
    then use for loop and a while loop to check is number >= userInput to add num, such as
    
    int array_Num[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string array_Roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string romanNum;
    for(int i = 0; i < 13; i++){
        while(n >= array_Num[i]){
            n = n - array_Num[i];
            romanNum = romanNum + array_Roman[i];
        }
    }
    return romanNum;
    
    but I'm not sure is it acceptable, so I didn't write like that, 
    just let you know I can do as that way if that is what you expect
    */

    // if userYear >= the year that corresponding to Roman numerals, then romanNum string
    // will add the corresponding romanNum, and remain year minus the roman numerals
    string romanNum;
    while(n >= 1000){
        n = n - 1000;
        romanNum = romanNum + "M";
    }
    if(n >= 900){
        n = n - 900;
        romanNum = romanNum + "CM";
    }
    if(n >= 500){
        n = n - 500;
        romanNum = romanNum + "D";
    }
    if(n >= 400){
        n = n - 400;
        romanNum = romanNum + "CD";
    }
    while(n >= 100){
        n = n - 100;
        romanNum = romanNum + "C";
    }
    if(n >= 90){
        romanNum = romanNum + "XC";
        n = n - 90;
    }
    if(n >= 50){
        romanNum = romanNum + "L";
        n = n - 50;
    }
    if(n >= 40){
        romanNum = romanNum + "XL";
        n = n - 40;
    }
    while(n >= 10){
        romanNum = romanNum + "X";
        n = n - 10;
    }
    if(n >= 9){
        romanNum = romanNum + "IX";
        n = n - 9;
    }
    if(n >= 5){
        romanNum = romanNum + "V";
        n = n - 5;
    }
    if(n >= 4){
        romanNum = romanNum + "IV";
        n = n - 4;
    }
    while(n >= 1){
        romanNum = romanNum + "I";
        n = n - 1;
    }
    // return the romanNum string
    return romanNum;
    
}


int main()
{
    // creat constant number for year cenvert
	const int FIRST_YEAR = 1967;
    const int maxNum = 3999;
    const int maxYear = FIRST_YEAR + maxNum - 1;
    int userInput;

    //__________________________________________________________________________

    bool loopState = true;
    while(loopState){
        // print introduction
        cout << 
        "**************************************************************** \n" <<
        "* Super Bowl I took place on January 15, 1967.                 * \n" <<
        "* This Roman Numerals Converter was written by Jeremiah Davis. * \n" <<
        "* If you had a time machine, which year of the Super Bowl      * \n" <<
        "* would you like to attend (1967 - 5965) ?                     * \n" <<
        "**************************************************************** \n" << endl;
        cout << "Please enter the year you want to attend (press Q or q to quit) :";
        cin >> userInput;

        // if userInput is a number, then: 
        if (!cin.fail()){
            cout << " The time machine will bring you to the year " << userInput << "\n";
            // if userInput is between 1967 to 5965, then call the function
            if(userInput >= 1967 && userInput <= maxYear){
                cout << "It is Super Bowl " << roman_numeral(userInput-1967+1) 
                <<"." << endl;
            }
            // if userInput is not between that interval, print error massage then reloop
            else if(userInput < 1967){
                cout << "Wait! That year is before the first Super Bowl!" << endl;
            }
            else{
                cout << "Wait! That number is too large for Roman Numerals!" << endl;
            }

        }

        else{
            // clear falg for cin, input rest data to userInput_Check
            cin.clear();
            string userInput_Check;
            cin >> userInput_Check;
            // if input == Q | q, then set loopState to false to quit the loop
            if(userInput_Check == "Q" || userInput_Check == "q"){
                cout << "Back to 2024. Have a great day!" << endl;
                loopState = false;
            }
            // else, reloop
            else{
                cout << "Please use a four-digit numeral to represent a year (1967-5965)!" << endl;
            }
        }
        // clear flag and remove rest data before next input
        cin.clear();
        cin.ignore(1000,'\n');
        cout << endl;

    }

	return 0;
}