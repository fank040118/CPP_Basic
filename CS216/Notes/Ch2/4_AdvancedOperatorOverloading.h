#include <string>
#include <iostream>
using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

/*
高级操作符重载 (Advanced Operator Overloading)
=============================================

本文件展示了更复杂的操作符重载场景，包括：
1. 一元操作符 (Unary Operators)
2. 二元操作符 (Binary Operators) 
3. 成员函数 vs 友元函数的选择
4. 操作符重载的最佳实践

重点概念：
- 一元操作符：只操作一个操作数（如 -obj, ++obj）
- 二元操作符：操作两个操作数（如 obj1 + obj2）
- 左操作数决定实现方式：如果左操作数是当前类，用成员函数；否则用友元函数
*/

class Vector {
public:
    // 构造函数
    Vector() : x(0), y(0) {}
    
    Vector(int x_val, int y_val) : x(x_val), y(y_val) {}

    // =============================
    // 一元操作符重载 (Unary Operators)
    // =============================
    
    /* 一元操作符特点：
     * - 只有一个操作数
     * - 通常实现为成员函数（因为操作数就是当前对象）
     * - 不需要参数（操作数是隐式的 this）
     * 
     * 常见一元操作符：-, +, ++, --, !, ~
     */
    
    // 一元负号：返回相反的向量
    Vector operator-() const {
        return Vector(-x, -y);
    }
    
    /* 为什么使用 const？
     * - 一元负号不应该修改原对象
     * - 返回新对象而不是修改当前对象
     * - 符合数学直觉：-v 不改变 v 本身
     */
    
    // 前置递增操作符 ++vec
    Vector& operator++() {
        ++x;
        ++y;
        return *this;  // 返回引用，支持链式调用
    }
    
    // 后置递增操作符 vec++
    Vector operator++(int) {  // int 参数仅用于区分前置和后置
        Vector temp(*this);   // 保存原值
        ++x;
        ++y;
        return temp;          // 返回原值
    }
    
    /* 前置 vs 后置递增：
     * 前置 (++obj)：
     *   - 先递增，后返回
     *   - 返回引用，效率更高
     *   - 支持链式调用：++(++obj)
     * 
     * 后置 (obj++)：
     *   - 先返回原值，后递增
     *   - 返回值（副本），效率较低
     *   - 不支持链式调用：(obj++)++ 是错误的
     */

    // =============================
    // 二元操作符重载 (Binary Operators)
    // =============================
    
    /* 二元操作符实现方式选择：
     * 1. 成员函数：当左操作数是当前类对象时
     *    语法：ReturnType operator@(const RightType& right)
     *    调用：leftObj @ rightObj
     * 
     * 2. 友元函数：当左操作数不是当前类对象时，或需要对称性时
     *    语法：friend ReturnType operator@(const LeftType& left, const RightType& right)
     *    调用：leftOperand @ rightOperand
     */

    // 向量减法：Vector - Vector (成员函数实现)
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y);
    }
    
    // 向量与标量减法：Vector - int (成员函数实现)
    Vector operator-(int scalar) const {
        return Vector(x - scalar, y - scalar);
    }
    
    /* 为什么这两个用成员函数？
     * - 左操作数都是 Vector 对象
     * - 符合面向对象设计原则
     * - 语法自然：vec1 - vec2, vec - 5
     */

    // 向量加法：Vector + Vector (成员函数实现)
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    // 标量与向量加法：int + Vector (友元函数实现)
    friend Vector operator+(int scalar, const Vector& vec) {
        return Vector(scalar + vec.x, scalar + vec.y);
    }
    
    /* 为什么这个用友元函数？
     * - 左操作数是 int，不是 Vector
     * - 如果用成员函数，语法会变成 vec + scalar，但我们想要 scalar + vec
     * - 友元函数可以访问私有成员 vec.x 和 vec.y
     * - 实现操作的对称性：vec + 5 和 5 + vec 都可以工作
     */

    // =============================
    // 比较操作符
    // =============================
    
    // 相等比较
    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y;
    }
    
    // 不等比较（复用相等比较）
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
    
    // 小于比较（按向量长度的平方比较，避免浮点运算）
    bool operator<(const Vector& other) const {
        return (x*x + y*y) < (other.x*other.x + other.y*other.y);
    }

    // =============================
    // 流操作符（友元函数实现）
    // =============================
    
    friend ostream& operator<<(ostream& out, const Vector& vec) {
        out << "(" << vec.x << ", " << vec.y << ")";
        return out;
    }
    
    friend istream& operator>>(istream& in, Vector& vec) {
        cout << "Enter x y: ";
        in >> vec.x >> vec.y;
        return in;
    }

    // =============================
    // 访问器
    // =============================
    
    int getX() const { return x; }
    int getY() const { return y; }
    
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

private:
    int x, y;  // 向量的 x 和 y 分量
};

/* 成员函数 vs 友元函数选择指南
 * ============================
 * 
 * 使用成员函数当：
 * 1. 左操作数是当前类的对象
 * 2. 操作符在逻辑上属于该类
 * 3. 不需要访问其他类的私有成员
 * 
 * 使用友元函数当：
 * 1. 左操作数不是当前类的对象（如 int + Vector）
 * 2. 需要对称性（如交换律）
 * 3. 两个操作数地位相等（如两个不同类的对象相加）
 * 4. 流操作符（<<, >>）
 * 
 * 使用全局函数当：
 * 1. 不需要访问任何类的私有成员
 * 2. 完全独立的操作
 */

/* 操作符重载最佳实践
 * ==================
 * 
 * 1. 保持语义一致性：
 *    - + 用于加法/连接
 *    - < 用于小于比较
 *    - << 用于输出
 *    - = 用于赋值
 * 
 * 2. 保持对称性：
 *    如果实现了 a + b，考虑是否也需要 b + a
 * 
 * 3. 返回类型的选择：
 *    - 算术操作符：返回新对象的值
 *    - 比较操作符：返回 bool
 *    - 赋值操作符：返回引用
 *    - 流操作符：返回流引用
 * 
 * 4. const 正确性：
 *    - 不修改对象的操作符应该标记为 const
 *    - 参数尽可能使用 const 引用
 * 
 * 5. 效率考虑：
 *    - 使用引用避免不必要的拷贝
 *    - 前置递增通常比后置递增效率更高
 */

/* 使用示例：
 * 
 * int main() {
 *     Vector v1(3, 4);
 *     Vector v2(1, 2);
 *     
 *     // 一元操作符
 *     Vector v3 = -v1;           // 一元负号
 *     cout << "v3: " << v3 << endl;  // 输出: (-3, -4)
 *     
 *     Vector v4 = v1;
 *     cout << "++v4: " << ++v4 << endl;  // 前置递增
 *     cout << "v4++: " << v4++ << endl;  // 后置递增
 *     cout << "v4: " << v4 << endl;
 *     
 *     // 二元操作符
 *     Vector v5 = v1 + v2;       // Vector + Vector
 *     Vector v6 = v1 - v2;       // Vector - Vector
 *     Vector v7 = v1 - 1;        // Vector - int
 *     Vector v8 = 2 + v1;        // int + Vector (友元函数)
 *     
 *     cout << "v1 + v2: " << v5 << endl;
 *     cout << "v1 - v2: " << v6 << endl;
 *     cout << "v1 - 1: " << v7 << endl;
 *     cout << "2 + v1: " << v8 << endl;
 *     
 *     // 比较操作符
 *     if (v1 == v2) {
 *         cout << "v1 equals v2" << endl;
 *     } else {
 *         cout << "v1 not equals v2" << endl;
 *     }
 *     
 *     if (v1 < v2) {
 *         cout << "v1 is smaller than v2" << endl;
 *     }
 *     
 *     // 流操作符
 *     Vector v9;
 *     cout << "Enter vector: ";
 *     cin >> v9;                 // 使用 >> 操作符输入
 *     cout << "You entered: " << v9 << endl;  // 使用 << 操作符输出
 *     
 *     return 0;
 * }
 */

/* 常见错误和陷阱
 * ==============
 * 
 * 1. 忘记返回引用：
 *    错误：Vector operator=(const Vector& other) { ... }
 *    正确：Vector& operator=(const Vector& other) { ... }
 * 
 * 2. 自赋值检查缺失：
 *    Vector& operator=(const Vector& other) {
 *        if (this != &other) {  // 必要的检查
 *            // 赋值操作
 *        }
 *        return *this;
 *    }
 * 
 * 3. const 错误：
 *    错误：Vector operator+(Vector other)     // 应该用 const 引用
 *    正确：Vector operator+(const Vector& other) const
 * 
 * 4. 友元函数参数顺序错误：
 *    应该匹配调用顺序：scalar + vector -> operator+(scalar, vector)
 */

#endif /* VECTOR_H */