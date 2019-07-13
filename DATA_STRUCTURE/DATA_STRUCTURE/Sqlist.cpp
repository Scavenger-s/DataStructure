#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#define MAXSIZE 10
#define ADDSIZE 10
//Sqlist结构体
typedef struct {
	int *pre;
	int length;
	int listsize;
}Sqlist;
 //初始化
void InitSqlist(Sqlist &L) {
	//初始化长度
	L.length = 0;
	L.pre = (int *)malloc(sizeof(int) * MAXSIZE);
	if (!L.pre) return;//分配内存失败
	//初始化容量
	L.listsize = MAXSIZE;
}
//创建
void CreateSqlist(Sqlist &L, int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (L.length >= L.listsize) {

			L.pre = (int *)realloc(L.pre, ADDSIZE* sizeof(int));
			L.listsize += ADDSIZE ;
			printf_s("内存不够增加内存，L.listsize = %d\n", L.listsize);
			if (!L.pre) return;//分配内存失败
		}
	    L.pre[i] = arr[i];
	    L.length++;
	}
	
}
//插入元素
void InsertElen(Sqlist &L , int i ,int elem) {
	if (i < 1 || i>L.length+1)
		return;//i值不合法
	i--;
	for (int m = L.length - 1; m >= i; m--) {
		L.pre[m + 1] = L.pre[m];
	}
	L.pre[i] = elem;
	L.length++;
}
//删除元素
void DeleteIelem(Sqlist &L,int i) {
	if (i<1 || i>L.length+1)
		return;//i值不合法
	i--;
	for (int k = i; k < L.length;k++) {
		L.pre[k] = L.pre[k+1];
		
	}
	L.length--;
	
}
//按值查找
int LocateElem(Sqlist &L ,int e) {
	for (int i = 0; i < L.length-1; i++) {
		if (L.pre[i] == e)
			return i + 1;
	}
}
//输出
void DisplaySqlist(Sqlist &L) {
	for (int i = 0; i < L.length; i++)
		printf_s("a[%d]=%d\n",i,L.pre[i]);
	printf_s("length = %d\n", L.length);
}

//合并表
void Union(Sqlist &LA , Sqlist &LB , Sqlist &LC) {
	int *pa = LA.pre;
	int *pb = LB.pre;
	//计算lc的容量
	LC.listsize = LA.length + LB.length;
	//长度
	LC.length = LC.listsize;
	LC.pre  = (int*)malloc(sizeof(int)*LC.listsize);
	int *pc = LC.pre;
	if (!pc)return;//分配内存失败
	int *pa_last = pa + LA.length - 1;
	int *pb_last = pb + LB.length - 1;
	//遍历
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb){
			*pc++ = *pa++;
		}
			
		else {
			*pc++ = *pb++;
		}
		
	}
	//遍历剩余元素
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last) {
		*pc++ = *pb++;
	}
}
int main() {
	int arr[] = {1 , 2 , 3 , 9  , 8 ,10 ,11 ,2 ,3,4,6,7,8,9};
	Sqlist LA ,LB , LC;
	InitSqlist(LA);
	InitSqlist(LB);
	InitSqlist(LC);
	int arr2[] = {100 ,3 ,4, 6,7 ,8};
	CreateSqlist(LA , arr , sizeof(arr)/sizeof(arr[0]));
	CreateSqlist(LB, arr2, sizeof(arr2) / sizeof(arr2[0]));
	//DeleteIelem(LA ,5);
	DisplaySqlist(LA);
	printf_s("LB:\n");
	DisplaySqlist(LB);
	Union(LA, LB, LC);
	printf_s("LC:\n");
	DisplaySqlist(LC);
	//printf_s("%d", LocateElem(LA, 10));
	while (1);
}
	     
	
