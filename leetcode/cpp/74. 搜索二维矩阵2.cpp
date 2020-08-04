#include <bits/stdc++.h>
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
    } else if (m[r][c] < t) { // ���Ϸ��ͷ����� 
        if (search(m, t, r, c+1, r, c2)) {
            return true; // ����
        }
        if (search(m, t, r+1, c1, r2, c2)) {
            return true; // �·�
        }
    } else { // ���·��ͷ����� 
        if (search(m, t, r1, c1, r-1, c2)) {
            return true; // �Ϸ�
        }
        if (search(m, t, r, c1, r, c-1)) {
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
    return search(m, t, 0, 0, row-1, col-1);
}

int main() 
{
    vector<vector<int>> m = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    if (searchMatrix(m, 13)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;        
}

