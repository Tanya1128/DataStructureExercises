#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct _queue
{
    int front;//队头指针
    int rear;//队尾指针
    int* data;//指向数据区
}queue;

//创建一个空队列
queue* createQueue();
//入队
void enQueue(queue* q, int x);
//判断队列是否已满
bool isFull(queue* q);
//出队
void deQueue(queue* q);
//得到队头元素的值
int front(queue* q);
//判断队列是否为空
bool isEmpty(queue* q);
//返回队列长度
int size(queue* q);
//销毁队列
void destroyQueue(queue* q);
//从0号位置开始输出数据区的所有元素。无效位置输出'X'
void show(queue* q);

int main(void)
{
    char cmd[20];
    queue* pQueue = createQueue();
    int x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") == 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            if (isFull(pQueue) == true)
            {
                printf("FULL\n");
            }
            else
            {
                scanf("%d", &x);
                enQueue(pQueue, x);
            }
        }
        if (strcmp(cmd, "DEQUEUE") == 0)
        {
            if (isEmpty(pQueue) == true)
            {
                printf("EMPTY\n");
            }
            else
            {
                deQueue(pQueue);
            }
        }
        if (strcmp(cmd, "GETFRONT") == 0)
        {
            x = front(pQueue);
            printf("%d\n", x);
        }
        if (strcmp(cmd, "SIZE") == 0)
        {
            printf("SIZE = %d\n", size(pQueue));
        }
        if (strcmp(cmd, "SHOW") == 0)
        {
            show(pQueue);
        }
        scanf("%s", cmd);
    }
    destroyQueue(pQueue);
    return 0;
}

//从0号位置开始输出数据区的所有元素。无效位置输出'X'
void show(queue* q)
{
    if (q->front == q->rear)
        return;
    if (q->front < q->rear)
    {
        for (int i = 0; i < q->front; i++)
        {
            printf("X ");
        }
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
        for (int i = q->rear; i < MAXSIZE; i++)
        {
            printf("X ");
        }
    }
    else
    {
        for (int i = 0; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
        for (int i = q->rear; i < q->front; i++)
        {
            printf("X ");
        }
        for (int i = q->front; i < MAXSIZE; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    printf("\n");
}

/* 请在这里填写答案 */
queue* createQueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->data = (int*)malloc(MAXSIZE * sizeof(int));
    q->front = 0;
    q->rear = 0;
    return q;
}
void enQueue(queue* q, int x)
{

    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAXSIZE;

}
bool isFull(queue* q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}
void deQueue(queue* q)
{
    q->front = (q->front + 1) % MAXSIZE;

}
int front(queue* q)
{
    return q->data[q->front];
}
bool isEmpty(queue* q)
{
    return q->front == q->rear;


}
int size(queue* q)
{
    return ((q->rear - q->front) + MAXSIZE) % MAXSIZE;
}
void destroyQueue(queue* q)
{
    free(q);
    q->front = 0;
    q->rear = 0;
}
