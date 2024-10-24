/*
Course: CS215_401
Project: Lab5
Purpose: print triangle by 3 different degrees
Author: Anthony(Zijian) Wang
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void drawTri(int userInput){
    // print triangle
    cout << "The triangle with size " << userInput << " is: \n";
    for(int i = 0; i < userInput; i++){
        int level = i + 1;
        for(int k = 1; k <= userInput - level; k++){
        cout << ' ';
        }
        for(int j = userInput-level; j < userInput+level-1; j++){
            cout << '*';
        }
        cout << endl;
    }
}

void drawTriR90(int userInput){
    cout << endl;
    // print triangle rotated 90 degrees
        cout << "The rotation for 90 degrees clockwise: \n";
        int level = 1;
        for (int i = 1; i <= userInput; i++) {
            for (int k = 1; k <= level; k++) {
                cout << "*";
            }
            cout << endl;
            level++;
        }
        for (int i = 1; i <= userInput; i++) {
            for(int k = level-2; k >= 1; k--){
                    cout << "*";
            }
            cout << endl;
            level--;
        }
}

void drawTriR180(int userInput){
    cout << endl;
    // print triangle rotated 180 degrees
    cout << "The rotation for 180 degrees clockwise: \n";
    int level = userInput;
    for(int i = 0; i <= userInput; i++){
        for(int k = 1; k <= i; k++){
        cout << ' ';
        }
        for(int j = 1; j <= level*2-1; j++){
            cout << '*';
        }
        cout << endl;
        level--;
    }
}

int main()
{
    int userInput;
    // repeat until user enter Q
    bool loop = true;
    while(loop){
        if(cin.fail()){
            // check user input if it's not int
            cin.clear();
            string userInput_Check;
            cin >> userInput_Check;
            // quit program if it's Q or q
            if(userInput_Check == "q" || userInput_Check == "Q"){
                cout << "Thank you, have a great day!" << endl;
                loop = false;
            }
            // reloop if it's not Q or q
            else
                cout << "Invalid size!" << endl;
        // clean all input
        cin.clear();
        cin.ignore(1000,'\n');
        }

        cout << "Enter the size of your triangle (integer in [1, 30]) \n"
        << "Type Q to quit the program: ";
        cin >> userInput;

        if(!cin.fail()){
            cout << endl;
            // call function for draw triangle if userInput is in 1~30
            if(userInput >= 1 && userInput <= 30){
                drawTri(userInput);
                drawTriR90(userInput);
                drawTriR180(userInput);
            }
            else{
            // repeat loop without drawTri function if input out of range
            cout << "The size is not in the correct range!" << endl;
            }
            // clear any input that haven't been input.
        cin.ignore(1000,'\n');
        }
    }
    return 0;
}
