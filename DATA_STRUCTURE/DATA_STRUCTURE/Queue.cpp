#include<stdio.h>
#include<stdlib.h>
                              
//�ڵ�����
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode , *QueuePtr;

typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//��ʼ��������
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q ,int elem) {
	QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
	
	if (!q) {
		printf_s("����ʧ��");
		return;
	}//����ʧ��
	q->data = elem;
	q->next = NULL;
	Q.rear->next = q;
	Q.rear = q;
	printf_s("���Ԫ��Ϊ��%d\n",Q.rear->data);
}
bool QueueEmpty(LinkQueue &Q) {

	return Q.front == Q.rear ? true : false;
}
void DeQueue(LinkQueue &Q) {
	if (QueueEmpty(Q)) return;//����Ϊ��
	QueuePtr q = Q.front->next;
	int e = q->data;
	Q.front->next =q->next;
	if (Q.rear == q) Q.rear = Q.front;
	printf_s("����Ԫ��Ϊ��%d\n", e);
	free(q);
}

//�õ�����Ԫ��
void GetFrontElem(LinkQueue &Q) {
	QueuePtr q = Q.front->next;
	printf_s("����Ԫ��Ϊ%d��\n",q->data);
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