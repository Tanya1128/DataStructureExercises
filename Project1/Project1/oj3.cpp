#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct sqlist {
	int* elem;
	int length;
	int maxsize;
} *list;

void initlist(list L) {
	L->elem = (int*)malloc(max * sizeof(int));
	L->length = 0;
	L->maxsize = max;
}

void addlist(list L, int num, int i) {
	if (i<1 || i>L->length + 1) {
		printf("Î»ÖÃ´íÎó\n");
		return;
	}
	if (L->length == L->maxsize) {
		L->elem = (int*)realloc(L->elem, ((L->length + max) * sizeof(int)));
		L->maxsize += max;
	}
	for (int j = L->length; j >= i; j--) {
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i - 1] = num;
	L->length++;
}

void print(list L) {
	for (int i = 0; i < L->length; i++) {
		if (i == L->length - 1){
			printf("%d", L->elem[i]);
		}
		else {
			printf("%d ", L->elem[i]);
		}
	}
}
int main()
{
	list a = (list)malloc(sizeof(list));
	list b = (list)malloc(sizeof(list));
	list c = (list)malloc(sizeof(list));
	initlist(a);
	initlist(b);
	initlist(c);
	int num;
	while (1) {
		scanf("%d", &num);
		if (num == -1) {
			break;
		}
		addlist(a, num, a->length + 1);
	}

	while (1) {
		scanf("%d", &num);
		if (num == -1) {
			break;
		}
		addlist(b, num, b->length + 1);
	}

	int i = 0;
	int j = 0;
	while (i < a->length || j < b->length) {
		if (i == a->length || b->elem[j] < a->elem[i]) {
			addlist(c, b->elem[j], c->length + 1);
			j++;
		}
		else {
			addlist(c, a->elem[i], c->length + 1);
			i++;
		}
	}
	if (c->length == 0) {
		printf("NULL\n");
	}
	else {
		print(c);
	}
	return 0;
}