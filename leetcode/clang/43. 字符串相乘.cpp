#include <bits/stdc++.h>
using namespace std;

void reverse(char *n)
{ // ��ת�ַ���
    int len = strlen(n);
    for (int i = len / 2 - 1; i >= 0; i--) {
        char t = n[i];
        n[i] = n[len - i - 1];
        n[len - i - 1] = t;
    }
}

char *multiply(char *n1, char *n2)
{
    static char c[110 + 110] = { 0 }; // ȫ�ֱ���
    static int n[110 + 110] = { 0 }; // ȫ�ֱ���
    memset(n, 0, sizeof(n)); // �����ȫ�ֱ���
    memset(c, 0, sizeof(c)); // �����ȫ�ֱ���
    reverse(n1); // ��ת�ַ���
    reverse(n2); // ��ת�ַ���
    // ����˻�����ʽ�˷�  // c = a * b
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            n[i + j] += (n1[i] - '0') * (n2[j] - '0');
        }
    }
    // �ٴ����λ 
    int len = len1 + len2;
    for (int i = 0; i < len; i++) {
        n[i + 1] += n[i] / 10;
        n[i] = n[i] % 10;
    }
    len = len > 0 ? len : 1;//��֤��1λ
    for (int i = 0; i < len; i++) {
        c[i] = n[i] + '0'; // ���ֱ��ַ�
    }
    // ȥ��ĩβ��0
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
