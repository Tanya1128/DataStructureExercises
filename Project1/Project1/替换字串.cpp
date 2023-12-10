#include <stdio.h>
#include <string.h>

// 替换子串
char* StrStuff(char* dst, int idx, int len, const char* src);

int main()
{
    char a[1024], b[1024];
    int i, n;
    gets_s(a);
    scanf("%d%d%*c", &i, &n);
    gets(b);
    StrStuff(a, i, n, b);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrInsert(char* dst, int index, const char* src) {
	if (index > strlen(dst))
		return dst;
	char str[65536];
	strcpy(str, dst + index);
	strcpy(dst + index, src);
	return strcat(dst, str);
}
char* StrStuff(char* dst, int idx, int len, const char* src) {
	char str[1024];
	int slen = strlen(dst);
	if (idx > slen || idx < 0)
		return dst;
	if (len > slen - idx)
		len = slen - idx;
	if (len <= 0)
		return StrInsert(dst, idx, src);
	strcpy(dst + idx, dst + idx + len);
	return StrInsert(dst, idx, src);
}