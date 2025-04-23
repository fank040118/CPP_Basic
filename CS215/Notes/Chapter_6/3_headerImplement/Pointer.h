#include <string>
using namespace std;

#ifndef POINTER_H
#define POINTER_H

// 在之前的教程中，自定义的类的函数声明和定义都是单独写在各自的文件里的
// 但实际上，C++是允许将函数的定义直接写在 头文件.h 中的，这被称为
// Header Implement 或 Inline Implement：

// 如果所有函数的实现都写在了 头文件 中（即不存在给类函数定义用的.cpp文件）的话
// 编译这个文件将直接使用 g++ driverCode -o driverCode，而不需要包含userClass
// 这是因为编译器会自动寻找驱动代码所需的自定义类的文件（前提是驱动代码开头包含了
// 这个类的文件的头文件声明）

class Pointer {
public:
// 声明内部定义——————————————————————————————————————————————————————————————
// 比如在这里，这个类的默认构造函数被直接写在了声明部分内，这和平常直接在驱动代码中
// 定义函数是一样的，如果不把定义部分写在main函数后面，那么就可直接在声明部分写出函数定义
// 而且这种定义方法并不需要表明这个函数属于什么类，比如 Pointer::Pointer(){...}
// 而是直接写成 Pointer(){...}，因为 Pointer:: 已经隐性的包含在了声明部分
    Pointer(){
        value_x = 0;
        value_y = 0
        pointerName = "defaultPointer"
    };
// 声明结束后定义——————————————————————————————————————————————————————————————
// 同时，除了直接把函数定义写在 声明部分 以内以外，我们还可以把函数定义写在声明部分结束后
// 比如这里的 带参数构造函数 和 打印函数 都写在了这个文件的尾部，它们的介绍将会在那
    Pointer(int x, int y, string name);

    string print_pointer();

// 单独使用.cpp文件编译————————————————————————————————————————————————————————
// 除此以外还有我们常用的方法，即在同名的.cpp文件下进行单独编译，这个方法和之前所学的一样
    void set_pointer(int x, int y);

    void setNameOfPointer(string name);

private:
    int value_x, value_y;
    string pointerName;
};

// 声明结束后定义部分————————————————————————————————————————————————————————————
// 就像在之前提到的一样，我们可以在声明结束后定义，这部分的语法和单独在文件中编译一样
// 因为它写在了声明部分以外，所以需要显性的表明这个函数属于什么类，比如
// Pointer::Pointer(){...}，而不能直接写成 Pointer(){...}

// 同时，因为它仍然是在头文件中编译，而不是单独的文件，所以为了表明这个函数不需要在
// 单独的类函数定义文件 .cpp 中进行编译，需要使用关键字 inline，这是强制性的需求：
inline Pointer::Pointer(int x, int y, string name){
    value_x = x;
    value_y = y;
    pointerName = name;
};

inline string Pointer::print_pointer(){
    cout << value_x << " : " << value_y << " : " << pointerName << endl;
    string pointerString = to_string(value_x) + " : " + to_string(value_y) + " : " + pointerName;
    return pointerString;
};
