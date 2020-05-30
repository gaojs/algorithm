#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "hlist.h"
#include "hhash.h"
#include "securec.h"
#define strdup _strdup

#define ELE_COUNT 2
#define MAX_COUNT 1000
int s[MAX_COUNT][MAX_COUNT] = { 0 };

int sum(int *a, int n)
{
    if (a == NULL || n < 0) {
        return 0;
    }
    (void)memset_s(s, sizeof(s), 0, sizeof(s));
    for (int i = 0; i < n; i++) {
        s[i][i] = a[i];
        for (int j = i + 1; j < n; j++) {
            s[i][j] = s[i][j - 1] + a[j];
        }
    }
    return 1;
}

int* GetIndexList(int* a, int n, int* rn)
{
    if (s == NULL || n < 0 || rn == NULL) {
        return NULL;
    }
    *rn = 0;
    bool found = false;
    int min, max, result = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                if (!found) {
                    found = true;
                    sum(a, n);
                }
                if (result < s[i][j]) {
                    result = s[i][j];
                    min = i;
                    max = j;
                }
            }
        }
    }
    if (!found) { // Ã»ÕÒµ½
        return NULL;
    }
    int *p = (int*)malloc(sizeof(int)*ELE_COUNT);
    if (p == NULL) {
        return NULL;
    }
    p[0] = min;
    p[1] = max;
    *rn = ELE_COUNT;
    return p;
}

int main()
{
    // int a[] = { 1, 2, 3, 4 };
    // int a[] = { 1, 2, 3, 2, 3, 4 };
    int a[] = { 4, 6, 7, 4, -1, -3, 4 };
    int n = sizeof(a) / sizeof(a[0]);
    int rn = 0;
    int *p = GetIndexList(a, n, &rn);
    if (p != NULL) {
        for (int i = 0; i < rn; i++) {
            printf("%d ", p[i]);
        }
        free(p);
        p = NULL;
    }
    return 0;
}

