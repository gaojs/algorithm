#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
int num[N] = { 0 };
int op[N] = { 0 };

bool dfs(int num[], int op[], int *result, int* returnSize)
{
    if (num == NULL || op == NULL || returnSize == NULL) {
        return false;
    }
    if (op[0] == 0 && num[0] == 1) { // 找到一个答案
        result[*returnSize] = num[1];
        (*returnSize)++;
    }
    for (int i = 1; i <= op[0]; i++) {
        int size = sizeof(int)*(num[0] + 1);
        int *nt = (int*)malloc(size);
        memcpy(nt, num, size);
        int size2 = sizeof(int)*(op[0] + 1);
        int *ot = (int*)malloc(size2);
        memcpy(ot, op, size2);
        switch (op[i]) {
        case '+':
            nt[i] += nt[i + 1];
            break;
        case '-':
            nt[i] -= nt[i + 1];
            break;
        case '*':
            nt[i] *= nt[i + 1];
            break;
        }
        if (nt[0] > (i + 2)) {
            memcpy(&nt[i + 1], &nt[i + 2], sizeof(int)*(nt[0] - (i + 2)));
        }
        if (ot[0] > (i + 1)) {
            memcpy(&ot[i], &ot[i + 1], sizeof(int)*(ot[0] - (i + 1)));
        }
        nt[0]--;
        ot[0]--;
        dfs(nt, ot, result, returnSize);
        free(nt);
        free(ot);
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char *input, int* returnSize)
{
    if (input == NULL || returnSize == NULL) {
        return NULL;
    }
    *returnSize = 0;
    memset(num, 0, sizeof(num));
    memset(op, 0, sizeof(op));
    while (input[0] != 0) {
        if (input[0] >= '0' && input[0] <= '9') {
            // 读取一个数
            num[0]++; // 个数
            num[num[0]] = atoi(input);
            while (input[0] >= '0' && input[0] <= '9') {
                input++; // 略过这个数
            }
        }
        switch (input[0]) {
        case '+':
        case '-':
        case '*':
            op[0]++;
            op[op[0]] = input[0];
            input++; // 略过这个符号
            break;
        default:
            break;
        }
    }
    int size = sizeof(int) * (op[0] + 1) * (op[0] + 1);
    int *result = (int*)malloc(size);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, size);
    dfs(num, op, result, returnSize);
    return result;
}

int main()
{
    /*****************************
    */
    // char *str = (char*)"2-1-1"; // [0,2]
    char *str = (char*)"2*3-4*5"; // [-34,-14,-10,-10,10]
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

