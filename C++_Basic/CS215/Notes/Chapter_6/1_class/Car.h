#include <string>
using namespace std;
/*
想要创建一个类，就要先声明一个类，声明类需要使用格式为.h的文件，
这类文件的目的是声明这个类的各种成员和操作函数，但是
它并不会包含这些函数的定义，也就是说.h文件仅用于告知C++用户
创建了这个自定义类
*/
/*
在创建类以前，需要先确定这个类是否已经被定义，如果已经被定义
那么就不能重复定义这个类，此处的 #ifndef 和结尾的 #endif
代表“仅有 Car类 还未被定义的情况下，才运行内部的定义代码
*/
#ifndef Car_H
#define Car_H // define代表定义这个类

// 定义的格式为 class 类名 {定义内容}
class Car {

// public代表公有成员，在public内声明的函数和参数可以在类以外直接访问
// 比如在代码中可以直接调用公有成员，而不需要使用类的相关代码
public:
// 这是一个默认构造函数的声明，构造函数的意思是用于创建一个对象的函数
// 将()内留空代表当用户创建对象但并未给其传入任何参数(如价格，年份)时
// 使用创建类时预留的默认参数
Car();
// 这是带有参数的构建函数，当用户传入参数的情况下，将会以函数中提前设定的
// 参数顺序传入
Car(string, string, int);
// 这是用于打印车辆信息的函数声明，由于其目的只是打印参数而不是修改参数
// 所以可以使用const来表明该函数不会修改参数
// 除此以外，若对象创建时也以Const类型创建，那么对象只能使用Const类的
// 成员函数，例如 const Car beetle() 创建的const对象只能使用const函数
void showInfo() const;
// 这是用于重新设置年份的函数，当对象已经被创建完成以后，对象的参数就
// 必须使用非构造函数去修改
void setYear(int);
// 这是用于对比两个车辆的函数，因为对比的是两个Car类的对象的参数，所以其
// 括号里应该传入的对象类型也应该是Car类
void compareYear(Car);

// 上述的所有函数都被成为成员函数(member functions)，它们被定义为类的
// 一部分，用于操作类的属性(即下面的数据成员)

// private代表私有成员，私有成员只能通过公有函数进行访问和修改，
// 在代码中并不能直接获取私有成员的值，必须使用公有函数去获取
// 这将在另外两个文件中着重解释
private:
// 此处声明了三个对象的参数：车辆型号，制造商和年份
// 这些变量被称为数据成员(data  members)，它们代表了类的属性(attributes)
// 数据成员在类的声明部分定义，而不需要在源文件中再定义一次
// 每个该类的对象的数据成员都各自独立，修改某一个对象的数据成员
// 不会改变另一个对象的数据成员的值
string model;
string make;
int year;


};

#endif  /* CAR_H*/