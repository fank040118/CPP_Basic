#include <iostream>
using namespace std;

/* 
函数声明是一种告知编译器存在函数的行为，如果我们想要将函数的内容写在
main以后，那么我们就需要在main之前先声明它的存在，声明函数并不需要
包含函数内部需要处理内容的函数体，他存在的意义只是为了让编译器知道有
这个函数的存在，这是因为如果将函数直接写在main之后，编译器将无法处理
main中调用这个函数的命令，因为编译器并不知道有这个函数的存在。

在此处，我们声明了函数add，我们并未编写他的函数体，同时，在声明函数时
并不需要声明函数的参数名是什么，但是必须声明函数的参数类型是什么，这里
声明为了int类型。
要注意的是，声明函数使用的参数数量必须与函数本身所使用的参数数量完全
一致，不能在声明时只声明一个参数，但在调用时又输入了两个参数。
*/
int add(int, int);

int main() {
    int num1 = 5, num2 = 10;
    // 调用 add 函数
    int sum = add(num1, num2);
    cout << "Sum: " << sum << endl;

    return 0;
}

// 函数定义，参数名在定义中出现
int add(int a, int b) {
    return a + b;
}