#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double userNum;
    string userStr;

    /*
        “流”是C++中一个重要的概念，“输入流”可以理解为程序从外部 逐个 获取数据的过程，
    当我们使用 cin 函数时，我们就是在使用一个输入流对象，让程序cin这个输入流对象
    从输入缓冲区尝试读取数据并将其赋值给后续变量。

        “缓冲区”是一个储存数据的地方，输入缓冲区存放了用户输入的数据，在这些数据都被
    数据流读取并提取之前，他们会 一直 保持在输入缓冲区中，直到被成功读取。

        在这个例子中，我们为userNum和userStr分别声明了double和string类型，当用户直接
    在cin >> userNum这个指令处输入“123abc”时，数据“123abc”就被存放在了输入缓冲
    区中，并且等待cin函数将其读取到userNum这个变量中。
        但是，由于userNum是一个double变量，它不可能存放字符串类型的数据，所以“123abc”
    这个数据只有“123”的部分被成功读取给了userNum变量，而“abc”部分则‘卡在了’输入
    缓冲区中，他们在等待下一次输入流。

        那么当下一次cin >> userStr 处，数据"abc"就成功的被读取进了userStr这个变量中，
    用户将无法再给userStr这个变量赋值，即使这里有一条cin函数，但它却会赋值“abc”以后跳
    过让用户赋值的步骤。
    
        那么为什么程序会跳过让用户从终端输入数据赋给userStr这个变量的过程呢？这是因为
    cin这个函数的意义不能理解为“让用户输入数据到变量”，而是应该理解为“从输入缓冲区中读
    取数据并赋给变量”，也就是说，cin的目的是将缓冲区的数据传输给变量，而不是让用户手动
    赋值，如果输入缓冲区是空的，cin函数会“阻塞”程序，强迫让程序等待用户通过终端输入数
    据，这些数据会进去输入缓冲区，然后cin再从输入缓冲区中将这些数据赋给变量。
    */
    cout << "Please enter \"123abc\" " << endl;
    cin >> userNum;
    cin >> userStr;
    cout << "result is " << userNum << " and " << userStr << endl;

    return(0);
}