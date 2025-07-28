#include <iostream>
#include <iomanip>
using namespace std;

/*
函数(function)是一种能够执行特定任务的独立代码块，可以创建函数并在其中编写需要执行的任务。

函数的结构语法:
返回类型 函数名(参数列表){
    函数体
    return 返回值;  // 如果返回类型不是void
}

组成部分说明:
- 返回类型: 函数需要返回的值的数据类型
- 函数名: 函数的标识符，用于调用函数
- 参数列表: 函数接收的输入参数，可以有多个参数
- 函数体: 函数执行的具体代码逻辑
- 返回值: 函数处理后返回给调用者的结果

示例1: 带返回值的函数 - 计算两数相加
*/
double calculate_add(double userInput_1, double userInput_2) {
    double result = userInput_1 + userInput_2;
    return result;
}

// 示例2: 带返回值的函数 - 计算两数相除
double calculate_divide(double userInput_1, double userInput_2) {
    if (userInput_2 != 0) {
        double result = userInput_1 / userInput_2;
        return result;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

// 示例3: void类型函数 - 无返回值函数
// 如果函数只是执行操作而不需要返回结果，可以将返回类型设置为void
// void函数不使用return语句返回值，只是执行操作
void printMessage() {
    cout << "Hello, World!" << endl;
}

int main()
{
    cout << "Please enter two numbers for calculation: ";    
    double input_1, input_2;
    cin >> input_1 >> input_2;
    
    /*
    函数调用(function call):
    - 使用语法: 函数名(参数列表)
    - 参数传递: 按照函数定义的参数顺序传递实参
    - 作用域(scope): 函数内的局部变量只能在函数内部访问
    - 返回值: 通过return语句将结果返回给调用者
    
    下面演示不同函数的调用方式:
    */
    
    // 调用加法函数并输出结果
    cout << "Addition result: " << calculate_add(input_1, input_2) << endl;
    
    // 调用除法函数并输出结果
    cout << "Division result: " << calculate_divide(input_1, input_2) << endl;
    
    // 调用void函数，无返回值
    printMessage();
    
    return 0;
}

