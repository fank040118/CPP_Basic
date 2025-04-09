#include <iostream>
#include <string>
#include <vector>

using namespace std;

// C++ 中，模板可以提供默认类型参数，以标准库complex为例，它是一个模板类
template <typename T = double>
class complex{
    ...
    private:
    T real, imagel;
}
// 一般用 className<> 变量 来使用默认模板参数
complex<> c