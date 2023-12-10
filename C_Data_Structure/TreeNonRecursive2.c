//二叉树的非递归遍历
//后序：多一个指针用来判断右子树有没有被访问过
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int flag;//falg=0时是初始状态
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
        (*T)->flag=0;
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

//获取栈顶元素
StackNode* getTop(StackNode* S){
    if(isEmpty(S)){
        return NULL;
    }else{
        StackNode* node=S->next;
        return node;
    }
}

void postOrder(TreeNode* T){
    //先把根节点的值接过来
    TreeNode* node=T;
    StackNode* S=initStack();
    while (node||!isEmpty(S))
    {
        if(node){
            push(node,S);
            node=node->lchild;
        }else{
            TreeNode* top=getTop(S)->data;
            if(top->rchild&&top->rchild->flag==0){
                top=top->rchild;
                push(top,S);
                node=top->lchild;
            }else{
                top=pop(S)->data;
                printf("%c ",top->data);
                //同时还要标记一下
                top->flag=1;
            }
        }
    }
    
}

int main(int argc,char* argv[])
{
    TreeNode* T;
    int index=0;
    createTree(&T,argv[1],&index);
    postOrder(T);
    printf("\n");
    return 0;
}