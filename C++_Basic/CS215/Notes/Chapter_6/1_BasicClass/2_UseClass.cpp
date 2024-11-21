#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h" // 在需要使用自定义类时，加上该类的头文件.h

using namespace std;

// 先后需要运行的两个指令：前者用于生成两个cpp的可编译文件
// 后者运行了当前的可编译文件
// g++ 2_UseClass.cpp Car.cpp -o 2_UseClass
// ./2_UseClass

int main(){
    // 通过 Car::Car() 默认构造函数创建了一个Car对象，在不传入
    // 任何对象的参数(比如年份)时，不应该在其结尾加上括号
    // 因为那会导致编译器认为正在调用一个函数，而不是创建对象
    Car userCar_1;

    // 在代码中，若要调用对象的类下的某一个公开函数，应该使用
    // 对象名.函数名(参数) 的形式进行调用，若函数不需要传入
    // 任何参数，那么()内可以留空
    userCar_1.showInfo();

    // 通过 Car::Car(string, string, int) 构造函数创建了一个
    // Car对象，创建时括号内参数需要按照相应的顺序填入
    Car userCar_2("Chevo", "Cruze", 2007);

    // 对比两个Car对象，由于 Year 是一个私有成员，其不能直接在
    // 代码中显性使用，也就是说在此处直接写为
    // if(userCar_2.year > userCar_1.year)...
    // 而不调用Car类公有函数是不可取的，因为year作为私有成员，
    // 仅能在Car类公有函数下使用
    userCar_2.compareYear(userCar_1);

    return 0;
}