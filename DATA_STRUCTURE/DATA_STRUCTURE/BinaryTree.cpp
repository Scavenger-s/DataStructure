#include<stdio.h>
#include<stdlib.h>


//二叉树
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
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//初始化链队列
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, BiTree* elem) {
	QueuePtr q = (QueuePtr)malloc(sizeof(QNode));

	if (!q) {
		printf_s("分配失败");
		return;
	}//分配失败
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
	if (QueueEmpty(Q)) return NULL;//队列为空
	QueuePtr q = Q.front->next;
	BiTree* e = q->data;
	Q.front->next = q->next;
	if (Q.rear == q) Q.rear = Q.front;
	return e;
	free(q);
}
//创建二叉树
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
//前序遍历二叉树
void preTraverse(BiTree *&T) {
	
	if (T != NULL) {
		printf("%d\t-->", T->val);
		preTraverse(T->left);
		preTraverse(T->right);
	}
}
//中序遍历二叉树
void midTraverse(BiTree *&T) {
	if (T != NULL) {
		preTraverse(T->left);
		printf("%d\t-->", T->val);
		preTraverse(T->right);
	}
}
//二叉树后序遍历
void postTraverse(BiTree *&T) {
	if (T != NULL) {
		preTraverse(T->left);
		preTraverse(T->right);
		printf("%d\t-->", T->val);
	}
}
//层次遍历
void levelTraverse(BiTree *&T) {
	LinkQueue Q;
	InitQueue(Q);
	//根节点不为空进队
	if (T != NULL) {
		EnQueue(Q ,T);
	}
	
	//队列不为空
	while (!QueueEmpty(Q)) {
		//出队
		BiTree *q = DeQueue(Q);
		printf("%d\t-->", q->val);
		if(q->left != NULL)
			EnQueue(Q, q->left);
		if(q->left != NULL)
			EnQueue(Q, q->right);
	}

}
//树的高度
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