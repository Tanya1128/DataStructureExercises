#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//创建二叉树(遍历二叉树)
//因为C语言中的函数参数传递是按值传递的，
//如果你只传递一个指针作为参数，
//函数内部修改这个指针的值不会影响到函数外部的指针。
void createTree(TreeNode** T,char* data,int* index)  //传入根指针节点
{
	//*取值运算符，&取地址符
	char ch;
	ch = data[*index];
	*index+=1;
	if(ch=='#'){
		//此时为空节点
		*T=NULL;
	}else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		//创建左子树，逻辑一致，进行递归
		createTree(&((*T)->lchild),data,index);
		//创建右子树，逻辑一致，进行递归
		createTree(&((*T)->rchild),data,index);
	}
}

void preOrder(TreeNode* T){
	if(T==NULL){
		return;
	}else{
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void InOrder(TreeNode* T){
	if(T==NULL){
		return;
	}else{
		InOrder(T->lchild);
		printf("%c ",T->data);
		InOrder(T->rchild);
	}
}
void PostOrder(TreeNode* T){
	if(T==NULL){
		return;
	}else{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ",T->data);
	}
}
int main(int argc, char* argv[]){
	TreeNode* T;
	int index=0;
	createTree(&T,argv[1],&index);
	preOrder(T);
	printf("\n");
	InOrder(T);
	PostOrder(T);
	printf("\n");
	return 0;
}