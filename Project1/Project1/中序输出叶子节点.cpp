#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T);
void InorderPrintLeaves(BiTree T);
int main() {
    BiTree T;
    CreateBiTree(T);
    printf("Leaf nodes are:");
    InorderPrintLeaves(T);
    return 0;
}
void InorderPrintLeaves(BiTree T) {
    if (T == NULL) return;
    InorderPrintLeaves(T->lchild);
    if (T->lchild == NULL && T->rchild == NULL)
        printf(" %c", T->data);
    InorderPrintLeaves(T->rchild);
}
