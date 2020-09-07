#include <bits/stdc++.h>
using namespace std;


int climbStairs(int n)
{
    int a, b, c;

    a = b = c = 1;
    for (int i = 1; i < n; i++) {
        c = a + b;
        a = b, b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
    return 0;
}
