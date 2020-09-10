#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] < target) {
            continue;
        } else {
            return i;
        }
    }
    return n;
}

int main()
{
    vector<int> nums = { 1,3,5,6 };
    // int target = 5; // 2
    // int target = 2; // 1
    // int target = 7; // 4
    int target = 0; // 0
    cout << searchInsert(nums, target);
    return 0;
}
