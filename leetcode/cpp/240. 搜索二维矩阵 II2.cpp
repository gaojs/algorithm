#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

bool search(vector<vector<int>>& m, int t, int r1, int c1, int r2, int c2)
{
    if (r1 > r2 || c1 > c2) {
        return false;
    }
    int r = (r1 + r2) / 2;
    int c = (c1 + c2) / 2;
    if (m[r][c] == t) {
        return true;
    } else if (m[r][c] < t) { // �����Ͻ� 
        if (search(m, t, r1, c+1, r, c2)) {
            return true; // ����
        }
        if (search(m, t, r+1, c1, r2, c)) {
            return true; // ����
        }
        if (search(m, t, r+1, c+1, r2, c2)) {
            return true; // ���� 
        }
    } else { // �����½ǣ������ϣ����ϣ����� 
        if (search(m, t, r1, c1, r-1, c-1)) {
            return true; // ����
        }
        if (search(m, t, r1, c, r-1, c2)) {
            return true; // ����
        }
        if (search(m, t, r, c1, r2, c-1)) {
            return true; // ���� 
        }
    } 
    return false;
}

bool searchMatrix(vector<vector<int>>& m, int t) 
{
    int row = m.size();
    if (row <= 0 ) {
        return false;
    }
    int col = m[0].size();
    return search(m, t, 0, 0, row - 1, col - 1);
}

int main() 
{
    vector<vector<int>> m = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    if (searchMatrix(m, 20)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;        
}

