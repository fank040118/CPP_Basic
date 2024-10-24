/*
Course: CS215_401
Project: Lab4
Purpose: Find max and min for user input
Author: Anthony(Zijian) Wang
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int);
// declare function for calculate prime number.

int main()
{
    // creat variable
    int maxNum, minNum, userSum = 0;
    int count = 0, primeCount = 0;
    bool loop = true;

    // main program
    while(loop){
        
        cout << "Please enter a series of integers, then type Q or q to process: " 
        << endl;
        int userInput_1;
        cin >> userInput_1;
        

        // while cin.fail() is false, process max and min number for user input.
        if(!cin.fail()){
            // if userInput is a prime number, add prime number count to 1.
            if (userInput_1 > 0){
                if(isPrime(userInput_1) == true)
                    primeCount++;
            }
            // for the first time user input, set max and min to userInput.
            if(count == 0){
                maxNum = userInput_1;
                minNum = userInput_1;
            }
            // after first loop, compare userInput to max and min.
            if(count != 0){
                if(userInput_1 > maxNum)
                    maxNum = userInput_1;
                else if(userInput_1 < minNum)
                    minNum = userInput_1;
            }
            // output sum, clean and ignore rest input
            userSum = userSum + userInput_1;
            cout << "The current cumulative sum is: " << userSum << endl;
            count++;
            cin.clear();
            cin.ignore(1000,'\n');
        }
        // if cin is fail, check is user input equal to q or Q
        if(cin.fail()){
            cin.clear();
            string inputCheck;
            cin >> inputCheck;
            if(inputCheck == "q" || inputCheck == "Q"){
                // quit program without show results if user didn't enter any number
                if(count == 0){
                    cout << "No input number! \nHave a great day! " << endl;
                    loop = false;
                }
                // shows result if user end the program with vaild input
                if(count != 0){
                    cout << "Largest: " << maxNum << '\n'
                    << "Smallest: " << minNum << '\n'
                    << "How many prime number? " << primeCount << endl;
                    loop = false;
                }
            }
            // if input is not equal to Q, ask user to input again
            else{
                cout << "Invalid input, please try again..." << endl;
                cin.ignore(1000,'\n');
            }
        }
    }
    return 0;
}

bool isPrime(int userInput)
{
    // it's not a prime if number small or equal to one
    if(userInput <= 1)
        return false;
    // it's not a prime if number can be devided by any number that bigger than 1
    // to small tha square root of that number
    for(int i = 2; i <= sqrt(userInput); i++){
        if(userInput % i == 0)
            return false;
    }
    // it is a prime if this function didn't end before this line.
    return true;
}