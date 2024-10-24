/*
Course: CS215_401
Project: Lab6
Purpose: print superbowl season by roman numeral
Author: Anthony(Zijian) Wang
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
   It returns a string form of a Roman Numeral.
   n must be between 1 and 3999, inclusive.
   @param n int: representing the number to convert into Roman Numeral
   @return string: representing the corresponding Roman Numeral for n

L = 50
C = 100
D = 500
M = 1000
CM = 900
*/

/*
in the roman_numeral function, romanNum string will add the corresponding year
by while loop that check is the year bigger than the roman numeral, the year
will minus the number
*/

string roman_numeral(int n){
    string romanNum;
    int yearRemain = n;
    
    while(yearRemain >= 900){
        yearRemain = yearRemain - 900;
        romanNum = romanNum + "CM";
    }
    while(yearRemain >= 500){
        yearRemain = yearRemain - 500;
        romanNum = romanNum + "D";
    }
    while(yearRemain >= 100){
        yearRemain = yearRemain - 100;
        romanNum = romanNum + "C";
    }
    while(yearRemain >= 100){
        yearRemain = yearRemain - 100;
        romanNum = romanNum + "C";
    }
    if(yearRemain >= 90){
        romanNum = romanNum + "XC";
        yearRemain = yearRemain - 90;
    }

    if(yearRemain >= 50){
        romanNum = romanNum + "L";
        yearRemain = yearRemain - 50;
    }

    if(yearRemain >= 40){
        romanNum = romanNum + "XL";
        yearRemain = yearRemain - 40;
    }

    while(yearRemain >= 10){
        romanNum = romanNum + "X";
        yearRemain = yearRemain - 10;
    }
    if(yearRemain >= 9){
        romanNum = romanNum + "IX";
        yearRemain = yearRemain - 9;
    }
    if(yearRemain >= 5){
        romanNum = romanNum + "V";
        yearRemain = yearRemain - 5;
    }
    if(yearRemain >= 4){
        romanNum = romanNum + "IV";
        yearRemain = yearRemain - 4;
    }
    while(yearRemain >= 1){
        romanNum = romanNum + "I";
        yearRemain = yearRemain - 1;
    }
    return romanNum;
}

// Tests for your roman_numeral function.
// Note: you don't have to write anything in main().
// If you correctly complete the function, your program should compile and
// your output should be EXACTLY the same as show in the Lab 6 document.
int main()
{
	const int FIRST_YEAR = 1967;

	cout << setw(42) << "Super Bowl Records" << endl;
	cout << "The first Super Bowl was held at the Los Angeles Memorial" << endl;
	cout << "Coliseum on January 15, 1967." << endl;

	cout << setw(12) << "Year" << setw(22) << "Super Bowl" << endl;

	for (int year = 2000; year < 2100; year++)
	{
		int super_bowl_num = year - FIRST_YEAR + 1; // 起始值是34
		if (year % 10 == 0)
		{
			cout << endl << "************************************"
				 << endl << endl;
		}
		cout << setw(12) << year << setw(8) << "--->" << "    "
			 << roman_numeral(super_bowl_num) << endl;;
	}

	return 0;
}