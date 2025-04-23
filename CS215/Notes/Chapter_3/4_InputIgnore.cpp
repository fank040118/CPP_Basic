#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    //char是一中单字符类型变量，它只能储存一个字符，所以适合用于名字缩写
    char firstName, lastName;

    cout << "please enter you first and last name." << endl;
    /*
    利用cin.ignore，我们可以忽略掉我们不需要使用的字符，比如在这个例子中，
    通过cin.ignore()我们忽略掉了名中所有的字符，使lastname能够直接读取到
    姓的第一个字符。
    */
    firstName = cin.get();
    cin.ignore(1000,' ');
    lastName = cin.get();
    cout << "your initial is " << firstName << lastName << endl;

    return(0);
}