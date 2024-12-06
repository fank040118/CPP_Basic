
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include "MathReport.h"
#include "MathOperations.h"

    // MathReport.cpp MathOperations.cpp

MathReport::MathReport(){
    numCorrectAnswers = 0;
    numWrongAnswers = 0;
    mathQuestions;
    errorList;
    practiceCounter = 0;
    initialWrong = 0;

}

void MathReport::insert(MathOperations newQuestion, int response){
    mathQuestions.push_back(newQuestion);
    if (newQuestion.checkAnswer(response)) {
        numCorrectAnswers++;
        }
    else {
        numWrongAnswers++;
        initialWrong++;
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

    int numOfQuestion = getNumOfCorrectAnswers() + getNumOfWrongAnswers();
    cout << "You've tried to solve the following " << numOfQuestion << " arithmetic problems." << endl;

    if (showAnswer){
        for (int i = 0; i < mathQuestions.size(); i++){
            cout << "Question " << i+1 << endl;
            mathQuestions[i].print();
            cout << mathQuestions[i].getAnswer() << endl;
        }
    }

    else{
        for (int i = 0; i < mathQuestions.size(); i++){
            cout << "Question " << i+1 << endl;
            mathQuestions[i].print();
        }
    }

    cout << "---------------------------------- \n" 
         << "You answered " << getNumOfCorrectAnswers() << " correctly \n"
         << "You answered " << getNumOfWrongAnswers() << " incorrectly" << endl;

    if(showAnswer){
        cout << "Great work!" << endl;
    }

    else{
        cout << "You will do better next time! \n"
             << "You still need more practice" << endl;
    }
}

bool MathReport::needMorePractice() {
    if(errorList == 0){
        return 0;
    }

    MathOperations currentQuestion = errorList.front();
    currentQuestion.print();

    int userAnswer;
    cout << "input your answer: ";
    cin >> userAnswer;
    cout << endl;

    if(!cin.fail()){
        if (userAnswer == currentQuestion.getAnswer()){
            errorList.pop_front();
            numCorrectAnswers++;
            numWrongAnswers--;
            cout << "your answer is correct!" << endl;
            practiceCounter++;
            cin.ignore(1000,'\n');
        }
        else{
            cout << "your answer is wrong !" << endl;
            errorList.push_back(errorList.front());
            errorList.pop_front();
            practiceCounter++;
            cin.ignore(1000,'\n');
        }   
    }
    else{
        cout << "invaild input!" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    return (errorList == 0);
}