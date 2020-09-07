#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    long long y = 0, t = abs(x);
    while (t != 0) {
        y = y * 10 + t % 10;
        t = t / 10;
    }
    return  (x == y);
}

int main()
{
    int n;
    cin >> n;
    cout << isPalindrome(n);
    return 0;
}
