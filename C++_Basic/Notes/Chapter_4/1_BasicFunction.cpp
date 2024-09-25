#include <iostream>
#include <iomanip>
using namespace std;

/*
函数function是一种能够执行特定任务的独立代码块，可以创建函数并在其中编写需要执行的任务，
函数的结构是：

返回类型 函数名(参数列表){
    函数体
    返回值
}

返回类型是函数需要返回的值的类型。函数名是函数本身的名称，在调用函数时将会使用它。参数列表
是函数内需要使用的变量，这些变量来自调用，如果调用时包含了三个参数，那么函数本身也至少需要
有三个参数。
函数体是在得到参数以后需要进行的任务，在任务结束以后，函数需要返回它的结果。

在这个例子中，我们设计了一个计算器，他的类型是double，名称叫做calculate_add，并且内有
两个变量，在函数体中有一行代码用于计算两个参数的相加结果，并在最终将这个结果返回。
*/
double calculate_devide(double userInput_1,double userInput_2){
    double result = userInput_1 / userInput_2;
    return result;
}

// 如果一个函数只是单纯的调用一下，并不需要结果，比如此处只是打印一个信息，并不需要返回任
// 何结果，那么可以将函数的类型设置为void，它将不返回任何值，只是运行。
void printMessage() {
    cout << "Hello, World!" << endl;
}

int main()
{
    cout << "please enter two number for calculation." << endl;    
    double input_1, input_2;
    cin >> input_1 >> input_2;
    /*
    在下行代码中，我们呼叫了函数，使用函数名(参数)呼叫函数，参数是需要使用的数，
    并且因为我们需要使用两个数,所以也需要按照函数内的参数的顺序输入，
    在此处input_1的值将赋予给userInput_1，input_2同理，除此以外，函数
    内的变量仅能在函数内使用，比如result变量的值在main中无法呼叫，只能通过
    return来输出他的值。
    */
    cout << 'the final result is: ' << calculate_add(input_1,input_2) << endl;

    printMessage();
    
    return 0;
    
}

