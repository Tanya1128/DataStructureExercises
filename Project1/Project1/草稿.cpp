#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
const int maxn = 50;
int a[maxn];
int n, k, ans;
bool prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)return false;
    }
    return true;
}
//t 代表已经选择的数字的个数  sum代表已经选择的数字之和 
//d是已经选择的数字中 最后一个数在数组中的位置
void dfs(int t, int sum, int d) {
    if (t == k) {
        if (prime(sum))ans++;//达到k个 检验是否是素数 计数
    }
    else {
        for (int i = d; i < n; i++) {//没到k个  继续从后边找下一个数
            dfs(t + 1, sum + a[i], i + 1);
        }
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
    char s[1101] = { 0 };
    int flag = 0, Y = 0;
    get_s(s);
    char res;
    for (int i = 1; i < strlen(s); i++) {
        if (s[0] == s[j]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        res = s[0];
    }
    if (flag == 1) {
        flag = 0;
        for (int i = 1; i < strlen(s); i++) {
            for (int j = 0; j < strlen(s); j++) {
                if (s[i] == s[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                res = s[i];
                Y = 1;
                break;
            }
            else {
                continue;
            }
        }
    }
    if (Y == 0) {
        printf("no\n");
    }
    else {
        printf("%c\n", res);
    }
    return 0;
}