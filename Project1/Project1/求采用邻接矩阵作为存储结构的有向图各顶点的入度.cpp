#include <stdio.h>
#define MVNum 100                 //��󶥵��� 
typedef struct {
    char vexs[MVNum];           //��Ŷ����һά���� 
    int arcs[MVNum][MVNum];     //�ڽӾ��� 
    int vexnum, arcnum;          //ͼ�ĵ�ǰ�������ͻ��� 
}MGraph;
void indegree(MGraph G)
{
    int cnt = 0;
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            if (G.arcs[j][i] == 1) {
                cnt++;
            }
        }
        printf("%c:%d\n", G.vexs[i], cnt);
        cnt = 0;
    }
}
void CreatMGraph(MGraph* G);/* ����ͼ */
int main()
{
    MGraph G;
    CreatMGraph(&G);
    indegree(G);
    return 0;
}
void CreatMGraph(MGraph* G)
{
    int i, j, k;
    scanf("%d%d", &G->vexnum, &G->arcnum);
    getchar();
    for (i = 0; i < G->vexnum; i++)
        scanf("%c", &G->vexs[i]);
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j] = 0;
    for (k = 0; k < G->arcnum; k++)
    {
        scanf("%d%d", &i, &j);
        G->arcs[i][j] = 1;
    }
}
