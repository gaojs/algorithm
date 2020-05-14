#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200 // ��֤�㹻��
int visit[N][N] = { 0 }; // �Ƿ����
char *result[N]= { 0 }; // ���ؽ��

bool dfs(char** a, int n, int* col, char *word, int r, int c)
{
    if (a == NULL || n == 0 || col == NULL || word == NULL) {
        return false; // ��������
    } else if (r < 0 || r >= n || c < 0 || c >= *col) {
        return false; // Խ����
    } else if (visit[r][c]) {
        return false; // �ѷ���
    } else if (a[r][c] != word[0]) {
        return false; // ��ĸ����� 
    } else if (strlen(word) == 1) { // ֻ��1����ĸ��������� 
        return true;
    } else { // �鿴��������ĸ 
        visit[r][c] = 1; // �ѷ��� 
        if (dfs(a, n, col, &word[1], r - 1, c)) {
            return true;
        }
        if (dfs(a, n, col, &word[1], r + 1, c)) {
            return true;
        }
        if (dfs(a, n, col, &word[1], r, c - 1)) {
            return true;
        }
        if (dfs(a, n, col, &word[1], r, c + 1)) {
            return true;
        }
        visit[r][c] = 0; // ���� 
        return false;
    }
}

bool exist(char** a, int n, int* col, char *word)
{
    if (a == NULL || n <= 0 || col == NULL || word == NULL) {
        return false;
    }
    memset(visit, 0, sizeof(visit));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < col[r]; c++) {
            if (a[r][c] != word[0]) {
                continue; // �������� 
            }
            if (dfs(a, n, col, &word[0], r, c)) {
                return true;
            }
        }
    }
    return false;
}

char **findWords(char** a, int n, int* col, char ** wdList, int m, int* returnSize)
{
    if (a == NULL || col == NULL || wdList == NULL || returnSize == NULL) {
        return NULL; // ��������
    } else if (n <= 0 || *col <= 0 || m <= 0) {
        *returnSize = 0;
        return NULL; // ��������
    }
    *returnSize = 0;
    memset(result, 0, sizeof(result));
    for (int i = 0; i < m; i++) {
        if (exist(a, n, col, wdList[i])) {
            int len = strlen(wdList[i]) + 1;
            result[*returnSize] = (char*)calloc(sizeof(char), len);
            strncpy(result[*returnSize], wdList[i], len - 1);
            (*returnSize)++;
        }
    }
    return result;
}

int main()
{
    /*****************************
    */
    char r1[] = { 'o', 'a', 'a', 'n' };
    char r2[] = { 'e', 't', 'a', 'e' };
    char r3[] = { 'i', 'h', 'k', 'r' };
    char r4[] = { 'i', 'f', 'l', 'v' };
    char *a[] = { r1, r2, r3, r4 };
    int col[] = { 4, 4, 4, 4 };
    const char *w[] = { "oath", "pea", "eat", "rain" };
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(w) / sizeof(w[0]);
    int returnSize = 0;
    char **p = findWords(a, n, col, (char **)w, m, &returnSize);
    if (p != NULL && returnSize) {
        for (int i = 0; i < returnSize; i++) {
            printf("%s\n", p[i]);
        }
    }
    return 0;
}

