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

bool searchMatrix(vector<vector<int>>& m, int t) 
{
    int row = m.size();
    if (row <= 0 ) {
        return false;
    }
    int col = m[0].size();
    int c = col - 1;
    int r = 0;
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

