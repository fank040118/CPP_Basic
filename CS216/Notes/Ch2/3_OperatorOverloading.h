#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef POINT_H
#define POINT_H

/*
操作符重载 (Operator Overloading) - 基础详解
==========================================

什么是操作符重载？
===============

简单来说，操作符重载就是让我们自己定义的类也能使用+、-、<<这些符号。

比如：
- 内置类型: int a = 5; int b = 10; int c = a + b;  // 可以直接用+
- 自定义类: Point p1, p2, p3; p3 = p1 + p2;       // 我们也想这样用+

为什么需要操作符重载？
==================

没有重载时，我们只能这样写：
Point p3;
p3.setX(p1.getX() + p2.getX());  // 很麻烦
p3.setY(p1.getY() + p2.getY());

有了重载后，我们可以这样写：
Point p3 = p1 + p2;  // 简洁直观

基本规则：
========
1. 只能重载已有的操作符，不能发明新的
2. 操作符的基本特性不变（优先级、参数个数等）
3. 至少有一个参数必须是用户定义的类型
4. 某些操作符不能重载：:: . .* ?: sizeof

两种实现方式：
============
1. 成员函数重载：操作符函数是类的成员
2. 友元函数重载：操作符函数不是成员，但能访问私有数据
*/

// 第一步：先看一个简单的Point类
class Point {
public:
    // 构造函数
    Point() : pointPosition(0), pointValue(0), pointName("default") {}
    
    Point(int pos, int val, const string& name) 
        : pointPosition(pos), pointValue(val), pointName(name) {}

    // =============================
    // 第一个例子：成员函数重载 (加法操作符+)
    // =============================
    
    /* 成员函数重载的语法：
     * 返回类型 operator操作符(参数列表)
     * 
     * 对于 p1 + p2 这个表达式：
     * - p1 是左操作数，自动成为this指针指向的对象
     * - p2 是右操作数，作为参数传入
     * - 所以成员函数只需要一个参数
     */
    Point operator+(const Point& other) const {
        // 创建一个新的Point对象作为结果
        Point result;
        result.pointPosition = this->pointPosition + other.pointPosition;
        result.pointValue = this->pointValue + other.pointValue;
        result.pointName = this->pointName + "+" + other.pointName;
        // 最终返回加法结果
        return result;
    }
    
    /* 这个函数的工作原理：
     * Point p1(1, 10, "first");
     * Point p2(2, 20, "second"); 
     * Point p3 = p1 + p2;  // 等价于 p3 = p1.operator+(p2);
     * 
     * 执行过程：
     * 1. p1成为this指向的对象
     * 2. p2作为other参数传入
     * 3. 函数返回新的Point对象
     */

    // =============================
    // 第二个例子：友元函数重载 (输出操作符<<)
    // =============================
    
    /* 什么是友元函数(friend function)？
     * ===============================
     * 
     * 友元函数是一个特殊的函数：
     * 1. 它不是类的成员函数
     * 2. 但是它可以访问类的私有(private)和保护(protected)成员
     * 3. 就像给了这个函数一把"钥匙"，让它能进入类的"私人区域"
     * 
     * 为什么<<操作符需要用友元函数？
     * =============================
     * 
     * 我们想这样使用：cout << point
     * 
     * 如果用成员函数：
     * - 语法会变成：point.operator<<(cout)
     * - 使用时就是：point << cout  // 这很奇怪！
     * 
     * 用友元函数：
     * - 语法是：operator<<(cout, point)
     * - 使用时就是：cout << point  // 这很自然！
     */
    
    friend ostream& operator<<(ostream& out, const Point& p);
    
    /* 友元函数的声明语法详解：
     * ==========================
     * 
     * friend ostream& operator<<(ostream& out, const Point& p);
     * 
     * 逐部分解释：
     * - friend: 关键字，表示这是友元函数
     * - ostream&: 返回类型，ostream的引用(如cout, cerr等)，因为函数的返回是ostream的引用，而不是Point对象
     * - operator<<: 特殊的函数名，表示重载<<操作符
     * - ostream& out: 第一个参数，输出流对象
     * - const Point& p: 第二个参数，要输出的Point对象
     * 
     * 为什么用引用(&)？
     * - ostream& out: 因为流对象不能复制，只能传引用
     * - const Point& p: 避免复制开销，const保证不修改原对象
     * 
     * 为什么返回ostream&？
     * - 支持链式调用：cout << p1 << p2 << p3;
     * - 工作原理：((cout << p1) << p2) << p3
     */

    // =============================
    // 第三个例子：比较操作符重载
    // =============================
    
    /* 比较操作符通常用成员函数实现
     * 因为语法 p1 == p2 很自然
     */
    bool operator==(const Point& other) const {
        // 比较所有成员变量是否相等
        return pointPosition == other.pointPosition && 
               pointValue == other.pointValue && 
               pointName == other.pointName;
    }
    
    /* 不等操作符可以复用相等操作符
     * 这是一个常见的技巧，避免重复代码
     */
    bool operator!=(const Point& other) const {
        return !(*this == other);  // 利用已有的==操作符
    }
    
    // 获取数据的函数(访问器)
    int getPosition() const { return pointPosition; }
    int getValue() const { return pointValue; }
    string getName() const { return pointName; }

private:
    int pointPosition;    // 位置信息
    int pointValue;       // 数值信息  
    string pointName;     // 名称信息
};

// =============================
// 友元函数的实现(定义)
// =============================

/* 重要：友元函数的实现
 * ==================
 * 
 * 友元函数只是在类里声明，实际的函数体要在类外面定义
 * 注意：定义时不需要写friend关键字！
 */
inline ostream& operator<<(ostream& out, const Point& p) {
    /* 第一步：理解这个函数在做什么
     * 当我们写 cout << point 时，这个函数被调用
     * - out 就是 cout
     * - p 就是 point对象
     * 
     * 第二步：访问私有成员
     * 因为这是友元函数，所以可以直接访问p的私有成员：
     * p.pointPosition, p.pointValue, p.pointName
     */
    
    /* 第三步：格式化输出
     * 使用 iomanip 库的功能来美化输出格式
     * setfill('0'): 用0填充空位
     * setw(2): 设置字段宽度为2位
     */
    out << "位置:" << setfill('0') << setw(2) << p.pointPosition
        << " 值:" << setw(2) << p.pointValue
        << " 名称:" << p.pointName;
    
    /* 第四步：返回流引用
     * 这很重要！必须返回out，这样才能支持链式调用
     * 比如：cout << p1 << " and " << p2;
     */
    return out;
}

/* 重要概念总结
 * =============
 * 
 * 1. 成员函数 vs 友元函数的选择：
 *    成员函数适用场景：
 *    - 左操作数是当前类对象：p1 + p2, p1 == p2
 *    - 语法：obj.operator+(other) 对应 obj + other
 *    
 *    友元函数适用场景：
 *    - 左操作数不是当前类：cout << point, cin >> point  
 *    - 需要访问私有成员但不是成员函数
 *    - 语法：operator<<(cout, point) 对应 cout << point
 * 
 * 2. const的重要性：
 *    - const Point& other: 传递引用避免复制，const确保不修改
 *    - 成员函数后的const: 表示这个函数不会修改对象状态
 *    - 例如：bool operator==(const Point& other) const
 * 
 * 3. 引用返回的意义：
 *    - ostream& 返回类型支持链式调用
 *    - Point& 返回类型支持连续赋值：p1 = p2 = p3;
 */

/* 完整使用示例和执行过程分析：
 * 
 * int main() {
 *     // 第一步：创建Point对象
 *     Point p1(1, 10, "first");   // pointPosition=1, pointValue=10, pointName="first"
 *     Point p2(2, 20, "second");  // pointPosition=2, pointValue=20, pointName="second"
 *     
 *     // 第二步：测试加法操作符重载(成员函数)
 *     cout << "=== 加法操作符测试 ===" << endl;
 *     Point p3 = p1 + p2;  // 调用: p1.operator+(p2)
 *     cout << "p1 + p2 = " << p3 << endl;  
 *     // 输出: p1 + p2 = 位置:03 值:30 名称:first+second
 *     
 *     // 第三步：测试输出操作符重载(友元函数)
 *     cout << "\n=== 输出操作符测试 ===" << endl;
 *     cout << "p1: " << p1 << endl;  // 调用: operator<<(cout, p1)
 *     cout << "p2: " << p2 << endl;  // 调用: operator<<(cout, p2)
 *     
 *     // 链式调用演示
 *     cout << "链式调用: " << p1 << " 和 " << p2 << endl;
 *     // 执行过程: ((cout << "链式调用: ") << p1) << " 和 ") << p2) << endl
 *     
 *     // 第四步：测试比较操作符重载(成员函数)
 *     cout << "\n=== 比较操作符测试 ===" << endl;
 *     if (p1 == p2) {  // 调用: p1.operator==(p2)
 *         cout << "p1 和 p2 相等" << endl;
 *     } else {
 *         cout << "p1 和 p2 不相等" << endl;  // 这个会被执行
 *     }
 *     
 *     // 测试相等情况
 *     Point p4(1, 10, "first");  // 和p1完全相同
 *     if (p1 == p4) {
 *         cout << "p1 和 p4 相等" << endl;  // 这个会被执行
 *     }
 *     
 *     return 0;
 * }
 * 
 * 预期输出：
 * === 加法操作符测试 ===
 * p1 + p2 = 位置:03 值:30 名称:first+second
 * 
 * === 输出操作符测试 ===
 * p1: 位置:01 值:10 名称:first
 * p2: 位置:02 值:20 名称:second
 * 链式调用: 位置:01 值:10 名称:first 和 位置:02 值:20 名称:second
 * 
 * === 比较操作符测试 ===
 * p1 和 p2 不相等
 * p1 和 p4 相等
 */

/* 初学者常见问题和解答：
 * 
 * Q1: 为什么有些操作符用成员函数，有些用友元函数？
 * A1: 关键看左操作数：
 *     - p1 + p2 → 左操作数p1是Point对象 → 用成员函数
 *     - cout << p1 → 左操作数cout不是Point对象 → 用友元函数
 * 
 * Q2: friend关键字会破坏封装吗？
 * A2: 是的，但有时是必要的。友元函数能访问私有成员，要谨慎使用。
 *     只在确实需要访问私有数据且无法用其他方式实现时才使用。
 * 
 * Q3: 为什么要返回引用？
 * A3: 支持链式调用和连续操作：
 *     - cout << p1 << p2;  // 需要operator<<返回ostream&
 *     - p1 = p2 = p3;      // 需要operator=返回Point&
 * 
 * Q4: const的作用是什么？
 * A4: 两个作用：
 *     - 参数const Point& other: 保护参数不被修改，提升性能
 *     - 函数后const: 承诺函数不修改对象状态
 * 
 * 设计原则：
 * ========
 * 1. 符合直觉：+ 做加法，<< 做输出，== 做比较
 * 2. 保持一致：有==就有!=，有<就考虑>、<=、>=
 * 3. 注重性能：能用引用就用引用，能用const就用const
 * 4. 选对方式：成员函数 vs 友元函数的选择看左操作数类型
 */

#endif /* POINT_H */