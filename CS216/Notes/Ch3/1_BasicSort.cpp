// C++ 基础排序算法笔记 (增强可读性版)
//
// 本笔记涵盖了三种基础的 O(n^2) 排序算法：
// 1. 冒泡排序 (Bubble Sort)
// 2. 选择排序 (Selection Sort)
// 3. 插入排序 (Insertion Sort)
//
// 每个算法都包含了非常详细的注释，解释了其：
// - 基本思想
// - 时间复杂度 (Time Complexity): 最好、平均和最坏情况
// - 空间复杂度 (Space Complexity): 执行算法所需的额外内存
// - 稳定性 (Stability): 是否能保持相等元素的原始相对顺序

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort 和 swap 需要这个头文件

// 使用 std 命名空间，使得代码更简洁，便于阅读。
// 在大型项目中通常不推荐全局使用，但在学习笔记中可以接受。
using namespace std;

// 辅助函数：打印 vector 中的内容
// 使用 const& (常量引用) 避免不必要的 vector 拷贝，提高效率。
// const 关键字保证这个函数不会修改传入的 vector。
void printVector(const string& label, const vector<int>& vec) {
    cout << label;
    // 使用范围-for循环 (range-based for loop) 遍历 vector
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// --- 1. 冒泡排序 (Bubble Sort) ---
//
// - 基本思想: 重复地遍历要排序的数列，一次比较两个相邻的元素，如果它们的顺序错误就把它们交换过来。
//   这个过程就像气泡从水底慢慢冒到水面一样，每一轮最大的元素都会"冒泡"到数组的末尾。
// - 时间复杂度:
//   - 最坏情况: O(n^2) (当数组完全逆序时)
//   - 平均情况: O(n^2)
//   - 最好情况: O(n) (当数组已经有序时，并且加入了优化标志)
// - 空间复杂度: O(1) (原地排序，in-place sort)
// - 稳定性: 稳定。因为只有当 `vec[j] > vec[j+1]` 时才交换，相等的值不会改变相对位置。
void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    bool swapped; // 优化标志：如果在一轮中没有发生任何交换，说明数组已经有序。

    // 外层循环控制排序的轮数，总共需要 n-1 轮。
    // 每一轮都会将当前未排序部分的最大值放到其最终位置。
    for (int i = 0; i < n - 1; ++i) {
        swapped = false; // 在每一轮开始前，重置交换标志

        // 内层循环负责在每一轮中进行相邻元素的比较和交换。
        // `-i` 的优化是因为每轮排序后，末尾的 i 个元素已经是有序的了，无需再比较。
        for (int j = 0; j < n - 1 - i; ++j) {
            // 如果前一个元素大于后一个元素，则它们的顺序是错误的
            if (vec[j] > vec[j + 1]) {
                // 调用 swap 函数交换它们的位置
                swap(vec[j], vec[j + 1]);
                // 标记本轮发生了交换
                swapped = true;
            }
        }

        // 优化：如果在一整轮的比较中都没有发生任何交换，
        // 这意味着数组已经完全排序好了，可以提前结束循环。
        if (!swapped) {
            break;
        }
    }
}

// --- 2. 选择排序 (Selection Sort) ---
//
// - 基本思想: 首先在未排序序列中找到最小（或最大）元素，存放到排序序列的起始位置，
//   然后再从剩余未排序元素中继续寻找最小元素，放到已排序序列的末尾。
// - 时间复杂度: O(n^2) (无论最好、最坏还是平均情况，都需要完整的双重循环来找到最小元素)
// - 空间复杂度: O(1) (原地排序)
// - 稳定性: 不稳定。例如，对于序列 {5a, 8, 5b, 2, 9}，第一轮会找到 2，并与 5a 交换，
//   交换后序列变为 {2, 8, 5b, 5a, 9}，此时 5a 和 5b 的相对顺序发生了改变。
void selectionSort(vector<int>& vec) {
    int n = vec.size();

    // 外层循环遍历数组，每次确定一个位置上的最终元素
    // 循环到 n-1 是因为当 i=n-2 时，最后一个元素 vec[n-1] 自然就位了
    for (int i = 0; i < n - 1; ++i) {
        // 假设当前位置 i 的元素就是未排序部分的最小值
        int min_idx = i;

        // 内层循环从 i+1 开始，遍历所有未排序的元素
        for (int j = i + 1; j < n; ++j) {
            // 如果发现了比当前最小值还小的元素
            if (vec[j] < vec[min_idx]) {
                // 就更新最小元素的索引
                min_idx = j;
            }
        }

        // 在一轮遍历结束后，如果最小值的索引不是 i，
        // 说明找到了一个更小的元素，需要进行交换。
        if (min_idx != i) {
            swap(vec[i], vec[min_idx]);
        }
    }
}

// --- 3. 插入排序 (Insertion Sort) ---
//
// - 基本思想: 构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//   这个过程非常像我们打扑克牌时，整理手中牌的过程。
// - 时间复杂度:
//   - 最坏情况: O(n^2) (当数组完全逆序时，每个元素都要移动到最前面)
//   - 平均情况: O(n^2)
//   - 最好情况: O(n) (当数组已经或基本有序时，每次插入都只需要少量比较)
// - 空间复杂度: O(1) (原地排序)
// - 稳定性: 稳定。因为元素是向后移动，直到找到一个小于或等于自己的元素，然后插入其后，不会改变相等元素的顺序。
void insertionSort(vector<int>& vec) {
    // 从第二个元素开始 (i=1)，因为第一个元素本身就可以看作是一个已排序的序列
    for (int i = 1; i < vec.size(); ++i) {
        int key = vec[i]; // `key` 是当前需要被插入到有序部分的元素
        int j = i - 1;    // `j` 指向已排序部分的最后一个元素

        // 从后向前，将所有比 key 大的元素向后移动一位，为 key 腾出空间
        // 循环条件：
        // 1. `j >= 0`: 保证不越界
        // 2. `vec[j] > key`: 找到第一个不大于 key 的元素时停止
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j]; // 元素后移
            j--;                 // 继续向前比较
        }

        // 循环结束后，j+1 就是 key 应该插入的正确位置
        vec[j + 1] = key;
    }
}

int main() {
    // 准备一个用于测试的原始数据
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "--- 1. 冒泡排序 (Bubble Sort) ---" << endl;
    vector<int> vec_bubble = data; // 复制一份数据进行排序，以防影响其他测试
    printVector("原始数组: ", vec_bubble);
    bubbleSort(vec_bubble);
    printVector("排序后:   ", vec_bubble);
    cout << endl; // 打印一个空行，让输出更清晰

    cout << "--- 2. 选择排序 (Selection Sort) ---" << endl;
    vector<int> vec_selection = data;
    printVector("原始数组: ", vec_selection);
    selectionSort(vec_selection);
    printVector("排序后:   ", vec_selection);
    cout << endl;

    cout << "--- 3. 插入排序 (Insertion Sort) ---" << endl;
    vector<int> vec_insertion = data;
    printVector("原始数组: ", vec_insertion);
    insertionSort(vec_insertion);
    printVector("排序后:   ", vec_insertion);
    cout << endl;

    cout << "--- 插入排序在近乎有序数组上的优势 ---" << endl;
    // 插入排序对于近乎有序的数组效率非常高，接近 O(n)
    vector<int> nearly_sorted = {2, 1, 3, 4, 6, 5, 7, 8};
    printVector("近乎有序数组: ", nearly_sorted);
    insertionSort(nearly_sorted);
    printVector("插入排序后:   ", nearly_sorted);
    cout << endl;

    cout << "--- 对比 C++ 标准库 std::sort ---" << endl;
    vector<int> vec_stl = data;
    printVector("原始数组: ", vec_stl);
    // `std::sort` 是一个高效的混合排序算法 (通常是内省排序 Introsort)，
    // 它结合了快速排序、堆排序和插入排序的优点，平均时间复杂度为 O(n log n)。
    sort(vec_stl.begin(), vec_stl.end());
    printVector("std::sort 后: ", vec_stl);
    cout << "\n注意: 在实际项目中，总是优先使用 std::sort，因为它经过高度优化，性能远超基础排序算法." << endl;

    return 0;
}