/*
 * Course:  CS215-401
 * Project: Lab 9
 * File:    MathOperations.cpp
 * Purpose: Define “MathOperations” class
 * Author:  Anthony Wang
 * Date:    2024/11/21
 */

#include <iostream>
#include <string>
#include "MathOperations.h"
using namespace std;
 
// Default constructor, set all number to 0
MathOperations::MathOperations(){
    operand1 = 0;
    operand2 = 0;
    theoperator = ' ';
    answer = 0;
};

// set number to op1 and op2
void MathOperations::setOperands(int op1, int op2){
    operand1 = op1;
    operand2 = op2;
};

// return theoperator
char MathOperations::getOperator() const{
    return theoperator;
};

// return answer
int MathOperations::getAnswer() const{
    return answer;
};

// Set theoperator to '+', set answer to op1+op2
void MathOperations::Addition(){
    answer = operand1 + operand2;
    theoperator = '+';
}

// Set theoperator to '-', set answer to op1-op2
void MathOperations::Subtraction(){
    answer = operand1 - operand2;
    theoperator = '-';
}

// Set theoperator to 'x', set answer to op1*op2
void MathOperations::Multiplication(){
    answer = operand1 * operand2;
    theoperator = 'x';
}

// Set theoperator to '÷', set answer to op1/op2
void MathOperations::Division(){
    answer = operand1 / operand2;
    theoperator = 246;
}

// return 1 when response == anser, 0 when reponse != answer
bool MathOperations::checkAnswer(int response) const{
    return response == answer;
};

// print equation
void MathOperations::print() const {
    cout << " " << operand1 << '\n'
         << theoperator << "  " << operand2 << '\n'
         << "-----" << endl;
}

// collect user's input
int MathOperations::collectUserAnswer() const {
    print();
    cout << "Please type your answer: ";

    int userAnswer = 0;
    
    // while loop ends when user's input don't trigger cin.fail()
    while (true) { 
        cin >> userAnswer;
        if (!cin.fail()) {
            cin.ignore(1000, '\n');
            return userAnswer;
        }
        else {
            cout << "Invalid input! Please try again..." << endl;
            cout << "Please type your answer: ";
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }
}