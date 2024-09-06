#include <iostream>
#include <cmath>
#include <cstdlib> // cstdlib又是另一个预处理库，包含更多指令，比如 绝对值
using namespace std;

int main()
{

    // 这是一种常见的计算方式
    int totalNum_1 = 5;
    totalNum_1 = totalNum_1 + 1 + 2 + 3;
    cout << totalNum_1 << endl;

    // 这是前者的缩减版本，他们两者结果一致，但是+=这个符号更加简便
    int totalNum_2 = 5;
    totalNum_2 += 1 + 2 + 3;
    cout << totalNum_2 << endl;

    // *= 等于将自己乘以某一倍数，后面的数字代表这个变量的乘数
    totalNum_2 *= 2;
    cout << totalNum_2 << endl;

    return 0;
}