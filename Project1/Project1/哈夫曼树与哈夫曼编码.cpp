#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bitree {
	int data;
	char name;
	char route[20];
	struct Bitree* left;
	struct Bitree* right;
}*bintree, bitnode;

typedef struct Pri_que {
	bintree elem;
	struct Pri_que* next;
}*pri_que, p_node;

void push(pri_que prque, bintree elem) {
	pri_que front = prque;
	prque = prque->next;
	while (prque && elem->data > prque->elem->data) {
		front = prque;
		prque = prque->next;
	}
	pri_que newNode = (pri_que)malloc(sizeof(p_node));
	newNode->elem = elem;
	front->next = newNode;
	newNode->next = prque;
}

bintree top(pri_que prque) {
	return prque->next->elem;
}

void pop(pri_que prque) {
	prque->next = prque->next->next;
}

int getSize(pri_que prque) {
	int size = 0;
	prque = prque->next;
	while (prque) {
		prque = prque->next;
		size++;
	}
	return size;
}

void cat(bintree parent, bintree left, bintree right) {
	parent->left = left;
	parent->right = right;
}

bintree build(bintree leaves, int n) {
	pri_que prque = (pri_que)malloc(sizeof(p_node));
	prque->next = NULL;
	for (int i = 0; i < n; i++) {
		push(prque, &leaves[i]);
	}
	while (getSize(prque) > 1) {
		bintree left_child = top(prque);
		pop(prque);
		bintree right_child = top(prque);
		pop(prque);
		bintree parent = (bintree)malloc(sizeof(bitnode));
		parent->data = left_child->data + right_child->data;
		parent->route[0] = '\0';
		cat(parent, left_child, right_child);
		push(prque, parent);
	}
	return top(prque);
}

int getWPL_tool(bintree branch) {
	if (branch == NULL)return 0;
	return getWPL_tool(branch->left) + getWPL_tool(branch->right) + branch->data;
}

int getWPL(bintree root) {
	if (root == NULL)return 0;
	return getWPL_tool(root->left) + getWPL_tool(root->right);
}

void update_route(bintree root) {
	if (root == NULL)return;
	if (root->left) {
		strcpy(root->left->route, root->route);
		int len = strlen(root->left->route);
		root->left->route[len] = '0';
		root->left->route[len + 1] = '\0';
		update_route(root->left);
	}
	if (root->right) {
		strcpy(root->right->route, root->route);
		int len = strlen(root->right->route);
		root->right->route[len] = '1';
		root->right->route[len + 1] = '\0';
		update_route(root->right);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	bitnode leaves[n];

	for (int i = 0; i < n; i++) {
		scanf("%c", &leaves[i].name);
		leaves[i].route[0] = '\0';
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &leaves[i].data);
		leaves[i].left = leaves[i].right = NULL;
	}

	bintree root = build(leaves, n);

	int WPL = getWPL(root);
	printf("%d\n", WPL);

	update_route(root);
	for (int i = 0; i < n; i++) {
		printf("%c:%s\n", leaves[i].name, leaves[i].route);
	}

	return 0;
}