//本题要求实现一个函数，删去给定整数数组中的重复整数，
//不重复的元素放于原数组中，不要改变原来的次序。该函数返回不重复的整数个数。
//函数接口定义：
//函数原型为：
//int Unique_Int(int a[], int n);
//其中 a[] 是输入的整数数组， n 是整数个数(0 <= n && n <= 100)。
//函数须返回 a中不重复的整数个数，删除重复的整数(仅保留第一个)，依然存于数组a中。

/* 请在这里填写答案 */
//输入样例：
//5
//2 5 2 2 - 1
//输出样例：
//3 2 5 - 1
//裁判测试程序样例：

#include <stdio.h>

int Unique_Int(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] == a[i]) {
                for (int k = j + 1; k < n; k++) {
                    a[k-1] = a[k];
                }
                n--;
            }
        }
    }
    return n;
}

int main()
{

    int a[100], n, k, count;

    scanf("%d", &n);
    for (k = 0; k < n; k++)
        scanf("%d", &a[k]);
    count = Unique_Int(a, n);
    printf("%d ", count);
    for (k = 0; k < count; k++)
        printf("%d ", a[k]);

    return 0;

}
