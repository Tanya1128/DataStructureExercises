#include <stdio.h>
#include <stdlib.h>
#define MVNum 100 

//����߽��
typedef struct ArcNode {
    int adjvex; //�ڽӵ���ָʾ�򶥵�V�ڽӵĵ���ͼ�е�λ��,���Ǹñ���ָ��Ķ����λ��
    struct ArcNode* nextarc;//����ָʾ�붥��V�ڽӵ���һ���ߵĽ�㣬������һ���ߵ�ָ��
    int info;//�����򣺴洢�ͱ���ص���Ϣ����Ȩֵ��
}ArcNode;//�߱��ɱ�ʾͼ�ж�����ϵ��2n�����������

//���嶥������Ϣ
typedef struct VNode {
    char data;//���������ڴ洢����V�����ƻ������й���Ϣ
    ArcNode* firstarc;//��������ָ�������е�һ����㣨���붥��V�ڽӵĵ�һ���ڽӵ㣩
    //Ҳ�������Ϊָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum];  //��ͷ���������б�ͷ�����˳��ṹ����ʽ�洢

//�����ڽӱ�Ľṹ
typedef struct {
    VNode vertices[MVNum];
    int vexnum, arcnum;
}ALGraph; 

void CreateUDG(ALGraph& G)
{
    scanf("%d %d", &G.vexnum, &G.arcnum);
    getchar();//��scanf���ɵĻس����ߣ����ⱻ�����ַ�
    for (int i = 0; i < G.vexnum; i++) {
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;//��ʼ��
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
        p->adjvex = y;//����
        //ͷ�巨
        p->nextarc = G.vertices[x].firstarc;
        G.vertices[x].firstarc = p;
        //����������ͼ������ҲҪ������һ������
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