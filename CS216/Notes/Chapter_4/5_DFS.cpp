#include <iostream>
#include <string>

using namespace std;

int main(){

    // 深度优先搜索Depth First Search，DFS算法————————————————————————————————————————————————
    // DFS和BFS都是用于遍历或搜索 树 或 图 等数据结构的算法
    // DFS 从根节点开始，通常根节点可以是任何一个点
    // DFS 不像BFS会先将所有最近的点探索一遍，而是先对某一条分支一直走到不能走为止
    // 当走到末尾时，再返回到上一次遇到的 分叉点 继续去探索，若本就没有分叉，那就会回到根节点
    // 因此，DFS非常适合探测某一特定方向是否连通
    
    /*
    其伪代码可写为：
    DFS(Graph, root):
        for each vertex v in the Graph:
            visited[v] = false          对图内所有节点v都设置为 未访问过
        create stack s
        visited[root] = true 
        s.push(root)                    将根节点设置为已访问过，并推入s

        while s != empty:               只要s还有元素，就一直循环
            u = s.pop()                 将u设置为s中的顶层元素
            if visited[u] == false      
                visited[u] = true       如果u是未被访问过的，将其设置为访问过
            for each unvisited vertex w adjacent to u
                s.push(w)               将所有u的未被访问过的相邻节点压入s
        这里和BFS最大的区别是，DFS使用了stack，stack是先进后出的逻辑，而BFS使用的是先进先出的队列
        这使得DFS会在后续循环中不停访问最后被推入的节点的相邻节点，直到该路径下的所有相邻节点都被访问了
        使得stack顶端留下的是上一个分叉的另一个节点，DFS才会重新从该节点继续向深处访问
        
    */

    return 0;
}