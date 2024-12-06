
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

// g++ Project_2.cpp MathOperations.cpp  MathReport.cpp -o Project_2
// ./Project_2

int main()
{
    int user_choice;
    MathOperations arithmetic_problem;
    MathReport userReport;
    do
    {
        
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
            if (user_choice == 5)
                break;
        }
        else{
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        } 

        int first_operand = 0;
        int second_operand = 0;

        switch (user_choice)
        {
            case 1: {
                srand(time(0));
                first_operand = rand() % 501;
                second_operand = rand() % 501;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Addition();
                cout << "\n";

                break;
            }
            case 2: {
                srand(time(0));
                first_operand = rand() % 501;
                second_operand = rand() % first_operand;

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Subtraction();
                cout << "\n";

                break;
            }
            case 3: {
                srand(time(0));
                first_operand = 11 + (rand() % 90);
                second_operand = 2 + (rand() % 9);

                arithmetic_problem.setOperands(first_operand, second_operand);
                arithmetic_problem.Multiplication();
                cout << "\n";

                break;
            }
            case 4: {
                srand(time(0));
                second_operand = 1 + (rand() % 9);
                first_operand = second_operand * (rand() % 99);

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
        /*
         * Setup arithmetic using the two operands, prompt the user for an
         * answer, and evaluate it.
         */
        correct_answer = arithmetic_problem.getAnswer();
        user_answer    = arithmetic_problem.collectUserAnswer();

        userReport.insert(arithmetic_problem, user_answer);

        if (correct_answer == user_answer) {
            cout << "Congratulations! " << user_answer << " is correct answer!" << endl;
        }
        else {
            cout << "Sorry! The answer is wrong. Keep practicing!" << ".\n";
        }
    } while (true);

    cout << "生成最初报告" << endl;
    userReport.generateReport(userReport.getNumOfWrongAnswers()==0);


    cin.ignore(1000,'\n');


    string userRetry;
    bool retryLoop = false;

    while (userReport.getNumOfWrongAnswers() && userReport.getNumOfWrongAnswers()) {
        cout << "Do you want to keep  trying with incorrect problems? \n" 
             << "Press Q (or q) to quit. " << endl; 

        cout << "等待用户输入" << endl;
        getline(cin, userRetry);
        cout << "收到输入" << endl;

        if (userRetry == "Q" || userRetry == "q") {
            cout << "循环结束, 用户输入了Q" << endl;
            break;
        }

        else if (!userRetry.empty()) {
            cout << "循环跳跃, 用户不止输入了空格" << endl;
            cout << "retry = false, !empty" << endl;
            continue;
        }

        else if (userRetry.empty()){
            cout << "循环结束, 用户输入了回车" << endl;
            retryLoop = true;
        }


        for(int i = 0; i <= userReport.getNumOfWrongAnswers(); i++){
            if(retryLoop){userReport.needMorePractice();}
        }
        
    }

    if(retryLoop){
        cout << "生成最终报告" << endl;
        userReport.generateReport(userReport.getNumOfWrongAnswers()==0);
        cout << "最终报告结束" << endl;
    }


    cout << "have a good day!" << endl;
    cout << "程序结束" << endl;

    return 0;
}