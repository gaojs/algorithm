#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


int xorOperation(int n, int start)
{
    int r = 0; // ���ڱ�����result
    for (int i = 0; i < n; i++) {
        int a = start + 2 * i;
        r ^= a;
    }
    return r;
}

int main()
{
    cout << xorOperation(5, 0);
    return 0;
}
