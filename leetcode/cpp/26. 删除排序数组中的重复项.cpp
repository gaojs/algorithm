#include <bits/stdc++.h>
using namespace std;

int removeDuplicates2(vector<int>& nums)
{ // 超出时间限制
    vector<int>::iterator it = nums.begin();
    while (it != nums.end()) {
        vector<int>::iterator nx = it + 1;
        while (nx != nums.end()) {
            if (*it == *nx) {
                nx = nums.erase(nx);
            } else {
                nx++;
            }
        }
        it++;
    }
    return nums.size();
}

int removeDuplicates3(vector<int>& nums)
{ // 超出时间限制
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == INT_MIN) {
                continue;
            } else if (nums[i] == nums[j]) {
                nums[j] = INT_MIN;
            }
        }
    }
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] != INT_MIN) {
            nums[i++] = nums[j];
        }
    }
    return i;
}

int removeDuplicates(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    vector<int> nums = { 3,2,2,3 };
    cout << removeDuplicates(nums);
    return 0;
}
