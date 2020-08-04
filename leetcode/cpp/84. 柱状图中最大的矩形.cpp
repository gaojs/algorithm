#include <bits/stdc++.h>
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

int main(void)
{
    vector<int> heights = { 2,1,5,6,2,3 };
    cout << largestRectangleArea(heights);
    return 0;
}

