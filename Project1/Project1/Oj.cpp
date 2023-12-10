#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int coef;
	int expo;
	struct _node* next;
}linkList;

void initList(linkList** l);

void createList(linkList* l);

void mulList(linkList* l1, linkList* l2);

void addList(linkList* l1, linkList* l2);

int main(int argc, char** argv)
{
	linkList* l1, * l2;
	initList(&l1);
	createList(l1);
	initList(&l2);
	createList(l2);
	mulList(l1, l2);
	addList(l1, l2);
	return 0;
}

void
initList(linkList** l)
{
	(*l) = (linkList*)malloc(sizeof(linkList));
	(*l)->next = NULL;
}

void
createList(linkList* l)
{
	int n;
	linkList* tail, * p;
	tail = l;
	scanf("%d", &n);

	while (n-- > 0) {
		p = (linkList*)malloc(sizeof(linkList));
		scanf("%d%d", &p->coef, &p->expo);
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
}

void
mulList(linkList* l1, linkList* l2)
{
	linkList* p1, * p2;
	linkList* result, * pre, * p;
	initList(&result);

	for (p1 = l1->next; p1 != NULL; p1 = p1->next) {
		for (p2 = l2->next; p2 != NULL; p2 = p2->next) {
			p = (linkList*)malloc(sizeof(linkList));
			p->coef = p1->coef * p2->coef;
			p->expo = p1->expo + p2->expo;

			pre = result;
			while (pre->next != NULL && pre->next->expo > p->expo) {
				/*
				** ����result, �ҵ������λ��
				*/
				pre = pre->next;
			}

			if (pre->next == NULL || pre->next->expo != p->expo) {
				/*
				** pre->nextΪNULLʱ, Ԫ��ֵΪ��С, ���������Ϊ��β
				** ���ж�pre->next�Ƿ�ΪNULL���Է�ֹ������ж������ֶԿ�ָ������õĴ���
				*/
				p->next = pre->next;
				pre->next = p;
			}
			else {
				/*
				** ���pre->next->expo����p->expo, ����Ϊͬ����, �ϲ�
				*/
				pre->next->coef += p->coef;
				free(p);
			}
		}
	}

	if (result->next != NULL) {
		/*
		** �����Ϊ�����ʽ, ��ʱresultΪ�ձ�
		*/
		for (p1 = result->next; p1 != NULL; p1 = p2) {
			if (p1->coef != 0) {
				printf("%d %d", p1->coef, p1->expo);
				if (p1->next != NULL) {
					printf(" ");
				}
			}
			p2 = p1->next;
			free(p1);
		}
	}
	else {
		printf("0 0");
	}
	free(result);
	printf("\n");
}

void
addList(linkList* l1, linkList* l2)
{
	linkList* result, * p, * tail;
	initList(&result);
	tail = result;

	l1 = l1->next;
	l2 = l2->next;
	while (l1 != NULL && l2 != NULL) {
		p = (linkList*)malloc(sizeof(linkList));
		if (l1->expo == l2->expo) {
			if (l1->coef + l2->coef) {
				p->coef = l1->coef + l2->coef;
				p->expo = l1->expo;
			}
			else {
				free(p);
				l1 = l1->next;
				l2 = l2->next;
				continue;
				/*
				** ���û��continue, free֮���p����ڱ�β
				*/
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1->expo > l2->expo) {
			p->coef = l1->coef;
			p->expo = l1->expo;
			l1 = l1->next;
		}
		else {
			p->coef = l2->coef;
			p->expo = l2->expo;
			l2 = l2->next;
		}
		if (l1 != NULL || l2 != NULL) {
			tail->next = p;
			tail = p;
		}
	}

	while (l1 != NULL && l2 == NULL) {
		/*
		** ������Ҫ�ж�, ���������߶�Ϊ��ָ��ʱ�Կ�ָ�������
		*/
		p = (linkList*)malloc(sizeof(linkList));
		p->coef = l1->coef;
		p->expo = l1->expo;
		l1 = l1->next;
		tail->next = p;
		tail = p;
	}

	while (l2 != NULL && l1 == NULL) {
		p = (linkList*)malloc(sizeof(linkList));
		p->coef = l2->coef;
		p->expo = l2->expo;
		l2 = l2->next;
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;

	if (result->next != NULL) {
		for (p = result->next; p != NULL; p = tail) {
			printf("%d %d", p->coef, p->expo);
			if (p->next != NULL) {
				printf(" ");
			}
			tail = p->next;
			free(p);
		}
	}
	else {
		printf("0 0");
	}
}

