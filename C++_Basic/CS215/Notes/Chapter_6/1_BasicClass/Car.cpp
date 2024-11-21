#include <string>
#include <iostream>
#include "Car.h"
using namespace std;
/*
在C++中，类的声明和实现是分开写的，类的声明部分放置在头文件.h中
实现放在源文件.cpp中，用于实现类的具体功能，类的声明和实现的文件
应该使用相同的名字

当实现类的成员函数时，需要使用作用域解析运算符(The Scope Resolution Operator)
即::，它的作用是指定函数属于哪个类，比如下面的构造函数，当实现构造函数Car(){...}
时，需要写为 Car::Car(){...}来指明这个构造函数应该属于Car类
 
这是默认构造函数的定义，当创建了一个Car对象但并未指定其参数时
默认构造函数将参数设为默认值*/
Car::Car(){
    make = "volkswagen";
    model = "Beetle";
    year = 1986;
}

// 这是带参数的构造函数，当创建Car对象并附带了参数时，相应的参数
// 会传入到该对象中
Car::Car(string mk, string md, int yr){
    make = mk;
    model = md;
    year = yr;
}

// 这是用于打印车辆信息的函数，由于其内部直接使用Cout，所以函数不
// 需要任何返回值，且由于函数不会更改对象的参数，所以使用const
// 可以表明函数仅调用对象参数
void Car::showInfo() const {
    cout << year << " " << make << " " << model << endl;
}

// 这是修改已存在的Car对象的Year参数的函数，已经被创建的对象不能再次
// 使用构建函数去修改参数，所以需要设立用于给参数重新赋值的新函数
void Car::setYear(int yr){
    year = yr;
}

// 这是对比两个车辆的年份的函数，传入的另一个对象也是一个Car类对象
// 所以在此处声明对象为Car类，将传入参数命名为 C
void Car::compareYear(Car C){
    if(year < C.year) cout << "Later is newer!" << endl;
    else if(year > C.year) cout << "Former is newer!" << endl;
    else cout << "They both made in same year." << endl;
}
/*
在上面这个函数中，对比两个Car类对象的值时使用的是“year”和C.year
前者是呼叫函数使用的对象，因为呼叫时已经包含了对象名，所以
调用其成员year时可以直接使用 year 来调用。
后者时呼叫函数中传入的参数，传入的参数需要使用.attributes来调用其
成员
我们在头文件里说过，放置在private下的成员只能使用公有参数来调用，
严格来说，是只能使用“同一个类的公有函数来调用”，在这个例子中，
compareYear(Car)是一个Car类的公有函数，所以它可以调用同类型的
对象C的某一个私有成员(year)
如果我们使用其他类的公有函数来调用的话，将会导致运行失败，因为
私有成员仅能使用同类的公有成员调用

同理，如果私有成员内有的不只是属性，还有 私有函数 的话，其也不能在
实际代码中直接使用，私有函数 也必须使用 共有函数 调用，即在函数中
调用另一个函数
*/