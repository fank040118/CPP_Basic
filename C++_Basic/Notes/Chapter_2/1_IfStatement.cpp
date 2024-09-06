#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    /*
    在C++中，if语法如下：
    if (condition) {
    statement_1
    }
    else if (condition) {
    statement_2
    }
    else {
    statement_3
    }
    C++语法中if语句的条件必须使用括号括起来，而条件触发的语句则应该在花括号中
    */
    double num_1 = 10;
    double num_2;
    cout << "Input a number" << endl;
    cin >> num_2;
    if (num_1 == num_2) {
        cout << "Our number is 10, same as yours." << endl;
    }
    else if (num_1 >= num_2) {
        cout << "Our number is 10, your number is smaller than ours." << endl;
    }
    else {
        cout << "Our number is 10, your number is bigger than ours." << endl;
    }

    double num_3 = 1;
    double num_4 = 2;
    // 在C++中，若if语句后没有使用{}，那么它也可以将后续的一个句子作为if语句执行后的触发语句
    // 但这仅对一个语句作用，
    if (num_3 < num_4) 
        cout << num_3 << " is smaller than " << num_4;  // 仅在if语句满足时执行
    cout << "这个语句会永远执行,无论if语句是否条件满足 \n" << endl;
    

    return 0;
}