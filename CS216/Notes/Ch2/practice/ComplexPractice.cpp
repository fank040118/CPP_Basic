#include <iostream>

// 练习：复数类操作符重载
//
// 目标：
// 1. 理解并实践 C++ 中的操作符重载。
// 2. 以成员函数和友元函数（friend function）两种方式实现操作符重载。
//
// 任务：
// 请完成下面的 `Complex` 类，并实现指定的重载操作符。
// `Complex` 类代表一个复数，形式为 a + bi，其中 a 是实部（real part），b 是虚部（imaginary part）。

class Complex {
public:
    // 构造函数 (Constructor)
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 成员函数：打印复数
    void print() const {
        std::cout << real << " + " << imag << "i";
    }

    // TODO 1: 以成员函数方式重载加法操作符 (+)
    // C3 = C1.operator+(C2) -> C3 = C1 + C2
    // (a + bi) + (c + di) = (a+c) + (b+d)i
    Complex operator+(const Complex& other) const {
        // 在这里写入你的实现
        Complex addiResult;
        addiResult.real = this->real + other.real;
        addiResult.imag = this->imag + other.imag;
        return (addiResult);
        // 返回一个新的 Complex 对象，其 real 和 imag 分别是两个复数对象对应部分的总和。
        // return Complex(real + other.real, imag + other.imag); // 这是一个示例实现，你可以参考它
    }

    // TODO 2: 以成员函数方式重载减法操作符 (-)
    // (a + bi) - (c + di) = (a-c) + (b-d)i
    Complex operator-(const Complex& other) const {
        // 在这里写入你的实现
        Complex subtResult;
        subtResult.real = this->real - other.real;
        subtResult.imag = this->imag - other.imag;
        return (subtResult);
    }

    // TODO 3: 以成员函数方式重载乘法操作符 (*)
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& other) const {
        // 在这里写入你的实现
        Complex multResult;
        multResult.real = (this->real * other.real - this->imag * other.imag);
        multResult.imag = (this->real * other.imag + this->imag * other.real);
        return (multResult);
    }

    // TODO 4: 以成员函数方式重载相等比较操作符 (==)
    // 如果两个复数的实部和虚部都相等，则认为它们相等。
    bool operator==(const Complex& other) const {
        // 在这里写入你的实现
        if(this->real == other.real && this->imag == other.imag) return true;
        else return false;
    }

    // 友元函数声明
    // 为什么 << 和 >> 通常需要声明为友元函数？
    // 因为我们希望这样写：std::cout << c1;
    // 如果作为成员函数，它必须被左边的操作数调用，也就是 std::cout.operator<<(c1);
    // 但我们无法修改 std::ostream 类来添加这个成员函数，所以我们将其实现为非成员函数。
    // 为了访问 Complex 类的私有成员 real 和 imag，我们需要将其声明为友元。
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

private:
    double real; // 实部
    double imag; // 虚部
};

// TODO 5: 以友元函数方式重载流插入操作符 (<<)
// 让我们可以像这样打印一个复数: std::cout << c1;
// 函数应该将复数格式化为 "a + bi" 的形式并输出到 ostream 对象中。
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    // 在这里写入你的实现
    os << c.real << " + " << c.imag << "i"; // 这是一个示例实现
    return os;
}

// TODO 6: 以友元函数方式重载流提取操作符 (>>)
// 让我们可以像这样从 istream 读取一个复数: std::cin >> c1;
// 函数应该提示用户分别输入实部和虚部。
std::istream& operator>>(std::istream& is, Complex& c) {
    // 在这里写入你的实现
    std::cout << "请输入实部 (real part): ";
    is >> c.real;
    std::cout << "请输入虚部 (imaginary part): ";
    is >> c.imag;
    return is;
}


int main() {
    Complex c1(2.5, 3.5);
    Complex c2(1.5, 2.0);
    Complex c3;

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

    // 测试加法
    c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl; // 预期输出: 4 + 5.5i

    // 测试减法
    c3 = c1 - c2;
    std::cout << "c1 - c2 = " << c3 << std::endl; // 预期输出: 1 + 1.5i

    // 测试乘法
    c3 = c1 * c2;
    std::cout << "c1 * c2 = " << c3 << std::endl; // 预期输出: -3.25 + 9.75i

    // 测试相等比较
    std::cout << "c1 == c2? " << (c1 == c2 ? "Yes" : "No") << std::endl; // 预期输出: No
    Complex c4(2.5, 3.5);
    std::cout << "c1 == c4? " << (c1 == c4 ? "Yes" : "No") << std::endl; // 预期输出: Yes

    // 测试流提取
    Complex c5;
    std::cout << "\n请输入一个新的复数 c5:" << std::endl;
    std::cin >> c5;
    std::cout << "你输入的 c5 = " << c5 << std::endl;

    return 0;
}
