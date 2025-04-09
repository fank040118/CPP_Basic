using namespace std;

// 这是个类模板————————————————————————————————————————————————————————————————
// 首先声明，这是一个类模板，模板参数是 pair
// 这里 class 代表 pair 是一个类型参数
// pair 实际上可以是任何数据类型，包括int，char这种内置类型或自定义类型
// 但这个类设计为储存两个相同类型的值，形成一个对
template <class pair>

class myPair {
    public:
    // 这是类模板的构造函数，接受两个类型为 pair 的参数，并将它们储存在内部数组中
    myPair(pair first, pair second) {
        values[1] = first;
        values[2] = second;
    };

    private:
    // pair values[]是一个包含两个元素的数组，数组的每个元素类型都是 pair
    pair values[2];

    // 那么怎么在实际代码中使用这个函数和这个类模板呢？怎么构造pair类对象？方法很简单，
    // 使用 mypair<类型> 对象名(值1，值2) 来声明一个Pair类对象
    // 其中 mypair=呼叫构造函数 <类型>=提供实际有效类型 对象名=提供pair类对象名 (值1，值2)=储存有效对象值
    // 比如 mypair<int> intpair(10, 20);
    // 或者 mypair<string> strpair("Hello", "World");

}