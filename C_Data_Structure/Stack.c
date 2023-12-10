#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initStack(){
    Node* S=(Node*)malloc(sizeof(Node));
    S->data=0;
    S->next=NULL;
    return S;
}

int isEmpty(Node* S){
    if(S->data==0||S->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

int getTop(Node* S){
    if(isEmpty(S)){
        return -1;
    }else{
        return S->next->data;//第一个节点的data域
    }
}

int pop(Node* S){
    if(isEmpty(S)){
        return -1;
    }
    else{
        Node* node=S->next;
        S->next=node->next;
        int data=node->data;
        free(node);
        return data;
    }

}
//入栈
void push(Node* S,int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=S->next;
    S->next=node;
    S->data++;
}

//遍历栈
void printStack(Node* S){
    Node* node=S->next;
    while(node){
        printf("%d-> ",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main()
{
    Node* L=initStack();
    push(L,1);
    push(L,2);
    push(L,3);
    push(L,4);
    push(L,5);
    printStack(L);
    int i=pop(L);
    printf("current pop elem is %d\n",i);
    printStack(L);
    return 0;
};
