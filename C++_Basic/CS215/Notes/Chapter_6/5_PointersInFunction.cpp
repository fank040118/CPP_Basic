#include <string>
#include <iostream>
#include "Car.h"
using namespace std;

// 这是一个普通的构造函数，函数输入的参数 mk，md，yr
// 会传入对象的属性，当函数的参数和对象的属性名不一致时
// 编译器能够理解两个变量的差异，它等价于
// Car.make = mk;
// Car.model = md;
// Car.year = yr;
Car::Car(string mk, string md, int yr){
    make = mk;
    model = md;
    year = yr;
}

// 但如果传入的参数名和对象的属性名一致，那么编译器会认为
// 这是同一个变量的名，导致编译器开始尝试将参数的值赋给自己
// 那么此时可以使用 this指针，this指针用于显性的指明对象的属性
// 通过以下的方法，编译器能够分出左侧为对象属性，右侧为函数参数
// 它等价于 Car.make = make
Car::Car(string make, string made, int year){
    this->make = make;
    this->model = made;
    this->year = year;
}

// 指针也可以作为按值传递参数去实现按引用传递
// 在这个函数中，传入一个指针参数，并在函数内 解引用 这个指针
// 将其指向的变量的值修改为99，这种方法由于是通过内存地址直接
// 修改的变量的值，所以它虽然不带有按引用传递符号&，但却能跨函数
// 直接修改一个变量的值
void userFunc(int *p){
    *p = 99;
}

int main{

    int x = 3; // 设int类值x=3
    int *q = &x; // 将q设置为x的指针
    userFunc(q); // 使用q呼叫userFunc，从而改变x的值
    cout << x << endl; // x变为99

    return 0;
}
