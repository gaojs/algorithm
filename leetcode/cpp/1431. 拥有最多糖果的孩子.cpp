#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


vector<bool> kidsWithCandies(vector<int>& a, int n)
{
    int mx = INT_MIN;
    for (int e : a) {
        if (mx < e) {
            mx = e;
        }
    }
    vector<bool> res;
    for (int e : a) {
        if (n + e>=mx) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
    }
    return res;
}


int main()
{
    vector<int> a = { 2,3,5,1,3 };
    int extra = 3;
    vector<bool> res = kidsWithCandies(a, extra);
    for (bool e : res) {
        cout << e << endl;
    }
    return 0;
}
