#include <stdio.h>

char* StrChr(char* str, char chr);

int main()
{
    char s[1024], x, * p;
    gets_s(s);
    x = getchar();
    p = StrChr(s, x);
    if (p)
    {
        printf("%d\n", p - s);
    }
    else
    {
        puts("None");
    }
    return 0;
}
char* StrChr(char* str, char chr) {
    while (*str) {
        if (*str == chr) {
            return str;
        }
        str++;
    }

    return NULL;
}
