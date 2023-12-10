#include<stdio.h>
#include<stdlib.h>

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

//所以牺牲了一个空间用于区分队空和队满的条件，队满的条件则相应变更为Q.rear==(Q.rear+1)%maxsize
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

void printQueue(Queue* Q){
    //要知道当前队列有多少个元素
    int length=(Q->rear-Q->front+MAXSIZE)%MAXSIZE;
    int index=Q->front;
    for(int i=0;i<length;i++){
        printf("%d-> ",Q->data[index]);
        index=(index+1)%MAXSIZE;
    }
    printf("NULL\n");
}
int main()
{
    Queue* Q=initQunue();
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    enQueue(Q,4);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    return 0;
}