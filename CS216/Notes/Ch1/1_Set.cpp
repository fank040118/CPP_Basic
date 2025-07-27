#include <iostream>
#include <string>
#include <vector>
#include <set> // 为了使用 set，需要在头文件中包含 set
#include <unordered_set> // 引入 unordered_set 以作对比

// 建议：在头文件或大型项目中，为了避免命名冲突，
// 最好不要使用 `using namespace std;`，
// 而是显式地使用 `std::` 前缀，例如 `std::cout`。
// 在这个学习文件中，为了简洁，我们继续使用它。
using namespace std;

int main(){
 
    // set (集合) ——————————————————————————————————————————————————————
    // 在数学上，Set(集合) 代表一种由不重复元素构成的组合。
    // 在C++中，`std::set` 是一个【有序】且【元素唯一】的关联性容器(Associative Container)。
    
    // 1. 有序性 (Ordered):
    // `std::set` 内部的元素默认按升序排列。对于基本类型，是按其值大小；
    // 对于字符串，是按字典序 (lexicographical order)。
    // 这种有序性是通过底层的数据结构——通常是红黑树(Red-Black Tree)，一种自平衡二叉搜索树——来保证的。
    // 正因为如此，`std::set` 的插入、删除、查找操作的平均时间复杂度都是 O(log n)，效率非常高。

    // 2. 唯一性 (Unique):
    // 集合中不能存在重复的元素。

    // 集合的创建 ——————————————————————————————————————————————————————
    set<string> word_set; // 推荐在变量名中体现其类型，例如 `word_set`

    // 集合的元素插入 ——————————————————————————————————————————————————
    word_set.insert("Apple");
    word_set.insert("Peach");
    word_set.insert("Banana"); // 无论插入顺序如何，集合内部都会自动排序

    // 尝试插入重复元素 "Apple"
    word_set.insert("Apple"); // 操作会失败，但不会报错。集合内容依然是 {"Apple", "Banana", "Peach"}
    
    // 集合的遍历 (现代C++方式) ————————————————————————————————————————
    cout << "Set elements (sorted):" << endl;
    // C++11 引入了基于范围的 for 循环 (range-based for loop)，是遍历容器的首选方式，更简洁安全。
    for (const string& s : word_set) {
        cout << s << endl;
    }
    // 输出:
    // Apple
    // Banana
    // Peach
    
    // 集合的元素检查 ——————————————————————————————————————————————————
    // 方法一: .count() (C++11及之前)
    // .count(key) 返回值为0或1。它利用底层树结构进行快速查找(O(log n))，而不是遍历所有元素。
    if (word_set.count("Apple") > 0) {
        cout << "\n\"Apple\" is in the set." << endl;
    }

    // 方法二: .find() (所有版本)
    // .find(key) 返回一个指向元素的迭代器(iterator)，如果找不到则返回 .end()。
    // 当你不仅想检查存在性，还想获取该元素的迭代器时，这个方法很有用。时间复杂度 O(log n)。
    auto it = word_set.find("Banana");
    if (it != word_set.end()) {
        cout << "Found \"Banana\" in the set." << endl;
    }

    // 方法三: .contains() (C++20 新增)
    // 这是最现代、最直观的方式，如果你的编译器支持C++20标准。
    // if (word_set.contains("Peach")) {
    //     cout << "\"Peach\" is in the set." << endl;
    // }

    // 集合的元素删除 ——————————————————————————————————————————————————
    word_set.erase("Banana"); // 通过 .erase(key) 删除指定元素
    // 如果元素不存在，例如 word_set.erase("Grape")，操作不会产生任何效果，也不会报错。

    cout << "\nAfter erasing \"Banana\":" << endl;
    for (const string& s : word_set) {
        cout << s << endl;
    }

    // 从其他容器初始化或插入元素 ——————————————————————————————————————
    vector<string> wordList = {"Watermelon", "Strawberry", "Orange"};

    // 方式一: 使用构造函数直接从一个范围初始化
    set<string> fruit_set(wordList.begin(), wordList.end());
    cout << "\nSet initialized from a vector:" << endl;
    for (const string& fruit : fruit_set) {
        cout << fruit << endl;
    }

    // 方式二: 使用 .insert() 插入一个范围的元素
    word_set.insert(wordList.begin(), wordList.end());
    cout << "\nword_set after inserting a range of elements:" << endl;
    for (const string& word : word_set) {
        cout << word << endl;
    }

    // 其他常用操作 ————————————————————————————————————————————————————
    cout << "\nIs word_set empty? " << (word_set.empty() ? "Yes" : "No") << endl; // .empty() 检查是否为空
    cout << "Size of word_set: " << word_set.size() << endl; // .size() 返回元素数量

    word_set.clear(); // .clear() 清空集合
    cout << "After clear(), size of word_set: " << word_set.size() << endl;

    // 补充: 无序集合 std::unordered_set ———————————————————————————————
    // 如果你不需要元素有序，可以使用 `std::unordered_set`。
    // 它底层基于哈希表(Hash Table)实现，插入、删除、查找的平均时间复杂度为 O(1)，
    // 在某些场景下比 `std::set` 更快。
    // 但它的缺点是元素无序，且最坏情况下的时间复杂度可能达到 O(n)。
    unordered_set<string> unordered_word_set = {"Apple", "Peach", "Banana"};
    cout << "\nUnordered set elements (order is not guaranteed):" << endl;
    for (const string& s : unordered_word_set) {
        cout << s << endl;
    }

    return 0;
}
