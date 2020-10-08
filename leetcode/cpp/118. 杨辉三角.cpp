#include <securec.h>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> generate(int numRows)
{
    vector<int> pre;
    vector<vector<int>> res;
    if (numRows > 0) { // Ìí¼ÓÒ»¸ö
        pre = vector<int>(1, 1);
        res.push_back(pre);
    }
    for (int n = numRows; n > 1; n--) {
        vector<int> now(1, 1);
        int preSize = pre.size();
        for (int i = 0; i < preSize - 1; i++) {
            now.push_back(pre[i] + pre[i + 1]);
        }
        now.push_back(1);
        res.push_back(now);
        pre = now;
    }
    return res;
}

int main()
{

    vector<vector<int>> res = generate(5);
    for (vector<int> r : res) {
        for (int e : r) {
            cout << e << ",";
        }
        cout << endl;
    }
}
