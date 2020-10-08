#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& a)
{
    set<int> kinds;
    for (int e : a) {
        kinds.insert(e);
    }
    return min(kinds.size(), a.size() / 2);
}

int main()
{
    // vector <int> a = { 1, 1, 2, 3 }; //2
    vector <int> a = { 1,1,2,2,3,3 }; //3
    cout << distributeCandies(a);
}
