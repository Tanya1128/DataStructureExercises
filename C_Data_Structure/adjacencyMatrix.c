//图的创建（邻接矩阵）和遍历（BFS和DFS）
#include<stdio.h>
#include<stdlib.h>

typedef struct Graph{
    char* vexs; //图的顶点；
    int** arcs;//图的边  二级指针存的是一级指针的值
    int vexNum;
    int arcNum;
}Graph;

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
            if(G->arcs[i][j]!=0){
                G->arcNum++;
            }
        }
        G->arcNum/=2;  //无向图
    }
}

//图的遍历的两种方法：BFS和DFS（深度优先遍历）
//BFS：1.找一个节点访问，2.找这个节点可以访问的节点，3.重复第一步，直到所有节点访问完毕
//和二叉树的层次遍历有点像 

void DFS(Graph* G, int* visited,int index){
    printf("%c\t",G->vexs[index]);
    visited[index]=1;
    for(int i=0;i<G->vexNum;i++){
        if(G->arcs[index][i]==1&&!visited[i]){
            DFS(G,visited,i);
        }
    }
}

//BFS
#define MAXSIZE 5
typedef struct Queue
{
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQunue(){
    Queue* Q=(Queue*)malloc(sizeof(Queue));
    Q->front=Q->rear=0;
    return Q;
}

int isFull(Queue* Q){
    if((Q->rear+1)%MAXSIZE==Q->rear){
        return 1;
    }else{
        return 0;
    }
}

//入队
int enQueue(Queue* Q,int data){
    if(isFull(Q)){
        return 0;
    }else{
        //data是数组，rear是数值，data[rear]就是数组的第rear-1个元素
        Q->data[Q->rear]=data;
        //此处取余是考虑了入队后刚好为满的情况，如果不取余，rear会＞MAXSIZE
        Q->rear=(Q->rear+1)%MAXSIZE;
        return 1;
    }
}

int isEmpty(Queue* Q){
    if(Q->rear==Q->front){
        return 1;;
    }else{
        return 0;
    }
}

int deQueue(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    }else{
        //因为data[]是结构体Queue中的一个数组，因此Q->rear就是队尾指针所处位置
        //也是下一个元素的下标，因此是把data赋给Q指向的data[]
        int data=Q->data[Q->front];
        Q->front=(Q->front+1)%MAXSIZE;
        return data;
    }
}

void BFS(Graph* G, int* visited,int index){
    Queue* Q=initQunue();
    printf("%c\t",G->vexs[index]);
    visited[index]=1;
    enQueue(Q,index);
    while(!isEmpty(Q)){
        int i=deQueue(Q);
        for(int j=0;j<G->arcs[index][j]==1&&!visited[j]){
            if(G->arcs[i][j]==1&&!visited[j]){
                printf("%c\t",G->vexs[j]);
                visited[j]=1;
                enQueue(Q,j);
            }
        }
    }
}
int main()
{
    Graph* G=initGraph(5);
    int* visited =(int*)malloc(sizeof(int)*G->vexNum);
    for(int i=0;i<G->vexNum;i++){
        visited[i]=0;
    }
    int arcs[5][5]={
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0,
    };
    createGraph(G,"ABCDE",(int*)arcs);
    DFS(G,visited,0);
    printf("\n"); 
    BFS(G,visited,0);
    printf("\n");
    return 0;
}