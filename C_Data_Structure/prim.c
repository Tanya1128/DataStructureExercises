//最小生成树prim算法
#include<stdio.h>
#include<stdlib.h>

//这里用的是无向带权图
// 如果图顶点之间不通，那么邻接矩阵的值为MAX
//如果顶点是自己本身，那么值为0

#define MAX 32767

typedef struct Graph{
    char* vexs; //图的顶点；
    int** arcs;//图的边  二级指针存的是一级指针的值
    int vexNum;
    int arcNum;
}Graph;

//为prim算法定义一个数据结构
typedef struct Edge{
    char vex;//元素
    int weight;//权值；
}Edge;

//从index这个顶点开始找最小生成树
//当edge.weight=0时，代表顶点加入到U集合中
Edge* initEdge(Graph* G,int index){
    Edge* edge=(Edge*)malloc(sizeof(Edge)*G->vexNum);
    for(int i=0;i<G->vexNum;i++){
        edge[i].vex=G->vexs[index];
        edge[i].weight=G->arcs[index][i];
    }
    return edge;
}
//找到最小边，然后把相应的顶点加入U集合中去
int getMinEdge(Edge* edge,Graph* G){
    int index;
    int min=MAX;
    for(int i=0;i<G->vexNum;i++){
        if(edge[i].weight!=0&&min>edge[i].weight){
            min=edge[i].weight;
            index=i;
        }
    }
    return index;
}

void prim(Graph* G,int index){
    int min;
    Edge* edge=initEdge(G,index);
    //要找n个顶点，已经加入了一个，所以还要遍历n-1次
    for(int i=0;i<G->vexNum-1;i++){
        min=getMinEdge(edge,G);
        printf("v%c ---> v%c,weight = %d \n",edge[min].vex,G->vexs[min],edge[min].weight);
        edge[min].weight=0;
        for(int j=0;j<G->vexNum;j++){
            if(G->arcs[min][j]<edge[j].weight){
                edge[j].weight=G->arcs[min][j];
                edge[j].vex=G->vexs[min];
            }
        }
    }
}
Graph* initGraph(int vexNum){
    Graph* G=(Graph*)malloc(sizeof(Graph));
    G->vexs=(char*)malloc(sizeof(char)*vexNum);
    G->arcs=(int**)malloc(sizeof(int*)*vexNum);
    for(int i=0;i<vexNum;i++){
        G->arcs[i]=(int*)malloc(sizeof(int)*vexNum);
    }
    G->vexNum=vexNum;
    G->arcNum=0;
    return G; 
}

void createGraph(Graph* G,char* vexs,int* arcs){
    for(int i=0;i<G->vexNum;i++){
        G->vexs[i]=vexs[i];
        for(int j=0;j<G->vexNum;j++){
            G->arcs[i][j]=*(arcs+i*G->vexNum+j);
            if(G->arcs[i][j]!=0&&G->arcs[i][j]!=MAX){
                G->arcNum++;
            }
        }
        G->arcNum/=2;  //无向图
    }
}

//留一个DFS用来判断图是否初始化成功
void DFS(Graph* G, int* visited,int index){
    printf("%c\t",G->vexs[index]);
    visited[index]=1;
    for(int i=0;i<G->vexNum;i++){
        if(G->arcs[index][i]>0 && G->arcs[index][i] != MAX &&!visited[i]){
            DFS(G,visited,i);
        }
    }
}

int main()
{
    Graph* G=initGraph(6);
    int* visited =(int*)malloc(sizeof(int)*G->vexNum);
    for(int i=0;i<G->vexNum;i++){
        visited[i]=0;
    }
    int arcs[6][6]={
        0,6,1,5,MAX,MAX,
        6,0,5,MAX,3,MAX,
        1,5,0,5,6,4,
        5,MAX,5,0,MAX,2,
        MAX,3,6,MAX,0,6,
        MAX,MAX,4,2,6,0,
    };
    createGraph(G,"123456",(int*)arcs);
    DFS(G,visited,0);
    printf("\n"); 
    prim(G,0); //假设从第一个节点开始
    return 0;
}