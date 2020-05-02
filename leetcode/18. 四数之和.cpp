// https://leetcode-cn.com/problems/4sum/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int cmp(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b; // 比较大小
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    if (nums == NULL || returnSize == NULL || returnColumnSizes == NULL) {
        return NULL;
    } 
    // 方便起见，先申请足够的内存
    int max_count = numsSize * numsSize * numsSize; // 认为足够了
    int **p = (int **)malloc(sizeof(int*) * max_count); 
    if (p == NULL) { // 申请内存是否失败
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * max_count);
    if (*returnColumnSizes == NULL) { // 申请内存是否失败
        free(p); // 释放之前申请的内存
        return NULL;
    }
    memset(*returnColumnSizes, 0, sizeof(int) * max_count);
    *returnSize = 0;
    // 从小到大排序，时间复杂度O(nlogn)
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n"); /**/
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) { // 剪枝
            continue;
        } 
        for (int j = i + 1; j < numsSize; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) { // 剪枝
                continue;
            } 
            for (int k = j + 1; k < numsSize; k++) {
	            if (k > j + 1 && nums[k] == nums[k - 1]) { // 剪枝
	                continue;
	            } 
	            // 这里用二分查找，进行优化
	            int left = k + 1;
	            int right = numsSize - 1;
	            while (left <= right) {
	                int mid = (left + right) / 2;
	                int sum = nums[i] + nums[j] + nums[k] + nums[mid];
	                // printf("[%d]%d + [%d]%d + [%d]%d + [%d]%d = (%d-%d)%d\n", 
	                //    i, nums[i], j, nums[j], k, nums[k], mid, nums[mid], left, right, sum);
	                if (sum == target) { // 找到一个解
	                    p[*returnSize] = (int*)malloc(sizeof(int) * 4);
	                    if (p[*returnSize] == NULL) {
	                        return NULL;
	                    }
	                    p[*returnSize][0] = nums[i];
	                    p[*returnSize][1] = nums[j];
	                    p[*returnSize][2] = nums[k];
	                    p[*returnSize][3] = nums[mid];
	                    (*returnColumnSizes)[*returnSize] = 4;
	                    (*returnSize)++;
	                    break; // 找到则退出 
	                } else if (sum > target) {
	                    right = mid - 1;
	                } else {
	                    left = mid + 1;
	                }
	            } 
            }            
        }
    }
    return p;
}

int main()
{
	int nums[] = {1,-2,-5,-4,-3,3,3,5}; // {0, 0, 0, 0}; // {1, 0, -1, 0, -2, 2};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = -11; // 1; // 0;
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int** p = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
	if (p != NULL) {
		for (int i = 0; i < returnSize ; i++) {
			for (int j = 0; j <returnColumnSizes[i] ; j++) {
				printf("%d,", p[i][j]);
			}
			printf("\n");
			free(p[i]);
		}
		free(returnColumnSizes);
		free(p);
	}
	return 0;	
} 
