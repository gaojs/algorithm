#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& a)
{
    int s = 0;
    int mn = INT_MAX;
    for (int e : a) {
        if (e > mn) {
            int t = e - mn;
            s += t;
        }
        mn = e;
    }
    return s;
}

int main()
{
    vector<int> a = { 7,1,5,3,6,4 };
    cout << maxProfit(a) << endl;
    vector<int> a2 = { 1,2,3,4,5 };
    cout << maxProfit(a2) << endl;
    vector<int> a3 = { 7,6,4,3,1 };
    cout << maxProfit(a3) << endl;
    return 0;
}
