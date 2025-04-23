/*
 * Course:  CS215-401
 * Project: Project 2
 * File:    MathReport.cpp
 * Purpose: declare MathReport Class
 * Author:  Anthony Wang
 * Date:    2024/12/5
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include "MathReport.h"
#include "MathOperations.h"

MathReport::MathReport(){
    // Default constructor, set all number to 0
    numCorrectAnswers = 0;
    numWrongAnswers = 0;
    mathQuestions;
    errorList;
}

void MathReport::insert(MathOperations newQuestion, int response){
    // insert question into mathQuestion and errorList(if it's wrong)
    // increase Correct or Wrong depends on user's answer
    mathQuestions.push_back(newQuestion);
    if (newQuestion.checkAnswer(response)) {
        numCorrectAnswers++;
        }
    else {
        numWrongAnswers++;
        errorList.push_back(newQuestion);
        }
}

// return num of answers
int MathReport::getNumOfCorrectAnswers() const {
    return numCorrectAnswers;
}
int MathReport::getNumOfWrongAnswers() const {
    return numWrongAnswers;
}

void MathReport::generateReport(bool showAnswer) const {
    // cout summary
    int numOfQuestion = getNumOfCorrectAnswers() + getNumOfWrongAnswers();
    cout << "You've tried to solve the following " << numOfQuestion << " arithmetic problems." << endl;

    // if showAnswer=true, print with answer.
    if (showAnswer){
        for (int i = 0; i < mathQuestions.size(); i++){
            cout << "Question " << i+1 << endl;
            mathQuestions[i].print();
            cout << mathQuestions[i].getAnswer() << endl;
            cout << endl;
        }
    }
    else{
        for (int i = 0; i < mathQuestions.size(); i++){
            cout << "Question " << i+1 << ":" << endl;
            mathQuestions[i].print();
            cout << endl;
        }
    }

    cout << "---------------------------------- \n" 
         << "You answered " << getNumOfCorrectAnswers() << " correctly \n"
         << "You answered " << getNumOfWrongAnswers() << " incorrectly" << endl;

    if(numCorrectAnswers>numWrongAnswers){
        cout << "Great work!" << endl;
    }
    else{
        cout << "“You will do better next time!" << endl;
    }
}

bool MathReport::needMorePractice() {
    // return 0 if there is no question in errrolist
    if(errorList.size() == 0){
        return 0;
    }
    // print first question from errorlist
    MathOperations currentQuestion = errorList.front();
    currentQuestion.print();
    // ask input
    int userAnswer;
    cout << "Please type your answer: ";
    cin >> userAnswer;
    cout << endl;

    if(!cin.fail()){
        // if user's answer is correct, popout the question from error list
        // if it's not, put the question to the end of the list, so in
        // next loop, it will print the second question by .front()
        if (userAnswer == currentQuestion.getAnswer()){
            errorList.pop_front();
            numCorrectAnswers++;
            numWrongAnswers--;
            cout << "Congratulations! " << userAnswer << " is the right answer!" << endl;
            cin.ignore(1000,'\n');
        }
        else{
            cout << "Sorry! The answer is wrong. Keep practicing! " << endl;
            errorList.push_back(errorList.front());
            errorList.pop_front();
            cin.ignore(1000,'\n');
        }   
    }
    else{
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    // return 1 if there is question in errorList
    return (errorList.size() != 0);
}