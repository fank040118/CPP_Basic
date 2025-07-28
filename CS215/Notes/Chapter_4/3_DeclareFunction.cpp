#include <iostream>
using namespace std;

/*
函数声明(Function Declaration) / 函数原型(Function Prototype):

目的:
- 告知编译器函数的存在，以便在定义之前就能调用
- 解决函数定义顺序问题(当函数定义在main之后时)

语法: 返回类型 函数名(参数类型列表);

特点:
1. 只需要参数的类型，参数名可选
2. 必须以分号结尾
3. 参数数量和类型必须与函数定义完全匹配
4. 通常放在文件顶部或头文件中

编译过程:
- 编译器从上到下处理代码
- 如果在main中调用函数，但函数定义在main之后，就需要先声明
*/

// 函数声明示例 - 只有类型，无参数名
int add(int, int);

// 函数声明示例 - 包含参数名(可选，但有助于理解)
double multiply(double num1, double num2);

// void函数声明
void printResult(int result);

int main() {
    cout << "=== 函数声明与定义示例 ===" << endl;
    
    int num1 = 5, num2 = 10;
    double x = 3.5, y = 2.0;
    
    // 调用已声明的函数(定义在main之后)
    int sum = add(num1, num2);
    double product = multiply(x, y);
    
    printResult(sum);
    cout << "Product of " << x << " and " << y << " is: " << product << endl;

    return 0;
}

// 函数定义 - 必须与声明匹配
int add(int a, int b) {
    return a + b;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

void printResult(int result) {
    cout << "Addition result: " << result << endl;
}