/*
 * Course:  CS215-401
 * Project: Project 2
 * File:    Projecy_2.cpp
 * Purpose: Driver file that implement a math tutor program
 * Author:  Anthony Wang
 * Date:    2024/12/5
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

// g++ Project_2.cpp MathOperations.cpp  MathReport.cpp -o Project_2
// ./Project_2

// define constent variable for different equations
const int MIN_RANGE_ONE = 1;
const int MAX_RANGE_THREE = 500;
const int MIN_MULTIPLY_FIRST  = 11;
const int MAX_MULTIPLY_FIRST  = 90;
const int MIN_MULTIPLY_SECOND  = 2;
const int MAX_MULTIPLY_SECOND  = 9;
const int MIN_DIVISION = 2;
const int MAX_DIVISION = 98;

int main()
{

    int user_choice;
    MathOperations arithmetic_problem;
    MathReport userReport;

    do{
        
        int correct_answer = -1;
        int user_answer    = -1;

        cout << "Math is Fun !!! \n"
             << "Challenge yourself with one of the following problems! \n"
             << "--------------------------------------- \n"
             << "1. Addition problem \n"
             << "2. Subtraction problem \n"
             << "3. Multiplication problem \n"
             << "4. Division problem \n"
             << "5. Quit this program \n"
             << "---------------------------------------"<< endl;
        cout << "Enter your choice (1-5): ";
        
        // get user's input to choose question or quit program
        cin >> user_choice;
        if (!cin.fail()){
            // quit do-while loop if user input is 5
            if (user_choice == 5) {
                cout << " and now it's time for a break!" << endl;
                cin.ignore(1000,'\n');
                break;
            }
            // ask user to input again if user input is not in range
            else if(user_choice > 5 || user_choice < 1) {
                cin.ignore(1000,'\n');
                cout << "Invalid selection! The valid choices are 1, 2, 3, 4, and 5." << endl;
                continue;
            }
        }
        // ask user to input again if user input is not a int.
        else{
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        } 

        cin.ignore(1000,'\n');

        // generate question
        int first_operand = 0;
        int second_operand = 0;
        srand(time(0));
        switch (user_choice)
        {
            case 1: { // addition question
                // first = [1,500], second = [1,500]
                first_operand = MIN_RANGE_ONE + rand() % MAX_RANGE_THREE;
                second_operand = MIN_RANGE_ONE + rand() % MAX_RANGE_THREE;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Addition();
                cout << "\n";

                break;
            }
            case 2: { // Subtraction question
                // first = [1,500], second = [1,first]
                first_operand = MIN_RANGE_ONE + rand() % MAX_RANGE_THREE;
                second_operand = MIN_RANGE_ONE + rand() % MAX_RANGE_THREE;

                // if the first number is smaller than second one, switch their position
                // to make the result always be positive or zero
                if(first_operand < second_operand){
                    int tempNum = second_operand;
                    second_operand = first_operand;
                    first_operand = tempNum;
                }

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Subtraction();
                cout << "\n";

                break;
            }
            case 3: { // Multiplication question
                // first = [11,99], second = [2,9]
                first_operand = MIN_MULTIPLY_FIRST + (rand() % MAX_MULTIPLY_FIRST);
                second_operand = MIN_MULTIPLY_SECOND + (rand() % MAX_MULTIPLY_SECOND);

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Multiplication();
                cout << "\n";

                break;
            }
            case 4: { // Division question
                // first = [second*2, 891(equal to 9*99)], second = [2,9]
                second_operand = MIN_DIVISION + (rand() % (MAX_MULTIPLY_SECOND-1));
                first_operand = second_operand * (2 + (rand() % MAX_DIVISION));

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Division();
                cout << "\n";

                break;
            }
            default: {
                cout << "Invalid selection! The valid choices are 1, 2, 3, 4, and 5." << endl;
                continue;
            }
        }
        // get user's answer and check if it is correct
        correct_answer = arithmetic_problem.getAnswer();
        user_answer    = arithmetic_problem.collectUserAnswer();
        // input the question into the userReport.
        userReport.insert(arithmetic_problem, user_answer);
        
        // if answer is correct, cout "congratulations"
        if (correct_answer == user_answer) {
            cout << "Congratulations! " << user_answer << " is correct answer!" << endl;
        }
        // else, cout "sorry"
        else {
            cout << "Sorry! The answer is wrong. Keep practicing!" << ".\n";
        }
    } while (true);

    // generate report
    userReport.generateReport(userReport.getNumOfWrongAnswers()==0);

    string userRetry;
    bool retryLoop = false;
    // ask user if wanna practice wrong questions when there is wrong question left
    while (userReport.getNumOfWrongAnswers()) {
        cout << "Do you want to keep  trying with incorrect problems? \n" 
             << "Press Q (or q) to quit. " << endl; 

        getline(cin, userRetry);

        if (userRetry == "Q" || userRetry == "q") {
            // quit program
            break;
        }

        else if (!userRetry.empty()) {
            // ask again
            continue;
        }

        else if (userRetry.empty()){
            // start call needMorePractice
            retryLoop = true;
        }
        // a for loop that call needMorePractice, the time it call = num of wrong
        // there is no code for use the return from needMorePractice, I don't know
        // how to use that return bool value while it's running the practice
        int currentWrong = userReport.getNumOfWrongAnswers();
        for(int i = 1; i <= currentWrong; i++){
            if(retryLoop){userReport.needMorePractice();}
        }
    }
    // if there is no more wrong questions, generate report again
    if(retryLoop){
        userReport.generateReport(userReport.getNumOfWrongAnswers()==0);
    }

    cout << "Thank you for using the Math Tutor! Have a great day. " << endl;

    return 0;
}