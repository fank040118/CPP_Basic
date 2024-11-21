#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// C++是一种“面向对象语言”，“面向对象”的语言中，对象是具有内置功能的数据类型，

int main()
{
    // 比如此处创建了一个字符串对象“greeting”，并为其赋值了一串字符
    string greeting = "Hello, World!";
    // 这里调用了String类对象的“length()”方法，这个方法会返回字符串的长度，
    // 并将其赋给变量“n”，“length()”是string类对象的内置函数
    int n = greeting.length();

    /*
    同理，vector的push_back()也是vector类对象的内置函数，这些类型的变量
    都被成为“对象”，因为它们都有“内置方法”，可以使用其预先设定好的函数
    对其进行操作。

    但是，变量 n 并不是一个对象，因为它只是一个简单的整数类型，它不存在
    任何内置方法，只是单纯的一个 原始数据类型

    面向对象编程中，用户可以自行创造“对象”，比如设计一个储存大量不同车辆
    信息的系统，当车辆的数量变得非常多时，关于车辆的信息的变量将会越来越多，
    那么，可以自行创造一个对象用于储存，处理和调用车辆信息
    */


    /*
    比如此处用户创建了一个名为“car”的自定义类，并创建了一个名为beetle的
    car类对象
    car beetle = car();

    随后，用户使用.setPrice()来设定这个对象的内置属性(价格)，这是一个
    自定义函数，由用户自行定义
    beetle.setPrice(23000);

    最后，用户创建了一个名为beetle_year的变量，并使用.getYear()来获取
    这个对象的属性“year”，并将其赋给beetle_year
    int beetle_year = beetle.getYear();

    从上面的例子分析：
    car 是一个用户自行创建的对象类型或类(class)，它不直接内置于C++，而是
    用户自行创建并定义的类，它如同字符串类(string)，vector类(vector)一样
    是具有内置方法的类型
    beetle 是用户创建的一个为 car 类的变量，这个个体变量属于这个类，它将
    可以使用 car 类的内置方法，就像创建一个字符串变量后可以使用字符串变量的
    内置方法.length()一样
    */


    /*
    在下例中，userVector是一组数据值，储存了一个Vector类变量的数据，
    .push_back()是一个操作，操作和数据值合并在一起为一个组，这个组
    就是一个类，
    */
    vector<int> userVector = {1,2,3,4};
    userVector.push_back(5);
    cout << userVector[3] << endl;


    /*
    一个类(class)可以看作是一种模板，定义了一组具有相同行为的对象，
    类之下不仅有对象本身，也有对象所包含的数据，比如 car 类型中，
    一个对象可以有“年份”，“颜色”，“价格”等数据，每个该类的对象都有
    自己相对应的数据，这些数据被称为 数据成员(data memebers)

    除此以外，类之下还有能够对对象进行操作的函数，函数将能直接改变，
    调用或者增加一个对象的数据成员，比如修改汽车的价格，查找汽车的
    年份等操作。

    同样的例子中，Car是类的名称，beetle是这个类的对象，也可以说是一个
    该类的实例，Car()是一个构造函数，代表构建一个该类的对象
    Car beetle = Car()；
    */
    
    return 0;
}