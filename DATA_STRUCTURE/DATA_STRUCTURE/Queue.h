#pragma once
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;
void InitQueue(LinkQueue &Q);