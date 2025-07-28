#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>  // 用于C字符串函数
using namespace std;

int main()
{
    cout << "=== C字符串(C-String) vs C++字符串(String) ===" << endl;
    
    /*
    C字符串(C-String):
    - 本质是字符数组(char array)
    - 以空字符'\0'结尾(null-terminated)
    - 继承自C语言的字符串处理方式
    - 内存管理需要手动处理
    */
    
    // 创建C字符串的方式
    char cstr1[] = "Hello World";  // 自动添加'\0'
    char cstr2[] = {'H', 'e', 'l', 'l', 'o', '\0'};  // 手动指定每个字符
    
    cout << "C字符串cstr1: " << cstr1 << endl;
    cout << "C字符串cstr2: " << cstr2 << endl;
    
    // C字符串的特点演示
    cout << "\nC字符串内部结构:" << endl;
    for(int i = 0; cstr1[i] != '\0'; i++) {
        cout << "cstr1[" << i << "] = '" << cstr1[i] << "'" << endl;
    }
    cout << "结尾的空字符: '\\0'" << endl;
    
    /*
    C++ string类:
    - 标准库提供的字符串类
    - 自动管理内存
    - 提供丰富的成员函数
    - 更安全、更易用
    */
    string cppStr = "Hello World";
    cout << "\nC++字符串: " << cppStr << endl;
    cout << "字符串长度: " << cppStr.length() << endl;
    
    // 比较两种字符串类型
    cout << "\n=== 功能对比 ===" << endl;
    
    // 字符串连接
    string str1 = "Hello ";
    string str2 = "World";
    string result = str1 + str2;  // C++ string支持+操作
    cout << "C++ string连接: " << result << endl;
    
    // C字符串需要使用函数进行操作
    char cstr3[20] = "Hello ";
    strcat(cstr3, "World");  // 使用strcat函数连接
    cout << "C字符串连接: " << cstr3 << endl;
    
    /*
    重要区别:
    1. 内存管理: C++string自动管理，C字符串需要手动管理
    2. 安全性: C++string更安全，C字符串容易越界
    3. 功能性: C++string功能更丰富
    4. 兼容性: C字符串与C语言兼容
    */
    
    return 0;
}