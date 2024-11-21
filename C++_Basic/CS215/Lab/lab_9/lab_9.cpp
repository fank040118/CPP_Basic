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

using namespace std;

const int MAX_THREE_DIGIT  = 999;
const int MAX_ONE_DIGIT    = 9;
const int ARITHMETIC_TYPES = 4;  // There are four kinds of basic arithmetic.

int main()
{
    string user_choice;
    do
    {
        MathOperations arithmetic_problem;
        int correct_answer = -1;
        int user_answer    = -1;

        cout << "Would you like to practice some arithmetic?\n";
        cout << "Press Enter to continue or press Q (or q) to quit...";
        getline(cin, user_choice);

        if (user_choice == "Q" || user_choice == "q")
        {
            // User wants to quit
            break;
        }
        else if (!user_choice.empty())
        {
            // User didn't press only enter
            cout << "Invalid input!" << endl;
            continue;
        }

        srand(time(0));
        // Generate number in the range of [1, 999]
        int first_operand = rand() % MAX_THREE_DIGIT + 1;
        // Generate number in the range of [1, 9]
        int second_operand = rand() % MAX_ONE_DIGIT + 1;

        /*
         * Setup arithmetic using the two operands, prompt the user for an
         * answer, and evaluate it.
         */
        arithmetic_problem.setOperands(first_operand, second_operand);
        cout << "\n";
        for (int i = 0; i < ARITHMETIC_TYPES; i++)
        {
            switch (i)
            {
                case 0:
                    arithmetic_problem.Addition();
                    break;
                case 1:
                    arithmetic_problem.Subtraction();
                    break;
                case 2:
                    arithmetic_problem.Multiplication();
                    break;
                default:
                    arithmetic_problem.Division();
                    break;
            }
            correct_answer = arithmetic_problem.getAnswer();
            user_answer    = arithmetic_problem.collectUserAnswer();
            if (correct_answer == user_answer)
            {
                cout << "Congratulations! " << correct_answer
                     << " is the right answer!\n";
            }
            else
            {
                cout << "Sorry! The correct answer is " << correct_answer
                     << ".\n";
            }
        }
    } while (true);

    cout << "Thank you for practicing! Have a great day.\n";
    return 0;
}