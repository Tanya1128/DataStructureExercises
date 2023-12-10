#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};
/*------��ջ�Ķ���-------*/
typedef Position SElementType;
typedef struct SNode* PtrToSNode;
struct SNode {
    SElementType data;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

/* ����ʵ�֣�ϸ�ڲ��� */
Stack CreateStack();
int IsEmpty(Stack S);
Stack Push(Stack& S, SElementType X);
SElementType Pop(Stack& S); /* ɾ����������S��ջ��Ԫ�� */
SElementType Peek(Stack S);/* ������S��ջ��Ԫ�� */
/*----��ջ�Ķ������-----*/

void CreateBiTree(BinTree& T); /* ����ʵ�֣�ϸ�ڲ��� */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main()
{
    BinTree BT;
    CreateBiTree(BT);
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    return 0;
}

void InorderTraversal(BinTree BT)
{
    if (BT != NULL) {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}
void PreorderTraversal(BinTree BT)
{
    if (BT != NULL) {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal(BinTree BT)
{
    if (BT != NULL) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}