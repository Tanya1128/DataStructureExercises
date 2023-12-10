//二叉树的非递归遍历
//前序+中序
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef struct StackNode{
    TreeNode* data;
    struct StackNode* next;
}StackNode;

//创建二叉树
void createTree(TreeNode** T,char* data,int* index){
    char ch;
    ch=data[*index];
    *index+=1;
    if(ch=='#'){
        //此时为空
        *T=NULL;
    }else{
        //此时不为空
        *T=(TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        //创建左子树，逻辑一致，进行递归
        createTree(&(*T)->lchild,data,index);
        //创建右子树，逻辑一致，进行递归
        createTree(&(*T)->rchild,data,index);
    }
}

//写一个初始化栈的函数
StackNode* initStack(){
    StackNode* S=(StackNode*)malloc(sizeof(StackNode));
    S->data=NULL;
    S->next=NULL;
    return S;
}
//入栈
void push(TreeNode* data,StackNode* S){
    //头插法
    StackNode* node=(StackNode*)malloc(sizeof(StackNode));
    node->data=data;
    node->next=S->next;
    S->next=node;
}

int isEmpty(StackNode* S){
    if(S->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

StackNode* pop(StackNode* S){
    if(isEmpty(S)){
        return NULL;
    }else{
        StackNode* node=S->next;
        S->next=node->next;
        return node;
    }
}

void preOrder(TreeNode* T){
    TreeNode* node=T;
    StackNode* S=initStack();
    while(node||!isEmpty(S)){
        if(node){
            printf("%c ",node->data);
            push(node,S);
            node=node->lchild;
        }else{
            //出栈的是StackNode类型的元素，->data才是TreeNode类型的叶子节点，仔细看一下前面定义的结构体
            node=pop(S)->data;
            node=node->rchild;
        }
    }
}

void inOrder(TreeNode* T){
    TreeNode* node=T;
    StackNode* S=initStack();
    while(node||!isEmpty(S)){
        if(node){
            push(node,S);
            node=node->lchild;
        }else{
            node=pop(S)->data;
            printf("%c ",node->data);
            node=node->rchild;
        }
    }
}

int main(int argc,char* argv[])
{
    TreeNode* T;
    int index=0;
    createTree(&T,argv[1],&index);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    return 0;
}