/*
 * Course:  CS215-401
 * Project: Lab 9
 * File:    Lab9.cpp
 * Purpose: Driver file for student's class
 * Author:  Anthony Wang
 * Date:    2024/11/21
 */

// g++ lab_9.cpp MathOperations.cpp -o lab_9
// ./lab_9

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;


int main()
{
    int user_choice;
    do
    {
        MathOperations arithmetic_problem;
        MathReport userReport;
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
        cin >> user_choice;

        if (!cin.fail()){
            if (user_choice == "5")
                break;
        }
        else{
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        } 

        switch (user_choice)
        {
            case 1:
                srand(time(0));
                int first_operand = rand() % 500;
                int second_operand = rand() % 500;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Addition();
                cout << "\n";

            case 2;
                srand(time(0));
                int first_operand = rand() % 500;
                int second_operand = rand() % 500;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Subtraction();
                cout << "\n";

            case 3;
                srand(time(0));
                int first_operand = rand() % 500;
                int second_operand = rand() % 500;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Multiplication();
                cout << "\n";

            case 4;
                srand(time(0));
                int first_operand = rand() % 500;
                int second_operand = rand() % 500;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Division();
                cout << "\n";

            default:
                cout << "Invalid selection! The valid choices are 1, 2, 3, 4, and 5." << endl;
                continue;
        }
        /*
         * Setup arithmetic using the two operands, prompt the user for an
         * answer, and evaluate it.
         */
        correct_answer = arithmetic_problem.getAnswer();
        user_answer    = arithmetic_problem.collectUserAnswer();

        userReport.insert(arithmetic_problem, user_answer);

        if (correct_answer == user_answer)
        {
            cout << "Congratulations! " << user_answer << " is correct answer!" << endl;
        }
        else
        {
            cout << "Sorry! The answer is wrong. Keep practicing!" << ".\n";
        }
    } while (true);

    cout << "Thank you for practicing! Have a great day.\n";
    return 0;
}