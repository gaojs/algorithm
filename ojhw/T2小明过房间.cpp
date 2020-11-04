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
        return false; // Խ����
    }
    if (!a[y][x] || v[y][x]) { // ���ʹ�
        return false;
    }
    v[y][x] = true; // �����
    if (y == (r - 1)) { // �����һ����
        return true;
    }
    // �������ܵĵ�
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
    for (int x = 1; x < c; x++) { // ɨ���һ��
        if (a[1][x] > 0) { // ��ʼ��Խ
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
        if (ok(a)) { // �ҵ�·����
            cout << (k + 1);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
