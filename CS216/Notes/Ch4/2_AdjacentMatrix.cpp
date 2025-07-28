#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main(){

    cout << "=== 邻接矩阵(Adjacency Matrix)表示法 ===" << endl;
    
    /*
    邻接矩阵定义:
    - 用于表示图中顶点间连接关系的二维数组
    - 对于n个顶点的图，使用n×n的矩阵A表示
    - A[i][j] = 1 表示顶点i和顶点j之间有边连接
    - A[i][j] = 0 表示顶点i和顶点j之间没有边连接
    
    存储结构:
    1. 顶点数组: 存储所有顶点信息
    2. 邻接矩阵: 存储边的连接关系
    */
    
    // 示例图的顶点
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E'};
    int n = vertices.size();
    
    // 有向图的邻接矩阵示例
    cout << "\n--- 有向图邻接矩阵示例 ---" << endl;
    int directedGraph[5][5] = {
        //A  B  C  D  E
        { 0, 1, 0, 0, 1 }, // A
        { 1, 0, 0, 1, 0 }, // B  
        { 0, 0, 0, 0, 1 }, // C
        { 0, 0, 1, 0, 0 }, // D
        { 0, 1, 0, 0, 0 }  // E
    };
    
    // 打印邻接矩阵
    cout << "邻接矩阵表示:\n   ";
    for(int i = 0; i < n; i++) {
        cout << vertices[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < n; i++) {
        cout << vertices[i] << "  ";
        for(int j = 0; j < n; j++) {
            cout << directedGraph[i][j] << " ";
        }
        cout << endl;
    }
    
    // 解读邻接矩阵
    cout << "\n图的边关系解读:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(directedGraph[i][j] == 1) {
                cout << "存在弧: " << vertices[i] << " → " << vertices[j] << endl;
            }
        }
    }
    
    /*
    邻接矩阵的特点:
    
    无向图:
    - 矩阵是对称的 (A[i][j] = A[j][i])
    - 主对角线通常为0 (无自环)
    
    有向图:
    - 矩阵可能不对称
    - A[i][j] = 1 不意味着 A[j][i] = 1
    
    加权图:
    - 可以用权重值代替0/1
    - 无连接用∞或特殊值表示
    */
    
    cout << "\n--- 邻接矩阵的优缺点 ---" << endl;
    cout << "优点:" << endl;
    cout << "1. 查询两顶点间是否有边: O(1)时间" << endl;
    cout << "2. 添加/删除边: O(1)时间" << endl;
    cout << "3. 适合稠密图(边数较多)" << endl;
    cout << "4. 矩阵运算方便" << endl;
    
    cout << "\n缺点:" << endl;
    cout << "1. 空间复杂度: O(n²)，对稀疏图浪费空间" << endl;
    cout << "2. 遍历所有边: O(n²)时间" << endl;
    cout << "3. 不适合动态添加/删除顶点" << endl;

    return 0;
}
