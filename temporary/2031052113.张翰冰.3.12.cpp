//3.12
#include<stdio.h>
 
#define maxSize 20
 
/* 顺序队类型定义 */
typedef struct {
	int data[maxSize];
	int front;// 队首指针
	int rear;// 队尾指针
	int tag;// 表示队列是空还是不空，约定tag=0时队空，tag=1时队不空
} SqQueue;
 
/* 初始化队列 */
void initQueue(SqQueue &qu) {
	qu.front=0;// 队首和队尾指针重合并指向0
	qu.rear=0;
	qu.tag=0;// 标志位表示队空
}
 
/* 判断队空 */
int isQueueEmpty(SqQueue qu) {
	if(qu.tag==0&&qu.front==qu.rear) { // tag=0表示队空
		return 1;// 1表示判断结果为空
	} else {
		return 0;// 0表示判断结果为非空
	}
}
 
/* 判断队满 */
int isQueueFull(SqQueue qu) {
	if(qu.tag==1&&qu.front==qu.rear) { // 由于有标志位tag，故可以用此等式判断是否队满
		return 1;
	} else {
		return 0;
	}
}
 
/* 入队 */
int enQueue(SqQueue &qu,int x) {
	if(isQueueFull(qu)==1) {
		return 0;
	} else {
		qu.rear=(qu.rear+1)%maxSize;// 若队未满，则移动指针
		qu.data[qu.rear]=x;// 再存入元素
		qu.tag=1;// 只要进队就将tag设置为1，因为只有进队才可能会发生队满
		return 1;
	}
}
 
/* 出队 */
int deQueue(SqQueue &qu,int &x) {
	if(isQueueEmpty(qu)==1) { // 若队空，则不能出队
		return 0;
	} else {
		qu.front=(qu.front+1)%maxSize;// 若队不空，则移动指针
		x=qu.data[qu.front];// 再取出元素
		qu.tag=0;// 只要有元素出队，就把tag置为0，因为只有出队才可能队空
		return 1;
	}
}
 
/* 打印队列 */
void printQueue(SqQueue qu) {
	printf("\n");
	while(qu.rear!=qu.front) {
		qu.front=(qu.front+1)%maxSize;
		printf("%d\t",qu.data[qu.front]);
	}
	printf("\n");
}
 
int main() {
	SqQueue qu;
	int nums[]= {1,2,3,4,5,6};
	int n=6;
	for(int i=0; i<n; i++) {
		int m=enQueue(qu,nums[i]);// 将数组中的元素入队
	}
	printQueue(qu);// 打印队列
 
	int x;
	deQueue(qu,x);// 将元素1出队
	printQueue(qu);// 打印队列
	return 0;
}
