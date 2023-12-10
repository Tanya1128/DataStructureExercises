#include <stdio.h>

char* StrCpy(char* dst, const char* src);

int main()
{
    char a[1024], b[1024];
    gets_s(a);
    StrCpy(b, a);
    puts(b);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrCpy(char* dst, const char* src)
{
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char* p = dst;
    while ((*p++ = *src++) != '\0');
    return dst;
}