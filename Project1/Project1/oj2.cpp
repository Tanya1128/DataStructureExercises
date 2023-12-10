#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode {
    int coef;
    int expn;  
    struct PolyNode *next;
}PLink;

void initList(PLink **p);
void create(PLink *p);
void AddPoly(PLink *p1, PLink *P2);
void MulPoly(PLink *p1, PLink *p2);

int main()
{
    PLink *p1, *p2;
    initList(&p1);
    create(p1);
    initList(&p2);
    create(p2);

    MulPoly(p1, p2);
    AddPoly(p1, p2);
    return 0;
}
void initList(PLink **p)
{
    (*p) = (PLink*)malloc(sizeof(PLink));
    (*p)->next = NULL;
}
void create(PLink *p)
{
    int n;
    PLink *r,*s;
    r = p;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        s = (PLink*)malloc(sizeof(PLink));
        scanf("%d%d", &s->coef, &s->expn);
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void AddPoly(PLink *p1, PLink *p2)
{
    PLink *temp,*k0,*K;
    initList(&K);
    k0 = K;

    p1 = p1->next;
    p2 = p2->next;
    while (p1!=NULL && p2!=NULL) {
        temp = (PLink*)malloc(sizeof(PLink));
        if (p1->expn>p2->expn) {
            temp->coef= p1->coef;
            temp->expn = p1->expn;
            p1 = p1->next;
        }else if (p1->expn==p2->expn) {
            if (p1->coef + p2->coef) {
                temp->coef = p1->coef + p2->coef;
                temp->expn = p1->expn;
            }else {
                free(temp);
                p1 = p1->next;
                p2 = p2->next;
                continue;
            }
            p1 = p1->next;
            p2 = p2->next;
        }else {
            temp->coef = p2->coef;
            temp->expn = p2->expn;
            p2 = p2->next;
        }
        if (p1 != NULL || p2!= NULL) {
            k0->next = temp;
            k0 = temp;
        }
    }

    while (p1!=NULL&&p2==NULL) {
        temp = (PLink*)malloc(sizeof(PLink));
        temp->coef = p1->coef;
        temp->expn = p1->expn;

        p1 = p1->next;
        k0->next = temp;
        k0 = temp;
    }

    while (p2 != NULL && p1 == NULL) {
        temp = (PLink*)malloc(sizeof(PLink));
        temp->coef = p2->coef;
        temp->expn = p2->expn;

        p2 = p2->next;
        k0->next = temp;
        k0 = temp;
    }
    k0->next = NULL;

    if (K->next!=NULL) {
        for (temp = K->next; temp != NULL; temp = k0) {
            printf("%d %d", temp->coef, temp->expn);
            if (temp->next!=NULL) {
                printf(" ");
            }
            k0 = temp->next;
            free(temp);
        }
    }
    else {
        printf("0 0");
    }
}

void MulPoly(PLink *p1, PLink *p2)
{
    PLink *q1, *q2;
    PLink *p, *res, *pre;
    initList(&p);

    for (q1 = p1->next; q1 != NULL; q1 = q1->next) {
        for (q2 = p1->next; q2 != NULL; q2 = q2->next) {
            p = (PLink*)malloc(sizeof(PLink));
            p->coef = q1->coef * q2->coef;
            p->expn = q1->expn + q2->expn;

            pre = res;
            while (pre->next != NULL && pre->next->expn > p->expn) {
                pre = pre->next;
            }
            if (pre->next == NULL || pre->next->expn != p->expn) {
                p->next = pre->next;
                pre->next = p;
            }
            else {
                pre->next->coef += p->coef;
                free(p);
            }
        }
    }
    if (res->next!=NULL) {
        for (q1 = res->next; q1 != NULL; q1 = q1->next) {
            if (!q1->coef) {
                printf("%d %d", q1->coef, q1->expn);
                if (q1->next!=NULL) {
                    printf(" ");
                }
            }
            free(q1);
        }
    }
    else {
        printf("0 0");
    }
    free(res);
    printf("\n");
}