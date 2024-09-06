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
    // variable.at[x]和variable[x]都能提取变量在某一索引处的值，但是前者会更安全，在索引越界
    // 或者不存在时仅会抛出异常，而不是直接导致程序出错
    char firstLetter = name_1.at(0); // char是只能储存单个字符的类型
    cout << firstLetter << endl;

    
    /*
    字符串可以直接使用加减，和其他语言相同,但要注意的是，字符串的相加需要以变量的形式做加减，
    比如，"Anthony" + "Wang"是不能使用的，这是两个独立的字符串，而不是以变量的形式做加减
    */
    string firstName = "Anthony";
    string lastName = "Wang";
    string fullName = firstName + " " + lastName;
    cout << fullName << endl;

    return 0;
}
