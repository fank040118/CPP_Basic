#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int num_1 = 123;
    int num_2 = 456;

    int userInput;
    cout << "Input a number bigger than 10: " << endl;
    cin >> userInput;
    /*
    C++中有与matlab类似的变量的作用域，即某一个变量在某一个代码块中被声明后，该代码只会在
    该代码块中存在，在代码块外尝试访问该变量将会导致程序出错。

    在这个例子中，int num_1是一个变量声明，且它存在于if语句的代码块中，这导致这个num_1的值
    仅能在这个代码块中访问，当我们在if语句的外部尝试再访问它时，他将会变成最初的num_1 = 123
    而不是num_1 = 234，这是因为“234”这个值仅在if代码块中存在，并不影响外部的num_1的值。

    但是，num_2 = 654是一种赋值行为，而不是声明变量，所以它的值并不被限制在这个代码块中，
    即使跳出if语句，num_2 = 654也仍然生效，
    */
    if (userInput > 10) {
        int num_1 = 234;
        num_2 = 654;
        cout << "num_1 = " << num_1 << ", num_2 = " << num_2 << endl;
    }

    cout << "num_1 = " << num_1 << ", num_2 = " << num_2 << endl;

    return(0);
}