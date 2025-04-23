#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // 这是sort需要的头文件

using namespace std;

void vecPrint(vector<int> vec);

int main(){
    // 冒泡排序Bubble Sort——————————————————————————————————————————————————————————
    // 这是个基本的冒泡排序算法代码，首先有个Vector：
    vector<int> a = {1,3,4,8,5,7,6};
    // 然后一个for循环，它会遍历所有元素：
    for (int i = 0; i < a.size(); i++){
        // for循环里嵌套另一个for循环，这个for循环的元素少一位，每一次大循环遍历完了，小循环都会少遍历一个数
        // 这个 for 循环会从 [0] 遍历到 size()-1-i
        // 每一次都会比较 当前数 和 下一个数，如果 当前数 大于 下一个数，那么替换它们两
        // 这样每一次都会让相邻两个元素被排序正常，而总遍历次数将会确保每一次都把最大的数
        // 移动到当前的末尾
        // 随着这个末尾每一次遍历都会让最后一位数排序正常，所以每遍历一次，下一次需要遍历的数都减一
        for(int j = 0; j < a.size()-i-1; j++)
        if (a[j] > a[j+1]){
            int tmp;
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
        }
    }
    vecPrint(a);

    // Sort功能—————————————————————————————————————————————————————————————————————
    // 我们可以像上面一样自己写排序，也能直接用标准模板库STL提供的排序：
    // 使用它需要在头文件包含<algorithm>
    // 语法为 sort(First, Last);
    // 其中 First 和 Last 是一个可排序结构的元素开头和元素结尾
    vector<int> b = {9,7,8,6,4,5,3,1,2};
    // 比如这里要排序整个vector，那就用 begin() 和 end()
    sort(b.begin(), b.end());
    vecPrint(b);
}

void vecPrint(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
    cout << endl;
}