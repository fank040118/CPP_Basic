#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(){
    // 空指针Null——————————————————————————————————————————————————————
    // Null Pointer，即 空指针，常用来表示“空”，或“指向
    // 无效地址”，在现代C++语法中更推荐使用nullptr来表示空指针
    // 比如在下面的例子中，ip1和ip2都指向了实际的变量地址，但
    // ip3并未指向任何变量的地址，此时它就是一个“野指针”(dangling pointer)
    // 这种指针的状态时未定义的，它可能指向任何一个地址，如果使用它
    // 可能会得到无法预测的输出，严重的来说，甚至可能会导致编译器崩溃
    // 如果尝试使用 &ip3 去解引用它，那么会导致无法编译
    int num_1 = 1, num2 = 2, num3 = 3;
    int *ip1 = &num_1, *ip2 = &num2, *ip3;
    cout << ip1 << " " << ip2 << " " << ip3 << endl;

    // 想要正确的给指针定义为空指针，需要赋予其Null，此时指针的指向地址为0
    // 在C++中，空指针并不是“没有指向地址”，而是“指向了一个没有值的地址”，
    // 这个地址通常被定义为“0”
    // 在大多数时候，创建指针的时候可以直接将其赋值为Null，以避免未初始化
    // 造成的不稳定性，有时候也能将空指针定义为错误标志
    ip3 = NULL;
    ip2 = nullptr;
    cout << ip2 << " " << ip3 << endl;


    /* 语法总结：————————————————————————————————————————————————————
    定义指针-------------类型* 指针名
    指向变量地址---------指针 = &变量
    解引用指针-----------*指针
    用指针赋值变量-------*指针 = 值
    克隆指针指向变量-----*指针A = *指针B
    克隆指针地址---------指针A = 指针B
    */

    // 箭头操作符与对象——————————————————————————————————————————————
    vector<int> userVec_1 = {1,2,3,4,5};
    // 指针也可以指向用户自定义的类以及其他对象，即使它们可能能够储存多个值
    // 比如，指向 vector类 的指针也应该声明为 vector类
    // 虽然对象可能存在多个值，例如这里的vector实际上储存了多个int值，但是
    // 它们被储存在了连续的内存块中，所以指针实际上指向了内存块的起始处
    vector<int> *vectorPtr = &userVec_1;
    // 可以看到指针所打印的值是vector的内存起始值
    cout << vectorPtr << endl;
    // 箭头操作符(Arrow operator)是 点操作符(. operator)的衍生，正常情况下，
    // vector的函数push_back()应该使用点操作符，即vector.push_back()，
    // 但若拥有指向了vector地址的指针，那么可以直接为指针使用箭头操作符进行
    // 等同的效果，即 pointer->function()，在此处为 vectorPtr->push_back()
    // 指针使用 箭头操作符 不需要为指针进行解引用即可直接访问指向地址的对象的
    // 成员，因为 pointer->function() 实际上是 (*pointer).function() 的简写
    // 所以当使用 箭头操作符 时，编译器已经自动进行过解引用
    vectorPtr->push_back(6);
    // 此处等同于 (*vectorPtr).push_back(6) 或 userVec_1.push_back(6)
    for(int i=0; i < userVec_1.size(); i++){
        cout << userVec_1[i] << " ";
    }
    cout << endl;
    // 要注意的是 *vectorPtr.push_back(7) 是一个错误的语法，虽然 *vectorPtr
    // 能够解引用为 userVec_1，但它并不能等同于 userVec_1.push_back()，因为
    // 点操作符 的优先级要高于 解引用，所以编译器会尝试直接对指针运行类的函数
    // 导致出错，正确的方法是用括号将 解引用 操作符包起来，调高其优先级
    (*vectorPtr).push_back(7);
    for(int i=0; i < userVec_1.size(); i++){
        cout << userVec_1[i] << " ";
    }
    cout << endl;
    
    return 0;
}