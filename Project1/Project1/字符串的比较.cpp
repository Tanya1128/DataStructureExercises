#include <stdio.h>

int StrCmp(const char* str1, const char* str2);

int main()
{
    char a[1024], b[1024];
    int r;
    gets_s(a);
    gets_s(b);
    r = StrCmp(a, b);
    if (r > 0)
    {
        puts("a > b");
    }
    else if (r < 0)
    {
        puts("a < b");
    }
    else
    {
        puts("a == b");
    }
    return 0;
}

/* 你提交的代码将被嵌在这里 */
int StrCmp(const char* str1, const char* str2)
{
    int i;
    for (i = 0; str1[i] != '\0'||str2[i] != '\0'; i++) {
        if (str1[i] + '26' > str2[i] + '26') {
            return 1;
        }
        else if (str1[i] + '26' < str2[i] + '26') {
            return -1;
        }
    }
    if (str1[i]!='\0') {
        return 1;
    }
    if (str2[i] != '\0') {
        return -1;
    }
    return 0;
}