#include"stdio.h"
#include"stdlib.h"
typedef struct LNode {
	int data;
	struct LNode * next;
}Linklist;
//初始化
void InitLinkList(Linklist *&L) {
    Linklist * head = (Linklist*)malloc(sizeof(Linklist));
	head->next = NULL;
	L = head;
}
//创建链表,头插法
void CreateLinklist(Linklist *&L ,int arr[] , int n) {
	//创建头结点
	Linklist *q = L;
	for (int i = 0; i < n; i++) {
		//创建节点
		Linklist *p = (Linklist*)malloc(sizeof(Linklist));
		p->data = arr[i];
		p->next = q->next;
		q->next = p;
	}
	
}
//尾插法
void CreateRearLinklist(Linklist *&L, int arr[], int n) {
	
	
	Linklist *q = L;
	for (int i = 0; i < n; i++) {
		//创建节点
		Linklist *p = (Linklist*)malloc(sizeof(Linklist));
		p->data = arr[i];
		p->next = q->next;
		q->next = p;
		q = p;
	}
	
}
//按索引插入元素
void InsetByindex(Linklist *&L,int index , int elem) {
	L = L->next;
	for (int i = 1; i < index && L != NULL;i++) {
		L = L->next;
	}
	if (L == NULL)
	{
		printf_s("error");
	}
	else {
		Linklist *p = (Linklist*)malloc(sizeof(Linklist));
		p->data = elem;
		p->next = L->next;
		L->next = p;
	}
}
//按索引输出elem
void DisplayByindex(Linklist *&L ,int index) {
	Linklist *q = L->next;
	int j = 1;
	while (q != NULL && j < index) {
		q = q->next;
		j++;
	}
	int  e = q->next->data;
	printf_s("%d/n" , e);
}
//找到第i位元素
void GetElem(Linklist *&L , int i) {
	int j = 1;
	Linklist *q = L->next;
	while (q != NULL && j < i) {
		q = q->next;
		j++;
	}
	if (q == NULL || j > i)return;//error
	int e = q[j].data;
	printf_s("第%d位元素为%d\n" ,i,e );
}
//插入元素
void ListInset(Linklist *&L , int i ,int e) {
	Linklist *p = L->next;
	int j = 1;
	while (p != NULL && j < i) {
		j++;
		p = p->next;
	}
	if (p == NULL || j > i)return;//error
	Linklist *q = (Linklist *)malloc(sizeof(Linklist));
	q->data = e;
	q->next = p->next;
	p->next = q;
}
//输出
void DisplayLinklist(Linklist *&L) {
	L = L->next;
	while (L!= NULL)
	{
		printf_s("%d\t", L->data);
		L = L->next;
	}
}

int main() {
	
	Linklist *L;
	int arr[] = {6,5,11,22,3,8,99};
	InitLinkList(L);
	//CreateLinklist(L, arr, sizeof(arr) / sizeof(arr[0]));
	CreateRearLinklist(L , arr , sizeof(arr)/sizeof(arr[0]));
	/*
	DisplayLinklist(L);
	printf_s("\n");
	InsetByindex(L , 5 ,1000);*/
	DisplayLinklist(L);
	printf_s("\n");
	//DisplayByindex(L , 5);
	ListInset(L, 5 ,100);
	DisplayLinklist(L);
	//GetElem(L , 5);
	while (true);
	return 0;
}