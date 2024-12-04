/*
 * Course:  CS215-401
 * Project: Lab 9
 * File:    
 * Purpose: define function for MathOperations class
 * Author:  Anthony Wang
 * Date:    2024/11/22
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include "MathReport.h"
#include "MathOperations.h"
using namespace std;

MathReport::MathReport(){
    numCorrectAnswers = 0;
    numWrongAnswers = 0;
    mathQuestions;
    errorList;

}

void MathReport::insert(MathOperations newQuestion, int response){
    mathQuestions.push_back(newQuestion);
    if (MathOperations.checkAnswer(response)) {
        numCorrectAnswers++;
        }
    else {
        numWrongAnswers++;
        errorList.push_back(newQuestion);
        }
}

int MathReport::getNumOfCorrectAnswers() const {
    return numCorrectAnswers;
}

int MathReport::getNumOfWrongAnswers() const {
    return numWrongAnswers;
}

void MathReport::generateReport(bool showAnswer) const {
    if (showAnswer){
        for (int i = 0, i < mathQuestions.size(), i++){
            mathQuestions(i).print;
        }
    }
    else{
        for (int i = 0, i < mathQuestions.size(), i++){
            mathQustions(i).print;
            cout << mathQuestions(i).getAnswer << endl;
        }
    }
}

bool MathReport::needMorePractice() {
    if (errorList.size >= 1){return 1;}
    else {return 0;}
}