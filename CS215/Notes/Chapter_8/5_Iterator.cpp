#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    
    vector<int> vec1 = {10,20,30,40,50,60,70,80,90};
    // 迭代器 可以用于遍历元素
    for(vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it){
        cout << *it << endl;
    }

    // 自动类型推导(auto)————————————————————————————————————————————————
    // 自动类型推导 是 C++11标准 引入的关键字，它能够根据变量的初始化表达式来自动
    // 判断变量的类型，而无需程序员在代码中显性的写出它的类型，当编译器遇到一个
    // 使用了 auto 声明的变量时，它会自动根据 “=” 右侧的值来判断变量的类型
    auto userNum = 100; // 此处等价于 int userNum = 100;
    cout << userNum << endl;

    // 那么创建一个迭代器的时候，就可以使用auto来快速创建
    // 其中 auto it = vec1.end()-1 等价于 vector<int>::iterator it = vec1.end()-1
    for(auto it = vec1.end()-1; it >= vec1.begin(); --it){
        cout << *it << endl;
    }

    // 此处一样等价于 vector<int>::iterator vec_position = vec1.begin()
    auto vec_position = vec1.begin();

    while(vec_position != vec1.end()){
        cout << *vec_position << endl;
        vec_position++;
    }

    // 后置递增(x++)和前置递增(++x)—————————————————————————————————————————
    
    // x++ 叫做 后置递增，它会创建一个当前变量的副本，然后再原变量上递增一位，再返回
    // 这个变量的原始状态的副本，也就是说它会先复制变量，然后递增原变量，最后返回副本
    
    // ++x 叫做 前置递增，它会直接在变量本身上做递增操作，然后直接返回本身的引用，不会
    // 额外创建副本，也不会产生拷贝

    int x = 100;
    int y = 50;
    // 比如此处，y++仍然会返回原来的 50，而不是 51，它只有在表达式执行完毕后才会更新为 51
    cout << x + y++ << endl; // 所以这里等价为 x + y，然后y = y + 1，结果仍然是 150

    // 对于普通的简单类型，如int来说，如果只是用来递增，那么这两种递增的性能差不多，
    // 对于迭代器这类占用较大，较复杂的对象，使用前置递增会更加高效

    // 常量迭代器(Const iterator)—————————————————————————————————————————————
    // 与普通迭代器不同，常量迭代器能够保证无法通过迭代器修改元素，它在需要提取，调用元素
    // 但不希望误修改元素时十分有用

    // 可以通过 const_iterator 显性的声明一个常量迭代器
    for(vector<int>::const_iterator it = vec1.begin(); it != vec1.end(); ++it){
        cout << *it << endl;
    }
    
    // cend() 和 cbegin() 和普通的 end() 与 begin() 不同
    // 它们所返回的是常量迭代器，而不是普通的迭代器，所以此处即使不显性的声明 it
    // 是常量迭代器，也仍然会让其变为常量迭代器
    for(auto it = vec1.cend()-1; it >= vec1.cbegin(); --it){
        cout << *it << endl;
    }

    // 反向迭代器(Reverse Iterators)——————————————————————————————————————
    // 虽然普通迭代器就可以做到反向访问元素，但是也有专门的反向迭代器 
    // 如果使用 rbegin() 和 rend()，就会得到与 begin() 和 end() 相反的值
    // 因为 rbegin() 会返回指向容器的最后一个元素的反向迭代器，
    // 而 rend() 会返回指向容器的第一个元素之前的位置的反向迭代器
    // 所以使用反向迭代器实际上相当于从尾部遍历到起点处

    // 反向迭代器本质上还是一个普通的迭代器，但是其内部增加了一个适配器，用于反转
    // 迭代器的操作，所以当我们使用反向迭代器时，迭代器的“朝向”被反转了过来
    // 而迭代器的 ++ 和 -- 本质上是命令迭代器“前进”或“后退”，所以当我们使用
    // 反向的迭代器时，为了让迭代器从尾向头部移动，实际上应该使用 ++it 而不是 --it
    // 因为 --it 会命令迭代器向后移动，而迭代器朝向的是头，背对的是尾，所以 --it
    // 反而会导致迭代器朝向尾部移动，引发错误

    // 此处等价于 (auto it = vec1.end()-1; it >= vec1.begin(); --it)
    for(auto it = vec1.rbegin(); it != vec1.rend(); ++it){
        cout << *it << endl;
    }

    // 要注意的是，如果要使用C++11以前的方法声明迭代器，需要更改声明迭代器时
    // 迭代器的类型，它不再是 iterator 而是 inverse_iterator
    for (vector<int>::reverse_iterator it = vec1.rbegin(); it != vec1.rend(); ++it){
        cout << *it << endl;
    }

    // 反向迭代器也有常量版本，即 crbegin() 和 crend()，此处不做演示

    // 基于范围的For循环(range-based for loop)———————————————————————————————————
    // 在 C++11 引入了一种基于范围的for循环，它可以直接遍历一个容器中的所有元素
    // 且不需要显性的创建一个迭代器或调用 begin() 或 end()

    // 在这种for循环中，需要使用 auto& 而不是 auto，因为auto会复制元素，而auto&
    // 则会直接引用访问元素，避免额外拷贝

    // 其语法为 for(auto& x : 容器名)(...)     在这个语法中
    // 编译器会临时创建一个遍历每个元素的迭代器，并自动获取 begin() 和 end()
    // 再依次将迭代器指向的元素绑定给 x，也就是说 x 本身并不是一个迭代器，迭代器由
    // 编译器创建并使用，x 只是获取了迭代器指向的元素，并作为一个普通变量来使用
    // 所以当使用 x 时并不需要使用 解引用符号* 就能直接使用，因为 x 保存的并不是地址

    for(auto& num : vec1){ // 创建一个临时迭代器，迭代器每次循环开始时都会将新元素
    // 绑定给 num，num 直接等于 迭代器指向的元素
        cout << num << endl; // 直接打印 num，因为 num 保存的不是地址而是元素
    }

    

    return 0;
}