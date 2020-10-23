#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int dist;

    Point(int px, int py) : x(px), y(py) {
        dist = x * x + y * y;
    }

    bool operator<(const Point &b) {
        return dist < b.dist;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<Point> ps;
    int n = points.size();
    for (vector<int> e: points) {
        ps.push_back(Point(e[0], e[1]));
    }
    sort(ps.begin(), ps.end());

    vector<vector<int>> ans;
    for (int i = 0; i < k && i < n; i++) {
        vector<int> an = {ps[i].x, ps[i].y};
        ans.push_back(an);
    }
    return ans;
}


int main() {

    // vector<vector<int>> a = {{1,  3}, {-2, 2}};
    vector<vector<int>> a = {{3,3},{5,-1},{-2,4}};
    vector<vector<int>> ans = kClosest(a, 2);
    for (vector<int> an:ans) {
        cout << "[";
        for (int a :an) {
            cout << a << ",";
        }
        cout << "],";
    }
    return 0;
}
