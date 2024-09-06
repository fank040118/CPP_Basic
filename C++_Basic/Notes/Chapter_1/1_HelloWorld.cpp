
// include <iostream> 是一个预处理指令，它引入了一个叫做“input/output stream”的库，它包含了标准输出输入的基本定义
// using namespace std 是一个预处理指令，它的目的是为了告诉编译器这个文件将使用 std命名空间 的所有符号
// 它包含了绝大多数我们使用的符号，以避免后续每次使用这类符号（函数，类，对象）都要重复编写 std 这个指令
// 这两个预处理指令都是每次文件创建时的必须指令
#include <iostream>

using namespace std;

int main()
{   
    /* C++中 cout 是输出指令，而 cin 是输入指令，它们类似于Python中的print和input，
    <<和>>代表着两种不同的流输入符，一种叫输入运算符，另一种叫输出运算符
    前者将右边的值输入到左边的输入流中，后者把左侧的值提取并储存在右侧的变量中，
    它们是输入/输出的必要条件，如果同一语句中包含多个值，就要在值之间插入流输入/输出符
    */
    cout << "Hello World !" << endl;

    // 在C++中，你必须在让用户输入一个值之前，先声明这个值，你不能凭空让用户直接通过输入来创建一个新值
    string userInput;
    cin >> userInput;

    // C++中，输出多个不同的值时需要使用 << 分割，这个例子中前面的字符串一个值，中间的变量是一个值，
    // 后面的换行符又是一个新值
    cout << "your input is: " << userInput << endl;

    return 0;
}