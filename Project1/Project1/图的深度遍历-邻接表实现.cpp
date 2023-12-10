#include"stdio.h"
#include"stdlib.h"
#define MAX_VERTEX_NUM 10      /*������󶥵���*/
typedef int Vertex;
typedef struct  ArcNode {       /*����*/
    int adjvex;               /*�ڽӵ���*/
    struct  ArcNode* nextarc; /*ָ����һ������*/
}ArcNode;
typedef struct VNode {           /*ͷ���*/
    Vertex data;                  /*������*/
    ArcNode* firstarc;          /*ָ���һ������*/
}VNode, AdjList[MAX_VERTEX_NUM]; /*AdjList����������*/
typedef struct {
    AdjList vertices;           /*�ڽӱ������鶨��*/
    int vexnum, arcnum;          /*ͼ�е�ǰ�������ͱ���*/
} ALGraph;                 /*ͼ����*/
typedef enum { FALSE, TRUE } Boolean;
Boolean visited[MAX_VERTEX_NUM];/*�����־������Ϊȫ�ֱ���*/
void CreatALGraph(ALGraph* G);/* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */
void DFS(ALGraph* G, int v){
    ArcNode* pre;
    visited[v] = TRUE;
    printf(" %d", v);
    for (pre = G->vertices[v].firstarc; pre != NULL;pre=pre->nextarc) {
        if (visited[pre->adjvex] == FALSE) {
            DFS(G, pre->adjvex);
        }
    }
}
int main()
{
    Vertex v;
    ALGraph G;
    CreatALGraph(&G);
    scanf("%d", &v);
    printf("DFS from %d:", v);
    DFS(&G, v);
    return 0;
}