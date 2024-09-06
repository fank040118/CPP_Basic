#include <iostream>
#include <cmath> // cmath是另一个预处理库，它包含了一些特殊数学计算字符，例如sqrt指令
using namespace std;

int main()
{
    /*
    在下面的例子中，result_1这个变量虽然创建时被声明了是double值，但是创建并输入了值以后，
    打印它时却仍然是7/4得到的整数1，而不是1.75这个浮点数，也就是说，它的值最终还是被计算为了整数
    这是因为当C++运算时，若算式内的值都是整数，那么最终得到的结果也会是整数，即使这两个整数的计算
    本应该会得到一个存在小数的结果，这与其他语言不通
    */
    double result_1 = 0;
    result_1 = 7/4;
    cout << result_1 << endl;

    /*
    在这个例中，最终算式被成功的计算为了浮点数，这是因为只要算式中存在一个浮点数，那么C++最终就会将其
    计算为浮点数结果，result_3虽然是一个整数结果，但计算时使用了浮点数，所以他的结果仍然是double
    */
    double result_2 = 0;
    double result_3 = 0;
    result_2 = 7/4.0;
    result_3 = 6/2.0;
    cout << result_2 << endl << result_3 << endl;
    cout << typeid(result_3).name() << endl;

    /*
    在这个例子中，我们使用 const 指令来创建了一个值，它与直接创建值之间的区别是 const 创建
    的值将在程序运行期间 无法被更改 ，这代表一旦程序运行且这个值被成功创建，它将只能被引用，
    但任何尝试修改这个值的操作都会导致程序直接出错，const 特别适合创建那些本就应该是固定的值
    */
    const double price = 100;
    double money = 0;
    cout << "How much money you have?" << endl;
    cin >> money;
    cout << "you can buy " << money/price << " of it" << endl;




    return 0;
}