#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct QNode
{
    int data;
    struct QNode * rear;
    struct QNode * next;
}QNode,*LinkQueue;

int InitLinkQueue(LinkQueue * L)
{

    (*L)=(LinkQueue)malloc(sizeof(QNode));
    if((*L)==NULL)
    {
        printf("内存分配失败！\n");
        return 1;
    }
    (*L)->rear=(*L);
    return 1;
}

//链式队列的建立
int Create(LinkQueue * L,int n)
{
    srand(time(0));
    LinkQueue P;
    for(int i=0;i<n;i++)
    {
        P=(LinkQueue)malloc(sizeof(QNode));
        P->data=rand()%100+1;
        (*L)->rear->next=P;
        (*L)->rear=P;
    }
    P->next=(*L);
    return 1;
}

//入队操作
int EnQueue(LinkQueue * L,int e)
{
    LinkQueue P;
    P=(LinkQueue)malloc(sizeof(QNode));
    P->data=e;
    P->next=(*L);
    (*L)->rear->next=P;
    (*L)->rear=P;
    return 1;
}


//出队操作
int DeQueue(LinkQueue * L,int * e)
{
    LinkQueue temp;
    *e=(*L)->next->data;
    temp=(*L)->next;
    (*L)->next=(*L)->next->next;
    delete(temp);
    return 1;

}

//输出
void Print(LinkQueue * L)
{
    LinkQueue P;
    P=(*L)->next;
    printf("输出元素:\n");
    while(P!=(*L))
    {
        printf("%d ",P->data);
        P=P->next;
    }
    printf("\n");
}


int main()
{
    LinkQueue L;
    int ElemNumber;
    int EnElem,DeElem;
    InitLinkQueue(&L);
    printf("请输入元素个数：\n");
    scanf("%d",&ElemNumber);
    Create(&L,ElemNumber);
    Print(&L);
    printf("请输入入队元素：\n");
    scanf("%d",&EnElem);
    EnQueue(&L,EnElem);
    Print(&L);
    printf("出队操作，并返回出队元素：\n");
    DeQueue(&L,&DeElem);
    printf("出队元素为：%d\n",DeElem);
    Print(&L);
    return 0;
}
