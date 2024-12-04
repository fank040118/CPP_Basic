#include <string>
#include <iostream>

using namespace std;

// 在以下函数中，函数参数为一个char类型指针，函数内使用
// 指针指向的的值生成一个新变量 cpp_str，并返回新变量的地址
string* to_cpp_string(char* c_str) {
	string cpp_str(c_str);
	return &cpp_str;
}

int main() {

	// 在 main函数() 中定义了一个char数组，并调用函数将其返回的指针存入
	// cpp_version，最终cout地址指向的值
	char init_greeting[] = "Hello, World!";
	string* cpp_version = nullptr;
	cpp_version = to_cpp_string(init_greeting);
	cout << *cpp_version << endl;
	/*
	但这里会存在错误，因为函数返回的地址是是局部变量的地址，但局部变量
	在函数结束时会被销毁，因为 to_cpp_string函数 在被呼叫时被放入了堆栈
	中的顶部，当其运行完成后，堆栈将会将其 堆栈帧 弹出(释放)，
	
	那么指针 cpp_version 指向的内存地址的原有局部变量在函数结束后销毁，
	再次cout指针指向地址的值可能会发生无法预测的情况

	这种错误是由堆栈的后进先出的顺序导致的，因为函数 to_cpp_string 是
	在 main() 中呼叫的，所以它在堆栈中被后压入，在其运行完成后被先弹出
	所以其内部的局部变量 cpp_str 在函数运行完成后被回收，此后 cpp_version
	所指向的地址不再有效，它变为了悬空指针(Dangling Pointer)，此时使用 
	cout<<*cpp_version 尝试解引用一个无效地址时将导致未定义行为
	*/

	return 0;
}