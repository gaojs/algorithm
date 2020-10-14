#include <securec.h>
#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string>& strs)
{
    const int ALPHA_COUNT = 26;
    vector<int> cnt(ALPHA_COUNT);
    vector<int> minCnt(ALPHA_COUNT, INT_MAX);
    for (const string& str : strs) { // ÒýÓÃ
        fill(cnt.begin(), cnt.end(), 0);
        for (char ch : str) {
            cnt[ch - 'a']++;
        }
        for (int i = 0; i < ALPHA_COUNT; ++i) {
            if (minCnt[i] > cnt[i]) {
                minCnt[i] = cnt[i];
            }
        }
    }

    vector<string> ans;
    for (int i = 0; i < ALPHA_COUNT; ++i) {
        for (int n = minCnt[i]; n > 0; n--) {
            ans.emplace_back(1, i + 'a');
        }
    }
    return ans;
}

int main()
{
    vector<string> a = { "bella", "label", "roller" };
    vector<string> ans = commonChars(a);
    for (string s : ans) {
        cout << s << ",";
    }
    cout << endl;
    vector<string> a2 = { "cool", "lock", "cook" };
    vector<string> ans2 = commonChars(a2);
    for (string s : ans2) {
        cout << s << ",";
    }
    return 0;
}