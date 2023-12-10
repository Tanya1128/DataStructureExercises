#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 11
#define N 10
typedef char ElemType;
typedef struct   // 顺序循环队列结点定义
{
    ElemType* name[MaxSize];   //小孩姓名
    int front, rear;        //队首和队尾指针
} SqQueue;
void InitQueue(SqQueue*& q);   //初始化队列；
void DestroyQueue(SqQueue*& q);  //销毁队列；
bool QueueEmpty(SqQueue* q);  //判定队列为空时返回true; 否则返回false;
bool enQueue(SqQueue*& q, ElemType* e);  // e 入队；成功入队返回true; 否则返回false;
bool deQueue(SqQueue*& q, ElemType*& e);  //出队，返回出队元素e，且成功出队返回true,否则返回false;

int main()
{
    ElemType* e;
    int n, i;
    SqQueue* q;
    InitQueue(q);
    scanf("%d", &n);
    while (1)
    {
        char* name = (char*)malloc(sizeof(char) * N);
        scanf("%s", name);
        if ((strcmp("-1", name) == 0) || enQueue(q, name))
            break;
    }
    i = n - 1;
    while (QueueEmpty(q))
    {
        deQueue(q, e);
        if (i-- > 0)
            enQueue(q, e);
        else
        {
            printf("%s\n", e);
            i = n - 1;
            free(e);
        }
    }
    DestroyQueue(q);
}
void InitQueue(SqQueue*& q) {
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void DestroyQueue(SqQueue*& q) {
    free(q);
}

bool QueueEmpty(SqQueue* q) {
    return q->front == q->rear;
}

bool enQueue(SqQueue*& q, ElemType* e) {
    if ((q->rear + 1) % MaxSize == q->front) {
        return false;
    }
    q->name[q->rear] = e;
    q->rear = (q->rear + 1) % MaxSize;
    return true;
}

bool deQueue(SqQueue*& q, ElemType*& e) {
    if (q->front == q->rear) {
        return false;
    }
    e = q->name[q->front];
    q->front = (q->front + 1) % MaxSize;
    return true;
}