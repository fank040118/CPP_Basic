#include <iostream>
#include <string>

using namespace std;

int main(){
    // 邻接表Adjacent List————————————————————————————————————————————————————————————
    // 邻接表和邻接矩阵类似，都用于储存图，但有以下区别：
    // 邻接表使用 二位不规则数组Two dimensional ragged array 来储存边，不规则意味着每个
    // 顶点之间的相邻顶点数量可能不同
    // 顶点列表是一个单链表，用于储存图中的所有顶点
    // 邻接列表专门用于储存边的信息
    //
    // 邻接表比邻接矩阵的空间使用效率更高，因为邻接矩阵需要为每一个顶点都做一个一维数组
    // 储存它与其他点之间的边的信息，所有一维数组合并成一个二维数组，但实际上图中
    // 所存在的边数量可能远小于二维数组所拥有的元素数量
    // 但邻接表只储存实际存在的边，如果不存在，那么两顶点间将不会有数据
    //
    // 例如，一个邻接表的数据可能如下：
    // A - {B}
    // B - {A C E}
    // C - {B D E}
    // D - {C E}
    // E - {B C D}
    // 左侧是顶点链表，右侧是相对应的邻接列表，储存与顶点连接的其他顶点，以形成边
    



    return 0;
}




























