#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    // map——————————————————————————————————————————————————————————————
    // map是一种关联性的容器(Associative Container)
    // 内部为 key-value 结构，每一个key对应一个value, 和python中的字典类似
    // map中每个key都是唯一的，不可能存在两个一样值的key，这会带来查找问题
    // 虽然一个key对应一个value，但是value可以通过设成 set, vector之类的容器
    // 也可以同时储存多个变量, 或者使用 multimap

    // map底层是二叉平衡树，所以查找，插入，删除等指令可通过二叉数查找，
    // 在O(log n)时间内都可完成

    // map的创建—————————————————————————————————————————————————————————
    map<string, int> userMap_1;

    // map的元素插入和删除———————————————————————————————————————————————
    // 通过使用 map.insert(make_pair(key, value))来进行新元素的插入，它会放在
    // map的最后
    userMap_1.insert(make_pair("Apple", 5));
    // 更简单的方法是 map[key] = value
    userMap_1["Banana"] = 10;
    // map.erase(key) 用于删除目标key和value
    userMap_1.erase("Banana");

    // map的元素查询——————————————————————————————————————————————————————
    // 可通过使用 map[key] 直接查询 key 对应的 value
    cout << userMap_1["Banana"] << endl;
    // 如果没有相对应的key，就会被创建出一个初始化了value的key，其value会是默认值
    cout << userMap_1["Pineapple"] << endl;

    // 更安全的做法是通过 map.find(key) 来查找，如果不存在相应key的话也不会创建
    // 新的value
    // 创建一个 迭代器，让其通过 find() 指令遍历整个map
    auto it = userMap_1.find("WaterMalon");
    // 如果 迭代器 指向的目标不是map的最后一个位置，那么就代表找到了相对应的key和value
    if(it != userMap_1.end()){
        cout << it->first  << " -> " << it->second << endl;
    }
    else{
        cout << "can not find the key" << endl;
    }
    // 如果只是想检查是否存在对应的key时，不需要使用迭代器，保证find()指向的元素不是
    // map的最后一个位置就好
    if(userMap_1.find("Apple") != userMap_1.end()){
        cout << "Apple found" << endl;
    }
    else{
        cout << "can not find the key" << endl;
    }

    return 0;
}