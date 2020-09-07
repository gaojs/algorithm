#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int y = 0;
    while (x != 0) {
        y = y * 10 + x % 10;
        x = x / 10;
    }
    return (y > INT_MAX || y < INT_MIN) ? 0 : y;
}

int main()
{
    int n;
    cin >> n;
    cout << reverse(n);
    return 0;
}
