#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    /*
    C和C++在默认情况下使用一种叫“C-string“的字符数组来储存字符，在不使用
    #include <string>的情况下，我们使用char类型来储存字符串，但我们知道
    char类型实际上只能储存 单个字符，所以当我们需要储存多个字符的时候，我
    们就需要使用C-string来储存字符：
    char userChar[] = "xxxx...."
    此类型就是一个C-String，它实际上是一个数组，这个数组中有多个char类型
    变量，而每个变量都储存一个字符。
    */
   char userChar[] = "hello world";
   // cout可以正常打印一整个C-string的内容，但无法用在普通的数组上。
   cout << userChar << endl;
   /*
   为什么C-string可以被Cout打印，但普通的数组却不行呢？因为C-string是一种
   以‘\0’(空字符)结尾的数组，而普通数组并没有这样的形式，空字符用于标注这个
   字符串(虽然它本质上是一个数组)的结束位置，而当cout命令发现这个数组是以空
   字符结尾时，它将使用类似于字符串打印的方式去打印这个数组。
   */
    return 0;
}