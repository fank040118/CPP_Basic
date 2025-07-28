#include <iostream>
#include <iomanip>
using namespace std;

/*
高级函数概念 - 参数传递方式

1. 按值传递(Pass-by-Value):
   - 函数接收参数的副本(copy)
   - 函数内对参数的修改不会影响原始变量
   - 适用于不需要修改原始数据的情况
*/
int passByValue(int input) {
    input++;  // 只修改副本，不影响原变量
    cout << "Inside function: " << input << endl;
    return input;
}

/*
2. 按引用传递(Pass-by-Reference):
   - 使用引用符号(&)声明参数
   - 函数直接操作原始变量，不创建副本
   - 函数内对参数的修改会影响原始变量
   - 更高效，避免大型对象的复制开销
*/
int passByReference(int &input) {
    int returnValue = input + 10;
    input = input + 5;  // 直接修改原始变量
    cout << "Inside function, modified input: " << input << endl;
    return returnValue;
}

// 示例3: 使用引用传递交换两个数的值
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "=== 按值传递示例 ===" << endl;
    int x = 3;
    cout << "Original x: " << x << endl;
    cout << "Function return: " << passByValue(x) << endl;
    cout << "x after function call: " << x << endl;  // x仍为3，未被修改
    
    cout << "\n=== 按引用传递示例 ===" << endl;
    cout << "Original x: " << x << endl;
    cout << "Function return: " << passByReference(x) << endl;
    cout << "x after function call: " << x << endl;  // x被修改为8
    
    cout << "\n=== 交换函数示例 ===" << endl;
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapNumbers(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    
    return 0;
}