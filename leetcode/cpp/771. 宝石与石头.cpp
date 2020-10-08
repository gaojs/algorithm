#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string J, string S)
{
    int cnt = 0;
    for (char e : S) {
        if (J.find_first_of(e) != string::npos) {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    string J = "aA", S = "aAAbbbb";
    cout << numJewelsInStones(J, S);
    return 0;
}
