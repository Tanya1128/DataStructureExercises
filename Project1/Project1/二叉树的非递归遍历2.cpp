#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

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
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* ����ʵ�֣�ϸ�ڲ��� */
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, SElementType X);
SElementType Pop(Stack S); /* ɾ����������S��ջ��Ԫ�� */
SElementType Peek(Stack S);/* ������S��ջ��Ԫ�� */
/*----��ջ�Ķ������-----*/

BinTree CreateBinTree(); /* ����ʵ�֣�ϸ�ڲ��� */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreateBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */