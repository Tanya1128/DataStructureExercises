#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
void CreateBinTree(BinTree& T); /* ʵ��ϸ�ں��� */
int LeafCount(BinTree T);

int main()
{
    BinTree  BT;
    CreateBinTree(BT);
    printf("%d\n", LeafCount(BT));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
int LeafCount(BinTree T)
{
    int count;
    if (T == NULL) {
        count = 0;
    }
    else if (T->Left == NULL && T->Right == NULL) {
        count = 1;
    }
    else {
        count = LeafCount(T->Left) + LeafCount(T->Right);
    }
    return count;
}