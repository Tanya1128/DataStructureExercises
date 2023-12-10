#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	for (int i = 0; i < t; i++) {
		int flag = 0;
		char s[50];
		scanf("%s", s);
		getchar();
		int len = strlen(s);
		int k,t=0,cnt,r=0;
		scanf("%d", &k);
		getchar();
		while (t<len) {
			cnt = 0;
			for (int j = t + 1; j < len; j++) {
				if (s[j] == s[t]) {
					cnt++;
				}
				if (cnt == k) {
					r = j;
					break;
				}
			}
			if (cnt == k) {
				flag = 1;
				printf("%d\n", r - t + 1);
				break;
			}
			t++;
		}
		if (flag == 0) {
			printf("-1\n");
		}
	}
	return 0;
}