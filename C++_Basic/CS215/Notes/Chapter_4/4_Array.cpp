#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    /*
    数组Array是C++内常用的列表式类型，它和Python中的List列表有着较大区别。
    
    1:类型－－数组不能像Python的list一样放置不同类型的元素，C++的数组本身也
    存在着类型，如果创建数组时使用的类型是int，那么数组所能够储存的变量的类型
    也只能是int类型。
    2:大小－－数组不能像Python的list一样随意更改其大小，如果我们创建了一个
    长度为5的数组，那么这个数组就只能储存5个元素，在程序运行期间，我们不能更
    改数组的长度。
    */
    
    // C++的数组创建依照 类型 名称[容量] 的创建方法来创建，例如：
    double userArray_1[5];
    

    // 或者也可以使用 常量 来创建数组，但要注意它必须是一个不可修改的常量，这
    // 是因为数组本身的大小必须是固定的，所以创建时引用的变量也必须是固定的。
    // 要注意的是数组是不可以重新定义的，如果一个数组已经被提前声明了，那么它的
    // 内存就已经提前被规划好了，大小一旦确定就不能够改变。
    const int arraySize = 10;
    double userArray_2[arraySize];

    // 我们有几种方式能够初始化一个数组：
    int userArray_3[5] = {1,2,3,4,5};
    int userArray_4[] = {1,2,3,4,5}; // 这与前者相同，数组会自动变为5格大小
    int userArray_5[5] = {1,2,3}; // 这会创建 {1,2,3,0,0} 
    /*
    当我们创建了一个数组，但只为其部分元素填充了值的时候，我们称其为“部分显示化”
    数组，这类数组中未被赋值的变量位置将会默认以“零值”代替，而int类型中的零值
    就是0，所以即使没有为索引处为[3]和[4]的地方填写值，它也会储存0值，且这个值
    是实际存在的值，并非空值，它是可访问也是可使用的。
    如果创建数组时未给其赋值，那么我们将其称为“未显示化“的数组，也就是说它的
    内容是完全未被定义的(假如创建了一个5格元素大小的数组，但元素是什么却没有被
    定义)，那么此时这个数组内的元素将会是 完全随机 的元素，在这里创建的数组是
    double数组，那么它内部的元素有可能是任意double值。
    */
    int userArray_6[5] = {}; // 零值数组
    // 但如果创建数组时各给其赋值{}，那么他就会默认创建为0值数组，这种方式叫
    // 列表初始化
    

    // 使用 array[i] 能够访问索引为i处的元素(从0开始)，如果不写出索引，编译器
    // 将会访问 数组 的内存地址，而不是数组的元素，所以使用索引查找数组是必须的
    cout << userArray_3[0] << endl;

    // C++并没有类似于python一样的切片功能，所以我们并不能使用类似array[0:5]
    // 一样的方法去访问数组的某一部分的元素，这会产生错误，而正确方法如下：
    for(int i = 0; i <= 3; i++){
        cout << userArray_3[i] << " ";
    }
    cout << endl;

    // 我们可以使用 array[i] = x 来为数组的某一索引处的变量重新赋值，但这
    // 个方法并不能用于给数组增加元素，数组的大小并不能通过赋值的方法改变。
    userArray_5[3] = 40;
    userArray_5[4] = 50;
    for(int i = 0; i <= 4; i++){
        cout << userArray_5[i] << " ";
    }

    cout << endl;

    return 0;
}