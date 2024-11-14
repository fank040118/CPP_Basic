#include <iostream>
#include <iomanip>
using namespace std;
/*
按值传递函数传递参数进行运算的时候，运算的结果不会影响传递的原变量的值，
这是因为当我们传入某个参数时，给予函数的值是该参数的副本，而无论副本如何
改变，原参数都不会有任何变化。
*/
int myfunc(int input) {
    input++; // input的值加1，但这是副本的加1
    return input;
}
/*
另一种方式是按引用传递，即在函数的参数列表中将 需要引用的值 前加上个&，
这种方式将会改变调用函数时输入的参数本身，这与按值传递相反，它将会给予
函数该参数本身，最终返回的值将会被更改
*/
int myfunc_2(int &input){
    input = input + 10;
    return input;
}

int main()
{
    int x = 3;
    cout << myfunc(x) << endl; // 输出的是4，它是函数myfunc的结果
    cout << x << endl;  // 输出的是3，因为x本身没有被改变，

    myfunc_2(x);
    cout << x << endl; // 输出的是13，因为myfunc_2会直接更改参数的值
    return 0;
}