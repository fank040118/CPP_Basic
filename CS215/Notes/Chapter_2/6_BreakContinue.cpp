#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int i = 0;
    cout << "input a number, input 0 to quit" << endl;
    cin >> i;
    /*
    break和continue用法与其他语言一致。
    */
    while (i <= 10){
        if (i == 0){
            cout << "i = 0, while quit" << endl;
            break;
        }
        cout << i << endl;
        i++;
    }

    i = 0;
    cout << "input a number" << endl;
    cin >> i;
    while (i < 10){
        if (i == 5){
            cout << i << endl;
            i = i + 2;
            continue;
        }
        cout << i << endl;
        i++;
    }
    return(0);
}