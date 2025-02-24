#include <string>
using namespace std;
#ifndef Car_H
#define Car_H

class Car {

    // 友元类(Friend Class)是 C++自定义类的一个重要代码，
    // 格式为  friend class 类名称;
    // 在一个自定义类中可以定义这个类的友元类，那么这个友元类将可以访问这个自定义类的
    // 所有数据成员和函数成员，这包括 private 内的成员
    // 但C++一般注重封装性，所以通常不建议太过频繁的使用友元类
    friend class Dealership;
    // 这行代码可以放在 class Car{} 内的任意一个位置，这不影响它的作用，
    // 比如即使把它放在 public 里也一样可以运行，并且一样可以在这个友元类内访问私有成员
public:
    Car();
    Car(string, string, int);

private:
    string model;
    string make;
    int year;


};
#endif  /* CAR_H*/