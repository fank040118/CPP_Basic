#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double userNum;
    double userNumSum = 0;
    int count = 0;
    
    cout << "Please enter number to calcualte sum, enter 0 to quit" << endl;

    /*
    当我们创建循环时，我们需要为程序放置一个“探针”，作为让用户自行退出循环的方法，在这个
    代码例子中，探针就是“0”，当用户输入0时，循环就会结束，如果用户输入的是非0，那么程序
    将会进入If语句并处理输入数据。
    */
    do{
        cin >> userNum;
        if(userNum != 0){
            userNumSum = userNumSum + userNum;
            count++;
        }
        cout << "the num you entered was " << userNum << endl;
    }while(userNum != 0);

    cout << "you entered " << count << " numbers.\n"
    << "the sum of them is " << userNumSum << endl;

    return(0);
}