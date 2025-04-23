#include <iostream>
#include <string>
/*
在之前学习中使用的栈(Stack)，是由程序运行时用于函数调用与局部变量储存的系统级栈(Call Stack)
这个栈是由编译器和操作系统在底层内存上进行管理的一块区域，它根据代码运行状况会自行
扩大或缩小，用来记录函数内参数，地址，变量数据等一系列信息，它是一种底层内存结构，不由
用户来进行操作

但栈并不是只有这一种表现方式，它也可以作为一种具体的数据结构，让用户自行创建并管理，就像
其它变量一样
这样的栈是一种由代码显性创建，调用，操作的对象，它和之前的栈有着一样的“先进后出”或
“后进先出”的结构
*/
#include <stack>

using namespace std;

bool valid_parentheses(string);

int main(){
    
    // 通过 stack<类型> 变量名; 能够创建一个栈类型容器
    stack<int> intStack;
    stack<string> stringStack;

    // push() 是栈的常用函数，用于将一个元素压入至栈
    intStack.push(1);
    intStack.push(2);

    // 由于栈的元素是先进后出，后进先出，所以现在栈的顶元素是“2”
    // top() 函数用来返回栈顶元素
    cout << intStack.top() << endl;

    // pop() 函数用来弹出栈顶元素，想要弹出顶元素下面的元素
    // 就必须先弹出栈顶元素，这是栈本身的数据结构决定的
    // 那么在运行这个命令以后，栈此时就只剩一开始压入的元素 1 了
    intStack.pop();

    // empty() 函数用来检查栈是否为空，它的返回值为布尔类型
    // 如果栈已经空了，那么返回1，反之则返回0
    // 在前面加上 ! 的话则变成了没有空返回1，已经空返回0
    cout << !intStack.empty() << endl;

    // 栈的运用————————————————————————————————

    // 利用栈的先进后出的特性，我们可以用它来将一个数列进行反转
    int userArray[5] = {1,2,3,4,5};
    stack<int> userStack;

    for(int i=0; i<5; i++){
        // 通过一个for循环，以此推入数列的值，那么栈内元素将会是[1,2,3,4,5]
        userStack.push(userArray[i]);
    }
    for(int i=0; i<5; i++){
        // 然后将栈的顶元素依次赋给数列的元素，并弹出那个元素，那么此后数列内的元素
        // 将是反转后的元素
        userArray[i] = userStack.top();
        userStack.pop();
    }
    for(int i=0; i<5; i++){
        cout << userArray[i]; // 此时可以看到数列内的元素已经被反转成了[5,4,3,2,1]
    }
    cout << endl;

    // 栈还可以用来检查字符，假设我们有一串字符，字符中有些随机的字符和一系列括号
    // 如果我们想检查是否每个 左括号 都能和一个 右括号 匹配，那么我们可以使用栈
    // 来完成
    string userString = "((...())123)()";
    cout << valid_parentheses(userString) << endl;

    return 0;
}
// 传入字符串
bool valid_parentheses(string str) {
    // 创建一个用来储存单个字符的栈
    stack<char> char_stack;
    // 遍历字符串中的每一个字符
    for (int i = 0; i < str.length(); i++) {
        // 如果字符 = 左括号，那么将其压入到栈中
        if (str[i] == '(') {
            char_stack.push(str[i]);
        } else if (str[i] == ')') {
            // 遇到右括号就看看栈里有没有左括号与之匹配
            if (char_stack.empty()) {
                // 栈空的情况下还有右括号，无法匹配
                // 那么返回 false
                return false;
            }
            // 如果没有，就弹出一个左括号与之匹配
            char_stack.pop();
        }
    }
    // 处理完所有字符后检查
    return char_stack.empty();
}
