#include <string>
using namespace std;
#ifndef Vector
#define Vector

class Point {
    public:
    Vector(){
        x = 0;
        y = 0;
    };
    // 除了重载 << 符号以外，还能重载其他符号，比如加减乘除：
    Vector(int x, int y){
    // 假如上述的带参数构造函数的实际实现是这样的：
        this->x = x;
        this->x = y;
    };
    //也就是将传入的两个参数设置成这个对象的数据

    // 那么我们就可以重载这个对象的减号符号：

    // 一元运算符————————————————————————————————————————————————————————————
    // 一元运算符 是 直接操作一个操作数的运算符，比如给一个操作数取反，+1，*2的情况
    // 这种运算符不需要传入其他参数

    // 比如这个函数，它将没有传入参数情况下的 “-VectorObj”
    // 设置成了一个特殊函数，这个函数将会返回一个 x 和 y 都变成相反值的新Vector
    // 之所以把它设置成了const，是因为它是通过返回一个新Vector来工作的
    // 我们并不希望它直接将原对象的 x 和 y 反转（即使我们可以这么做）
    // 这类似于 -a
    Vector operator-() const{
        return Vector(-x, -y)
    };

    // 二元操作符————————————————————————————————————————————————————————————
    // 二元操作符 是 需要操作两个操作数的运算符，比如两个操作数相加，相减，相乘的情况
    // 这个函数和上述类似，但它不是将值设置成负值，而是在传入参数时，创建一个
    // 新的Vector，且其 x 和 y 值是 原vector的值 - 传入参数量
    // 这类似于 a - b
    Vector operator-(int scalar)const{
        return Vector(x - scalar, y - scalar)
    };

    // 这个函数也是减去新值，但它是 vector - vector，且两个vector都被声明为const
    // 来传入，以避免创建出来的新 vector 不小心修改了旧vector的值
    // 这类似于 a1 - b1, a2 - b2
    Vector operator-(const Vector& other) const{
        return Vector(x - other.x, y - other.y)
    };

    // 友元函数和普通函数区别——————————————————————————————————————————————————
    // 可以注意到，上面的所有函数都是直接在vector这个类里写的，这些重载符号直接通过vector
    // 这个类实现，但实际上并非所有重载符号都可以通过类自身实现：
    // 成员函数重载的一个限制是：左操作数 必须是 该类对象
    // 比如上面定义的 vector - scalar或者 vector - vector
    // 在 - 左侧的的操作数都是 vector
    // 唯一一个特例是最初的 一元运算符（即上文中直接以源对象取反作为返回值的函数）
    // 一元运算符 因为只操作一个操作符，所以不在乎左右的概念，它可以直接使用成员函数重载

    // 但如果要做到 scalar - vector，那么就不能用成员函数去重载了，这种情况下必须使用
    // 友元函数（或普通函数，比如直接在驱动代码中写重载操作符的函数）
    // 比如：
    friend Vector operator+(int scalar, const Vector& vec){
        return Vector(scalar + vec.x, scalar + vec.y)
    };
    // 在上述函数中，这是个 scalar + vector 的操作，+ 左边是scalar，所以必须使用友元函数
    // 由于友元函数可以直接访问成员函数，所以这里也能直接用vec.x和vec.y进行操作

    private:
    int x;
    int y;
}