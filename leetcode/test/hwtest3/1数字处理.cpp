#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "hlist.h"
#include "hhash.h"
#include "securec.h"
#define strdup _strdup


char *reverse(char *s)
{
    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);
    // 故意多分配点，后续可用
    int size = len + 10;
    char *a = (char*)malloc(size);
    if (a == NULL) {
        return NULL;
    }
    int ret = memset_s(a, size, 0, size);
    if (ret != EOK) {
        free(a);
        a = NULL;
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        a[i] = s[len - i - 1];
    }
    return a;
}

int find(char *a, bool *found)
{
    if (a == NULL || found == NULL) {
        return -1;
    }
    int end = -1;
    int len = strlen(a);
    for (int i = len - 1; i > 0; i--) {
        if (a[i] == '1' && a[i - 1] == '1') {
            end = i;
            *found = true;
            for (; i >= 0; i--) {
                if (a[i] != '1') {
                    break;
                }
            }
            break;
        }
    }
    return end;
}

int sethigh(char *a, int end)
{
    if (a == NULL || end < 0) {
        return end;
    }
    a[end++] = '1';
    bool set = false;
    while (a[end] == '1') {
        set = true;
        a[end] = '0';
        end++;
    }
    if (set) {
        return sethigh(a, end);
    } else {
        return end - 2;
    }
}

void setlow(char *a, int end)
{
    if (a == NULL || end < 0) {
        return;
    }
    while (end >= 0) {
        if (a[end] == '1') {
            a[end] = '0';
        }
        end--;
    }
}

char* GetSignal(char* s)
{
    if (s == NULL) {
        return NULL;
    }
    // 反序一下，方便追加字符
    char *a = reverse(s);
    if (a == NULL) {
        return NULL;
    }
    bool found = false; // 找到连续的1
    int end = find(a, &found);
    char *p = NULL;
    if (!found) { // 直接反序返回
        p = reverse(a);
    } else {
        end = sethigh(a, end + 1);
        setlow(a, end);
        p = reverse(a);
    }
    free(a);
    a = NULL;
    return p;
}

int main()
{
    // char s[] = "101010";
    // char s[] = "100011";
    char s[] = "101011";
    char *p = GetSignal(s);
    // char *p = reverse(s);
    if (p != NULL) {
        printf("%s", p);
        free(p);
    }
    return 0;
}

