#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


vector<int> runningSum(vector<int>& a)
{
    for (int i = 1; i < a.size(); i++) {
        a[i] += a[i - 1];
    }
    return a;
}

int main()
{
    vector<int> a = { 1,2,3,4 };
    vector<int> res = runningSum(a);
    for (int e : res) {
        cout << e << " ";
    }
    return 0;
}
