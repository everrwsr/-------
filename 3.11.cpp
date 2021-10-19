//3.11 
	#include "stdio.h"
	#include "stdlib.h"
	struct dnode 
	{
		int data;
		dnode *next;
	 	dnode *rear;
	};
	void cquene(dnode *&L,int a[],int n)
	{
		dnode *temp,*node;
		L=(dnode *)malloc(sizeof(dnode));
		L->next=NULL;
		L->rear=NULL;
		temp=L;
		for(int i=0; i<n; i++) 
		{ 
			node=(dnode *)malloc(sizeof(dnode)); 
			node->data=a[i];
			temp->next=node;
			temp=node;
		}
		temp->next=L;
		L->rear=temp;
	}
	void display(dnode *L) 
	{
		dnode *temp;
		temp=L->next;
		printf("\n");
		while(temp!=L) 
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	void inquene(dnode *&rear,int x) 
	{
		dnode *newNode=(dnode *)malloc(sizeof(dnode));
		newNode->data=x;
		newNode->next=rear->next;
		rear->next=newNode;
		rear=newNode;
	}
	
	int dquene(dnode *&rear,int &x) 
	{
		dnode *tempDelNode;
		if(rear->next==rear) 
		{
			return 0;
		} 
		else 
		{
			tempDelNode=rear->next->next;
			x=tempDelNode->data;
			rear->next->next=tempDelNode->next; 
			if(tempDelNode==rear) 
			{
				rear=rear->next;
			}
			free(tempDelNode);
			return 1;
		}
	}
	 
	int main()
	{
		dnode *list,*t1,*t2;
		int a[]= {17,28,76,67,99,21,34};
		cquene(list,a,7);
		printf("初始队列元素为：\n");
		display(list);
		inquene(list->rear,41);
		inquene(list->rear,42);
		inquene(list->rear,43);
		printf("入队后队列元素为：\n");
		display(list);
		int x;
		dquene(list->rear,x);
		printf("出队后队列元素为：\n");
		display(list);
		return 0;
	}
