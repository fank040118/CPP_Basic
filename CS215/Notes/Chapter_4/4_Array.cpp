#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    /*
    数组(Array) - C++中的固定大小数据结构
    
    与Python列表的区别:
    1. 类型统一性: 数组中所有元素必须是同一数据类型
    2. 固定大小: 数组大小在声明时确定，运行时不可改变
    3. 内存连续: 数组元素在内存中连续存储，访问效率高
    
    数组的特点:
    - 静态分配内存
    - 索引从0开始
    - 越界访问可能导致未定义行为
    */
    
    cout << "=== 数组声明方式 ===" << endl;
    
    // 方式1: 直接指定大小 - 语法: 类型 数组名[大小]
    double userArray_1[5];
    cout << "声明了大小为5的double数组" << endl;

    // 方式2: 使用常量指定大小
    // 注意: 数组大小必须是编译时常量(const或constexpr)
    const int arraySize = 10;
    double userArray_2[arraySize];
    cout << "使用常量声明了大小为" << arraySize << "的数组" << endl;

    cout << "\n=== 数组初始化方式 ===" << endl;
    
    // 方式1: 完全初始化 - 提供所有元素的值
    int userArray_3[5] = {1, 2, 3, 4, 5};
    cout << "完全初始化数组: ";
    for(int i = 0; i < 5; i++) {
        cout << userArray_3[i] << " ";
    }
    cout << endl;
    
    // 方式2: 自动推导大小 - 编译器根据初始值确定数组大小
    int userArray_4[] = {1, 2, 3, 4, 5};
    cout << "自动推导大小的数组(大小为5): ";
    for(int i = 0; i < 5; i++) {
        cout << userArray_4[i] << " ";
    }
    cout << endl;
    
    // 方式3: 部分初始化 - 未指定的元素自动设为0(零值初始化)
    int userArray_5[5] = {1, 2, 3};  // 结果: {1, 2, 3, 0, 0}
    cout << "部分初始化数组: ";
    for(int i = 0; i < 5; i++) {
        cout << userArray_5[i] << " ";
    }
    cout << endl;
    
    // 方式4: 零值初始化 - 所有元素初始化为0
    int userArray_6[5] = {};
    cout << "零值初始化数组: ";
    for(int i = 0; i < 5; i++) {
        cout << userArray_6[i] << " ";
    }
    cout << endl;
    
    /*
    初始化类型说明:
    1. 部分初始化: 只提供部分元素值，其余自动设为零值
    2. 零值初始化: 使用{}显式将所有元素设为零值  
    3. 未初始化: 不提供初始值，元素值不确定(可能是垃圾值)
    */
    
    cout << "\n=== 数组访问与修改 ===" << endl;
    
    // 数组元素访问: 使用下标操作符[]
    // 语法: 数组名[索引] (索引从0开始)
    cout << "第一个元素: " << userArray_3[0] << endl;
    cout << "最后一个元素: " << userArray_3[4] << endl;
    
    // 遍历数组 - 使用循环访问所有元素
    cout << "遍历userArray_3: ";
    for(int i = 0; i < 5; i++) {  // 注意: i < 5, 不是 i <= 4
        cout << userArray_3[i] << " ";
    }
    cout << endl;
    
    // 修改数组元素 - 可以修改已存在的元素值
    cout << "\n修改数组元素:" << endl;
    cout << "修改前userArray_5: ";
    for(int i = 0; i < 5; i++) {
        cout << userArray_5[i] << " ";
    }
    cout << endl;
    
    userArray_5[3] = 40;
    userArray_5[4] = 50;
    
    cout << "修改后userArray_5: ";
    for(int i = 0; i < 5; i++) {
        cout << userArray_5[i] << " ";
    }
    cout << endl;
    
    /*
    重要注意事项:
    1. 数组索引从0开始，最大索引为(大小-1)
    2. C++不提供切片功能，需要用循环处理数组段
    3. 可以修改元素值，但不能改变数组大小
    4. 访问越界索引会导致未定义行为
    */

    return 0;
}