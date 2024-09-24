#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /*
    此处演示一个复杂的循环结合体，我们想要用户输入一个数，并按照数生成一个金字塔
    我们先让用户输入一个单数，因为金字塔的顶端应该只有一个字，所以加上金字塔的两侧
    就是一个单数，若数是双数，那么就将其加一
    */
    int userInput;
    cout << "input a odd number" << endl;
    cin >> userInput;

    if (userInput % 2 == 0){
        cout << "Your input is a even number, we add 1 to make it to odds." << endl;
        userInput++;
    }
    /*
    此处我们计算出金字塔顶端与左右底端的水平距离：
      *     像图中这种情况，当用户输入5时，顶端就相距离两侧各2个空格
     ***    所以顶端空格数量就是 (用户输入-1)/2 即 (5-1)/2 = 2
    *****   每增加一行，两侧的空格数量就各减1
    */
    int space = (userInput-1)/2;

    // 我们先给出一个循环，作为循环金字塔层数的主体，当内部的循环进行结束
    // 时，这个循环就会输出一个回车使金字塔构建进入下一层
    for(int i = 1; i <= userInput; i = i+2){

        // 我们先输出金字塔两侧的空格，金字塔顶端的两侧空格数量就是space
        // 直接输出金字塔左侧的空格(右侧是自然空下来的，不需要输出)
        for(int k = 1; k <= space; k++){
            cout << " ";
        }

        // 输出空格以后，输入金字塔本身，该层需要的数量i ＝ i + 2
        // (第一层只有1个),所以此处的循环只需要保证j <= i时重复输出
        for(int j = 1; j <= i;j++){
            cout << "o";
        }

        //一层的金字塔完成以后，开始构建下一层，并将下一层的空格数－1
        cout << endl;
        space = space - 1;

    }
    return(0);
}