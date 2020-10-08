#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


int numIdenticalPairs(vector<int>& a)
{
    int cnt = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    // vector<int> a = { 1,2,3,1,1,3 }; // 4
    // vector<int> a = { 1,1,1,1 }; // 6
    vector<int> a = { 1, 2, 3 }; // 0    
    cout << numIdenticalPairs(a) << endl;
    return 0;
}
