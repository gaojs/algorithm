#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& a)
{
    int m, w,n, i, j;
    m = w = n = i = j = 0;
    while (i < a.size()) {
        if (n >= s) {
            if (m == 0 || m > w) {
                m = w;
            }
            n -= a[i];
            w -= 1;
            i++;
        } else {
            if (j < a.size()) {
                n += a[j];
                w += 1;
                j++;
            } else {
                break;
            }
        }
    }
    return m;
}

int main()
{
    {
        vector<int> a = { 2,3,1,2,4,3 };
        cout << minSubArrayLen(7, a) << endl;
    }
    {
        vector<int> a = { 1,2,3,4,5 };
        cout << minSubArrayLen(15, a) << endl;
    }
    return 0;
}
