#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double userInput, userResult = 0;
    int loop = 1;
    cout << "please enter a number, enter q or Q to quit." << endl;
    /*
    在这个例子中，我们通过使用cin.fail()来检测用户的输入是否代表需要退出程序。
    并且通过while循环，让这个程序能够在用户不希望退出的情况下保持运行.
    在初始状态下，loop=true，所以while循环会持续运行。
    */
    while(loop){
        cin >> userInput;
        /*
        若用户的输入是数字，那么程序将正常运行，计算数字总和，并且跳过接下来的
        while(cin.fail())，让程序在计算以后允许用户输入下一个值。
        这里要在结尾带上一个cin.ignore()，因为用户可能会输入数字和字母的混合
        值，使用这个指令让未进入userInput的所有剩余数据都从缓存区中清除，保证
        程序不会在下一次循环时将上一次输入的值输入进userInput导致跳过输入环节
        */
        if(!cin.fail()){
            userResult = userInput + userResult;
            cout << "result is " << userResult << endl;
            cin.ignore(1000,'\n');
        }
        /*
        当用户输入的值不是数字时，进入While循环，清除输入流错误状态，并创建一
        个新的变量用于检测输入值是否是”Q“，为什么要创建新的变量呢？因为原来的
        变量userInput已经被声明为了double值，无法将字符输入并检查它是否是
        探针值，那么创建一个新的String值将会是更加通用的方法。
        若用户输入值是“Q”，那么将loop值设置为false，使程序退出主循环，若用户
        输入值不是“Q”，那么清除缓存区并重新开始主循环，让用户有机会再次输入值
        */
        while(cin.fail()){
            cin.clear();
            string inputCheck;
            cin >> inputCheck;
            if(inputCheck == "q" || inputCheck == "Q"){
                cout << "you entered Q, program quit." << endl;
                loop = 0;
                break;
            }
            else{
                cout << "you entered a non-number, but it's not Q." << endl;
                cin.ignore(1000,'\n');
                cin >> userInput;
            }
        }

    }

    return(0);
}