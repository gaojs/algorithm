#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100000000
bool a[N] = { 0 };

int bulbSwitch1(int n)
{ // 模拟方法
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
{ // 分解因数的个数
    int sum = 0;
    for (int k = 1; k <= n; k++) {
        int count = 1; // 因数的个数
        for (int i = 2; i <= k; i++) {
            if (k % i == 0) {
                count++;
            }
        }
        sum += count % 2;
    }    
    return sum;
}

// 只有平方数的因数个数为奇数，原因很简单，平方值因数被公用

int bulbSwitch(int n)
{ // 求平方数的个数
    int sum = 0;
    for (int i = 1; i*i <= n; i++) {
        sum++;
    }
    return sum;
}

int bulbSwitch3(int n)
{ // 求平方根
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

