#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T);
void InorderPrintNodes(BiTree T);

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("Nodes are:");
    InorderPrintNodes(T);
    return 0;
}

void InorderPrintNodes(BiTree T) {
    if (!T)return;
    InorderPrintNodes(T->lchild);
    if ((T->lchild && !T->rchild) || (T->rchild) && !T->lchild)printf(" %c", T->data);
    InorderPrintNodes(T->rchild);
}