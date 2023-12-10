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
#define MAXSIZE 100 // 最大栈容量

typedef int ElemType; // 栈元素类型定义

// 定义顺序栈结构体
typedef struct {
    ElemType* base; // 栈底指针
    ElemType* top; // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack* S) {
    S->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    S->top = S->base;
}

// 入栈操作
void Push(SqStack* S, ElemType e) {
    *(S->top) = e;
    S->top++;
}

// 出栈操作
void Pop(SqStack* S, ElemType* e) {
    if (S->top == S->base) {
        return;
    }
    S->top--;
    *e = *(S->top);
}

// 判断栈是否为空
int IsEmpty(SqStack* S) {
    return S->top == S->base;
}

// 十进制转二进制
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

void StackInitiate(SeqStack *S)             /*初始化顺序堆栈S*/
{    S->top = 0;                         /*定义初始栈顶下标值*/
}

int StackNotEmpty(SeqStack S)
/*判顺序堆栈S非空否，非空则返回1，否则返回0*/
{
    if (S.top <= 0)  return 0;
    else return 1;
}

int StackPush(SeqStack* S, int* x)
/*把数据元素值x压入顺序堆栈S，入栈成功则返回1，否则返回0 */
{
    if (S->top >= MaxStackSize)
    {
        printf("堆栈已满无法插入! \n");
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
/*弹出顺序堆栈S的栈顶数据元素值到参数d ，出栈成功则返回1，否则返回0*/
{
    if (S->top <= 0)
    {
        //printf("堆栈已空无数据元素出栈! \n");
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
/*取顺序堆栈S的当前栈顶数据元素值到参数d ，成功则返回1，否则返回0*/
{
    if (S->top <= 0)
    {
        printf("堆栈已空! \n");
        return 0;
    }
    else
    {
        *d = S->stack[S->top - 1];
        return 1;
    }
}
//提示：十进制数值转换成二进制使用辗转相除法将一个十进制数值转换成二进制数值。即用该十进制数值除以2，并保留其余数；
//重复此操作，直到该十进制数值为0为止。最后将所有的余数反向输出就是所对应的二进制数值
void f(int s)//输入十进制数为s
{
    SeqStack* S = (SeqStack*)malloc(sizeof(SeqStack));

    //由于之前定义函数的时候使用了返回0/1的操作，所以需要用一个i来存这个元素，事实上，如果上面函数如果选择void可以不用这个没用的一步 
    //t、q是接下来的两个需要用的参数 
    int t, i, q;
    //入栈 
    while (s != 0)
    {
        t = s % 2;
        s = s / 2;
        i = StackPush(S, &t);
        if (i == 0)	return;
    }
    //出栈输出 
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