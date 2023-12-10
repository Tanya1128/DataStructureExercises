#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXQSIZE 100//���п��ܴﵽ����󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct {
    char name[20]; //����
    char sex; //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
} Person;
//- - - - - ���е�˳��洢�ṹ- - - - - 
typedef struct {
    Person* data;
    int front; //ͷָ��
    int rear; //βָ��
} Queue;
typedef Queue* SqQueue;
SqQueue Mdancers, Fdancers; //�ֱ�����ʿ��Ůʿ����߶���
int InitQueue(SqQueue& Q);
void DestroyQueue(SqQueue& q);
int QueueLen(SqQueue Q);//���г��� 
int EnQueue(SqQueue& Q, Person e);//������� 
int QueueEmpty(SqQueue& Q);//�����Ƿ�Ϊ�� 
int DeQueue(SqQueue& Q, Person& e);//������ 
void DancePartner(Person dancer[], int num); //������ 
int main() {
    int i;
    int n;
    Person dancer[2 * MAXQSIZE];
    cin >> n;
    for (i = 0; i < n; i++) cin >> dancer[i].name >> dancer[i].sex;
    InitQueue(Mdancers); //��ʿ���г�ʼ��
    InitQueue(Fdancers); //Ůʿ���г�ʼ��
    cout << "The dancing partners are:" << endl;
    DancePartner(dancer, n);
    if (!QueueEmpty(Fdancers)) {
        cout << "F:" << QueueLen(Fdancers);
    }
    else if (!QueueEmpty(Mdancers)) {
        cout << "M:" << QueueLen(Mdancers);
    }
    DestroyQueue(Fdancers);
    DestroyQueue(Mdancers);
    return 0;
}
int InitQueue(SqQueue& Q) {//����һ���ն���Q
    Q = (SqQueue)malloc(sizeof(Queue));
    Q->data = (Person*)malloc(MAXQSIZE * sizeof(Person)); //Ϊ���з���һ���������ΪMAXSIZE������ռ�
    if (!Q->data)
        exit(OVERFLOW); //�洢����ʧ��
    Q->front = Q->rear = 0; //ͷָ���βָ����Ϊ�㣬����Ϊ��
    return OK;
}
void DestroyQueue(SqQueue& q)
{
    delete q;
}
int QueueLen(SqQueue Q) {
    return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}
//���г��� 
int EnQueue(SqQueue& Q, Person e) {
    if ((Q->rear + 1) % MAXQSIZE == Q->front) {
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}
//������� 
int QueueEmpty(SqQueue& Q) {
    return Q->front == Q->rear;
}//�����Ƿ�Ϊ�� 
int DeQueue(SqQueue& Q, Person& e) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}//������ 
void DancePartner(Person dancer[], int num) {
    for (int i = 0; i < num; i++) {
        if (dancer[i].sex == 'F') {
            EnQueue(Fdancers, dancer[i]);
        }
        else {
            EnQueue(Mdancers, dancer[i]);
        }
    }
    Person p1, p2;
    while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {
        DeQueue(Fdancers, p1);
        DeQueue(Mdancers, p2);
        printf("%s  %s\n", p1.name, p2.name);
    }
} 
