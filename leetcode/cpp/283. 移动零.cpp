#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


void moveZeroes(vector<int>& a)
{
    int cnt = 0;
    for (auto it = a.begin(); it != a.end();) {
        if (*it == 0) {
            it = a.erase(it);
            cnt++;
        } else {
            it++;
        }
    }
    for (; cnt > 0; cnt--) {
        a.push_back(0);
    }
}

int main()
{
    vector <int> a = { 0, 1, 0, 3, 12 };
    moveZeroes(a);
    for (int e : a) {
        cout << e << ",";
    }
}
