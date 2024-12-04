#include <iostream>
#include <string>

using namespace std;

void  staticFunc() {
	static int callCount = 0; // 创建一个静态变量，静态变量只会初始化一次
	// 静态变量的作用域(Scope)和普通函数一样只存在于被定义时所处于的函数区，
	// 但是它被储存在静态内存中，所以即使函数的内存被释放，它也保留
	callCount += 1; // 静态变量每次运行函数时都会 +1
	cout << callCount << endl; // 输出静态变量的值
}

string* to_cpp_string(char* c_str) { 
	// 传入的是 char类对象的指针，而不是char类对象，因为创建时使用的
	// char init_greeting[] = "Hello, World!"; 
	// 这个指令创建的是一个char类数组，可以传入char类数组的指针
	// 在默认情况下，char类型只能储存单个字符
	// 所以此处如果直接传入char类对象，就会导致只能传入单个字符
	string cpp_str(c_str); // 将传入的 char类指针指向的值赋值给string变量，
	// 这是一种特殊的赋值方法，可以将char类对象的值赋给string类对象
	return &cpp_str; // 最终返回构造的string类对象的地址
}

int main() {
	/*
	内存有两种行为，分配(Allocate)和释放(Deallocate)，
	分配是指为某一种用途预留一部分内存，比如一个变量
	释放是指程序不再需要某一部分内存时将其归还给系统

	内存有着几种不同的类型：
	静态内存(Static Memory)：
		在程序运行以前就被分配好的内存，并且在程序的整个生命周期内都存在，不会归还系统
		比如 全局变量，静态变量等

	自动内存/栈内存(Automatic Memory/Stack Memory)：
		在程序执行时自动分配和释放，是默认的内存管理方式
		比如 函数中的局部变量

	动态内存/堆内存(Dynamic Memory/Heap Memory)
		在运行时通过显式调用(new 或 malloc),需要显式释放(delete 或 free)
		充满灵活性，但很容易引发内存泄漏或悬空指针

	静态内存在程序开始时分配，结束时释放
	自动内存在作用域内分配，作用域结束时释放
	动态内存由程序员决定分配和释放

	静态内存和自动内存都由编译器管理，动态内存由程序员显式管理，
	静态内存位于数据区，自动内存位于栈，动态内存位于堆
	*/

	// 静态内存：—————————————————————————————————
	staticFunc(); // 第一次呼叫函数，callCount = 1
	staticFunc(); // 第二次， callCount = 2
	staticFunc(); // 第三次， callCount = 3

	// 这是因为函数内使用的是 静态变量(Static veriable)，静态变量被储存在了
	// 数据段(Data Segment)上，而不是栈上，所以在函数结束以后，它的值仍然保留，
	// 静态变量在函数调用期间会保留其状态(即上一次调用时的值)，静态变量使用的
	// 就是 静态内存，它被放在数据段(Data segment)中，在main()函数开始之前就
	// 被分配，在main()函数结束以后才会释放

	// 数据段(Data Segment)是内存的一部分，它专门用于储存静态分配的变量，包括全局变量
	// 和静态变量，数据段分为两部分：
	// 可写部分——储存可修改的全局变量和静态变量，这些变量在程序中途可以修改
	// 只读部分——储存只读的数据，比如用 const 修饰的全局常量，这些数据在中途不可修改
	// 静态变量的内存在数据段中是固定的，在程序生命周期内一直都在，它不能被删除
	// 静态变量的内存分配在程序启动时就会被分配，但是静态变量的初始化会在相应代码运行时进行

	// 自动内存：—————————————————————————————————
	char init_greeting[] = "Hello, World!"; // 创建一个char类数组，储存了一系列字符
	string* cpp_version = nullptr; //创建并初始化一个指针
	cpp_version = to_cpp_string(init_greeting); // 将char类数组经过函数后的返回值赋值给指针
	// cout << *cpp_version << endl; //这将导致错误，因为它指向的对象是一个局部变量，
	// 局部变量使用了自动内存，在函数结束后将会被回收，导致地址指向的值变为无效
	// 自动内存使用的则是之前介绍的 栈(Stack)，与数据段(Data segment)不同，栈储存的是局部变量
	// 和函数调用信息的内存区域，栈上的内存由程序







	return 0;
}