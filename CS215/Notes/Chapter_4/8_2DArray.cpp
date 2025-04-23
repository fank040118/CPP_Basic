#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 这是文件底部的函数的声明，即使是声明，也需要包含函数的列数
void arrayAdd(int[][5],int, int);

int main()
{
    /*
    二维数组是类似于矩阵或表格的数据，他是具有多行多列的数组，二维数组和一维
    数组遵从相似的操作逻辑，二维数组和一维数组一样，储存的值必须是相同的类型。
    在C++中，使用 类型 数组名[行][列]来创建一个二维数组：
    */
    // 这样就能创建一个3行4列的数组。
    const int arrayRow = 3, arrayColumn = 4;
    int myArray_1[arrayRow][arrayColumn] = {};
    
    // 使用这种方式可以初始化一个二维数组，要注意的是每行结尾都有逗号
    int myArray_2[arrayRow][arrayColumn] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };
    // 通过先打印一行的每一列的元素，再进一行的方法，我们能够依次打印
    // 一个二维数组中的所有元素。
    for(int i=0; i < arrayRow; i++){
        for(int j=0; j < arrayColumn; j++){
            cout << myArray_2[i][j] << ' ';
        }
        cout << endl;
    }

    /*
    在二维数组中，如果我们想要将数组传输给一个函数，我们必须显性地告诉
    函数我们的数组的 列数 的大小，因为编译器需要准确的知道每行有多少列
    才能调用正确的内存地址。
    所以说，当我们构建一个为二维数列使用的函数的时候，我们就需要提前定义
    这个函数能够接受的列数的大小，如果我们在稍候构建了一个有更多列数或
    更少列数的数组，我们就无法将这个数组调进这个函数中，这是一个硬性限制。
    */
    // 比如说，我们在此处有一个5*5的数组：
    int myArray_3[5][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25},
    };
    // 那么我们调用的函数的列数就必须 完全等于5。

    int rowSize = 5;
    arrayAdd(myArray_3, rowSize, 5);
    for(int i=0; i < rowSize; i++){
        for(int j=0; j < 5; j++){
            cout << myArray_3[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

/*
这是一个用来给5列数组的每个值都加值的函数，因为我们知道函数对于数组来说
是引用传递，所以当我们传递这个数组给函数时，我们并不需要任何返回值，因
为它直接修改了数组本身。

在这个函数中，我们包含了数组类型，数组的列数，数组的行数，以及我们需要加的值
函数会先遍历一行里的每一列，将每个值加addNum，然后再进行下一行，以此类推
*/
void arrayAdd(int array[][5],int rowSize, int addNum){
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < 5; j++){
            array[i][j] = array[i][j] + addNum;
        }
    }
}