// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char **p, int *size, char *str, int i, int len, char *digits) 
{
    if (p == NULL || size == NULL || str == NULL || digits == NULL) {
        return; // 输入参数不对
    }
    const char letters[10][5] = { "", "", // 0, 1
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" // 2~9
    };
    // printf("%d, i=%d, len=%d, digits=%s, str=%s\n", *size, i, len, digits, str);
    if (digits[0]) {
        if (digits[0] > '9' || digits[0] < '2') {
            return;
        } else {
            const char *pt = letters[digits[0] - '0'];
            int tLen = strlen(pt);
            for (int k = 0; k < tLen; k++) {
                str[i] = pt[k];
                dfs(p, size, str, i + 1, len, &digits[1]);
            }
            str[i] = 0; // 回溯
        }
    } else {
        // printf("size=%d, str=%s\n", *size, str);
        p[*size] = (char*)calloc(sizeof(char), (len + 1));
        if (p[*size] == NULL) { // 内存申请失败
            return;
        }
        strncpy(p[*size], str, len);
        (*size)++;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char *digits, int* returnSize)
{
    if (digits == NULL || returnSize == NULL) { 
        return NULL;
    } else if (digits[0] == 0) {    
    	*returnSize = 0;	
    	return NULL;
	}
    char *str = (char*)calloc(sizeof(char), dLen + 1);
    if (str == NULL) { // 内存申请失败
        return NULL;
    }
    int maxSize = 1;
    for (int i = 0; i < dLen; i++) {
        maxSize *= 4; // 每个数字最多对应4个字母
    }
    char **p = (char**)calloc(sizeof(char*), maxSize);
    if (p == NULL) { // 内存申请失败
        free(str);
        return NULL;
    }
    int size = 0;
    dfs(p, &size, str, 0, dLen, digits);
    *returnSize = size;
    free(str);
    return p;
}
	
int main()
{
	// char digits[] = {"23"};
	char digits[] = {""};
	int returnSize = 0;
	char **p = letterCombinations(digits, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%s,", p[i]);
		free(p[i]);
	}
	return 0;
}
