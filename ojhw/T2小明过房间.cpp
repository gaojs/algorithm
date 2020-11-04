#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int y, x;
    Point(int py, int px) : y(py), x(px) {}
};

bool cross(vector<vector<int>> &a, vector<vector<bool>> &v, int x, int y)
{
    int r = a.size();
    int c = a[0].size();
    if (x < 1 || x >= c || y < 1 || y > r) {
        return false; // 越界了
    }
    if (!a[y][x] || v[y][x]) { // 访问过
        return false;
    }
    v[y][x] = true; // 标记它
    if (y == (r - 1)) { // 到最后一行了
        return true;
    }
    // 访问四周的点
    if (cross(a, v, x, y + 1)) {
        return true;
    }
    if (cross(a, v, x - 1, y)) {
        return true;
    }
    if (cross(a, v, x + 1, y)) {
        return true;
    }
    if (cross(a, v, x, y - 1)) {
        return true;
    }
    return false;
}

bool ok(vector<vector<int>> &a)
{
    int r = a.size();
    int c = a[0].size();
    vector<vector<bool>> v(r, vector<bool>(c, 0));
    for (int x = 1; x < c; x++) { // 扫描第一行
        if (a[1][x] > 0) { // 开始穿越
            if (cross(a, v, x, 1)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int m, n, x, y;

    cin >> m >> n; // (n,m)->(y,x)
    if (m <= 0 || n <= 0) {
        return -1;
    }
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<Point> points;
    while (cin >> x && x != -1) {
        cin >> y;
        Point point(y, x);
        points.push_back(point);
    };
    for (int k = 0; k < points.size(); k++) {
        a[points[k].y][points[k].x] = (k + 1);
        if (ok(a)) { // 找到路径了
            cout << (k + 1);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
