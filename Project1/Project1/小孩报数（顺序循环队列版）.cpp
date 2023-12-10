#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 11
#define N 10
typedef char ElemType;
typedef struct   // ˳��ѭ�����н�㶨��
{
    ElemType* name[MaxSize];   //С������
    int front, rear;        //���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue*& q);   //��ʼ�����У�
void DestroyQueue(SqQueue*& q);  //���ٶ��У�
bool QueueEmpty(SqQueue* q);  //�ж�����Ϊ��ʱ����true; ���򷵻�false;
bool enQueue(SqQueue*& q, ElemType* e);  // e ��ӣ��ɹ���ӷ���true; ���򷵻�false;
bool deQueue(SqQueue*& q, ElemType*& e);  //���ӣ����س���Ԫ��e���ҳɹ����ӷ���true,���򷵻�false;

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