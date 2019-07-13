//ѭ������
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZEE 5
//����һ��Ԫ��
typedef struct {
	int *base;
	int front;
	int rear;
}SqQueue;
//��ʼ������
void InitQueue(SqQueue &Q) {
	
	Q.base = (int *)malloc(sizeof(int)*MAXSIZEE);
	if (!Q.base)return;//����ʧ��*/
	Q.front = Q.rear = 0;
}
//����
void EnQueue(SqQueue &Q , int elem) {
	if ((Q.rear + 1) % MAXSIZEE == Q.front)  return;//����
	Q.base[Q.rear] = elem;
	Q.rear = (Q.rear + 1) % MAXSIZEE;
	
}

bool SqQueueEmpty(SqQueue &Q) {
	return Q.front == Q.rear ? true : false;
}
//����
void Dequeue(SqQueue &Q) {
	if (SqQueueEmpty(Q)) return;//����Ϊ�շ���
	int e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZEE;
	printf_s("%d\t ����",e);
}

//���г���
int GetLength(SqQueue &Q) {
	return (Q.rear - Q.front + MAXSIZEE) % MAXSIZEE;
}

//flag ����
typedef struct {
	int *base;
	int front;
	int rear;
	bool flag;
}SqQueuef;

//��ʼ������
void InitQueuef(SqQueuef &Q) {

	Q.base = (int *)malloc(sizeof(int)*MAXSIZEE);
	if (!Q.base)return;//����ʧ��*/
	Q.front = Q.rear = 0;
	Q.flag = false;
}

//����
void EnQueuef(SqQueuef &Q, int elem) {
	
	if (Q.flag && Q.rear == Q.front)return;//����
	Q.flag = true;
	Q.base[Q.rear] = elem;
	Q.rear = (Q.rear + 1) ;
}

//����
void Dequeuef(SqQueuef &Q) {
	
	if (!Q.flag && Q.front == Q.rear) return;//����Ϊ�շ���
	Q.flag = false;
	int e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZEE;
	printf_s("%d\t ����", e);
}

//���г���
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
	printf_s("������Ԫ��Ϊ��%d\n" , GetLengthf(Q));
	for (int i = 0; i < GetLengthf(Q); i++) {
		printf_s("%d\t", Q.base[i]);
	}
	//printf_s("%d",Q.base[0]);
	while (1);
}