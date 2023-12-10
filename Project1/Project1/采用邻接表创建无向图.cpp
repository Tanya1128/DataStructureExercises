#include <stdio.h>
#include <stdlib.h>
#define MVNum 100 

//定义边结点
typedef struct ArcNode {
    int adjvex; //邻接点域：指示域顶点V邻接的点在图中的位置,就是该边所指向的顶点的位置
    struct ArcNode* nextarc;//链域：指示与顶点V邻接的下一条边的结点，就是下一条边的指针
    int info;//数据域：存储和边相关的信息，如权值等
}ArcNode;//边表：由表示图中顶点间关系的2n个边链表组成

//定义顶点结点信息
typedef struct VNode {
    char data;//数据域：用于存储顶点V的名称或其他有关信息
    ArcNode* firstarc;//链域：用于指向链表中第一个结点（即与顶点V邻接的第一个邻接点）
    //也可以理解为指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum];  //表头结点表：由所有表头结点以顺序结构的形式存储

//定义邻接表的结构
typedef struct {
    VNode vertices[MVNum];
    int vexnum, arcnum;
}ALGraph; 

void CreateUDG(ALGraph& G)
{
    scanf("%d %d", &G.vexnum, &G.arcnum);
    getchar();//把scanf生成的回车读走，避免被当作字符
    for (int i = 0; i < G.vexnum; i++) {
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;//初始化
    }
    getchar();
    char e1, e2;
    for (int k = 0; k < G.arcnum; k++) {
        scanf("%c %c", &e1, &e2);
        int x, y;
        for (int j = 0; j < G.vexnum; j++) {
            if (G.vertices[j].data == e1) {
                x = j;
            }
            if (G.vertices[j].data == e2) {
                y = j;
            }
        }
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = y;//顶点
        //头插法
        p->nextarc = G.vertices[x].firstarc;
        G.vertices[x].firstarc = p;
        //由于是无向图，所以也要考虑另一个顶点
        ArcNode* q = (ArcNode*)malloc(sizeof(ArcNode));
        q->adjvex = x;

        q->nextarc = G.vertices[y].firstarc;
        G.vertices[y].firstarc = q;
        getchar();
    }
}

int main() {
    ALGraph G;
    int i, j, sum = 0;
    CreateUDG(G);
    ArcNode* p;
    for (i = 0; i < G.vexnum; ++i) {
        sum = 0;
        p = G.vertices[i].firstarc;
        for (; p != NULL; p = p->nextarc) {
            sum += 1;
        }
        if (i == 0)
            printf("%d", sum);
        else
            printf(" %d", sum);
    }
    return 0;
}