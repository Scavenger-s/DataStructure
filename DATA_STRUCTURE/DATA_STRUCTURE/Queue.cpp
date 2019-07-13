#include<stdio.h>
#include<stdlib.h>
                              
//节点类型
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode , *QueuePtr;

typedef struct {
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//初始化链队列
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q ,int elem) {
	QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
	
	if (!q) {
		printf_s("分配失败");
		return;
	}//分配失败
	q->data = elem;
	q->next = NULL;
	Q.rear->next = q;
	Q.rear = q;
	printf_s("入队元素为：%d\n",Q.rear->data);
}
bool QueueEmpty(LinkQueue &Q) {

	return Q.front == Q.rear ? true : false;
}
void DeQueue(LinkQueue &Q) {
	if (QueueEmpty(Q)) return;//队列为空
	QueuePtr q = Q.front->next;
	int e = q->data;
	Q.front->next =q->next;
	if (Q.rear == q) Q.rear = Q.front;
	printf_s("出队元素为：%d\n", e);
	free(q);
}

//得到队首元素
void GetFrontElem(LinkQueue &Q) {
	QueuePtr q = Q.front->next;
	printf_s("队首元素为%d：\n",q->data);
}

int main() {
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q, 3);
	EnQueue(Q, 5);
	DeQueue(Q);
	DeQueue(Q);
	EnQueue(Q, 150);
	GetFrontElem(Q);
	while (1);
}