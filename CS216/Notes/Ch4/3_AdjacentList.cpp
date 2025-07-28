#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){
    
    cout << "=== 邻接表(Adjacency List)表示法 ===" << endl;
    
    /*
    邻接表定义:
    - 使用数组+链表的组合数据结构表示图
    - 每个顶点对应一个链表，存储与该顶点相邻的所有顶点
    - 相比邻接矩阵，空间效率更高，特别适合稀疏图
    
    数据结构组成:
    1. 顶点数组: 存储所有顶点
    2. 邻接链表数组: 每个顶点对应一个链表，存储其邻居顶点
    */
    
    // 示例图的顶点
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E'};
    int n = vertices.size();
    
    // 使用vector<list>实现邻接表
    vector<list<int>> adjList(n);
    
    cout << "\n--- 构建无向图的邻接表 ---" << endl;
    
    // 添加边 (使用索引表示顶点)
    // A(0) - B(1), A(0) - E(4)
    adjList[0].push_back(1); adjList[1].push_back(0);
    adjList[0].push_back(4); adjList[4].push_back(0);
    
    // B(1) - C(2), B(1) - D(3)  
    adjList[1].push_back(2); adjList[2].push_back(1);
    adjList[1].push_back(3); adjList[3].push_back(1);
    
    // C(2) - D(3), C(2) - E(4)
    adjList[2].push_back(3); adjList[3].push_back(2);
    adjList[2].push_back(4); adjList[4].push_back(2);
    
    // D(3) - E(4)
    adjList[3].push_back(4); adjList[4].push_back(3);
    
    // 打印邻接表
    cout << "邻接表表示:" << endl;
    for(int i = 0; i < n; i++) {
        cout << vertices[i] << " -> ";
        for(int neighbor : adjList[i]) {
            cout << vertices[neighbor] << " ";
        }
        cout << endl;
    }
    
    /*
    邻接表 vs 邻接矩阵 对比:
    
    空间复杂度:
    - 邻接表: O(V + E) (V个顶点，E条边)
    - 邻接矩阵: O(V²)
    
    时间复杂度:
    操作          邻接表     邻接矩阵
    查找边       O(degree)    O(1)
    添加边       O(1)         O(1)
    删除边       O(degree)    O(1)
    遍历邻居     O(degree)    O(V)
    */
    
    cout << "\n--- 邻接表的优缺点分析 ---" << endl;
    cout << "优点:" << endl;
    cout << "1. 空间效率高: O(V+E)，适合稀疏图" << endl;
    cout << "2. 遍历某顶点的邻居效率高" << endl;
    cout << "3. 添加边操作简单" << endl;
    cout << "4. 动态图结构支持好" << endl;
    
    cout << "\n缺点:" << endl;
    cout << "1. 查找特定边需要遍历链表" << endl;
    cout << "2. 删除边相对复杂" << endl;
    cout << "3. 不适合稠密图" << endl;
    cout << "4. 内存访问局部性较差" << endl;
    
    cout << "\n--- 应用场景选择 ---" << endl;
    cout << "选择邻接表的情况:" << endl;
    cout << "- 稀疏图(边数相对较少)" << endl;
    cout << "- 需要频繁遍历顶点的邻居" << endl;
    cout << "- 图结构经常变化" << endl;
    
    cout << "\n选择邻接矩阵的情况:" << endl;
    cout << "- 稠密图(边数接近V²)" << endl;
    cout << "- 需要频繁查询两顶点间是否有边" << endl;
    cout << "- 图结构相对固定" << endl;

    return 0;
}