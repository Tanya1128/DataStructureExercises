#include <stdio.h>
#include <string.h>
int main() {
    int n, i = 0, m, flag = 0, k = 0, flag2 = 0, flag4 = 0, flag3 = 0;
    char s[100];
    scanf("%d", &n);
    getchar();
    while (n--) {
        gets_s(s);
        m = strlen(s);
        if (m >= 6 && m <= 16) {
            for (i = 0; i < m; i++) {
                if (s[0] >= 'A' && s[0] <= 'Z') {
                    flag = 1;
                }
                if (s[i] >= 'a' && s[i] <= 'z') {
                    flag2 = 1;
                }
                if (s[i] == '@' || s[i] == '%' || s[i] == '#' || s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '$') {
                    flag3 = 1;
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    flag4 = 1;
                }
            }
        }
        if (flag != 1 || flag4 != 1 || flag2 != 1 || flag3 != 1)
            printf("No\n");
        else
            printf("Yes\n");
        flag = 0;
        flag2 = 0;
        flag3 = 0;
        flag4 = 0;
    }
    return 0;
}
