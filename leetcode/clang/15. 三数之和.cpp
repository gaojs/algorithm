// https://leetcode-cn.com/problems/3sum

int cmp(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b; // �Ƚϴ�С
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
    // ����������������㹻���ڴ�
    int max_count = numsSize * numsSize; // ��Ϊ�㹻��
    int **p = (int **)malloc(sizeof(int*) * max_count); 
    if (p == NULL) { // �����ڴ��Ƿ�ʧ��
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * max_count);
    if (*returnColumnSizes == NULL) { // �����ڴ��Ƿ�ʧ��
        free(p); // �ͷ�֮ǰ������ڴ�
        return NULL;
    }
    memset(*returnColumnSizes, 0, sizeof(int) * max_count);
    *returnSize = 0;
    // ��С��������ʱ�临�Ӷ�O(nlogn)
    qsort(nums, numsSize, sizeof(int), cmp);
    /* for (int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n"); */
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) { // ��֦
            continue;
        }        
        if (i > 0 && nums[i] == nums[i - 1]) { // ��֦
            continue;
        } 
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] > 0) { // ��֦
                continue;
            } 
            if (j > i + 1 && nums[j] == nums[j - 1]) { // ��֦
                continue;
            } 
            // �����ö��ֲ��ң������Ż�
            int left = j + 1;
            int right = numsSize - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int sum = nums[i] + nums[j] + nums[mid];
                // printf("[%d]%d + [%d]%d + [%d]%d = (%d-%d)%d\n", 
                //      i, nums[i], j, nums[j], mid, nums[mid], left, right, sum);
                if (sum == 0) { // �ҵ�һ����
                    p[*returnSize] = (int*)malloc(sizeof(int) * 3);
                    if (p[*returnSize] == NULL) {
                        return NULL;
                    }
                    p[*returnSize][0] = nums[i];
                    p[*returnSize][1] = nums[j];
                    p[*returnSize][2] = nums[mid];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                    break; // �ҵ����˳� 
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
