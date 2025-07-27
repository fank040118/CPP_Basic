#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    // ==================== C++ map 容器详解 ====================
    
    // 1. map 基本概念
    // - map 是关联容器（Associative Container）
    // - 存储 key-value 键值对，类似 Python 字典
    // - 每个 key 唯一，不允许重复
    // - 底层实现：红黑树（自平衡二叉搜索树）
    // - 时间复杂度：查找/插入/删除均为 O(log n)
    // - key 按升序自动排序

    // 2. map 的创建
    map<string, int> fruitPrices;           // 空 map
    map<string, int> scores = {             // 初始化列表创建
        {"Alice", 95},
        {"Bob", 87},
        {"Charlie", 92}
    };

    // 3. 元素插入
    cout << "\n=== 元素插入示例 ===" << endl;
    
    // 方法1：使用 insert() 和 make_pair()
    fruitPrices.insert(make_pair("Apple", 5));
    
    // 方法2：使用 [] 运算符（更简洁）
    fruitPrices["Banana"] = 3;
    fruitPrices["Orange"] = 4;
    
    // 方法3：使用 insert() 和大括号初始化
    fruitPrices.insert({"Grape", 8});
    
    // 方法4：使用 emplace()（C++11，效率更高）
    fruitPrices.emplace("Mango", 6);
    
    // 显示所有水果价格
    cout << "水果价格表：" << endl;
    for(const auto& pair : fruitPrices) {
https://gf2.sunborngame.com/amhyyz?assist_code=2716063280        cout << pair.first << ": $" << pair.second << endl;
    }

    // 4. 元素查找
    cout << "\n=== 元素查找示例 ===" << endl;
    
    // 方法1：使用 [] 运算符（危险：不存在时会创建新元素）
    cout << "Apple 价格: $" << fruitPrices["Apple"] << endl;
    
    // 注意：如果 key 不存在，[] 会创建默认值
    cout << "Pineapple 价格: $" << fruitPrices["Pineapple"] << endl; // 创建了值为0的新元素
    
    // 方法2：使用 find()（推荐，安全）
    auto it = fruitPrices.find("Watermelon");
    if(it != fruitPrices.end()) {
        cout << it->first << " 价格: $" << it->second << endl;
    } else {
        cout << "找不到 Watermelon" << endl;
    }
    
    // 方法3：使用 count() 检查是否存在
    if(fruitPrices.count("Apple") > 0) {
        cout << "Apple 存在，价格: $" << fruitPrices["Apple"] << endl;
    }
    
    // 方法4：使用 contains()（C++20）
    // if(fruitPrices.contains("Apple")) {
    //     cout << "Apple 存在" << endl;
    // }

    // 5. 元素删除
    cout << "\n=== 元素删除示例 ===" << endl;
    
    cout << "删除前 map 大小: " << fruitPrices.size() << endl;
    
    // 方法1：通过 key 删除
    fruitPrices.erase("Pineapple");
    
    // 方法2：通过迭代器删除
    auto banana_it = fruitPrices.find("Banana");
    if(banana_it != fruitPrices.end()) {
        fruitPrices.erase(banana_it);
    }
    
    cout << "删除后 map 大小: " << fruitPrices.size() << endl;
    
    // 6. 遍历 map
    cout << "\n=== 遍历方式示例 ===" << endl;
    
    // 方法1：范围 for 循环（C++11，推荐）
    cout << "学生成绩（范围for）：" << endl;
    for(const auto& student : scores) {
        cout << student.first << ": " << student.second << endl;
    }
    
    // 方法2：传统迭代器
    cout << "\n剩余水果（迭代器）：" << endl;
    for(auto it = fruitPrices.begin(); it != fruitPrices.end(); ++it) {
        cout << it->first << ": $" << it->second << endl;
    }

    // 7. 常用操作
    cout << "\n=== 常用操作示例 ===" << endl;
    
    cout << "map 是否为空: " << (scores.empty() ? "是" : "否") << endl;
    cout << "map 大小: " << scores.size() << endl;
    
    // 清空 map
    fruitPrices.clear();
    cout << "清空后 fruitPrices 大小: " << fruitPrices.size() << endl;

    // 8. 高级用法：复杂数据类型作为 value
    cout << "\n=== 高级用法示例 ===" << endl;
    
    // map 的 value 可以是复杂类型
    map<string, vector<int>> studentGrades;
    studentGrades["Alice"] = {95, 87, 92};
    studentGrades["Bob"] = {78, 85, 90};
    
    cout << "学生多科成绩：" << endl;
    for(const auto& student : studentGrades) {
        cout << student.first << ": ";
        for(int grade : student.second) {
            cout << grade << " ";
        }
        cout << endl;
    }

    // 9. 实际应用示例：单词计数
    cout << "\n=== 实际应用：单词计数 ===" << endl;
    
    string text = "hello world hello cpp world hello";
    map<string, int> wordCount;
    
    // 简单的单词分割和计数（实际项目中应使用更复杂的分词）
    string word = "";
    for(char c : text + " ") {  // 在末尾加空格确保最后一个词被处理
        if(c == ' ') {
            if(!word.empty()) {
                wordCount[word]++;  // 如果不存在会自动创建并初始化为0，然后+1
                word = "";
            }
        } else {
            word += c;
        }
    }
    
    cout << "单词出现次数：" << endl;
    for(const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << " 次" << endl;
    }

    return 0;
}
