#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


void moveZeroes(vector<int>& a)
{
    int index = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[index++] = a[i];
        } 
    }
    while (index < n) {
        a[index++] = 0;
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
