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
void CreateBinTree(BinTree& T); /* 实现细节忽略 */
int NodeCount(BinTree T);

int main()
{
    BinTree  BT;
    CreateBinTree(BT);
    printf("%d\n", NodeCount(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
int NodeCount(BinTree T)
{
    if (T) {
        if (T->Left && T->Right) {
            return 1 + NodeCount(T->Left) + NodeCount(T->Right);
        }
        else if (T->Left && !T->Right) {
            return NodeCount(T->Left);
        }
        else if (!T->Left && T->Right) {
            return NodeCount(T->Right);
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}