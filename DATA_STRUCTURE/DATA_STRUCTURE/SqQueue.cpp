//循环队列
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZEE 5
//牺牲一个元素
typedef struct {
	int *base;
	int front;
	int rear;
}SqQueue;
//初始化队列
void InitQueue(SqQueue &Q) {
	
	Q.base = (int *)malloc(sizeof(int)*MAXSIZEE);
	if (!Q.base)return;//分配失败*/
	Q.front = Q.rear = 0;
}
//进队
void EnQueue(SqQueue &Q , int elem) {
	if ((Q.rear + 1) % MAXSIZEE == Q.front)  return;//队满
	Q.base[Q.rear] = elem;
	Q.rear = (Q.rear + 1) % MAXSIZEE;
	
}

bool SqQueueEmpty(SqQueue &Q) {
	return Q.front == Q.rear ? true : false;
}
//出队
void Dequeue(SqQueue &Q) {
	if (SqQueueEmpty(Q)) return;//队列为空返回
	int e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZEE;
	printf_s("%d\t 出队",e);
}

//队列长度
int GetLength(SqQueue &Q) {
	return (Q.rear - Q.front + MAXSIZEE) % MAXSIZEE;
}

//flag 方法
typedef struct {
	int *base;
	int front;
	int rear;
	bool flag;
}SqQueuef;

//初始化队列
void InitQueuef(SqQueuef &Q) {

	Q.base = (int *)malloc(sizeof(int)*MAXSIZEE);
	if (!Q.base)return;//分配失败*/
	Q.front = Q.rear = 0;
	Q.flag = false;
}

//进队
void EnQueuef(SqQueuef &Q, int elem) {
	
	if (Q.flag && Q.rear == Q.front)return;//队满
	Q.flag = true;
	Q.base[Q.rear] = elem;
	Q.rear = (Q.rear + 1) ;
}

//出队
void Dequeuef(SqQueuef &Q) {
	
	if (!Q.flag && Q.front == Q.rear) return;//队列为空返回
	Q.flag = false;
	int e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZEE;
	printf_s("%d\t 出队", e);
}

//队列长度
int GetLengthf(SqQueuef &Q) {
	return (Q.rear - Q.front ) ;
}
int main() {
	
	//SqQueue Q;
	/*
	InitQueue(Q);
	EnQueue(Q ,3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	EnQueue(Q, 6);*/
	
	//Dequeue(Q);

	SqQueuef Q;
	InitQueuef(Q);
	EnQueuef(Q, 3);
	EnQueuef(Q, 4);
	EnQueuef(Q, 5);
	EnQueuef(Q, 6);
	EnQueuef(Q, 56);
	printf_s("队列中元素为：%d\n" , GetLengthf(Q));
	for (int i = 0; i < GetLengthf(Q); i++) {
		printf_s("%d\t", Q.base[i]);
	}
	//printf_s("%d",Q.base[0]);
	while (1);
}