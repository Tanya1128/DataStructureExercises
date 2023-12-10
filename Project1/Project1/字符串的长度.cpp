#include <stdio.h>

int StrLen(const char* str);

int main()
{
    char s[1024];
    int n;
    gets(s);
    n = StrLen(s);
    printf("%d\n", n);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
int StrLen(const char* str)
{
    int cnt=0;
    for (int i = 0; str[i] != '\0'; i++) {
        cnt++;
    }
    return cnt;
}