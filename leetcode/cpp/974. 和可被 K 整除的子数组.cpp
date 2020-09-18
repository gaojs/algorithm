#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& a, int k)
{ // 超出时间限制
    int s = 0;
    int n = a.size();
    vector<int> t(n, 0);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n - r; c++) {
            t[c] += a[c + r];
            if (t[c] % k == 0) {
                s++;
            }
        }
    }
    return s;
}

int main()
{
    vector<int> a = { 4,5,0,-2,-3,1 };
    cout << subarraysDivByK(a, 5) << endl;
    return 0;
}
