#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& vt)
{
    int sum = 0; // 累加器
    stack<int> index; // 单调递减
    for (size_t i = 0; i < vt.size(); i++) {
        if (index.size() > 0) {
            int top = index.top();
            while (vt[i] > vt[top]) {
                index.pop(); // 出栈
                if (index.empty()) {
                    break; // 直接压栈
                }
                int w = (i - 1) - index.top(); // 宽
                int mh = min(vt[index.top()], vt[i]);
                int h = mh - vt[top]; // 高
                sum += w * h; // 面积
                top = index.top();
            }
        }
        index.push(i); // 压栈
    }
    return sum;
}

int main(void)
{
    // vector<int> vt = { 4,2,3 }; // 1
    // vector<int> vt = { 0,1,0,2,1,0,1,3,2,1,2,1 }; // 6
    vector<int> vt = { 4, 2, 0, 3, 2, 5 }; // 9
    cout << trap(vt);
    return 0;
}
