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
/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode* PtrToSNode;
struct SNode {
    SElementType data;
    PtrToSNode next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
int IsEmpty(Stack S);
Stack Push(Stack& S, SElementType X);
SElementType Pop(Stack& S); /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S);/* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

void CreateBiTree(BinTree& T); /* 裁判实现，细节不表 */
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