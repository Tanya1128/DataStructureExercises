#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char* StrRemove(char* str, int idx, int len);

int main()
{
    char a[1024];
    int i, n;
    gets(a);
    scanf("%d%d", &i, &n);
    StrRemove(a, i, n);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrRemove(char* str, int idx, int len) {
    int strlength = strlen(str);
    if (idx < 0 || idx >= strlength) {
        return str;
    }
    if (len < 0) {
        len = 0;
    }
    else if (len > strlength - idx) {
        len = strlength - idx;
    }
    memmove(str + idx, str + idx + len, strlength - idx - len + 1);
    return str;
}