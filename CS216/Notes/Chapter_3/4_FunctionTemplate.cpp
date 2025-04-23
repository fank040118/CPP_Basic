#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 函数模板————————————————————————————————————————————————————————————————————
// 函数模板用于在代码中声明，而不是作为一个独立的类
// 首先需要使用 template <class 类名(非实际)> 或 template <typename 类名(非实际)> 声明这是个模板 
template <typename T>
// 对于函数内部，这里使用两个 T 类变量
void printIt(T a, T b){
    // 创建一个新的 T 类变量 c，c = a + b
    T c = a + b;
    cout << a << " and " << b << endl;
    cout << "Together they make: " << c << endl;
}

// 这是另一个template，用于把b中元素复制到a
template <typename TYPE>
void copy(TYPE a[], TYPE b[], int n){
    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }
    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << endl;
}

int main(){
    // 呼叫函数时直接传入数值就可，编译器会自动推导传入参数的类型
    printIt(1, 2);
    // char也可以传入，他们会被转换为 ASCII码
    printIt('A', '1');
    // 也可以显性的要求传入参数是什么类型，两者没有本质区别
    printIt<int>(5, 9);

    // 创建两个函数，用于copy模板
    // 两个都是int类，它们被放进
    int f1[5], f2[5] = {1,2,3,4,5};
    copy(f1, f2, 5);

    // 使用char也行
    char f3[3], f4[3];
    copy(f3, f4, 5);

    return 0;
}