#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// 此处声明两个函数，一个用户计算平方，一个用于打印vector
vector<int> squareVec(int);
void printVector(const vector<int>&);

int main()
{
    // 创建一个值，它是vector的大小
    int userNum;
    cout << "enter a int ";
    cin >> userNum;
    // 呼叫平方函数，它的返回值将用于创建一个vector
    vector<int> resultVec = squareVec(userNum);
    // 呼叫打印函数
    printVector(resultVec);

    return 0;
}

/*
vector和数组不一样，因为vector的内存是动态的，所以它可以作为一个函数的返回值，
那么我们也可以创建一个vector函数，比如此处就是
vector<int> squareVec(int n){}
-类型-       -名称-    -传递参数-
在函数内，我们创建了一个空vector，没有大小，for循环每循环一次，我们就使用
push_back()为vector添加一个新值，并在结尾处将vector设为返回值。
*/ 
vector<int> squareVec(int n){
    vector<int> resultVec;
    for(int i = 0; i <= n; i++)
        resultVec.push_back(i*i);
    return resultVec;
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}