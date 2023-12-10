#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
    struct Node* pre;
	struct Node* next;
}Node;

Node* initList(){
	Node* L=(Node*)malloc(sizeof(Node));
	L->data=0;
    L->pre=L;
	L->next=L;//头节点指向自己
	return L;
}

//头插法
void headInsert(Node* L,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
    if(L->data==0){
        //链表为空
        node->pre=L;
        node->next=L->next;
        L->next=node;
        L->pre=node;
    }else{
	    node->next=L->next;
	    node->pre=L;
        L->next->pre=node;
        L->next=node;
    }
	L->data++;
}

void tailInsert(Node* L,int data){
	Node* node=L;
	for(int i=0;i<L->data;i++){
		node=node->next;
	}
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->pre=node;
	n->next=L;
	L->pre=n;
	node->next=n;
	L->data++;
}

int deleteData(Node* L,int data){
	Node* node=L->next;
	while(node!=L){
		if(node->data==data){
			node->pre->next=node->next;
			node->next->pre=node->pre;
			free(node);
			L->data--;
			return 1;
		}
		node=node->next;
	}
	return 0;
}

void printList(Node* L){
	Node* node=L->next;
	while(node!=L){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
}
int main()
{
	Node* L=initList();
	headInsert(L,2);
	headInsert(L,1);
	tailInsert(L,3);
	tailInsert(L,4);
	printList(L);
	deleteData(L,3);
	printList(L);
    return 0;
}