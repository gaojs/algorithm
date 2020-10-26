#include <bits/stdc++.h>

using namespace std;

struct node {
    int value; // 值
    int index; // 序号
    int count; // 小于它的数量
    bool operator<(node &b) {
        return value < b.value;
    }
};

vector<int> smallerNumbersThanCurrent(vector<int> &a) {
    int n = a.size();
    vector<node> vn(n);
    for (int i = 0; i < n; i++) {
        vn[i].value = a[i];
        vn[i].index = i;
        vn[i].count = 0;
    }
    sort(vn.begin(), vn.end());

    int count = 1;
    int pre_count = 0;
    int pre_value = vn[0].value;
    for (int i = 1; i < n; i++) {
        if (vn[i].value == pre_value) {
            vn[i].count = pre_count;
            count++;
        } else if (vn[i].value > pre_value) {
            pre_count += count;
            vn[i].count = pre_count;
            count = 1;
        } else {
            cout << "imposible!" << endl;
        }
        pre_value = vn[i].value;
    }

    vector<int> ans(n, 0);
    for (int i = 1; i < n; i++) {
        ans[vn[i].index] = vn[i].count;
    }
    return ans;
}

int main() {
    // vector<int> a = {8, 1, 2, 2, 3}; // 4,0,1,1,3
    // vector<int> a = {6,5,4,8}; // 2,1,0,3
    vector<int> a = {7,7,7,7}; // 0,0,0,0
    vector<int> ans = smallerNumbersThanCurrent(a);
    for (int an:ans) {
        cout << an << ",";
    }
    return 0;
}
