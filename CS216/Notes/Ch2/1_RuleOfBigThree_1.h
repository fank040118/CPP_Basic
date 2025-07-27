#include <string>
using namespace std;
#ifndef intList
#define intList

/*
大三法则 (Rule of Big Three)
====================

当自定义的类中包含动态分配的资源(如使用new创建的对象、指针等)时，通常需要
显式实现以下三个特殊成员函数：

1. 拷贝构造函数 (Copy Constructor)
   - 用途：当创建一个对象作为另一个对象的副本时调用
   - 语法：ClassName(const ClassName& other)
   - 时机：对象初始化时，如 MyClass obj2(obj1) 或 MyClass obj2 = obj1

2. 赋值运算符 (Assignment Operator)
   - 用途：当一个已存在的对象被赋值为另一个已存在对象的值时调用
   - 语法：ClassName& operator=(const ClassName& other)
   - 时机：赋值操作时，如 obj2 = obj1 (obj2已经存在)

3. 析构函数 (Destructor)
   - 用途：当对象被销毁时自动调用，用于释放动态分配的资源
   - 语法：~ClassName()
   - 时机：对象离开作用域、delete操作、程序结束时

核心原理：
如果类管理动态资源，编译器提供的默认版本通常执行浅拷贝，这会导致:
- 多个对象指向同一内存地址
- 双重释放 (double free) 错误
- 内存泄漏
- 悬空指针 (dangling pointer)

因此，如果需要自定义其中任何一个函数，通常需要定义全部三个函数。
*/

class intList {
    public:
        intList();
        intList(int size, int capacity);
        // 拷贝构造函数 (Copy Constructor)
        // 用于创建一个新对象，并将其初始化为另一个对象的副本
        intList(const intList& other);
        
        // 赋值运算符 (Assignment Operator) 
        // 用于将一个已存在对象的值赋给另一个已存在的对象
        intList& operator=(const intList& other);
        
        // 析构函数 (Destructor)
        // 用于释放对象占用的动态内存
        ~intList();

        /* 为什么使用引用传递 (Reference Passing)？
         * 
         * 错误示例: intList(const intList other);  // 按值传递
         * 
         * 按值传递会导致无限递归：
         * 1. 调用拷贝构造函数时，需要先复制参数 other
         * 2. 复制 other 的过程本身就需要调用拷贝构造函数
         * 3. 这会导致函数无限调用自身，最终栈溢出
         * 
         * 正确做法: intList(const intList& other);  // 引用传递
         * 
         * 引用传递的优势：
         * - 不需要复制参数对象，直接访问原对象
         * - 避免无限递归
         * - 性能更好（无需额外的对象创建）
         * - const 确保不会意外修改源对象
         */

        /* 深拷贝 vs 浅拷贝 (Deep Copy vs Shallow Copy)
         * =============================================
         * 
         * 当复制包含指针成员的对象时，有两种拷贝方式：
         * 
         * 1. 浅拷贝 (Shallow Copy) - 编译器默认行为
         *    - 只复制成员变量的值（对于指针，只复制地址值）
         *    - 结果：多个对象的指针指向同一块内存
         *    - 问题：
         *      a) 修改一个对象会影响其他对象
         *      b) 对象销毁时可能出现双重释放错误
         *      c) 一个对象释放内存后，其他对象变成悬空指针
         * 
         * 2. 深拷贝 (Deep Copy) - 手动实现
         *    - 为指针成员分配新的内存空间
         *    - 复制指针指向的实际数据到新内存
         *    - 结果：每个对象都有独立的内存空间
         *    - 优势：对象间完全独立，安全可靠
         * 
         * 何时需要深拷贝？
         * - 类包含指针成员变量
         * - 类管理动态分配的内存
         * - 类包含文件句柄、网络连接等资源
         * 
         * 何时可以使用浅拷贝？
         * - 类只包含基本数据类型 (int, double, bool 等)
         * - 类只包含标准库对象 (string, vector 等，它们已经实现了深拷贝)
         * - 类不管理任何动态资源
         */

        /* 实现示例对比
         * ==============
         * 
         * 错误的浅拷贝实现：
         * intList(const intList& other) {
         *     size = other.size;
         *     capacity = other.capacity;
         *     list = other.list;  // 错误！只复制了指针地址
         * }
         * 
         * 问题：两个对象的 list 指针指向同一块内存
         * 
         * 正确的深拷贝实现：
         * intList(const intList& other) {
         *     size = other.size;
         *     capacity = other.capacity;
         *     list = new int[capacity];  // 分配新内存
         *     for (int i = 0; i < size; i++) {
         *         list[i] = other.list[i];  // 复制实际数据
         *     }
         * }
         * 
         * 赋值运算符实现：
         * intList& operator=(const intList& other) {
         *     if (this != &other) {  // 自赋值检查
         *         delete[] list;     // 释放原有内存
         *         size = other.size;
         *         capacity = other.capacity;
         *         list = new int[capacity];  // 分配新内存
         *         for (int i = 0; i < size; i++) {
         *             list[i] = other.list[i];  // 复制数据
         *         }
         *     }
         *     return *this;  // 返回自身引用，支持链式赋值
         * }
         * 
         * 析构函数实现：
         * ~intList() {
         *     delete[] list;  // 释放动态分配的内存
         * }
         */




    private:
        int size;      // 当前存储的元素数量
        int capacity;  // 数组的总容量
        int* list;     // 指向动态分配数组的指针
};

/* 现代C++改进建议：
 * 
 * 1. Rule of Five (C++11):
 *    除了大三法则，还应该实现移动构造函数和移动赋值运算符
 * 
 * 2. Rule of Zero:
 *    尽量使用智能指针（std::unique_ptr, std::shared_ptr）
 *    或标准容器（std::vector），避免手动内存管理
 * 
 * 3. 使用 std::vector 重写示例：
 *    class intList {
 *    private:
 *        std::vector<int> list;  // 自动管理内存
 *    public:
 *        // 无需手动实现大三法则，vector已经正确实现了
 *    };
 */

#endif  /* intList_H */
