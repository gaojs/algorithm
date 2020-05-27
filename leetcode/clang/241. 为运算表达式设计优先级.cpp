#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COUNT 10000 // 确保足够大
// Note: The returned array must be malloced, assume caller calls free().
int* diffWaysToCompute(char *str, int* returnSize)
{
    if (str == NULL || returnSize == NULL) {
        return NULL;
    }
    *returnSize = 0;
    int ops = 0, len = strlen(str);
    for (int i = 0; i < len; i++) { // 求运算符个数
        if (str[i] >= '0' && str[i] <= '9') {
            continue; // 正常的数字
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
            ops++; // 符号数
        } else {
            return NULL;
        }
    }
    if (ops == 0) { // 没有运算符，只有一个数
        int *result = (int*)malloc(sizeof(int));
        result[0] = atoi(str);
        *returnSize = 1;
        return result;
    } else { // 对每个运算符，进行分治处理
        int size = sizeof(int)* MAX_COUNT;
        int *result = (int*)malloc(size);
        if (result == NULL) {
            return NULL;
        }
        memset(result, 0, size);
        for (int i = 0; i < len; i++) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
                char *leftStr = (char *)calloc(sizeof(char), i + 1);
                char *rightStr = (char *)calloc(sizeof(char), len - i);
                strncpy(leftStr, str, i);
                strncpy(rightStr, str + i + 1, len - i - 1);
                int leftSize, rightSize;
                int *leftArr = diffWaysToCompute(leftStr, &leftSize);
                int *rightArr = diffWaysToCompute(rightStr, &rightSize);
                for (int left = 0; left < leftSize; left++) {
                    for (int right = 0; right < rightSize; right++) {
                        int a = leftArr[left];
                        int b = rightArr[right];
                        switch (str[i]) {
                        case '+':
                            result[*returnSize] = a + b;
                            break;
                        case '-':
                            result[*returnSize] = a - b;
                            break;
                        case '*':
                            result[*returnSize] = a * b;
                            break;
                        }
                        if ((*returnSize) < MAX_COUNT) {
                            (*returnSize)++;
                        } else {
                            printf("overflow\n");
                            break;
                        }
                    }
                }
                free(leftStr);
                free(rightStr);
                free(leftArr);
                free(rightArr);
            }
        }
        return result;
    }
}

int main()
{
    /*****************************
    */
    // char *str = (char*)"2-1-1"; // [0,2]
    // char *str = (char*)"2*3-4*5"; // [-34,-14,-10,-10,10]
    char *str = (char*)"1-2+3*4-5*6-7+8*9";
    int returnSize = 0;
    int *p = diffWaysToCompute(str, &returnSize);
    if (p != NULL) {
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", p[i]);
        }
        free(p);
    }
    return 0;
}

