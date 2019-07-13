#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#define MAXSIZE 10
#define ADDSIZE 10
//Sqlist�ṹ��
typedef struct {
	int *pre;
	int length;
	int listsize;
}Sqlist;
 //��ʼ��
void InitSqlist(Sqlist &L) {
	//��ʼ������
	L.length = 0;
	L.pre = (int *)malloc(sizeof(int) * MAXSIZE);
	if (!L.pre) return;//�����ڴ�ʧ��
	//��ʼ������
	L.listsize = MAXSIZE;
}
//����
void CreateSqlist(Sqlist &L, int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (L.length >= L.listsize) {

			L.pre = (int *)realloc(L.pre, ADDSIZE* sizeof(int));
			L.listsize += ADDSIZE ;
			printf_s("�ڴ治�������ڴ棬L.listsize = %d\n", L.listsize);
			if (!L.pre) return;//�����ڴ�ʧ��
		}
	    L.pre[i] = arr[i];
	    L.length++;
	}
	
}
//����Ԫ��
void InsertElen(Sqlist &L , int i ,int elem) {
	if (i < 1 || i>L.length+1)
		return;//iֵ���Ϸ�
	i--;
	for (int m = L.length - 1; m >= i; m--) {
		L.pre[m + 1] = L.pre[m];
	}
	L.pre[i] = elem;
	L.length++;
}
//ɾ��Ԫ��
void DeleteIelem(Sqlist &L,int i) {
	if (i<1 || i>L.length+1)
		return;//iֵ���Ϸ�
	i--;
	for (int k = i; k < L.length;k++) {
		L.pre[k] = L.pre[k+1];
		
	}
	L.length--;
	
}
//��ֵ����
int LocateElem(Sqlist &L ,int e) {
	for (int i = 0; i < L.length-1; i++) {
		if (L.pre[i] == e)
			return i + 1;
	}
}
//���
void DisplaySqlist(Sqlist &L) {
	for (int i = 0; i < L.length; i++)
		printf_s("a[%d]=%d\n",i,L.pre[i]);
	printf_s("length = %d\n", L.length);
}

//�ϲ���
void Union(Sqlist &LA , Sqlist &LB , Sqlist &LC) {
	int *pa = LA.pre;
	int *pb = LB.pre;
	//����lc������
	LC.listsize = LA.length + LB.length;
	//����
	LC.length = LC.listsize;
	LC.pre  = (int*)malloc(sizeof(int)*LC.listsize);
	int *pc = LC.pre;
	if (!pc)return;//�����ڴ�ʧ��
	int *pa_last = pa + LA.length - 1;
	int *pb_last = pb + LB.length - 1;
	//����
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb){
			*pc++ = *pa++;
		}
			
		else {
			*pc++ = *pb++;
		}
		
	}
	//����ʣ��Ԫ��
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
	     
	
