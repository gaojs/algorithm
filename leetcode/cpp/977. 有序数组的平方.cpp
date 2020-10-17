#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& a)
{
    vector<int> res;
    for (int e : a) {
        res.push_back(e*e);
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> a={ -4, -1, 0, 3, 10};
    vector<int> res = sortedSquares(a);
    for (int e : res) {
        cout << e << ",";
    }
    return 0;
}