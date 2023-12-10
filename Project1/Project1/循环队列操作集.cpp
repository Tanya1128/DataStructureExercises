#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct _queue
{
    int front;//��ͷָ��
    int rear;//��βָ��
    int* data;//ָ��������
}queue;

//����һ���ն���
queue* createQueue();
//���
void enQueue(queue* q, int x);
//�ж϶����Ƿ�����
bool isFull(queue* q);
//����
void deQueue(queue* q);
//�õ���ͷԪ�ص�ֵ
int front(queue* q);
//�ж϶����Ƿ�Ϊ��
bool isEmpty(queue* q);
//���ض��г���
int size(queue* q);
//���ٶ���
void destroyQueue(queue* q);
//��0��λ�ÿ�ʼ���������������Ԫ�ء���Чλ�����'X'
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

//��0��λ�ÿ�ʼ���������������Ԫ�ء���Чλ�����'X'
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

/* ����������д�� */
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
