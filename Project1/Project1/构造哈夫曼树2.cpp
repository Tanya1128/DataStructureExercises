#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

using namespace std;
typedef struct {
	int weight;
	int parent;
	int lchild, rchild;
} htnode;
void select(htnode* p, int m, int& s1, int& s2) {
	int j;
	s1 = 0;
	s2 = 0;
	for (j = 1; j <= m; j++) {
		if (p[j].weight <= p[s1].weight && p[j].parent == 0)
			s1 = j;
	}
	for (j = 1; j <= m; j++) {
		if (p[j].weight <= p[s2].weight && p[j].parent == 0 && j != s1)
			s2 = j;
	}
}
using namespace std;
int main() {
	int n, s1, s2, start;
	cin >> n;
	if (n == 0)cout << 0.00000;
	else {
		int m = 2 * n - 1;
		int sum = 0;
		int dig = 0;
		double re;
		string s[n + 1];
		htnode ht[m + 1];
		for (int i = 1; i <= n; i++) {
			ht[i].lchild = 0;
			ht[i].rchild = 0;
			ht[i].parent = 0;
			cin >> s[i];
			scanf(" ");
			cin >> ht[i].weight;
			sum += ht[i].weight;
		}
		for (int j = n + 1; j <= m; j++) {
			ht[j].weight = 0;
			ht[j].parent = 0;
			ht[j].lchild = 0;
			ht[j].rchild = 0;
		}
		ht[0].weight = 100000;
		for (int j = n + 1; j <= m; j++) {
			select(ht, j - 1, s1, s2);
			ht[s1].parent = j;
			ht[s2].parent = j;
			ht[j].lchild = s1;
			ht[j].rchild = s2;
			ht[j].weight = ht[s1].weight + ht[s2].weight;
		}
		for (int i = 1; i <= n; i++) {
			start = 0;
			for (int c = i, f = ht[c].parent; f != 0; c = f, f = ht[c].parent)
				start++;
			dig += ht[i].weight * start;
		}
		re = dig * 1.0 / sum;
		printf("%.5f", re);
	}
}