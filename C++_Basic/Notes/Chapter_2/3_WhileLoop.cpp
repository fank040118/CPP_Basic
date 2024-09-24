#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    /*
    While loop与其他语言一致，仅会在condition成立的情况下才会执行后续的执行语句
    */
    int i = 1;
    while(i < 10){
        i = i + 1;
        cout << i << endl;
    }
    
    /*
    do-while循环是一种特殊的循环，它与while循环的执行顺序相反，在while循环中，只有当condition
    成立的情况下才能运行后续的执行语句，也就是说，只要condition不成立，那么语句就不会执行。

    但是do-while循环相反，do-while循环会优先运行内部的执行语句，然后再运行while的condition，
    这代表语句会 至少运行一次 ，哪怕实际上语句的condition不成立，它是一种 先执行，再判断 的
    语句，在一些特定的场景下，do-while循环能够保证程序能够至少运行执行语句一次。
    */
    i = 1;
    do {
        cout << i << endl;
        i++;
    } while (i<1);

    return(0);
}