#include <string>
#include <iostream>
using namespace std;

#ifndef POINT_H
#define POINT_H

/*
静态成员 (Static Members)
========================

静态成员是属于类本身而不是属于任何特定对象实例的成员。

主要特点：
1. 不绑定到对象实例：静态成员属于整个类，不是某个特定对象
2. 共享内存：所有该类的对象实例共享同一个静态数据成员
3. 生命周期：从程序开始到程序结束，与对象的创建/销毁无关
4. 早期初始化：在任何对象创建之前就已经存在
*/

class Point {
public:
    Point() {
        how_many++;  // 每创建一个对象，计数器加一
    }
    
    ~Point() {
        how_many--;  // 对象销毁时，计数器减一
    }

    // =========================
    // 静态数据成员 (Static Data Members)
    // =========================
    
    // 声明静态数据成员，用于统计Point对象的数量
    static int how_many;
    
    /* 访问方式：
     * 1. 通过类名访问: Point::how_many
     * 2. 通过对象实例访问: obj.how_many (不推荐，容易误导)
     * 
     * 示例使用：
     * Point::how_many = 0;     // 初始化
     * Point p1, p2;           // 创建两个对象
     * cout << Point::how_many; // 输出 2
     * 
     * 优势：
     * - 避免全局变量命名冲突
     * - 提供类级别的数据封装
     * - 可以设置访问权限（public/private/protected）
     */

    // =========================
    // 静态成员函数 (Static Member Functions) 
    // =========================
    
    /* 静态成员函数特点：
     * 1. 不与任何对象实例绑定
     * 2. 没有 this 指针
     * 3. 只能访问静态成员和其他静态函数
     * 4. 不能访问非静态成员变量
     * 5. 可以在没有任何对象实例的情况下调用
     */
    
    // 获取当前对象数量
    static int getCount() {
        return how_many;
    }
    
    // 重置计数器（仅供演示，实际中可能不安全）
    static void resetCount() {
        how_many = 0;
    }
    
    // 打印当前对象数量
    static void printCount() {
        cout << "Current Point objects: " << how_many << endl;
    }
    
    /* 声明和定义语法：
     * 
     * 声明 (in class):
     * static ReturnType functionName(parameters);
     * 
     * 定义 (outside class):
     * ReturnType ClassName::functionName(parameters) {
     *     // 注意：定义时不需要 static 关键字
     * }
     * 
     * 调用方式：
     * 1. 通过类名: Point::getCount()
     * 2. 通过对象: obj.getCount() (不推荐，容易误导)
     */

    /* 访问限制示例：
     * 
     * static void demonstrateAccess() {
     *     // 可以访问：
     *     how_many = 10;           // 静态数据成员
     *     getCount();              // 其他静态成员函数
     *     
     *     // 不能访问：
     *     // point_num = 5;        // 错误！非静态数据成员
     *     // this->point_name;     // 错误！没有 this 指针
     * }
     * 
     * 使用场景：
     * 1. 工厂函数 (Factory Functions)
     * 2. 工具函数 (Utility Functions)
     * 3. 单例模式实现
     * 4. 类级别的统计信息
     */

private:
    int point_num;     // 普通数据成员，每个对象实例都有自己的副本
    string point_name; // 普通数据成员
};

/* 静态数据成员的定义和初始化
 * ===========================
 * 
 * 静态数据成员必须在类外部定义和初始化：
 * 
 * // 在源文件（.cpp）中定义
 * int Point::how_many = 0;  // 初始化为 0
 * 
 * 注意事项：
 * 1. 定义时不需要 static 关键字
 * 2. 必须在全局作用域中定义
 * 3. 只能定义一次，通常在 .cpp 文件中
 * 4. 如果不显式初始化，默认初始化为 0（整数类型）
 */

/* 使用示例：
 * 
 * int main() {
 *     cout << Point::getCount() << endl; // 输出: 0
 *     
 *     Point p1, p2;                      // 创建两个对象
 *     Point::printCount();               // 输出: Current Point objects: 2
 *     
 *     {
 *         Point p3;                      // 作用域内创建第三个对象
 *         cout << Point::getCount();     // 输出: 3
 *     }  // p3 销毁
 *     
 *     cout << Point::getCount() << endl; // 输出: 2
 *     
 *     return 0;
 * }
 */

#endif  /* POINT_H */
