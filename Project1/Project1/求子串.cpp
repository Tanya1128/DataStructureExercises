#include <stdio.h>
#include <string.h>

char* StrMid(char* dst, const char* src, int idx, int len);

int main()
{
    char a[128], b[128];
    int s, n;
    gets_s(a);
    scanf("%d%d", &s, &n);
    StrMid(b, a, s, n);
    puts(b);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrMid(char* dst, const char* src, int idx, int len) {
    if (idx < 0 || len <= 0) {
        dst[0] = '\0';
    }
    else {
        int srclength = strlen(src);
        if (idx >= srclength) {
            idx = srclength - 1;
        }
        if (idx + len > srclength) {
            len = srclength - idx;
        }
        strncpy(dst, src + idx, len);
        dst[len] = '\0';
    }
    return dst;
}