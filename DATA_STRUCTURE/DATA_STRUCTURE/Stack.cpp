#include<stdio.h>
#include<stdlib.h>
//栈
#define  STACK_ININT_SIZE 10

typedef struct {
	int top;
	int *base;
}SqStack;

//初始化栈

void InitStack(SqStack &S) {
	S.top = -1;
	S.base = (int *)malloc(sizeof(int)*STACK_ININT_SIZE);
	if (!S.base)return ;//没有分配成功
}

//入栈
void Push(SqStack &S , int e) {
	S.base[++S.top] = e;
}

//出栈
int Pop(SqStack &S) {
	return S.base[S.top--];
}

//取栈顶元素
int GetTop(SqStack &S) {
	return S.base[S.top];
}

//是否栈空
bool StackEmpty(SqStack &S) {
	return S.top == -1 ? true : false;
}

//中缀表达式转后缀
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
	printf_s("出栈元素为：%d\n",Pop(S));
	printf_s("栈是否为空：%d",StackEmpty(S));
	while (1);
}