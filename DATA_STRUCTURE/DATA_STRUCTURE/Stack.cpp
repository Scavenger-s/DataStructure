#include<stdio.h>
#include<stdlib.h>
//ջ
#define  STACK_ININT_SIZE 10

typedef struct {
	int top;
	int *base;
}SqStack;

//��ʼ��ջ

void InitStack(SqStack &S) {
	S.top = -1;
	S.base = (int *)malloc(sizeof(int)*STACK_ININT_SIZE);
	if (!S.base)return ;//û�з���ɹ�
}

//��ջ
void Push(SqStack &S , int e) {
	S.base[++S.top] = e;
}

//��ջ
int Pop(SqStack &S) {
	return S.base[S.top--];
}

//ȡջ��Ԫ��
int GetTop(SqStack &S) {
	return S.base[S.top];
}

//�Ƿ�ջ��
bool StackEmpty(SqStack &S) {
	return S.top == -1 ? true : false;
}

//��׺���ʽת��׺
void EvaluateExpression(char c[] , SqStack &S1) {
	while (*c != '#') {
		
		
		c++;
	}
}
int main() {
	SqStack S;
	InitStack(S);
	Push(S , 4);
	Push(S, 8);
	printf_s("��ջԪ��Ϊ��%d\n",Pop(S));
	printf_s("ջ�Ƿ�Ϊ�գ�%d",StackEmpty(S));
	while (1);
}