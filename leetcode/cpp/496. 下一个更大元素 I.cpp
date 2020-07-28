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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    stack<int> index;
    vector<int> rt(nums2.size(), -1);
    for (int i = 0; i < nums2.size(); i++) {
        if (index.size() > 0) { // 有元素了
            int top = index.top();
            while (nums2[i] > nums2[top]) {
                rt[top] = nums2[i];
                index.pop(); // 出栈
                if (index.empty()) {
                    break; // 栈空
                }
                top = index.top();
            }
        }
        index.push(i); // 压栈
    }
    // 从rt挑选出nums1的元素
    map<int, int> mp; // HashMap?
    for (int i = 0; i < nums2.size(); i++) {
        mp[nums2[i]] = rt[i];
    }
    vector<int> rt2(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++) {
        rt2[i] = mp[nums1[i]];
    }
    return rt2;
}

int main(void)
{
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };
    vector<int> rt = nextGreaterElement(nums1, nums2);
    for (int e : rt) {
        cout << e << " ";
    }
    return 0;
}
