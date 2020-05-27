#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define strdup _strdup

#define MAX_COUNT 1000000
// ���У���������ĸ������ݽṹ
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
        if (strcmp(result[i], s) == 0) { // �Ѿ�������
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
            continue; // ��ǰ��
        } else if (sLen == qLen) {
            if (strcmp(s, q[i]) == 0) {
                return true; // �Ѵ��ڣ���������
            }
        } else { // ǰ�涼�Ǹ������ַ�����
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
        char *str = que[head]; // ȡ��
        que[head++] = 0; // ȡ����0
        int len = strlen(str); // ȡ����
        if (!found) { // ��ʱ��δ�ҵ�
            if (isValid(str)) { // �ҵ���
                found = true; // ��¼����
                maxLen = len; // ���Ž�ĳ���
                if (insert(str, result, returnSize)) {
                    continue; // ��������������
                }
            } else if (len > 1) { // �������е����ֽڣ��������
                for (int i = 0; i < len; i++) {
                    if (str[i] != '(' && str[i] != ')') {
                        continue; // �����ַ�������
                    }
                    memset(tstr, 0, sizeof(tstr));
                    strncpy(tstr, str, sizeof(tstr) - 1);
                    memmove(&tstr[i], &tstr[i + 1], len - i);
                    if (!exist(que, head, tail, tstr)) {
                        que[tail++] = strdup(tstr);
                    }
                }
            }
        } else { // ֮ǰ�Ѿ��ҵ����жϺ����Ƿ�Ҳ��
            if (len == maxLen) { // �ȳ��������ǽ�
                if (isValid(str)) { // Ҳ�����Ž�
                    if (insert(str, result, returnSize)) {
                        continue; // ��������������
                    }
                    continue;
                }
            } else if (len > maxLen) { // ���п�����������
                for (int i = 0; i < len; i++) {
                    if (str[i] != '(' && str[i] != ')') {
                        continue; // �����ַ�������
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
        // ������Ҫ
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
    if (*returnSize == 0) { // ���ؿմ�
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
    // char a[] = "(((((())"; // ��ʱ
    char a[] = "())v)(()(((((())"; // ��ʱ
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

