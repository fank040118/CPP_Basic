#include <iostream>
#include <string>
#include <vector>
#include <fstream> // 想要使用 fstream 就需要带有 <fstream> 头文件

using namespace std;

// 当用户运行程序时，可能想要传入一些不在代码内的信息，比如txt文件，图片等
// 这些信息需要通过 命令行参数Command Line Arguments 做到，它是常用的
// 用于传入额外信息的指令，通过它可以将额外信息传递给Main函数

// 由于Main函数不是我们显性调用的，而是运行环境启动时调用的
// 不像用户自行创建的函数，需要在Main中显性调用才会直接被运行

// 在命令行窗口中，传入文件的命令是 prog -v input.dat
// 其中 prog 代表可执行程序的名称
// -v 和 input.dat 是传给程序的命令行参数
// -v 代表一个选项，而 input.dat 则是传入的文件

// 命令行参数———————————————————————————————————————————————————————————
// 当在C++中想要使用命令行参数时，需要将 main函数 定义为如下格式：
int main(int argc, char* argv[]){
// 其中 argc(argument count) 代表传入的 命令行参数 的数量，这包括这个程序本身
// 所以如果额外传入了一个外来参数，argc就会等于2
// argv[](argument vector) 是一个字符串数组，每个元素都是一个命令行参数
// 比如 prog -v input.dat 会让 argc 变为3
// 其中 argv[0] = "prog", argv[1] = "-v", argv[2] = "input.dat" 

// 命令行参数代码举例————————————————————————————————————————————————————

    //在上面已经在main函数中指定可以使用命令行参数以后，如果代码必须要特定数量的参数
    // 才能运行，那么就可以使用if语句来判断传入的参数数量是否等于需要的参数
    // 比如此处，如果传入的参数数量不为2，那么代码将会直接退出而不是尝试继续运行
    if(argc != 2){
        cout << "Invaild command!" << endl;
        cout << "Please enter the command: programname filename" << endl;
        return 1;
    }

    // 在 C++ 中，想要对文件进行读写等操作，就需要使用头文件 <fstream>，它包含了
    // ifstream, ofstream 和 fstream 三个主要的 文件流 类，分别用于
    // 只读----, 只写---- 和 读写---- 文件
    // 这里使用的是 fstream，它可读也可写，fstream inData 声明了一个叫做 inData
    // 的对象，它目前尚未定义为任何实际的文件
    fstream inData;

    // 使用 fstream.open(参数) 可以打开指定路径的文件，argv[1]就是用户在命令行
    // 输入的文件名参数
    // inData 是一个 文件流 类型变量，在将文件授予给这个变量后，它并不是变成了那个
    // 文件，而是成为了一个“指向了文件的通道“，它和文件绑定在一起，对他的改变也会直接
    // 改变文件本身
    inData.open(argv[1]);
    // 使用 fstream.fail() 可以检查变量是否成功打开了文件，它和 cin.fail() 的原理一样
    if(!inData.fail()){
        // 如果没有出现错误，那就创建一个新的字符串
        string str;
        // eof 代表 end of file，即文件结尾，这里代表在inData读取到文件末尾的话
        // 就会让循环关闭，
        while(!inData.eof()){
            // getline() 是一个从流对象中逐行读取文本的函数，可将文本从流对象中读取到其他变量中
            // 第一个参数是 inData，第二个参数是 str，每一次运行，getline都会将第一个参数
            // 中的一行(不含最后的换行符)移动到第二个参数中
            getline(inData, str);
            // 每次读取都会将当前读取到的文本打印
            cout << str << endl;
        }
    }
    // 在读取完成以后，使用 fstream.close() 关闭文件流，即使不这么做，程序结束时也会关闭
    inData.close()




    return 0;
}