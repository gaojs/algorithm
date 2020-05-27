// https://leetcode-cn.com/problems/3sum

int cmp(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b; // 比较大小
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (nums == NULL || returnSize == NULL || returnColumnSizes == NULL) {
        return NULL;
    } 
    // 方便起见，先申请足够的内存
    int max_count = numsSize * numsSize; // 认为足够了
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
    /* for (int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n"); */
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) { // 剪枝
            continue;
        }        
        if (i > 0 && nums[i] == nums[i - 1]) { // 剪枝
            continue;
        } 
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] > 0) { // 剪枝
                continue;
            } 
            if (j > i + 1 && nums[j] == nums[j - 1]) { // 剪枝
                continue;
            } 
            // 这里用二分查找，进行优化
            int left = j + 1;
            int right = numsSize - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int sum = nums[i] + nums[j] + nums[mid];
                // printf("[%d]%d + [%d]%d + [%d]%d = (%d-%d)%d\n", 
                //      i, nums[i], j, nums[j], mid, nums[mid], left, right, sum);
                if (sum == 0) { // 找到一个解
                    p[*returnSize] = (int*)malloc(sizeof(int) * 3);
                    if (p[*returnSize] == NULL) {
                        return NULL;
                    }
                    p[*returnSize][0] = nums[i];
                    p[*returnSize][1] = nums[j];
                    p[*returnSize][2] = nums[mid];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                    break; // 找到则退出 
                } else if (sum > 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }            
        }
    }
    return p;
}
