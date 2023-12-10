#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* initList(){
	Node* L=(Node*)malloc(sizeof(Node));
	L->data=0;
	L->pre=NULL;
	L->next=NULL;
	return L;
}

void headInsert(Node* L,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	
	//需要完成四个指针的改变
	if(L->data==0){
        //L->next->pre=node;
	    node->next=L->next;//node->next指向L->next
        node->pre=L;
	    L->next=node;
	}
	//当链表中没有节点（也就是只有头节点）时
	//此时只需要涉及到头节点指针和新节点的pre指针的改变
	else{
		node->pre=L;
		node->next=L->next;
        L->next->pre=node;
        L->next=node;
		L->data++;//头节点记录的链表长度+1
	}
}

int deleteData(Node* L,int data){
	Node* node=L->next;
	while(node){
		if(node->data==data){
			if(node->next==NULL){
			    node->pre->next=NULL;
		    }else{
			    node->pre->next=node->next;
			    node->next->pre=node->pre;
			    free(node);
			    L->data--;
				return TRUE;
		    }
		}
		node=node->next;
	}
	return FALSE;
}

void tailInsert(Node* L,int data){
	Node* node=L;
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	while(node->next){
		node=node->next;
	}
	n->next=node->next;//n->next指向node->next
	node->next=n;
	n->pre=node;
	L->data++;
}


void printList(Node* L){
	Node* node=L->next;
	while(node){
		printf("%d ->",node->data);
		node=node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* L= initList();
	headInsert(L,3);
	headInsert(L,2);
	headInsert(L,1);
	tailInsert(L,4);
	tailInsert(L,5);
	printList(L);
	deleteData(L,1);
    deleteData(L,5);
	printList(L);
	return 0;
}