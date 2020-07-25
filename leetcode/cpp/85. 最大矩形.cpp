// 办公室熄灯
#include <cmath>
#include <climits>
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

int largestRectangleArea(vector<int>& heights)
{
    int ret = 0;
    stack<int> index;
    index.push(-1); // 左边界起点
    heights.push_back(0); // 右边界最小值
    for (size_t i = 0; i < heights.size(); i++) {
        while (index.size() > 1) {
            int h = heights[index.top()];
            if (h < heights[i]) {
                break; // 直接入栈
            }
            index.pop(); // 出栈
            int left = index.top();
            int w = (i - 1) - left;
            int area = h * w;
            ret = max(ret, area);
        }
        index.push(i); // 入栈
    }
    return ret;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    if (matrix.empty()) {
        return 0;
    }
    int maxRect = 0;
    vector<int> height(matrix[0].size(), 0);
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < height.size(); j++) {
            if (matrix[i][j] == '0') {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        int area = largestRectangleArea(height);
        maxRect = max(maxRect, area);
        height.pop_back();
    }
    return maxRect;
}

int main(void)
{
    vector< vector<char> > matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << maximalRectangle(matrix);
    return 0;
}

