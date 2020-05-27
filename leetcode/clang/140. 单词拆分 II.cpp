#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void dfs(char *s, int **a, int n, int ai, char *wd, int wi, char** wdList, int *returnSize)
{
    if (s == NULL || a == NULL || n == 0 || wd == NULL || wdList == NULL || returnSize == NULL) {
        return; // ��������
    }
    // printf("n=%d, ai=%d, wi=%d, wd=%s, size=%d\n", n, ai, wi, wd, *returnSize);
    if (ai == n) { // �ҵ�һ���½�
         // ��2��֤�㹻�����������ÿ����ĸ����һ������
        int size = sizeof(char) * (n + 1) * 2;
        wdList[*returnSize] = (char*)malloc(size);
        memset(wdList[*returnSize], 0, size);
        strncpy(wdList[*returnSize], wd, wi - 1); // ȥ�����һ���ո�
        (*returnSize)++;
    } else if (a[ai] != NULL && a[ai][0] > 0) {
        int cnt = a[ai][0]; // ����
        for (int i = 1; i <= cnt; i++) {
            int aj = a[ai][i]; // ��һ��
            int len = aj - ai; // ���ʳ���
            strncpy(wd + wi, s + ai, len);
            wd[wi + len] = ' '; // ׷�ӿո�
            wd[wi + len + 1] = 0; // ��β��ʶ���ɲ���
            dfs(s, a, n, aj, wd, wi + len + 1, wdList, returnSize);
        }
    }
}

char **wordBreak(char *s, char **wd, int n, int *returnSize)
{
    if (s == NULL || wd == NULL || n == 0 || returnSize == NULL) {
        return NULL; // ��������
    }
    *returnSize = 0;
    const int len = strlen(s);
    // dp[i] = dynamic plan, ��i���ַ������Ƿ�OK
    int size = sizeof(bool) * (len + 1);
    bool *dp = (bool *)malloc(size);
    memset(dp, 0, size);  // �����ڴ棬̫���ӷ���
    size = sizeof(int *) * (len + 1);
    int **cnt = (int **)malloc(size);
    memset(cnt, 0, size);  // �����ڴ棬̫���ӷ���

    dp[len] = true; // ��0���ַ�������ΪOK
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int wdlen = strlen(wd[j]);
            int k = i + wdlen; // ���
            if (k > len) { // ��β�����
                continue;
            }
            dp[i] = (dp[k] && strncmp(s + i, wd[j], wdlen) == 0) || dp[i];
            if (dp[k] && strncmp(s + i, wd[j], wdlen) == 0) {
                // ��¼ǰ���ϵ��������ʹ��
                // printf("i=%d, k=%d,  s=%s, wd[%d]=%s, wdlen=%d,  dp[%d]=%d, dp[%d]=%d\n",
                //    i, k, s + k, j, wd[j], wdlen, k, dp[k], i, dp[i]);
                if (cnt[i] == NULL) {
                    size = sizeof(int) * (n + 1);
                    cnt[i] = (int *)malloc(size);
                    memset(cnt[i], 0, size);
                    cnt[i][0] = 1; // ����
                    cnt[i][1] = k; // ����
                } else {
                    cnt[i][0]++; // ��������
                    cnt[i][cnt[i][0]] = k;
                }

            }/**/
        }
    }
    // ����ǰ���ϵ�����ɽ��
    size = sizeof(char*) * 1000; // (len + 1); // ����ñ�֤�㹻����
    char **wdList = (char **)malloc(size); // ���ʵ��б���Χ����
    memset(wdList, 0, size);  // �����ڴ棬̫���ӷ���
    size = sizeof(char) * (len + 1) * 2; // ��2��֤�㹻�����������ÿ����ĸ����һ������
    char* w = (char *)malloc(size); // ������ɵ�һ�У���ʱ����
    memset(w, 0, size); // �����ڴ棬̫���ӷ���

    dfs(s, cnt, len, 0, w, 0, wdList, returnSize);

    if (cnt != NULL) { // �ͷ��ڴ棬̫���ӷ���
        for (int i = 0; i <= len; i++) {
            if (cnt[i] != NULL) {
                free(cnt[i]);
                cnt[i] = NULL;
            }
        }
        free(cnt);
        cnt = NULL;
    }
    free(dp);
    dp = NULL;
    free(w);
    w = NULL;
    return wdList;
}

int main()
{
    // const char s[] = "catsandog", *wd[] = { "cats", "dog", "sand", "and", "cat" }; // ""
    // const char s[] = "catsanddog", *wd[] = {"cat", "cats", "and", "sand", "dog"}; // "cats and dog", "cat sand dog"
    // const char s[] = "pineapplepenapple", *wd[] = {"apple", "pen", "applepen", "pine", "pineapple"}; // "pine apple pen apple", "pineapple pen apple", "pine applepen apple"
    const char s[] = "aaaaaaa", *wd[] = { "aaaa", "aa", "a" };
    int n = sizeof(wd) / sizeof(wd[0]);
    int returnSize = 0;
    
    char **a = wordBreak((char*)s, (char**)wd, n, &returnSize);
    if (a != NULL && returnSize >= 0) {
        printf("returnSize=%d\n", returnSize);
        for (int i = 0; i < returnSize; i++) {
            printf("%s\n", a[i]);
            free(a[i]);
        }
        free(a);
    }
    return 0;
}
