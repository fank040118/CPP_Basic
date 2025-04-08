#include <string>
using namespace std;
#ifndef Point
#define Point

class Point {
    public:
    Point();
    // 运算符重载Operator Overloading——————————————————————————————————————————————————

    // 可以使用 operator 来重载C++内置运算符，这类似于函数重载，根据参数类型可以给运算符不同含义
    // 运算符重载可以扩展内置运算符的功能
    // 这样的话自定义类型将能够使用内置类型一样的各种运算符，而不需要不停调用函数来完成计算

    // <<操作符——————————————————————————
    // <<操作符 最初是 位左移操作符Bitwise left shift operator，但在iostream库中被重载用于输出流
    // 比如我们写
    // age = 10
    // cout << "123" << age << "abc" << endl;
    // 它会输出123410abc，这是应为<<被修改为了返回流对象的引用，所以在调用age时会引用cout而继续输出

    // 为一个类重载一个函数就需要使用 <<操作符，例如：
    friend ostream& operator<<(ostream& out, const Point& P);
    // 比如这个代码就重载了一个函数，但这个函数并不是Point类，而是point类的友元函数
    // 因此它可以访问Point类的私有成员，
    // 在这里：
    // friend 定义这个函数是一个 友元函数，这是基础步骤，否则这个函数没法访问当前类对象的成员
    // ostream& 定义这个函数的返回类型是 ostream，这类似于平常写 int function(int a, int b){...} 中的int
    // 这里最独特的是，这个函数的名称是 operator<<，operator是关键字，<<是要重载的操作符
    // 它代表，“我要定义一种关键字类(这里是operator，代表符号)的操作符(这里是<<)”，这就是重载的含义，重新定义一个操作符
    
    // 然后这个函数接受两个参数：
    // ostream& out：这是输出流的引用，比如cout
    // const point& P：这是当前类的引用，const确保只可访问不可修改

    /* 那么函数定义部分：
    ostream& operator<<(ostream& out, const Point& p){
        out << setfill('0') << stew(2) << p.pointPosition
        << ":" << setw(2) << p.pointValue
        << ":" << setw(2) << p.pointName;
        return out;
    }
    */
    // 这个代码格式化了 P 这个对象内的各个成员数据，将他们变成基本输出(利用<<操作符来做到)
    // 这些输出就类似于 cout << "abc" << "def"; 中的"abcdef"，它们被称为 输出流
    // 然后经由 out 来对这个基本输出进行操作：

    // 那么最终，当我们直接在驱动代码中写：
    // cout << point时，它会直接按照上面的格式打印这些成员数据
    // 这里的原理是：
    // cout << point 中，cout和point都作为了 operator<<(ostream& out, const Point &p)的参数
    // 其中out被传入了cout，P被传入了point，那么函数中实际上就会直接执行
    // cout << setfill('0')......
    // 这其实就是cout的直接形式，它直接在函数中打印了这个point的成员数据，并在打印后返回cout的引用
    // 这样后续还能继续使用 << 来输出，因为cout已经被返回引用了，就不需要再写一遍

    // 如果驱动代码中写 abc << point，那么这将不再有效，因为被调入函数的参数不是cout而是abc，那么
    // 函数内部就会变成 abc << setfill('0')......，但压根不存在 abc << ....这种输出形式  


    private:
    int pointPosition, pointValue;
    string pointName;
}