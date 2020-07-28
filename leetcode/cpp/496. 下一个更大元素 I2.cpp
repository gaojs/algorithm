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
    vector<int> rt(nums1.size(), -1);

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums2[j] != nums1[i]) {
                continue;
            }
            for (; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    rt[i] = nums2[j];
                    break;
                }
            }
            break;
        }
    }
    return rt;
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
