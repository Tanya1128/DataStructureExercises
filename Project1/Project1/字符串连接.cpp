#include<stdio.h>
#include "stdio.h"

void fun(char s1[80], char s2[40]);
int main()
{
	char str1[80], str2[40];
	gets_s(str1); 
	gets_s(str2);
	fun(str1, str2);
	puts(str1);
	return 0;
}
void fun(char s1[80], char s2[40])
{
	int i;
	for (i = 0; s1[i] != '\0'; ++i);
	for (int j = 0; s2[j] != '\0'; ++j) {
		s1[i] = s2[j];
		i++;
	}
}

/*
void fun(char s1[80], char s2[40]) {
	char* p = s1;
	char* q = s2;
	while (*p != '\0') {
		p++;
	}
	while (*q != '\0') {
		*p = *q;
		p++;
		q++;
	}
	*p = '\0';
}
*/