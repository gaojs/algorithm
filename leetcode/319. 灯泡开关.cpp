#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100000000
bool a[N] = { 0 };

int bulbSwitch1(int n)
{ // ģ�ⷽ��
    memset(a, 0, sizeof(a));
    for (int k = 1; k <= n; k++) {
        for (int i = k - 1; i < n; i += k) {
            a[i] = !a[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            sum++;
        }
    }
    return sum;
}

int bulbSwitch2(int n)
{ // �ֽ������ĸ���
    int sum = 0;
    for (int k = 1; k <= n; k++) {
        int count = 1; // �����ĸ���
        for (int i = 2; i <= k; i++) {
            if (k % i == 0) {
                count++;
            }
        }
        sum += count % 2;
    }    
    return sum;
}

// ֻ��ƽ��������������Ϊ������ԭ��ܼ򵥣�ƽ��ֵ����������

int bulbSwitch(int n)
{ // ��ƽ�����ĸ���
    int sum = 0;
    for (int i = 1; i*i <= n; i++) {
        sum++;
    }
    return sum;
}

int bulbSwitch3(int n)
{ // ��ƽ����
    return (int)sqrt(n);
}

int main()
{
    /*****************************
    */
    // int n = 1; // 1
    // int n = 2; // 1
    // int n = 3; // 1
    // int n = 4; // 2
    // int n = 5; // 2
    int n = 99999999;
    printf("%d", bulbSwitch(n));
    return 0;
}

