// C++ 函数模板笔记 (Function Template) - 增强可读性版
//
// 本笔记详细介绍了 C++ 中函数模板的概念和使用方法：
// 1. 函数模板的基本语法 (Function Template Syntax)
// 2. 模板参数的自动推导 (Template Parameter Deduction)
// 3. 显式模板实例化 (Explicit Template Instantiation)
// 4. 函数模板的实际应用示例 (Practical Examples)
//
// 函数模板允许我们编写可以处理多种数据类型的通用函数，
// 是 C++ 泛型编程的重要组成部分，能显著提高代码的复用性。

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// --- 基础函数模板示例 (Basic Function Template Example) ---
//
// 基本语法: template <typename T> 或 template <class T>
//
// 关键概念解释:
// - template: 模板关键字，声明这是一个模板函数
// - typename/class: 两者在函数模板中完全等价，都表示 T 是类型参数
// - T: 类型参数名，可以是任意有效标识符，T 是惯例
template <typename T>
void printAndAdd(T first, T second) {
    // 创建一个新的 T 类型变量，用于存储两个参数的和
    // 注意：这要求类型 T 必须支持 + 运算符
    T sum = first + second;
    
    cout << "参数1: " << first << endl;
    cout << "参数2: " << second << endl;
    cout << "它们的和: " << sum << endl;
    cout << "类型大小: " << sizeof(T) << " 字节" << endl;
    cout << "---" << endl;
}

// --- 数组操作函数模板 (Array Operation Function Template) ---
//
// 这个模板展示了如何处理数组类型的模板参数
// 同时演示了更复杂的模板函数逻辑
template <typename T>
void copyAndPrint(T destination[], const T source[], int size) {
    cout << "正在复制数组..." << endl;
    
    // 第一步：将源数组的元素复制到目标数组
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
    
    cout << "源数组: ";
    for (int i = 0; i < size; i++) {
        cout << source[i] << " ";
    }
    cout << endl;
    
    cout << "目标数组: ";
    for (int i = 0; i < size; i++) {
        cout << destination[i] << " ";
    }
    cout << endl;
    cout << "---" << endl;
}

// --- 高级函数模板示例：数组统计 (Advanced Function Template: Array Statistics) ---
template <typename T>
void analyzeArray(const T array[], int size, const string& arrayName) {
    if (size <= 0) {
        cout << "错误：数组大小必须大于0" << endl;
        return;
    }
    
    T sum = array[0];
    T min = array[0];
    T max = array[0];
    
    // 计算和、最小值、最大值
    for (int i = 1; i < size; i++) {
        sum += array[i];
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }
    
    cout << "=== " << arrayName << " 数组分析 ===" << endl;
    cout << "大小: " << size << " 个元素" << endl;
    cout << "总和: " << sum << endl;
    cout << "平均值: " << static_cast<double>(sum) / size << endl;
    cout << "最小值: " << min << endl;
    cout << "最大值: " << max << endl;
    cout << "范围: " << (max - min) << endl;
    cout << "---" << endl;
}

// --- 模板函数重载示例 (Template Function Overloading) ---
//
// 可以为模板函数创建特定类型的重载版本
template <typename T>
void displayValue(T value) {
    cout << "通用模板: " << value << endl;
}

// 为字符串类型提供特殊处理
template <>
void displayValue<string>(string value) {
    cout << "字符串特化: \"" << value << "\" (长度: " << value.length() << ")" << endl;
}

// --- 多参数模板函数 (Multi-Parameter Template Function) ---
template <typename T1, typename T2>
void compareTypes(T1 value1, T2 value2) {
    cout << "比较两个不同类型的值:" << endl;
    cout << "值1: " << value1 << " (类型大小: " << sizeof(T1) << " 字节)" << endl;
    cout << "值2: " << value2 << " (类型大小: " << sizeof(T2) << " 字节)" << endl;
    
    // 注意：这里不能直接比较 value1 和 value2，因为它们可能是不同类型
    cout << "类型是否相同: " << (typeid(T1).name() == typeid(T2).name() ? "是" : "否") << endl;
    cout << "---" << endl;
}

int main() {
    cout << "=== C++ 函数模板使用演示 ===" << endl << endl;
    
    // --- 1. 基础函数模板使用 ---
    cout << "1. 基础函数模板演示:" << endl;
    
    // 自动类型推导 (Automatic Type Deduction)
    // 编译器根据传入的参数自动推导出 T 的类型
    printAndAdd(10, 20);        // T 被推导为 int
    printAndAdd(3.14, 2.86);    // T 被推导为 double
    printAndAdd('A', 'B');      // T 被推导为 char，结果是 ASCII 值相加
    
    // 显式类型指定 (Explicit Type Specification)
    // 有时候我们需要明确指定类型，特别是当参数类型不明确时
    printAndAdd<int>(5, 9);     // 明确指定 T 为 int
    printAndAdd<double>(1, 2);  // 明确指定 T 为 double，1 和 2 会被转换为 double
    
    cout << "\n2. 数组操作模板演示:" << endl;
    
    // --- 2. 数组操作函数模板使用 ---
    
    // 整数数组示例
    int sourceInt[5] = {1, 2, 3, 4, 5};
    int destInt[5];  // 未初始化的目标数组
    copyAndPrint(destInt, sourceInt, 5);
    
    // 浮点数组示例
    double sourceDouble[4] = {1.1, 2.2, 3.3, 4.4};
    double destDouble[4];
    copyAndPrint(destDouble, sourceDouble, 4);
    
    // 字符数组示例
    char sourceChar[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char destChar[6];
    copyAndPrint(destChar, sourceChar, 6);
    
    cout << "\n3. 数组分析模板演示:" << endl;
    
    // --- 3. 高级函数模板使用 ---
    int numbers[] = {15, 3, 9, 1, 12, 7};
    double scores[] = {85.5, 92.3, 78.1, 95.7, 88.9};
    
    analyzeArray(numbers, 6, "整数");
    analyzeArray(scores, 5, "成绩");
    
    cout << "\n4. 模板特化演示:" << endl;
    
    // --- 4. 模板特化使用 ---
    displayValue(42);
    displayValue(3.14159);
    displayValue(string("Hello Template!"));
    
    cout << "\n5. 多参数模板演示:" << endl;
    
    // --- 5. 多参数模板使用 ---
    compareTypes(100, 3.14);          // int 和 double
    compareTypes('A', string("B"));   // char 和 string
    compareTypes(42, 42);             // 两个 int
    
    // --- 模板使用的重要提示 ---
    cout << "\n=== 函数模板使用要点 ===" << endl;
    cout << "1. 类型推导: 编译器能够根据参数自动推导模板参数类型" << endl;
    cout << "2. 类型约束: 模板函数中使用的运算符必须被类型 T 支持" << endl;
    cout << "3. 编译时展开: 每种类型都会生成对应的函数实例" << endl;
    cout << "4. 类型安全: 编译时进行类型检查，避免运行时错误" << endl;
    cout << "5. 性能优异: 没有运行时的类型转换开销" << endl;
    
    return 0;
}