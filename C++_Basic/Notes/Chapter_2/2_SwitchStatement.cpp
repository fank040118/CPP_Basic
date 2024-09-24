#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    /*
    C++中Switch语句只使用在整数或能够隐性转换为整数的类型之上，比如int,char等类型。
    Switch语句中 switch(variable) 中variable是语句的判断条件，比如在这个例子中，
    day是判断条件，在后续中若day = 1，那么就会进入到case 1这个条件中。

    在Switch语句中，一个条件触发的语句必须使用break来关闭Switch判断，如果没有使用
    break，那么switch语句将会继续进入下一个条件判断。
    
    如果有多个case指向了同一个执行语句，比如case 6和case 7都会指向cout<<"abc"，
    那么可以直接将两个case写在一起，比如case6:case7:cout<<"abc";break;
    */
    int day;
    cout << "What is the day of the week (1-7)? ";
    cin >> day;
    switch(day)
    {
        case 1: cout << "CS216" << endl;
        break;
        case 2: cout << "CS215 and CS275" << endl;
        break;
        case 3: cout << "CS215 and CS216 lab" << endl;
        break;
        case 4: cout << "CS215 and CS275" << endl;
        break;
        case 5: cout << "CS216" << endl;
        break;
        case 6: 
        case 7: cout << "Enjoy the weekend!" << endl;
        break;
        default: cout << "Invalid input" << endl;
    }
    return(0)
}