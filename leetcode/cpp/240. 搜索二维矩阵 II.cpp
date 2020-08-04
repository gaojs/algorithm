#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& m, int t) 
{
    int row = m.size();
    if (row <= 0 ) {
        return false;
    }
    int col = m[0].size();
    int c = col - 1;
    int r = 0; // ³õÊ¼Î»ÖÃÔÚÓÒÉÏ½Ç
    while ( r < row && c >=0 ) {
        if (m[r][c] == t) {
            return true;
        } else if (m[r][c] < t) {
            r++; // ÍùÏÂÕÒ 
        } else {
            c--; // Íù×óÕÒ 
        } 
    }
    return false;
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

