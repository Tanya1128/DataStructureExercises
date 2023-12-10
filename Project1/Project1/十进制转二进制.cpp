#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct Node {
    int data;
    int pre;
    int next;
}node;
int main()
{
    node str[100005];
    int i, n, ID, temp;
    scanf("%d%d", &ID, &n);
    for (i = 0; i < n; i++)
    {
        int ID1, num, next;
        scanf("%d%d%d", &ID1, &num, &next);
        str[ID1].data = num;
        str[ID1].next = next;
        if (next != -1)
            str[next].pre = ID1;
        if (next == -1)
        {
            temp = ID1;
        }
    }
    for (;;)
    {
        printf("%05d %d ", temp, str[temp].data);
        if (temp == ID)
        {
            printf("-1\n");
            break;
        }
        else
            printf("%05d\n", ID);
        temp = str[temp].pre;
        printf("%05d %d ", ID, str[ID].data);
        if (ID == temp)
        {
            printf("-1\n");
            break;
        }
        else
            printf("%05d\n", temp);
        ID = str[ID].next;
    }
    return 0;
}













#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100 // ���ջ����

typedef int ElemType; // ջԪ�����Ͷ���

// ����˳��ջ�ṹ��
typedef struct {
    ElemType* base; // ջ��ָ��
    ElemType* top; // ջ��ָ��
} SqStack;

// ��ʼ��ջ
void InitStack(SqStack* S) {
    S->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    S->top = S->base;
}

// ��ջ����
void Push(SqStack* S, ElemType e) {
    *(S->top) = e;
    S->top++;
}

// ��ջ����
void Pop(SqStack* S, ElemType* e) {
    if (S->top == S->base) {
        return;
    }
    S->top--;
    *e = *(S->top);
}

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(SqStack* S) {
    return S->top == S->base;
}

// ʮ����ת������
void DecToBin(int decimal) {
    SqStack S;
    InitStack(&S);

    while (decimal) {
        Push(&S, decimal % 2);
        decimal /= 2;
    }

    if (IsEmpty(&S)) {
        printf("0\n");
    }
    else {
        while (!IsEmpty(&S)) {
            int bin;
            Pop(&S, &bin);
            printf("%d", bin);
        }
        printf("\n");
    }
}

int main() {
    int decimal;
    scanf("%d", &decimal);

    DecToBin(decimal);

    return 0;
}


/*
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxStackSize 1000
typedef struct
{
    int stack[MaxStackSize];
    int top;
}SeqStack;

void StackInitiate(SeqStack *S)             /*��ʼ��˳���ջS*/
{    S->top = 0;                         /*�����ʼջ���±�ֵ*/
}

int StackNotEmpty(SeqStack S)
/*��˳���ջS�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
    if (S.top <= 0)  return 0;
    else return 1;
}

int StackPush(SeqStack* S, int* x)
/*������Ԫ��ֵxѹ��˳���ջS����ջ�ɹ��򷵻�1�����򷵻�0 */
{
    if (S->top >= MaxStackSize)
    {
        printf("��ջ�����޷�����! \n");
        return 0;
    }
    else
    {
        S->stack[S->top] = *x;
        S->top++;
        return 1;
    }
}

int StackPop(SeqStack* S, int* d)
/*����˳���ջS��ջ������Ԫ��ֵ������d ����ջ�ɹ��򷵻�1�����򷵻�0*/
{
    if (S->top <= 0)
    {
        //printf("��ջ�ѿ�������Ԫ�س�ջ! \n");
        return 0;
    }
    else
    {
        S->top--;
        *d = S->stack[S->top];
        return 1;
    }
}

int StackTop(SeqStack* S, int* d)
/*ȡ˳���ջS�ĵ�ǰջ������Ԫ��ֵ������d ���ɹ��򷵻�1�����򷵻�0*/
{
    if (S->top <= 0)
    {
        printf("��ջ�ѿ�! \n");
        return 0;
    }
    else
    {
        *d = S->stack[S->top - 1];
        return 1;
    }
}
//��ʾ��ʮ������ֵת���ɶ�����ʹ��շת�������һ��ʮ������ֵת���ɶ�������ֵ�����ø�ʮ������ֵ����2����������������
//�ظ��˲�����ֱ����ʮ������ֵΪ0Ϊֹ��������е��������������������Ӧ�Ķ�������ֵ
void f(int s)//����ʮ������Ϊs
{
    SeqStack* S = (SeqStack*)malloc(sizeof(SeqStack));

    //����֮ǰ���庯����ʱ��ʹ���˷���0/1�Ĳ�����������Ҫ��һ��i�������Ԫ�أ���ʵ�ϣ�������溯�����ѡ��void���Բ������û�õ�һ�� 
    //t��q�ǽ�������������Ҫ�õĲ��� 
    int t, i, q;
    //��ջ 
    while (s != 0)
    {
        t = s % 2;
        s = s / 2;
        i = StackPush(S, &t);
        if (i == 0)	return;
    }
    //��ջ��� 
    while (S)
    {
        if (!StackPop(S, &q))	return;
        printf("%d", q);
    }
}
void main()
{
    SeqStack* myS = (SeqStack*)malloc(sizeof(SeqStack));
    StackInitiate(myS);
    f(555);
}
*/