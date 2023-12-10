#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* initQueue(){
	Node* Q=(Node*)malloc(sizeof(Node));
	Q->data=0;
	Q->next=NULL;
	return Q;
} 

void enQueue(Node* Q,int data){
	Node* q=Q; 
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	for(int i=0;i<Q->data;i++){
		q=q->next;
	}
	node->next=q->next;
	q->next=node;
	q->data++;
}

void printQueue(Node* Q){
	Node* node=Q;
	while(node){
		printf("%d-> ",node->data);
		node=node->next;
	}
    printf("NULL\n");
}

int main()
{
	Node* Q=initQueue();
	enQueue(Q,1);
	enQueue(Q,2);
	enQueue(Q,3);
	enQueue(Q,4);
	enQueue(Q,5);
	enQueue(Q,6);
	printQueue(Q);
	return 0;
}