#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    /*
    高级数组操作 - 动态使用固定大小数组
    
    关键概念:
    1. 数组容量(capacity): 数组声明时的最大大小，固定不变
    2. 数组大小(size): 当前实际使用的元素个数，可以小于容量
    3. 有效元素: 实际存储有意义数据的元素
    
    为什么需要区分容量和大小:
    - 数组容量固定，但不一定完全使用
    - 需要跟踪当前使用了多少个元素
    - 便于实现插入、删除等动态操作
    */
    cout << "=== 数组复制操作 ===" << endl;
    
    const int MAX_SIZE = 5;
    int powers[MAX_SIZE] = {0, 1, 2, 4, 11};
    int lucky_numbers[MAX_SIZE];
    
    /*
    数组复制注意事项:
    - 不能直接使用 = 操作符复制整个数组
    - 必须逐个元素复制
    - 数组名实际上是指向第一个元素的指针
    */
    
    // 错误方式: lucky_numbers = powers;  // 编译错误！
    
    // 正确方式: 使用循环逐个复制元素
    for(int i = 0; i < MAX_SIZE; i++) {
        lucky_numbers[i] = powers[i];
    }
    
    cout << "原数组powers: ";
    for(int i = 0; i < MAX_SIZE; i++) {
        cout << powers[i] << " ";
    }
    cout << endl;
    
    cout << "复制后的lucky_numbers: ";
    for(int i = 0; i < MAX_SIZE; i++) {
        cout << lucky_numbers[i] << " ";
    }
    cout << endl;

    cout << "\n=== 数组元素插入操作 ===" << endl;
    
    /*
    在数组中间插入元素的步骤:
    1. 确保数组有足够空间(currentSize < maxCapacity)
    2. 将插入位置及之后的所有元素向右移动一位
    3. 在目标位置插入新元素
    4. 更新数组当前大小
    
    关键点: 必须从右向左移动元素，避免数据覆盖
    */
    
    int myArray[5] = {1, 2, 4, 5};  // 初始: {1, 2, 4, 5, 0}
    int currSize = 4;               // 当前有效元素个数
    int insertIndex = 2;            // 要插入的位置
    int insertValue = 3;            // 要插入的值
    
    cout << "插入前的数组: ";
    for(int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    cout << "(当前大小: " << currSize << ")" << endl;
    
    // 检查是否有足够空间插入
    if(currSize < 5) {
        // 从右向左移动元素，为新元素腾出空间
        for(int i = currSize; i > insertIndex; i--) {
            myArray[i] = myArray[i-1];
        }
        
        // 在指定位置插入新元素
        myArray[insertIndex] = insertValue;
        currSize++;  // 更新当前大小
        
        cout << "在索引" << insertIndex << "处插入" << insertValue << "后: ";
        for(int i = 0; i < 5; i++) {
            cout << myArray[i] << " ";
        }
        cout << "(当前大小: " << currSize << ")" << endl;
    }

    cout << "\n=== 数组元素删除操作 ===" << endl;
    
    /*
    删除数组中间元素的步骤:
    1. 将删除位置之后的所有元素向左移动一位
    2. 更新数组当前大小
    3. 可选: 清空最后一个位置的值
    
    关键点: 从左向右移动元素，填补删除位置的空缺
    */
    
    int deleteIndex = 1;  // 要删除的位置(删除元素2)
    
    cout << "删除前的数组: ";
    for(int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    cout << "(当前大小: " << currSize << ")" << endl;
    
    // 检查删除索引是否有效
    if(deleteIndex >= 0 && deleteIndex < currSize) {
        // 从左向右移动元素，覆盖要删除的元素
        for(int i = deleteIndex; i < currSize - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        
        // 更新当前大小并清空最后一个位置
        currSize--;
        myArray[currSize] = 0;  // 可选: 清空末尾元素
        
        cout << "删除索引" << deleteIndex << "处的元素后: ";
        for(int i = 0; i < 5; i++) {
            cout << myArray[i] << " ";
        }
        cout << "(当前大小: " << currSize << ")" << endl;
    }

    
    return 0;
}