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

/* ���ύ�Ĵ��뽫��Ƕ������ */
int StrLen(const char* str)
{
    int cnt=0;
    for (int i = 0; str[i] != '\0'; i++) {
        cnt++;
    }
    return cnt;
}