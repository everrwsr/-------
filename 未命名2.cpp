#include<iostream>
using namespace std;

#define ElemType int

/*
假设以带头结点的循环链表表示队列,并且只设一个指针指向队尾元素结点(注意:不设头指针),
*     试编写相应的置空队列、判断队列是否为空、入队和出队等算法。
*/

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;


typedef struct{
    QueuePtr rear;
    QNode head;
}LinkQueue;

string InitQueue(LinkQueue &Q){
    Q.rear = new QNode;                //Q.rear代表一个节点，该节点默认为头结点
    Q.rear->next = Q.rear;             //循环队列，尾指针指向头结点
    return "OK";
}

string EnQueue(LinkQueue &Q,ElemType e){ //在队尾插入
    QueuePtr S = new QNode; 
    S->data = e;
    S->next=Q.rear->next;                
    Q.rear->next=S;
    Q.rear=S;
    return "OK";   
}


string DeQueue(LinkQueue &Q,ElemType &e){

    QNode *q = Q.rear->next->next;
    e = q->data;
    Q.rear->next->next=q->next;
    if(Q.rear->next->next == Q.rear->next) Q.rear=Q.rear->next; //若删除的是最后一个元素时，
    delete q;                                                   //将尾指针归位，将尾指针代表头结点
    return "OK"; 
}

int IsEmpty(LinkQueue Q){
    if(Q.rear->next == Q.rear) return 1;
    else return 0;
}


int main(){

    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    cout << IsEmpty(Q)<<endl;
    ElemType a;
    DeQueue(Q,a);
    
    cout <<a;
    cout << IsEmpty(Q)<<endl;
    system("pause");
    return 0;
}
