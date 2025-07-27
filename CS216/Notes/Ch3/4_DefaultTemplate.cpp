// C++ 默认模板参数笔记 (Default Template Parameters) - 增强可读性版
//
// 本笔记详细介绍了 C++ 中默认模板参数的概念和使用方法：
// 1. 默认模板参数的基本语法 (Default Template Parameter Syntax)
// 2. 类模板中的默认参数 (Default Parameters in Class Templates)
// 3. 函数模板中的默认参数 (Default Parameters in Function Templates)
// 4. 多个默认参数的使用 (Multiple Default Parameters)
// 5. 默认参数的实际应用 (Practical Applications)
//
// 默认模板参数允许我们为模板参数提供默认值，使得模板的使用更加
// 灵活和便利，同时保持向后兼容性。

#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <memory>

using namespace std;

// --- 1. 基础类模板的默认参数示例 ---
//
// 语法：template <typename T = DefaultType>
// 当用户不指定模板参数时，编译器会使用默认类型
template <typename T = double>
class SimpleContainer {
private:
    T data;
    
public:
    // 构造函数：接受一个 T 类型的初始值
    SimpleContainer(T initialValue = T{}) : data(initialValue) {}
    
    // 设置数据
    void setData(T newData) {
        data = newData;
    }
    
    // 获取数据
    T getData() const {
        return data;
    }
    
    // 打印数据和类型信息
    void printInfo() const {
        cout << "存储的数据: " << data << endl;
        cout << "数据类型大小: " << sizeof(T) << " 字节" << endl;
        cout << "---" << endl;
    }
};

// --- 2. 复杂数据类型的模板类 (类似于标准库的 complex) ---
//
// 这个例子展示了如何创建一个类似于 std::complex 的模板类
// 默认使用 double 类型，但也可以指定其他数值类型
template <typename T = double>
class MyComplex {
private:
    T real;    // 实部 (real part)
    T imag;    // 虚部 (imaginary part)
    
public:
    // 默认构造函数
    MyComplex(T r = T{}, T i = T{}) : real(r), imag(i) {}
    
    // 获取实部
    T getReal() const { return real; }
    
    // 获取虚部
    T getImag() const { return imag; }
    
    // 设置实部
    void setReal(T r) { real = r; }
    
    // 设置虚部
    void setImag(T i) { imag = i; }
    
    // 复数加法
    MyComplex operator+(const MyComplex& other) const {
        return MyComplex(real + other.real, imag + other.imag);
    }
    
    // 复数乘法
    MyComplex operator*(const MyComplex& other) const {
        return MyComplex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }
    
    // 打印复数
    void print() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << (-imag) << "i";
        cout << endl;
    }
    
    // 计算模长 (magnitude)
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

// --- 3. 多个默认参数的模板类 ---
//
// 展示如何使用多个默认模板参数
// 从右到左必须都有默认值（如果要省略的话）
template <typename ValueType = int, typename SizeType = size_t, SizeType DefaultSize = 10>
class FlexibleArray {
private:
    ValueType* data;
    SizeType size;
    SizeType capacity;
    
public:
    // 构造函数
    FlexibleArray(SizeType initialSize = DefaultSize) 
        : size(0), capacity(initialSize) {
        data = new ValueType[capacity];
    }
    
    // 析构函数
    ~FlexibleArray() {
        delete[] data;
    }
    
    // 拷贝构造函数
    FlexibleArray(const FlexibleArray& other) 
        : size(other.size), capacity(other.capacity) {
        data = new ValueType[capacity];
        for (SizeType i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    
    // 添加元素
    void push_back(const ValueType& value) {
        if (size >= capacity) {
            cout << "数组已满，无法添加更多元素!" << endl;
            return;
        }
        data[size++] = value;
    }
    
    // 获取元素
    ValueType& operator[](SizeType index) {
        return data[index];
    }
    
    // 获取当前大小
    SizeType getSize() const { return size; }
    
    // 获取容量
    SizeType getCapacity() const { return capacity; }
    
    // 打印所有元素
    void printAll() const {
        cout << "数组内容: ";
        for (SizeType i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "\n大小: " << size << ", 容量: " << capacity << endl;
        cout << "---" << endl;
    }
};

// --- 4. 函数模板的默认参数 (C++11之后支持) ---
//
// 函数模板也可以有默认参数，但语法稍有不同
template <typename T = int, typename U = double>
auto calculateWeightedSum(T value1, U weight1, T value2, U weight2) 
    -> decltype(value1 * weight1 + value2 * weight2) {
    
    auto result = value1 * weight1 + value2 * weight2;
    
    cout << "加权求和计算:" << endl;
    cout << "值1: " << value1 << ", 权重1: " << weight1 << endl;
    cout << "值2: " << value2 << ", 权重2: " << weight2 << endl;
    cout << "结果: " << result << endl;
    cout << "---" << endl;
    
    return result;
}

// --- 5. 特化和默认参数的结合使用 ---
template <typename T = string>
class MessageLogger {
private:
    T prefix;
    
public:
    MessageLogger(const T& p = T{}) : prefix(p) {}
    
    void log(const T& message) {
        cout << "[" << prefix << "] " << message << endl;
    }
};

// 为整数类型提供特化
template <>
class MessageLogger<int> {
private:
    int logLevel;
    
public:
    MessageLogger(int level = 1) : logLevel(level) {}
    
    void log(int code) {
        cout << "[级别 " << logLevel << "] 错误代码: " << code << endl;
    }
};

int main() {
    cout << "=== C++ 默认模板参数使用演示 ===" << endl << endl;
    
    // --- 1. 基础默认参数使用 ---
    cout << "1. 基础默认参数演示:" << endl;
    
    // 使用默认类型 (double)
    SimpleContainer<> defaultContainer(3.14159);
    defaultContainer.printInfo();
    
    // 显式指定类型 (int)
    SimpleContainer<int> intContainer(42);
    intContainer.printInfo();
    
    // 显式指定类型 (string)
    SimpleContainer<string> stringContainer("Hello Default!");
    stringContainer.printInfo();
    
    cout << "\n2. 复数类演示:" << endl;
    
    // --- 2. 复数类的使用 ---
    
    // 使用默认类型 (double)
    MyComplex<> c1(3.0, 4.0);
    MyComplex<> c2(1.0, 2.0);
    
    cout << "复数1: ";
    c1.print();
    cout << "复数2: ";
    c2.print();
    
    MyComplex<> sum = c1 + c2;
    cout << "和: ";
    sum.print();
    
    MyComplex<> product = c1 * c2;
    cout << "积: ";
    product.print();
    
    cout << "复数1的模长: " << c1.magnitude() << endl;
    cout << "---" << endl;
    
    // 使用 float 类型
    MyComplex<float> floatComplex(1.5f, 2.5f);
    cout << "float类型复数: ";
    floatComplex.print();
    cout << "---" << endl;
    
    cout << "\n3. 多默认参数演示:" << endl;
    
    // --- 3. 多个默认参数的使用 ---
    
    // 全部使用默认值：int, size_t, 10
    FlexibleArray<> defaultArray;
    defaultArray.push_back(1);
    defaultArray.push_back(2);
    defaultArray.push_back(3);
    defaultArray.printAll();
    
    // 指定值类型为 double，其他使用默认值
    FlexibleArray<double> doubleArray(5);
    doubleArray.push_back(1.1);
    doubleArray.push_back(2.2);
    doubleArray.printAll();
    
    // 指定值类型和大小类型，使用默认容量
    FlexibleArray<string, int> stringArray;
    stringArray.push_back("Hello");
    stringArray.push_back("Template");
    stringArray.push_back("World");
    stringArray.printAll();
    
    // 完全指定所有参数
    FlexibleArray<char, size_t, 20> charArray(15);
    charArray.push_back('A');
    charArray.push_back('B');
    charArray.push_back('C');
    charArray.printAll();
    
    cout << "\n4. 函数模板默认参数演示:" << endl;
    
    // --- 4. 函数模板默认参数使用 ---
    
    // 使用默认类型
    calculateWeightedSum(10, 0.3, 20, 0.7);
    
    // 显式指定类型
    calculateWeightedSum<double, double>(5.5, 0.4, 3.3, 0.6);
    
    cout << "\n5. 消息记录器演示:" << endl;
    
    // --- 5. 特化与默认参数结合使用 ---
    
    // 使用默认的 string 版本
    MessageLogger<> stringLogger("INFO");
    stringLogger.log("系统启动成功");
    
    // 使用特化的 int 版本
    MessageLogger<int> intLogger(3);
    intLogger.log(404);
    
    // 使用不同的类型
    MessageLogger<char> charLogger('*');
    charLogger.log('#');
    
    // --- 标准库中的默认模板参数示例 ---
    cout << "\n6. 标准库默认参数演示:" << endl;
    
    // std::vector 的默认分配器
    vector<int> defaultVector = {1, 2, 3, 4, 5};
    cout << "vector 大小: " << defaultVector.size() << endl;
    
    // std::complex 的默认类型是 double
    complex<> stdComplex(2.0, 3.0);
    cout << "标准库复数: " << stdComplex << endl;
    cout << "模长: " << abs(stdComplex) << endl;
    
    // --- 默认模板参数的重要提示 ---
    cout << "\n=== 默认模板参数使用要点 ===" << endl;
    cout << "1. 语法简化: 用户可以省略常用的模板参数，简化代码" << endl;
    cout << "2. 向后兼容: 添加新的默认参数不会破坏现有代码" << endl;
    cout << "3. 从右到左: 默认参数必须从最右边开始连续提供" << endl;
    cout << "4. 类型推导: 编译器会根据默认值进行类型推导" << endl;
    cout << "5. 灵活性: 既支持默认使用，也支持完全自定义" << endl;
    cout << "6. 标准库应用: STL 大量使用默认模板参数提高易用性" << endl;
    
    return 0;
}