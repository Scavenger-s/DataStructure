#pragma once
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;
void InitQueue(LinkQueue &Q);