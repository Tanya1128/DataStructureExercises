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
    int nodes;
    if (T) {
        nodes = 1 + NodeCount(T->Left) + NodeCount(T->Right);
        return nodes;
    }
    else {
        return 0;
    }
}