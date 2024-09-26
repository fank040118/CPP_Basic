#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int remove_element(int values[], int size, int pos)
{
    if (size > 0 && pos < size)
    {
        // 从删除位置开始，将后面的元素往前移动一位,在有效位的前一位处结束
        // 因为i的大小是数组的大小，而大小实际上是索引＋1的数量，所以它
        // 身就已经超出了索引范围，导致最终一位会从虚空中取值，所以我们需要
        // 让其在i<size-1时就结束，如果size＝5，那么他就会在3处结束
        // 因为value[i] = values[i+1]会让最终位的前一位赋最终位的值
        for (int i = pos; i < size-1; i++) {
            values[i] = values[i + 1];
        }
        size--;  // 数组的当前大小减少1
    }
    return size;  // 返回新的数组大小
}

int main()
{
    /*
    当我们传递数组类型的变量给一个函数function时，函数并不知道这个数组有多大，
    所以在传递数组给函数时，我们必须手动传递其数组大小，写法为：
    int myFunc(int Array[], int size)
    在传递数组时，我们需要为其传递变量名后面加上"[]"，以便让函数知道我们传递
    的是一个数组，但并不需要声明数组的大小是多少。

    数组在函数中永远是 引用传递，这代表函数会直接改变数组本身的值，而不知创造
    一个数组的副本，但是我们并不需要使用＆符号声明它是引用传递，函数在确定变量
    是数组时会自动使用引用传递。
    */
    
    int myArray[5] = {1,2,3,4,5};
    int arraySize = 5;
    int deleteIndex = 1;

    arraySize = remove_element(myArray, arraySize, deleteIndex);

    for(int i = 0; i < arraySize; i++){
        cout << myArray[i] << ' ';
    }

    return 0;
}