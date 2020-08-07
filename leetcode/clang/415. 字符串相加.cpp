#include <bits/stdc++.h>
using namespace std;

char *addStrings(char *n1, char *n2)
{
    static char n[5100] = { 0 }; // 全局变量
    memset(n, 0, sizeof(n)); // 先清空全局变量
    for (int i = strlen(n1) - 1, j = strlen(n2) - 1, c = 0, k = 0;
        i >= 0 || j >= 0 || c != 0; i--, j--) {
        int x = (i >= 0) ? n1[i] - '0' : 0;
        int y = (j >= 0) ? n2[j] - '0' : 0;
        int t = x + y + c;
        c = t / 10; // 进位
        n[k++] = t % 10 + '0';
    }
    // 去除末尾的0
    for (int i = strlen(n) - 1; i > 0; i--) {
        if (n[i] != '0') {
            break;
        }
        n[i] = 0;
    }
    // 翻转字符串
    int len = strlen(n);
    for (int i = len / 2 - 1; i >= 0; i--) {
        char t = n[i];
        n[i] = n[len - i - 1];
        n[len - i - 1] = t;
    }
    return n;
}

int main()
{
    char n1[] = { "9" };
    char n2[] = { "99" };
    printf("%s", addStrings(n1, n2));
    return 0;
}
