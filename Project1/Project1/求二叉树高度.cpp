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
int GetHeight(BinTree BT);

int main()
{
    BinTree  BT;
    CreateBinTree(BT);
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
int GetHeight(BinTree BT)
{
    int HL, HR, MaxH;
    if (BT) {
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        MaxH = HL > HR ? HL : HR;
        return (MaxH + 1);
    }
    else {
        return 0;
    }
}