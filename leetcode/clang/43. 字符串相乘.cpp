#include <bits/stdc++.h>
using namespace std;

void reverse(char *n)
{ // 翻转字符串
    int len = strlen(n);
    for (int i = len / 2 - 1; i >= 0; i--) {
        char t = n[i];
        n[i] = n[len - i - 1];
        n[len - i - 1] = t;
    }
}

char *multiply(char *n1, char *n2)
{
    static char c[110 + 110] = { 0 }; // 全局变量
    static int n[110 + 110] = { 0 }; // 全局变量
    memset(n, 0, sizeof(n)); // 先清空全局变量
    memset(c, 0, sizeof(c)); // 先清空全局变量
    reverse(n1); // 翻转字符串
    reverse(n2); // 翻转字符串
    // 先算乘积，竖式乘法  // c = a * b
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            n[i + j] += (n1[i] - '0') * (n2[j] - '0');
        }
    }
    // 再处理进位 
    int len = len1 + len2;
    for (int i = 0; i < len; i++) {
        n[i + 1] += n[i] / 10;
        n[i] = n[i] % 10;
    }
    len = len > 0 ? len : 1;//保证有1位
    for (int i = 0; i < len; i++) {
        c[i] = n[i] + '0'; // 数字变字符
    }
    // 去除末尾的0
    for (int i = strlen(c) - 1; i > 0; i--) {
        if (c[i] != '0') {
            break;
        }
        c[i] = 0;
    }
    reverse(c);
    return c;
}

int main()
{
    // char n1[] = { "999" }, n2[] = { "999" }; // 998001
    char n1[] = { "0" }, n2[] = { "0" }; // 0
    printf("%s", multiply(n1, n2));
    return 0;
}
