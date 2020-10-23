#include <bits/stdc++.h>

using namespace std;

struct Section {
    int x, y;

    Section(int px, int py) : x(px), y(py) {}

    bool operator<(const Section &b) {
        return x < b.x;
    }
};

vector<vector<int>> merge(vector<vector<int>> &a) {
    vector<Section> ss;
    for (vector<int> e:a) {
        ss.push_back(Section(e[0], e[1]));
    }
    sort(ss.begin(), ss.end());

    vector<vector<int>> ans;
    int n = ss.size();
    if (n > 0) {
        vector<int> ps = {ss[0].x, ss[0].y};
        for (int i = 1; i < n; i++) {
            if (ss[i].x <= ps[1]) {
                ps[1] = max(ps[1], ss[i].y);
            } else {
                ans.push_back(ps);
                ps[0] = ss[i].x;
                ps[1] = ss[i].y;
            }
        }
        ans.push_back(ps);
    }
    return ans;
}

int main() {
    vector<vector<int>> a = {{1,  3},
                             {2,  6},
                             {8,  10},
                             {15, 18}};
    vector<vector<int>> ans = merge(a);
    for (vector<int> an:ans) {
        cout << "[";
        for (int a :an) {
            cout << a << ",";
        }
        cout << "],";
    }
    return 0;
}
