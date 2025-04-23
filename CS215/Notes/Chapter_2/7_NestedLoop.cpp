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
    cout << "input a number" << endl;
    cin >> userInput;

    for(int i = 0; i < userInput; i++){
        int level = i + 1;
        for(int k = 1; k <= userInput - level; k++){
        cout << ' ';
        }

        for(int j = userInput-level; j < userInput+level-1; j++){
            cout << '*';
        }
        cout << endl;
    }

    int level = 1;
    for (int i = 1; i <= userInput; i++) {
        for (int k = 1; k <= level; k++) {
            cout << "*";
        }
        cout << endl;
        level++;
        
    }
    for (int i = 1; i <= userInput; i++) {
        for(int k = level-2; k >= 1; k--){
                cout << "*";
        }
        cout << endl;
        level--;
    }
    // print triangle rotated 180 degrees
    level = userInput;
    for(int i = 1; i < userInput; i++){
        
        for(int k = 1; k < i; k++){
        cout << ' ';
        }

        for(int j = 1; j <= level*2-1; j++){
            cout << '*';
        }
        cout << endl;
        level--;
    }

    return(0);
}