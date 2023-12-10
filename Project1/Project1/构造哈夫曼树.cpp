#include<iostream>
#include<string>
#include<string.h>
using namespace std;

#define MAX 9999999

typedef struct
{
	string data;
	int weight;
	int parent, lchild, rchild;
}HTNode,* HuffmanTree;

typedef char** HuffmanCode;

void Select(HuffmanTree& HT, int top, int* m1, int* m2)
{
	int min = MAX;
	for (int i = 1; i <= top; ++i) {
		if (HT[i].weight < min && HT[i].parent == 0) {
			min = HT[i].weight;
			*m1 = i;
		}
	}
	min = MAX;
	for (int i = 1; i <= top; ++i) {
		if (HT[i].weight < min && i != *m1 && HT[i].parent == 0) {
			min = HT[i].weight;
			*m2 = i;
		}
	}
}
void createHuffmanTree(HuffmanTree& HT, int n) {
	if (n == 0) return;
	HT = new HTNode[2 * n];
	for (int i = 1; i < 2 * n; ++i) {
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> HT[i].data >> HT[i].weight;
	}

	int m1, m2;
	for (int i = n + 1; i < 2 * n; ++i) {
		Select(HT, i - 1, &m1, &m2);
		HT[i].weight = HT[m1].weight + HT[m2].weight;
		HT[m1].parent = i;
		HT[m2].parent = i;
		HT[i].lchild = m1;
		HT[i].rchild = m2;
	}
}

void HuffmanCoding(HuffmanTree ht, char** hc, int n) {
	char* cd = new char[n];
	cd[n - 1] = '\0';
	int now = 1;
	int p = 0, start, i = 0;
	while (i < n) {
		start = n - 1;
		now = i + 1;
		p = ht[now].parent;
		while (p != 0) {
			start--;
			if (ht[p].lchild == now) {
				cd[start] = '0';
			}
			else {
				cd[start] = '1';
			}
			now = p;
			p = ht[now].parent;
		}
		hc[i] = new char[n - start];
		strcpy(hc[i], &cd[start]);
		i++;
	}
	delete[] cd;
}

int main()
{

	return 0;
}