#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& a)
{
    int d = 0;
    int mn = INT_MAX;
    for (int e : a) {
        if (mn > e) {
            mn = e;
        } else {
            int t = e - mn;
            if (d < t) {
                d = t;
            }
        }
    }
    return d;
}

int main()
{
    vector<int> a = { 7,1,5,3,6,4 };
    cout << maxProfit(a) << endl;
    return 0;
}
