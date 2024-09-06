#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    /*
    在这个例子中，用户可以在同一个 cin 中多次输入变量的值，而每个变量之间既可以使用 空格 区分，
    也可以使用 回车 区分
    */
    cout << "How many CS215 lecture and lab you need to take every week?" << endl;
    double lectureTimes = 0;
    double LabTimes = 0;
    cin >> lectureTimes >> LabTimes;
    cout << "So you have " << lectureTimes + LabTimes 
    << " CS215 class every week." << endl;

    /*
    在C++中，若提前创建了一个变量和其类型，当用户为这个变量赋值时输入了错误的类型，程序会在默认情况下
    保持该变量为原有的值，而不是直接报错停止程序，在这个例子中，result_1默认是一个浮点数，当用户
    输入一个字符串时，C++会保持这个变量为创建时的默认值0。
    */
    cout << "input a string" << endl;
    double result_1 = 0;
    cin >> result_1;
    cout << result_1 << endl;

    /*
    使用String Variable ＝ "x"可以像其他变量类型一样单独储存变量，但这需要使用<String>头文件，
    默认情况下C++包含了一部分的字符串指令，但<String>包含更多处理字符串的指令
    */
    string name_1 = "Anthony";
    cout << name_1 << endl;
    cout << name_1.at(1) << endl; // variable.at(x)能够索引在x处的字符(索引从0开始)

    return 0;
}
