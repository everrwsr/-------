#include<iostream>
using namespace std;

#define ElemType int

/*
�����Դ�ͷ����ѭ�������ʾ����,����ֻ��һ��ָ��ָ���βԪ�ؽ��(ע��:����ͷָ��),
*     �Ա�д��Ӧ���ÿն��С��ж϶����Ƿ�Ϊ�ա���Ӻͳ��ӵ��㷨��
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
    Q.rear = new QNode;                //Q.rear����һ���ڵ㣬�ýڵ�Ĭ��Ϊͷ���
    Q.rear->next = Q.rear;             //ѭ�����У�βָ��ָ��ͷ���
    return "OK";
}

string EnQueue(LinkQueue &Q,ElemType e){ //�ڶ�β����
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
    if(Q.rear->next->next == Q.rear->next) Q.rear=Q.rear->next; //��ɾ���������һ��Ԫ��ʱ��
    delete q;                                                   //��βָ���λ����βָ�����ͷ���
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
