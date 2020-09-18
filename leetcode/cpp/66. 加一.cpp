#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& a)
{
    int c = 1;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) {
        int t = a[i] + c;
        a[i] = t % 10;
        c = t / 10;
    }
    if (c > 0) { // 最高位的进位
        a.insert(a.begin(), c);
    }
    return a;
}

int main()
{
    // vector<int> a = { 1,2,3 };
    vector<int> a = { 9 };
    a = plusOne(a);
    for (int e : a) {
        cout << e;
    }
    return 0;
}
