#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char c[81];
	scanf("%d", &n);
	getchar();
	while (n--) {
		gets(c);
		int len = strlen(c);
		int num = 0, cha = 0, other = 0, dot = 0;
		if (len < 6) {
			printf("Your password is tai duan le.\n");
			continue;
		}
		else
			for (int i = 0; i < len; i++) {
				if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')	cha++;
				else if (c[i] >= '0' && c[i] <= '9')	num++;
				else if (c[i] == '.')	dot++;
				else	other++;
			}
		if (other > 0) printf("Your password is tai luan le.\n");
		else if (cha != 0 && num == 0) 	printf("Your password needs shu zi.\n");
		else if (cha == 0 && num != 0)	printf("Your password needs zi mu.\n");
		else	printf("Your password is wan mei.\n");
	}
	return 0;
}
