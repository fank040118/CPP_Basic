#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    /*
    在上一节，我们提到使用“探针”来引导用户退出循环或退出程序，但在某些情况中，
    使用“探针”是不可能的，比如创建一个计算器，那么任意数字都能够作为计算器的输入，
    这样的情况下就没有任何数字可以作为“探针”，那么在这种情况下，要求用户输入其他
    类型的变量将会是更加通用的方法，比如要求用户输入“Q”来退出程序。

    但是，既然我们创建的变量是为了计算器使用的，那么他就有可能是一个Double值，在
    这种变量中输入字母“Q”会产生程序错误，那么我们就在此引入了一个新指令——
    cin.fail(),这个指令能够检测输入中是否存在错误。
    cin.fail()是一个布尔值，当输入流存在错误时，它会变成true，反之则是false
    */

    double userInput;
    double userResult;

    cout << "Please enter a number to mutiply it by 10." << endl;
    cin >> userInput;

    /*
        在这个例子中，如果用户输入的值不是Double值，那么Cin.fail将会变成true，
    并进入if(cin.fail())的条件语句中，并在cout以后清除错误状态并忽略后续字符，
    随后程序将会跳过else语句中的计算语句。
        cin.clear()是用来清除输入流中的错误状态的，若输入流中存在错误，cin.fail
    只是会让用户有能力知道存在错误，但它并不会解决这个错误，我们需要使用cin.clear()
    来清除这个错误标识，让程序继续运行。
        cin.ignore(x,y)是用来清空输入缓冲区的后续数据的函数，他有两个参数x和y，
    x可以设定为需要忽略的数据的量，当设定为10时，代表缓冲区中接下来的10个字符都
    被清除，y可以设定为一致忽略，直到遇到y字符停止忽略（y字符本身不会被清除）。

        在C++程序中，当用户输入一个值并回车时，C++会默认给他的结尾加上一个\n换行符，
    所以如果我们想使用cin.ignore来将缓冲区接下来的所有字符都清空，我们可以写为
    cin.ignore(3000,'\n')，3000是为了在遇到换行符之前能除掉足够多的字符。
    */

    if (cin.fail()){
        cout << "you entered a wrong variable, it is not a number!" << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else{
        userResult = userInput * 10;
        cout << "the result is: " << userResult << endl;
    }

    

    return(0);
}