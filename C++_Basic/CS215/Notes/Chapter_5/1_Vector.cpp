#include <iostream>
#include <iomanip>
#include <string>
#include <vector> // vector 是使用vector类型的必要头文件
using namespace std;

// vector的函数传递方法在文件尾部
void printVector(const vector<int> &);

int main()
{
    /*
    Vector向量，是一种C++标准库提供的动态数组的数据结构，它和数组都是能够储存
    多个值的数据类型，但它比起数组来说，解决了非常多静态数组的局限性的问题。
    Vector和数组不一样，他的大小是动态的，不想传统数组一样一旦确定大小就无法更改
    我们可以不断的向vector添加元素，即使它在定义时的大小非常小，直到耗尽内存。
    除此以外，非常方便的是vector在传递给函数时，我们不需要告诉函数它的大小
    是什么，因为vector会自行管理大小
    */

    // vector和数组的创建语法不同，它遵从
    // vector<类型> 名字 的格式创建，如果没有指明它有多大，那么它就是完全空
    // 的变量，甚至连”空值“都不存在
    vector<int> userVector_1;
    // 我们也可以创建一个有初始大小的vector，只需在名字以后加上一个(大小)：
    vector<int> userVector_2(5);
    // 这样就创建了一个具有5个零值的vector，vector和数组不一样，即使没有部分显
    // 示化，它的内容也会被赋零值，而不是存在随机数。

    // 我们可以直接创建一个没有大小的vector，并且直接为其初始化变量，那么它
    // 将自动变成相应的大小
    vector<int> userVector_3 = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++){
        cout << userVector_3[i] << ' ';
    }
    cout << endl;

    // push_back() 比较类似于python中的append，它会在vector的结尾处
    // 添加新的值，如果vector本身已经用完了空间，那么它也会为此多增一格
    userVector_3.push_back(10);
    printVector(userVector_3);

    // pop_back() 用于删除vector中的最后一个元素，同时也删除该元素的
    // 位置，但使用前最好确定vector存在元素，否则会导致越界访问
    if (userVector_3.size() > 0)
        userVector_3.pop_back();
    printVector(userVector_3);

    // 以下是两种常用的添加元素的方式，一种是创建空vector，然后通过循环
    // 为其赋值，另一种是创建指定大小的vector，然后给其索引赋值
    vector<int> sqrtVector;
    for (int i = 0; i < 10; i++){
        sqrtVector.push_back(i*i);
    }
    printVector(sqrtVector);

    vector<int> treeVector(10);
    for (int i = 0; i < treeVector.size(); i++){
        for (int j = 0; j <= i; j++){
            treeVector[i] = treeVector[i] + j;
        }
    }
    printVector(treeVector);

    return 0;
}

/*
vector和数组不一样，vector既可以按值传递，也可以引用传递，所以在函数中调用
vector时，如果需要使用引用传递，就需要标出&以表明我们需要使用引用传递，在对
于那些不会修改vector本身的数值的函数来说，使用引用传递是更合理的方法，因为
如果使用按值传递，编译器就需要额外创建一份vector的拷贝，消耗更多内存和性能，
而引用传递则可以直接使用原vector
*/

/*
    这个函数用于打印vector的每个元素，对于vector来说，我们并不需要呼叫函数
时调用它的大小，因为我们可以在函数内实时使用vector.size()来查询vector的大小。
    除此以外，既然这个函数只是用于打印vector的值，那么我们就可以将函数内的
vector定义为 const常数 来避免不小心修改它。
*/
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";  // 输出 vector 中的每个元素
    }
    cout << endl;
}