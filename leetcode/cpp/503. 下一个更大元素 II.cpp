#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    stack<int> index;
    int size = nums.size();
    vector<int> rt(size, -1);
    for (int i = 0; i < size * 2; i++) {
        int idx = i % size; // 下标不要出界
        if (index.size() > 0) { // 有元素了
            int top = index.top();
            while (nums[idx] > nums[top]) {
                rt[top] = nums[idx];
                index.pop(); // 出栈
                if (index.empty()) {
                    break; // 栈空
                }
                top = index.top();
            }
        }
        index.push(idx); // 压栈
    }
    return rt;
}

int main(void)
{
    vector<int> nums = { 1,2,1 };
    vector<int> rt = nextGreaterElements(nums);
    for (int e : rt) {
        cout << e << " ";
    }
    return 0;
}
