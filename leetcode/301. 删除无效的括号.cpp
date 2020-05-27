#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define strdup _strdup

#define MAX_COUNT 1000000
// 队列，广度搜索的辅助数据结构
char *que[MAX_COUNT] = { 0 };
char tstr[MAX_COUNT] = { 0 };

bool isValid(char *s)
{
    if (s == NULL) {
        return false;
    }
    int left, right;
    left = right = 0;
    for (; s[0]; s++) {
        switch (s[0]) {
        case '(':
            left++;
            break;
        case ')':
            right++;
            if (right > left) {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return (left == right);
}

bool insert(char *s, char **result, int *returnSize)
{
    if (s == NULL || result == NULL || returnSize == NULL) {
        return false;
    }
    for (int i = 0; i < *returnSize; i++) {
        if (strcmp(result[i], s) == 0) { // 已经存在了
            return false;
        }
    }
    result[*returnSize] = s;
    (*returnSize)++;
    return true;
}

bool exist(char *q[], int head, int tail, char *s)
{
    if (q == NULL || s == NULL || head < 0 || tail <= 0 || head > tail) {
        return false;
    }
    for (int i = tail - 1; i >= head; i--) {
        int sLen = strlen(s), qLen = strlen(q[i]);
        if (sLen < qLen) {
            continue; // 往前找
        } else if (sLen == qLen) {
            if (strcmp(s, q[i]) == 0) {
                return true; // 已存在，不用找了
            }
        } else { // 前面都是更长的字符串了
            return false;
        }
    }
    return false;
}

bool bfs(char *s, char **result, int *returnSize)
{
    if (result == NULL || returnSize == NULL) {
        return false;
    } else if (s == NULL || s[0] == 0) {
        *returnSize = 0;
        return false;
    }
    *returnSize = 0;
    bool found = false;
    int maxLen = strlen(s);
    memset(que, 0, sizeof(que));
    int head = 0, tail = 0;
    que[tail++] = strdup(s);
    while (head < tail) {
        char *str = que[head]; // 取串
        que[head++] = 0; // 取过置0
        int len = strlen(str); // 取长度
        if (!found) { // 暂时还未找到
            if (isValid(str)) { // 找到了
                found = true; // 记录下来
                maxLen = len; // 最优解的长度
                if (insert(str, result, returnSize)) {
                    continue; // 继续搜索其他解
                }
            } else if (len > 1) { // 把它所有的子字节，加入队列
                for (int i = 0; i < len; i++) {
                    if (str[i] != '(' && str[i] != ')') {
                        continue; // 其他字符，保留
                    }
                    memset(tstr, 0, sizeof(tstr));
                    strncpy(tstr, str, sizeof(tstr) - 1);
                    memmove(&tstr[i], &tstr[i + 1], len - i);
                    if (!exist(que, head, tail, tstr)) {
                        que[tail++] = strdup(tstr);
                    }
                }
            }
        } else { // 之前已经找到，判断后续是否也行
            if (len == maxLen) { // 等长，可能是解
                if (isValid(str)) { // 也是最优解
                    if (insert(str, result, returnSize)) {
                        continue; // 继续搜索其他解
                    }
                    continue;
                }
            } else if (len > maxLen) { // 还有可能有其他解
                for (int i = 0; i < len; i++) {
                    if (str[i] != '(' && str[i] != ')') {
                        continue; // 其他字符，保留
                    }
                    memset(tstr, 0, sizeof(tstr));
                    strncpy(tstr, str, sizeof(tstr) - 1);
                    memmove(&tstr[0], &tstr[1], len - i);
                    if (!exist(que, head, tail, tstr)) {
                        que[tail++] = strdup(tstr);
                    }
                }
            }
        }
        // 丢弃不要
        free(str);
    }
    return true;
}

char **removeInvalidParentheses(char *s, int* returnSize)
{
    if (s == NULL || returnSize == NULL) {
        return NULL;
    }
    char **result = (char**)calloc(MAX_COUNT, sizeof(char*));
    bfs(s, result, returnSize);
    if (*returnSize == 0) { // 返回空串
        result[*returnSize] = strdup("");
        (*returnSize)++;
    }
    return result;
}

int main()
{
    /*************************/
    // char a[] = "()())()"; // ["()()()", "(())()"]
    // char a[] = "(a)())()"; // ["(a)()()", "(a())()"]
    // char a[] = ")("; // [""]  
    // char a[] = "(((((";
    // char a[] = ")))((()(";
    // char a[] = "(((((())"; // 超时
    char a[] = "())v)(()(((((())"; // 超时
    int returnSize = 0;
    char **p = removeInvalidParentheses(a, &returnSize);
    if (p != NULL) {
        for (int i = 0; i < returnSize; i++) {
            printf("%s\n", p[i]);
            free(p[i]);
        }
        free(p);
    }
    /******************
    if (isValid(a)) {
        printf("true");
    } else {
        printf("false");
    }*/
    return 0;
}

