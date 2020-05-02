// https://leetcode-cn.com/problems/two-sum/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    static int index[3] = {0};
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                index[0] = i;
                index[1] = j;
                *returnSize = 2;
                return index;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
	int nums[] = {2, 7, 11, 15}, target = 9;
	int size = sizeof(nums)/sizeof(nums[0]);
	int returnSize = 0;
	int *p = twoSum(nums, size, target, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", p[i]);
	}
	free(p);
	return 0;
}
