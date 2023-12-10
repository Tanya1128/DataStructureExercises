#include <stdio.h>

char* StrInsert(char* dst, int idx, const char* src);

int main()
{
    char a[1024], b[1024];
    int i;
    gets_s(a);
    scanf("%d%*c", &i);
    gets_s(b);
    StrInsert(a, i, b);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrInsert(char* dst, int idx, const char* src)
{
    int i, j;
    int cnt;
    for (i = 0; dst[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++)
    {
        cnt++;
    }
    
    if (idx<0 || idx>i) {
        return dst;
    }
    else {
        int z = idx;
        //index之后的全部后移cnt个位置
        for (j = 0; src[j] != '\0'; j++) {
            for (int t = 0; t < cnt; t++) {
                for (int r = i; r >= idx; r--) {
                    dst[r + 1] = dst[r];
                }
                i++;
                idx++;
            }
        }

        for (int k = 0; k < cnt; k++, z++) {
            dst[z] = src[k];
        }

        return dst;
    }
}
/*
#include <stdio.h>
#include <string.h>
char* StrInsert(char *dst, int idx, const char *src) {
    int dstlength = strlen(dst);
    int srclength = strlen(src);
    if (idx < 0 || idx > dstlength) {
        return dst;
    }
    memmove(dst + idx + srclength, dst + idx, dstlength - idx + 1);
    memcpy(dst + idx, src, srclength);
    return dst;
    if (idx < 0 || idx > dstlength) {
        return dst;
    }
    memmove(dst + idx + srclength, dst + idx, dstlength - idx + 1);
    memcpy(dst + idx, src, srclength);
    return dst;
}
*/