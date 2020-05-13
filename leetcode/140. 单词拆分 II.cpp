#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void dfs(char *s, int **a, int n, int ai, char *wd, int wi, char** wdList, int *returnSize)
{
    if (s == NULL || a == NULL || n == 0 || wd == NULL || wdList == NULL || returnSize == NULL) {
        return; // 参数不对
    }
    // printf("n=%d, ai=%d, wi=%d, wd=%s, size=%d\n", n, ai, wi, wd, *returnSize);
    if (ai == n) { // 找到一个新解
         // 乘2保证足够，极端情况是每个字母都是一个单词
        int size = sizeof(char) * (n + 1) * 2;
        wdList[*returnSize] = (char*)malloc(size);
        memset(wdList[*returnSize], 0, size);
        strncpy(wdList[*returnSize], wd, wi - 1); // 去掉最后一个空格
        (*returnSize)++;
    } else if (a[ai] != NULL && a[ai][0] > 0) {
        int cnt = a[ai][0]; // 数量
        for (int i = 1; i <= cnt; i++) {
            int aj = a[ai][i]; // 下一个
            int len = aj - ai; // 单词长度
            strncpy(wd + wi, s + ai, len);
            wd[wi + len] = ' '; // 追加空格
            wd[wi + len + 1] = 0; // 结尾标识，可不加
            dfs(s, a, n, aj, wd, wi + len + 1, wdList, returnSize);
        }
    }
}

char **wordBreak(char *s, char **wd, int n, int *returnSize)
{
    if (s == NULL || wd == NULL || n == 0 || returnSize == NULL) {
        return NULL; // 参数错误
    }
    *returnSize = 0;
    const int len = strlen(s);
    // dp[i] = dynamic plan, 后i个字符串，是否OK
    int size = sizeof(bool) * (len + 1);
    bool *dp = (bool *)malloc(size);
    memset(dp, 0, size);  // 申请内存，太复杂繁琐
    size = sizeof(int *) * (len + 1);
    int **cnt = (int **)malloc(size);
    memset(cnt, 0, size);  // 申请内存，太复杂繁琐

    dp[len] = true; // 后0个字符串，认为OK
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int wdlen = strlen(wd[j]);
            int k = i + wdlen; // 后段
            if (k > len) { // 后段不够长
                continue;
            }
            dp[i] = (dp[k] && strncmp(s + i, wd[j], wdlen) == 0) || dp[i];
            if (dp[k] && strncmp(s + i, wd[j], wdlen) == 0) {
                // 记录前后关系，供后续使用
                // printf("i=%d, k=%d,  s=%s, wd[%d]=%s, wdlen=%d,  dp[%d]=%d, dp[%d]=%d\n",
                //    i, k, s + k, j, wd[j], wdlen, k, dp[k], i, dp[i]);
                if (cnt[i] == NULL) {
                    size = sizeof(int) * (n + 1);
                    cnt[i] = (int *)malloc(size);
                    memset(cnt[i], 0, size);
                    cnt[i][0] = 1; // 数量
                    cnt[i][1] = k; // 后项
                } else {
                    cnt[i][0]++; // 数量增加
                    cnt[i][cnt[i][0]] = k;
                }

            }/**/
        }
    }
    // 根据前后关系，生成结果
    size = sizeof(char*) * 1000; // (len + 1); // 这里得保证足够，汗
    char **wdList = (char **)malloc(size); // 单词的列表，范围变量
    memset(wdList, 0, size);  // 申请内存，太复杂繁琐
    size = sizeof(char) * (len + 1) * 2; // 乘2保证足够，极端情况是每个字母都是一个单词
    char* w = (char *)malloc(size); // 单词组成的一行，临时变量
    memset(w, 0, size); // 申请内存，太复杂繁琐

    dfs(s, cnt, len, 0, w, 0, wdList, returnSize);

    if (cnt != NULL) { // 释放内存，太复杂繁琐
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
