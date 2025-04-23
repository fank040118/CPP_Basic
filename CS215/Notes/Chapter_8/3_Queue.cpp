#include <iostream>
#include <string>

// 队列Queue 是一种基本数据结构，它和栈一样，是着重了元素顺序的结构
// 元素的加入(入队Enqueue)只能在队列的尾端(rear)进行
// 元素的取出(出队Dequeue)只能在队列的前端(front)进行
#include <queue>

using namespace std;

int main(){

    queue <int> intQueue;
    queue <string> stringQueue;

    // push()函数用于向队列末尾添加元素
    intQueue.push(1);
    intQueue.push(2);

    // front()函数用于返回队首的元素值
    cout << intQueue.front() << endl;

    // pop()函数用于弹出队首元素
    intQueue.pop();
    cout << intQueue.front() << endl;

    // empty()函数用于检查队伍是否为空
    cout << !intQueue.empty() << endl;

    return 0;
}