#include <string>
#include <iostream>

using namespace std;

int divint(int a, int b) {
	return a / b;
};

int main() {

	/*
	堆栈（Stack）是一种数据结构，它有“弹出”和“压入”两种操作，
	“压入”是指将元素放置在堆栈的顶部，如果堆栈内有元素，那么它将会放置
	在元素的上面
	“弹出”是指将堆栈内顶部的元素弹出，也就是说会弹出最后一个加入的元素
	这意味着堆栈的数据结构为“先进后出”或“后进先出”，即最后加入的元素
	会被最先移除，而最早加入的元素会最后移除，
	堆栈可以被想象为叠放衣服的衣柜，最后叠进去的衣服会最先被拿出来，而最早
	叠进去的衣服被堆在了底部，只有上面的衣服被拿走后才能取出

	例如一个堆栈从元素a0到an依次压入堆栈，那么取出元素时取出顺序将会是从
	元素an到a0依次取出

	调用堆栈(Call Stack)时一种用于记录函数调用信息的堆栈，
	调用堆栈储存一系列的 帧(Frames)，每一帧都包含了每个被调用函数的重要
	信息，以及自动分配的标识符，比如若存在两个函数 average() 和 add()，
	那么调用时会依次被压入堆栈，当函数完成后，将会从堆栈中移除，堆栈
	会回到 main() 状态

	Call-Stack | Call-Stack | Call-Stack | Call-Stack | Call-Stack | Call-Stack
	---------  | ---------  | add()      | ---------  | ---------  | ---------
	---------  | average()  | average()  | average()  | ---------  | ---------
	main()     | main()     | main()     | main()     | main()     | ---------
	*/

	int x = 5, y = 2;
	cout << divint(x, y);
	x = 3; y = 0;
	cout << divint(x, y);

	/*
	当程序进入 main() 时，堆栈状态只有main() 的活动帧，内部有"x=5, y=2"两个局部变量
	即 main(Locals: x=5; y=2;)

	当程序调用 divint(x,y) 时，堆栈状态新增了 divint() 的活动帧，内部有"a=5, b=2"两个
	局部变量
	即 divint(Args: a=5; b=2;) 
	   main(Locals: x=5; y=2;)

	当程序运行到 x=3；y=0；时，其修改了main函数中的局部变量
	即 main(Locals: x=3; y=0;)

	当程序再次调用 divint(x,y) 时，堆栈状态再次新增了 divint() 的活动帧，内部有"a=3, b=0"
	两个局部变量
	即 divint(Args: a=3; b=0;) 
	   main(Locals: x=3; y=0;)
	*/
	

	return 0;
}