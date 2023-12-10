#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef int Status;
typedef char SElemType;

typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue& Q, QElemType e);
Status DeQueue(LinkQueue& Q, QElemType& e);

int main() {
    LinkQueue Q;
    int n, m, i;
    char c;
    InitQueue(Q);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> c;
        EnQueue(Q, c);
    }
    for (i = 0; i < n; i++) {
        DeQueue(Q, c);
    }
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> c;
        EnQueue(Q, c);
    }
    for (i = 0; i < m; i++) {
        DeQueue(Q, c);
        cout << c << " ";
    }
    return 0;
}
/* 请在这里填写答案 */
Status EnQueue(LinkQueue& Q, QElemType e) {
    QueuePtr p;
    p = new QNode;
    p->data = e;
    p->next = NULL;

    Q.rear->next = p
        ;

    Q.rear = p
        ;
    return OK;
}


Status DeQueue(LinkQueue& Q, QElemType& e) {
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    e = p->data;

    Q.front->next = p->next
        ;
    if (Q.rear == p)

        Q.rear = Q.front
        ;
    delete p;
    return OK;
}
