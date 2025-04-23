#include <string>
using namespace std;
/*
封装(Encapsulation)指类型的数据成员(属性)被隐藏在了类的内部，
仅能通过类的受控的接口(成员函数)访问，这些被封装的内部数据是
对外不可见的，仅能通过创建类时定义的成员函数进行调用和修改，
比如对于string类对象，用户并不知道它是如何储存值的，但即使
这样，用户也能使用这个类提供的成员函数(.substr() length())
来使用或修改string类对象，这就是封装

封装能让代码更易于维护和修改，如果一个代码文件需要使用一个
类，但这个类需要修改某些实现以贴合代码的目的，那么只需修改
类本身的一部分成员函数或者属性即可，而无需修改运行这个类的
代码文件

接口(Interface)指的是外部代码与类的对象交互的通道，类的成员
函数就是接口，它使得外部代码能够与对象的属性和其他成员函数
进行交互
*/

#ifndef CLOCK_H
#define CLOCK_H

const int HOUR_MIN_SEC = 60;
const int HOURS_TO_WRAP = 24;

class Clock {
public:

    Clock();

    Clock(int hh, int mm, int ss);

    void setClock(int hh, int mm, int ss);

    // 成员函数分两种：修改器(Mutators)和访问器(Accessors)
    // 修改器是修改对象的数据成员的值的函数

    // 访问器是查询对象的数据成员的值的函数，访问器通常不会修改
    // 数据成员的值，所以它们通常是const类函数，以保证值的安全性
    // 除此以外，const类对象也只能用const类函数

    // 比如这里的设置时钟的秒/分/时的增加时间的函数就是修改器函数
    // 它们会直接修改对象的数据成员
    void incrementSeconds(int sec);
    void incrementMinutes(int min);
    void incrementHours(int hh);

    void addTime(Clock C);

    // 这里的打印时间和对比时间的函数就是访问器函数，它们不会
    // 修改对象的数据成员，所以最好将其声明并定义为const
    void printTime() const;
    int compareTime(Clock C) const;

private:

    // 这是对象的属性，即一种数据成员
    int hours, minutes, seconds;

    void adjustClock();
};

#endif  /* CLOCK_H*/