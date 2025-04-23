#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(const vector<int>& v);

// 线性搜索Linear Search——————————————————————————————————————————————————
// 从列表的开头开始，直到找到元素或达到列表末尾为止
// 不要求列表有序，即使是无序也能从头访问到尾

// 对于有n个元素的列表来说:
// 最坏的情况是查找n次，因为元素就在最后一位或者找不到
// 不成功的话是n+1次，因为还要额外确认一位保证目标元素不存在
// 如果目标存在，通常需要寻找 (n+1)/2 次
// 整体复杂程度是 O(n)

// 二分搜索Binary Search————————————————————————————————————————————————————
// 要求有序列表，因为二分搜索依赖于元素的大小比较
// 从列表的中间开始搜索，如果目标元素小于当前元素，那么开始向小的方向搜索，反之亦然

// 每一次搜索都能排除掉当前大小的一半的列表元素，复杂度为O(log n)

// 排序Sorting——————————————————————————————————————————————————————————————

// 选择排序Selection sort
// 选择排序通过将整个列表中尚未确定的最小元素与未确定列表内的第一位互换位置来排序列表
// 例如{3,4,2,1}中，列表中最小的元素是{1}，将其放置在第一位得：
// {1,4,2,3}，那么索引[0]处元素确定，接下来列表中最小的元素是{2}，将其放置在第二位得：
// {1,2,4,3}，那么索引[1]处元素确定，接下来列表中最小的元素是{3}，将其放置在第三位得：
// {1,2,3,4}，那么排序完成
// 这个过程可以通过递归完成
void selSort (vector<int>& userVec1){
    for(int i = 0; i < userVec1.size(); ++i){
        for(int j = i; j < userVec1.size(); ++j){
            if (userVec1[j] <= userVec1[i]){
                int minNum = userVec1[j];
                userVec1[j] = userVec1[i];
                userVec1[i] = minNum;
            }
        }
    }
}

// 冒泡排序Bubble Sort
// 冒泡排序通过对比相邻的元素进行排序，每次都对比 i 和 i+1 处的元素大小，如果前面的元素更大
// 那么更换它们的位置，然后在对比 i+1 和 i+2 处的元素，每一次循环都能把一个当前最大的元素
// 带到列表的最后一位，所以每一次循环的长度都会-1
void bubbleSort (vector<int>& userVec1){
    int maxNum = userVec1.size()-2;
    // 每次循环最大数-1，因为最后一位已经被确定
    for(int i = 0; i <= userVec1.size()-1; ++i){
        cout << "第" << i << "次循环" << endl;
        printVector(userVec1);
        // 每次对比当前数和下一位数
        for(int j = 0; j <= maxNum; ++j){
            if (userVec1[j] > userVec1[j+1]){
                int largerNum = userVec1[j];
                userVec1[j] = userVec1[j+1];
                userVec1[j+1] = largerNum;
            }
        }
        maxNum--;
    }
}

// 除此以外，还有 归并排序(Merge Sort)，它将元素先以二分的方式逐渐化为单个元素
// 再用二分的方式为每两个元素进行比较排序，再让每两组元素内的元素进行二次排序，以此类推
// 最终合并出有序的序列，其处理效果更快，但代码复杂度较高

// 另外还有 插入排序(Insertion Sort)，它将以第一个元素创建一个单元素的新序列
// 并逐步将后续元素插入到新序列中，若序列内当前的元素小于它，就将元素插入进下一位
// 若序列内当前的元素大于它，就将大于的元素右移并将当前元素插入


int main(){

    vector<int> userVec_1 = {5,4,3,2,1,0};
    selSort(userVec_1);
    printVector(userVec_1);

    vector<int> userVec_2 = {10,9,8,7,6,5};
    bubbleSort(userVec_2);
    printVector(userVec_2);

    return 0;
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}