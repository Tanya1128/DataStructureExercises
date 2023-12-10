#include <stdio.h>
#include <string.h>

int a[30];
int b[30][100007];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[100007];
        int k;
        scanf("%s %d", s, &k);

        if (k == 1) {
            printf("1\n");
            continue;
        }

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        int lens = strlen(s);

        for (int i = 0; i < lens; i++) {
            b[s[i] - 'a'][a[s[i] - 'a']++] = i;
        }

        int maxa = 0;

        for (int i = 0; i < 26; i++) {
            maxa = maxa > a[i] ? maxa : a[i];
        }

        if (maxa < k) {
            printf("-1\n");
            continue;
        }

        int ans = 100007;

        for (int i = 0; i < 26; i++) {
            if (a[i] >= k) {
                for (int j = 0; j < a[i]; j++) {
                    if (b[i][j + k - 1] != 0)
                        ans = ans < b[i][j + k - 1] - b[i][j] + 1 ? ans : b[i][j + k - 1] - b[i][j] + 1;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}