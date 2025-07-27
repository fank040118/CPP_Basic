#include <iostream>
#include <string>

using namespace std;

int main(){
    /*
    深度优先搜索Depth First Search，DFS算法————————————————————————————————————————————————
    DFS和BFS都是用于遍历或搜索 树 或 图 等数据结构的算法
    DFS 从根节点开始，通常根节点可以是任何一个点
    DFS 不像BFS会先将所有最近的点探索一遍，而是先对某一条分支一直走到不能走为止
    当走到末尾时，再返回到上一次遇到的 分叉点 继续去探索，若本就没有分叉，那就会回到根节点
    因此，DFS非常适合探测某一特定方向是否连通

    其伪代码可写为：
    DFS(Graph, root):
        for each vertex v in the Graph:
            visited[v] = false          对图内所有节点v都设置为 未访问过

        create stack s                  创建一个空的栈，称为s

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

    ——————————————————————————
    比如一个图为：
    A---B---D
    |
    C---E---F
    那么从A开始的DFS过程将是：
    初始化，所有顶点都是未访问的，将A(根节点)压入栈，并将其设置为已访问
    循环开始：
        弹出A，探测其相邻顶点 B 和 C，并将它们压入栈中（先压入B，后压入C)，此时栈为[C,B]
        弹出C（C是栈顶），探测其相邻顶点 E，将其压入栈中，此时栈为[E,B]
        弹出E（E是栈顶），探测其相邻顶点 F，将其压入栈中，此时栈为[F,B]
        此时由于E后面没有顶点了，那么栈就只剩[B]，那么弹出B，开始探测B相邻顶点 D
        最后弹出D，由于D没有相邻顶点，所以栈为空栈[]，DFS完毕

    更高效的DFS————————————————————————————————————————————————————————————————————

    一种更加简单的方法是一次只对节点访问一个相邻节点，在上面的伪代码中，虽然DFS是在往着某一个方向
    探索，但在每次弹出元素时，DFS都会把所有相邻顶点都压入栈
    
    其伪代码可写为：
    DFS(Graph, root):
        for each vertex v in the Graph:
            visited[v] = false

        create stack s

        visited[root] = true
        s.push(root)

        while s != empty:                    区别从此处开始：
            u = s.top()                      将u设为栈顶元素（第一次是根节点）
            if for all vertices adjacent to u is visited
                s.pop()                      如果u的所有相邻节点都被访问了，那么弹出u
            else                             否则，找出u附近的一个顶点，且只找一个
                find an unvisited adjacent vertex w 
                visited[w] = true            将其设为w并设为已访问，那么下一次循环中
                s.push(w)                    w就会是u

        通过这样的循环，DFS一次只会往栈里压一个元素，并依据该元素探测下一个未访问的元素，当
        该路径上所有元素都被访问过后，这些没有其他相邻的未访问的顶点的元素将会被全部弹出，
        并开始访问最近分叉的其他元素


    递归版本的DFS——————————————————————————————————————————————————————————————————

    DFS(Graph, root):
        visited[root] = true
        for each edge(root, v):
            if visited[v] != false:
                DFS(Graph, v)
    
    这样的递归循环，通过不断引用自身，不断探索某一方向的顶点，函数会一直调用直到末尾，
    当到达末尾时，递归开始往顶层处理，并开始下一次递归

    */

    

    return 0;
}