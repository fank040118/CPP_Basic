#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int)

int main()
{
    double maxNum, minNum, userSum = 0;
    int count = 0, primeCount = 0;
    bool loop = true;

    while(loop){
        cout << "Please enter a series of integers, then type Q or q to process:" << endl;
        double userInput_1;
        cin >> userInput_1;

        if(!cin.fail()){
            count++;
            if(floor(userInput_1) == userInput_1){
                if(isPrime(userInput_1) == true)
                    primeCount++;
            }
            if(count == 0){
                maxNum = userInput_1;
                minNum = userInput_1;
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else{
                if(userInput_1 > maxNum){
                    maxNum = userInput_1;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else if(userInput_1 < minNum){
                    minNum = userInput_1;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                else{
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }
            userSum = userSum + userInput_1;
            cout << "The current cumulative sum is: " << userSum << endl;
        }
        if(cin.fail()){
            cin.clear;
            string inputCheck;
            cin >> inputCheck;
            if(inputCheck == "q" || inputCheck == "Q"){
                if(count == 0){
                    cout << "No input number! \nHave a great day! " << endl;
                    loop = false;
                }
            
                if(count != 0){
                    cout << "Largest: " << maxNum
                    << "Smallest: " << minNum
                    << "How many prime number? " << primeCount << endl;
                }
            }
            else{
                cout << "Invalid input, please try again..." << endl;
                cin.ignore();
            }
        }
    }
    return(0);
}

bool isPrime(int userInput)
{
    if(userInput <= 1)
        return false;
    for(int i = 2; i <= sqrt(userInput); i++){
        if(userInput % i == 0)
            return false;
    }
    return true;
}
