#include<stdio.h>
#include<String.h>
int main()
{
	char ch = getchar();
	int r[5] = { 0 };
	char s1[4] = { '/*','(','[','{' };
	char s2[4] = { '*/',')', ']','}' };

	//char str[30];
	while (fgets()!='.')
	{
		if (ch == '/*') {
			r[0]++;
		}
		if (ch == '*/') {
			r[0]--;
		}

		if (ch == '(') {
			r[1]++;
		}
		if (ch == ')') {
			r[1]--;
		}

		if (ch == '[') {
			r[2]++;
		}
		if (ch == ']') {
			r[2]--;
		}

		if (ch == '{') {
			r[3]++;
		}
		if (ch == '}') {
			r[3]--;
		}

		int cnt = 0;
		int j;
		for (j = 0; j <= 3; j++) {
			if (r[j] == 1) {
				cnt++;
			}
			if (cnt > 1) {
				printf("NO\n");
				printf("%c-?\n", s2[j]);
				return;
			}
		}

		int i;
		for (i = 0; i <= 3; i++) {
			if (r[i] > 1) {
				printf("NO\n");
				printf("%c-?", s1[i]);
				return;
			}
			if (r[i] < 0) {
				printf("NO\n");
				printf("?-%c", s2[i]);
				return;
			}
		}
	}
	printf("YES\n");
	return 0;
}