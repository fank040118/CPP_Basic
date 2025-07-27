// C++ 类模板笔记 (Class Template) - 增强可读性版
//
// 本笔记详细介绍了 C++ 中类模板的概念和使用方法：
// 1. 类模板的基本语法 (Template Syntax)
// 2. 模板参数的使用 (Template Parameters)
// 3. 类模板的实例化 (Template Instantiation)
// 4. 类模板的实际应用示例 (Practical Examples)
//
// 类模板是 C++ 泛型编程的核心特性之一，允许我们编写可以处理
// 多种数据类型的通用类，提高代码的复用性和类型安全性。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- 类模板定义 (Class Template Definition) ---
//
// 基本语法: template <class T> 或 template <typename T>
//
// 关键概念解释:
// - template: 模板关键字，告诉编译器这是一个模板定义
// - class/typename: 两者在这里完全等价，都表示 T 是一个类型参数
// - T: 类型参数名（可以是任意标识符，T 是惯例）
// - 类型参数可以是任何类型：内置类型(int, char, double)或自定义类型
template <class T>
class MyPair {
public:
    // --- 构造函数 (Constructor) ---
    // 接受两个相同类型 T 的参数，用于初始化类的私有成员
    // 参数名使用有意义的名称，提高代码可读性
    MyPair(T firstValue, T secondValue) {
        values[0] = firstValue;  // 将第一个值存储在索引 0
        values[1] = secondValue; // 将第二个值存储在索引 1
    }

    // --- 公共成员函数 (Public Member Functions) ---
    
    // 获取第一个值
    T getFirst() const {
        return values[0];
    }
    
    // 获取第二个值
    T getSecond() const {
        return values[1];
    }
    
    // 设置第一个值
    void setFirst(T newValue) {
        values[0] = newValue;
    }
    
    // 设置第二个值
    void setSecond(T newValue) {
        values[1] = newValue;
    }
    
    // 打印两个值（用于调试和演示）
    void print() const {
        cout << "Pair: (" << values[0] << ", " << values[1] << ")" << endl;
    }
    
    // 交换两个值的位置
    void swap() {
        T temp = values[0];
        values[0] = values[1];
        values[1] = temp;
    }

private:
    // --- 私有成员变量 (Private Member Variables) ---
    // 存储两个相同类型 T 的值的数组
    // 使用数组而不是两个单独的变量，演示了模板与数组的结合使用
    T values[2];
};

// --- 类模板的使用示例和说明 ---
//
// 类模板的实例化 (Template Instantiation):
// 语法: ClassName<ActualType> objectName(arguments);
//
// 示例用法:
// 1. 整数对: MyPair<int> intPair(10, 20);
// 2. 字符串对: MyPair<string> strPair("Hello", "World");  
// 3. 浮点数对: MyPair<double> doublePair(3.14, 2.71);
// 4. 字符对: MyPair<char> charPair('A', 'B');
//
// 编译器工作原理:
// 当你写 MyPair<int> 时，编译器会自动生成一个专门处理 int 类型的类，
// 所有的 T 都会被替换成 int。这个过程叫做"模板实例化"。
//
// 优势说明:
// 1. 类型安全: 编译时检查类型匹配，避免运行时错误
// 2. 代码复用: 一个模板可以用于多种类型，避免重复代码
// 3. 性能优异: 编译时展开，没有运行时开销
// 4. 易于维护: 修改模板逻辑，所有实例化的类都会自动更新

// --- 演示函数 (Demonstration Function) ---
// 这个函数展示了如何在实际代码中使用类模板
void demonstrateClassTemplate() {
    cout << "\n=== 类模板使用演示 ===" << endl;
    
    // 1. 创建整数对
    MyPair<int> intPair(42, 100);
    cout << "整数对: ";
    intPair.print();
    
    // 2. 创建字符串对
    MyPair<string> stringPair("Hello", "Template");
    cout << "字符串对: ";
    stringPair.print();
    
    // 3. 创建浮点数对
    MyPair<double> doublePair(3.14159, 2.71828);
    cout << "浮点数对: ";
    doublePair.print();
    
    // 4. 演示成员函数的使用
    cout << "\n--- 成员函数演示 ---" << endl;
    cout << "整数对的第一个值: " << intPair.getFirst() << endl;
    cout << "整数对的第二个值: " << intPair.getSecond() << endl;
    
    // 5. 修改值
    intPair.setFirst(999);
    cout << "修改第一个值后: ";
    intPair.print();
    
    // 6. 交换值
    intPair.swap();
    cout << "交换后: ";
    intPair.print();
}