#include<stdio.h>
#include<stdlib.h>


//������
typedef struct Binary {
	int val;
	struct Binary *right;
	struct Binary *left;
}BiTree;
typedef struct QNode {
	BiTree* data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//��ʼ��������
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, BiTree* elem) {
	QueuePtr q = (QueuePtr)malloc(sizeof(QNode));

	if (!q) {
		printf_s("����ʧ��");
		return;
	}//����ʧ��
	q->data = elem;
	q->next = NULL;
	Q.rear->next = q;
	Q.rear = q;
	//return Q.rear->data;
}
bool QueueEmpty(LinkQueue &Q) {

	return Q.front == Q.rear ? true : false;
}
BiTree* DeQueue(LinkQueue &Q) {
	if (QueueEmpty(Q)) return NULL;//����Ϊ��
	QueuePtr q = Q.front->next;
	BiTree* e = q->data;
	Q.front->next = q->next;
	if (Q.rear == q) Q.rear = Q.front;
	return e;
	free(q);
}
//����������
BiTree*  CreateBinaryTree() {
	int data;
	printf("please input a number ,the number -1 end:");
	scanf_s("%d",&data);
	BiTree * T;
	printf("\n");
	if (data == -1) {
		T = NULL;
	}
	else
	{
		T = (BiTree*)malloc(sizeof(BiTree));
		T->val = data;
		T->left = CreateBinaryTree();
		T->right = CreateBinaryTree();
	}
	return T;
}
//ǰ�����������
void preTraverse(BiTree *&T) {
	
	if (T != NULL) {
		printf("%d\t-->", T->val);
		preTraverse(T->left);
		preTraverse(T->right);
	}
}
//�������������
void midTraverse(BiTree *&T) {
	if (T != NULL) {
		preTraverse(T->left);
		printf("%d\t-->", T->val);
		preTraverse(T->right);
	}
}
//�������������
void postTraverse(BiTree *&T) {
	if (T != NULL) {
		preTraverse(T->left);
		preTraverse(T->right);
		printf("%d\t-->", T->val);
	}
}
//��α���
void levelTraverse(BiTree *&T) {
	LinkQueue Q;
	InitQueue(Q);
	//���ڵ㲻Ϊ�ս���
	if (T != NULL) {
		EnQueue(Q ,T);
	}
	
	//���в�Ϊ��
	while (!QueueEmpty(Q)) {
		//����
		BiTree *q = DeQueue(Q);
		printf("%d\t-->", q->val);
		if(q->left != NULL)
			EnQueue(Q, q->left);
		if(q->left != NULL)
			EnQueue(Q, q->right);
	}

}
//���ĸ߶�
int maxDepth(BiTree *&T) {
	if (T == NULL)
		return 0;
	//int lefth = maxDepth(T->left);
	//int righth = maxDepth(T->right);
	//return lefth > righth ? (lefth + 1) :(righth + 1) ;
	return maxDepth(T->left) > maxDepth(T->right) ?
		maxDepth(T->left) + 1 : maxDepth(T->right) + 1;
}
int main() {
	BiTree *T = CreateBinaryTree();
	
	printf("preorder:\t");
	preTraverse(T);
	printf("\nmidorder:\t");
	midTraverse(T);
	printf("\npostorder:\t");
	postTraverse(T);
	printf("\nlevelorder:\t");
	levelTraverse(T);
	printf("\nthe height is %d\t",maxDepth(T));
	while (1);
	return 0;


}