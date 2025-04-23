#include <iostream>
#include <cmath>
#include <iomanip> // iomanip是另一个库，它包含了更多的指令，这个例子中的setprecision就在其中
using namespace std;

int main()
{

    /*
    在这个例子中，我们提前设置了一个浮点数，然后将其输出，在输出的过程中，我们首先使用fixed让
    结果输出时 禁用科学计数法 ，随后我们使用setprecision来控制值的小数点后的有效位数，
    在此处限制为了2，所以小数点后有小数只有2位，要注意的是，如果这里没有使用fixed指令，
    那么setprecision将会控制整个值得有效位数而非是小数点的有效位数，导致最终结果变成1.2
    */
    double num_1 = 1.21863;
    cout << fixed << setprecision(2) << num_1 << endl;

    // 这里我们重置化浮点数的显示方式和有效位数，在之前我们设置了它们，这两个格式化I/O操作符
    // 会一直保留在文件中，也就是说后续的所有输出都将受到这两个操作符的影响，除非我们手动初始化
    cout << defaultfloat << setprecision(6);

    /* 
    setw(n)是一个特殊的操作符，也在iomanip库中，它的目的是设置输出字符的宽度，如果输出字符
    的宽度小于n，那么默认情况下这个输出的左侧将会使用空格填充，如果输出字符的宽度大于或等于
    n，那么它将会被完整输出，不会因为这个操作符而被截断长度。与setprecision和fixed不同的是
    这个操作符仅会影响接下来的第一个输出操作，而不会一直保持影响，所以无需为其进行重置化。
    */
    double num_2 = 1.23456;
    double num_3 = 1.2;
    cout << setw(5) << num_2 << endl; // 1.23456大于这里设置的5，小数点也被纳入计数

    /*
    1.2小于这里设置的5，所以将会受到setw(5)的影响，除此之外，我们通过setfill(x)指令让填充
    输出时的填充字符从默认的字符变成了手动设置的x，并使用right让字符向右对齐，这代表num_3将
    会优先填充5个字符限制的右侧，而左侧没有填充的字符才会被setw和setfill代替填充。

    要注意的是setfill会如同setprecision和fixed一样影响后续的输出，所以想要重新使用默认的
    填充空格的话，就需要在下一次输出前使用setfill(' ')重置。
    */
    cout << setw(5) << setfill('*') << right << num_3 << endl;

    /*
    在这个例子中，我们先创建三个不同宽度和大小的数，然后将输出设置为非科学计数法，小数点有效位数
    为2位，且重置填充字符为空格，最后使用同样的字符宽度限制输出，这能轻松的让多个不同宽度和大小
    的变量以整洁的方式输出。
    */
    double num_4 = 1.23456;
    double num_5 = 2.34567;
    double num_6 = 34.5;
    cout << fixed << setprecision(2) << setfill(' ');
    cout << "----------|" << endl;
    cout << setw(10) << num_4 << "|" << endl;
    cout << setw(10) << num_5 << "|" << endl;
    cout << setw(10) << num_6 << "|" << endl;
    cout << "----------|" << endl;

    return 0;
}