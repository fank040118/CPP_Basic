#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void print2DVector(const vector<vector<double>>&);

int main()
{
    /*
        在C++中，2D的Vector和2D的数组本质上并不一样，数组作为固定且内存连续的数
    据类型，当我们创建一个2D的数组时，他实际上是多个在内存中连续的储存数据，每行每
    个数据之间都挨在一起
        但Vector作为一种动态的数据类型，它的数据并不一定像数组一样在内存的物理位置
    中紧紧相挨，那么当我们创建2D的Vector时，我们实际上是创建了一个一维的vector，
    然后再在这个vector中的每个元素单独创建一个vector进行嵌套使其组合在一起，举例：
    1 2 3 4
    5 6 7 8
    这个2d的vector实际上由三个vector组成，一个vector储存{1,2,3,4}，一个vector
    用于储存{5,6,7,8}，一个外层vector用于储存这两个内层vector，而随着vector的
    行数衍生，内部还会存在更多的vector，也就是说2d的vector本质上每一行都是一个独立
    的vector，而外层还有一个vector用户将每个内部的vector组合在一起。
    */
    int students, homeWorks;
    cout << "enter number of students and homeworks: ";
    cin >> students >> homeWorks;
    /*
        在老版本C++中，创建vector时我们需要使用 vector <vector<类型>> 名称来创建
    2d的vector，它实际上就是一个嵌套式的vector，第一个vector<>的类型是vector，也
    就是说它储存的变量类型就是vector，随后第二个vector的类型是我们想要储存的变量的类型，
    在下面的例子中，第二个vector储存的变量类型是double，而第一个vector则储存第二个类型
    的vector。
        在for循环中，我们每次主循环都会创建一个临时vector，并在次循环中为这个临时vector
    多次赋值，随后主循环结束时将这个临时vector赋值给主vector，因为主vector创建时所声明
    的变量类型就是vector，通过不断重复vector，我们创建出一个多个vector组成的vector。
    */
    vector<vector<double>> scores;
    for(int i = 0; i < students; i++){
        vector<double> templateVec; // 创建1维临时Vector
        for(int j = 0; j < homeWorks; j++){
            templateVec.push_back(100.0); // 每次循环时为临时Vector传入新参数
        }
        scores.push_back(templateVec); // 次循环结束后将临时Vector传入主Vector
    }
    print2DVector(scores); // 呼叫打印函数

    /*
    在C++11之后，我们可以快速地为2dVector赋值，但即使是C++11，2dVector
    本质上也仍然是嵌套式的vector，在这个例子中，赋值前需要先使用一个{}涵盖内部
    的所有vector，它实际上就是外层Vector，内部的每个值则是内层vector，它们
    使用逗号分离，就像一维的vector一样。
    */
    vector<vector<double>> scores_2 = {
        {90.0, 99.0, 95.0},
        {95.5, 97.0, 83.0},
        {89.0, 85.5, 90.5},
    };
    print2DVector(scores_2);


    return 0;
}


/*
对于一个2D vector来说，打印它的循环和打印数组的循环类似，我们已知
可以使用vector.size()来找出一个vector的大小，我们又知2D vector
中外层Vector的每个值都是一个Vector，也就是说每个Vector[i]都是
一个内层Vector，那么使用Vector[i].size()就能找出每个内层的大小

使用这个方法，我们先使用一个For循环遍历外层vector，再使用一个For
循环遍历每个内层Vector，就能打印出这个Vector的每个变量。

也正因如此，函数使用Vector时不需要输入它的大小即可使用。
*/
void print2DVector(const vector<vector<double>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++){
            cout << '\t' << v[i][j]; 
        }
        cout << '\n';
    }
    cout << endl;
}

