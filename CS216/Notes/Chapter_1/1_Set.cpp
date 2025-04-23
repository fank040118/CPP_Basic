#include <iostream>
#include <string>
#include <vector>
#include <set> // 为了使用Set，需要在头文件中包含Set

using namespace std;

int main(){
 
// 在数学上，Set(集合) 代表一种 无序 且 不重复 的元素构成的组合
// 但在C++中，它存在着元素之间的先后顺序
// 由于其存在顺序，所以插入/查找等操作时存在着操作顺序

// 集合的顺序默认情况下由变量的ASCII表大小来排序，也就是说插入的顺序
// 与集合内的元素的顺序无关，比如插入字母 A 和 B，无论先插入B还是A，
// 在集合内 永远都是 A 排在 B 前面，因为 A 在ASCII表中比 B 小，
// A 的ASCII编码是 65，而 B 的ASCII编码是 66
// 当然，由于大小写的字母存在着不一样的编码，所以这和字母表的顺序不完全一样
// 比如 a(小写) 的ASCII编码是 97, 它大于 B(大写) 的ASCII编码，所以它会
// 排在 B 后面

// 集合的创建——————————————————————————————————————————————————————

set<string> word; // 使用 set<类型> 变量名 创建一个集合；
word.insert("Apple"); // 通过 .insert() 为集合添加元素
// 如果这个集合中本就存在一个一样的元素，那么使用 .insert() 指令
// 实际上不会对集合进行任何改动，因为集合不允许存在重复的元素
// 不过它也不会产生任何错误

// 集合的元素修改———————————————————————————————————————————————————

word.erase("Banana"); // 通过 .erase() 为集合删除元素
// 同样的，如果集合中本就不存在一个对应的元素，那么使用 .erase() 指令
// 也不会对集合进行任何改动，且不会报错

word.clear(); // .clear() 可以直接清空一个集合

// 可以通过使用一个已经存在的列表类型(不一定是Vector)通过For循环依次
// 为集合插入元素，但就像之前提到的一样，集合的元素顺序与插入时的顺序无关
// 所以Vector内的元素的顺序并不一定会保留在集合中
vector<string> wordList = {"Apple", "Banana", "Peach", "Orange"};
for(int i = 0; i < wordList.size(); ++i){
    word.insert(wordList[i]);
}

// 在 C++11 后，新增了可以直接将一个容器内指定区间(含)的元素导入集合的方法，
// 它的语法是 集合.insert(容器区间左，容器区间右)
vector<string> newWordList = {"WaterMelon", "Strawberry"};
// 比如在这里就是将 newWordList 中从起始元素到结束元素全部插入集合中
word.insert(newWordList.begin(),newWordList.end());

// 集合的元素检查—————————————————————————————————————————————————————

// 通过使用 迭代器 快速访问集合内的所有元素
for(auto it = word.begin(); it != word.end(); ++it){
    cout << *it << endl;
}
for(set<string>::reverse_iterator it = word.rbegin(); it != word.rend(); ++it){
    cout << *it << endl;
}

cout << word.empty() << endl; // .empty() 可以检查集合内是否为空
cout << word.size() << endl; // .size() 可以检查集合内部的元素数量

// 有两种常用的检查集合内元素的方法
// 第一种是 集合.count(元素名) 的方法，它会遍历集合中所有元素，去计算该元素出现过几次
// 但是我们知道集合中的元素不能重复，所以一个元素最多就只有1个，那么这能得到的值
// 要么是1(有一个要找的元素)，要么是0(没有要找的元素)，它可以用来当作布尔值
if(word.count("Apple") > 0){
    cout << "there is least one apple in the set" << endl;
}

// 第二种是 集合.find(元素名) 的方法，它会自动为这个集合创建一个合适的遍历器
// 并从开始一直遍历到 .end() 处，如果这个迭代器找到了相对应的元素，那么它就会指向该元素
// 并停止继续遍历，返回一个相应的地址，但是如果集合内没有相对应的元素，那么它就会一直
// 遍历到集合的 .end() 处，所以通过 = 集合.end() 或 != 集合.end() 可以来判断集合内是否有相应元素 
if (word.find("Banana") != word.end()){
    cout << "there is least one banana in the set" << endl;
}


    
}