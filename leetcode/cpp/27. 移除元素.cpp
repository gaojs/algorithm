#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int i = 0;
    int n = nums.size();
    for (int j = 0; j < n; j++) {
        if (nums[j] == val) {
            continue;
        }
        nums[i++] = nums[j];
    }
    return i;
}

int main()
{
    int val = 3;
    vector<int> nums = { 3,2,2,3 };
    cout << removeElement(nums, val);
    return 0;
}
