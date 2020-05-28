#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

void freeArr(int **a, int n)
{
    if (a != NULL) {
        for (int i = 0; i < n; i++) {
            if (a[i] != NULL) {
                free(a[i]);
                a[i] = NULL;
            }
        }
        free(a);
        a = NULL;
    }
}

int **mallocArr(int n, int* col, int* rn, int** rcol)
{
    int **p = (int**)malloc(sizeof(int*)*n);
    if (p == NULL) {
        return NULL;
    }
    memset(p, 0, sizeof(int*)*n);
    *rcol = (int*)malloc(sizeof(int)*n);
    if (*rcol == NULL) {
        free(p);
        return NULL;
    }
    memset(*rcol, 0, sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(sizeof(int)*col[i]);
        if (p[i] == NULL) {
            freeArr(p, n);
            return NULL;
        }
        memset(p[i], 0, sizeof(int)*col[i]);
        (*rcol)[i] = col[i];
    }
    *rn = n;
    return p;
}

int cmp(const void* a, const void *b)
{
    if ((*(int**)a)[0] != (*(int**)b)[0]) {
        return -((*(int**)a)[0] - (*(int**)b)[0]);
    } else {
        return ((*(int**)a)[1] - (*(int**)b)[1]);
    }
}

void sort(int **a, int n)
{
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (cnt >= a[i][1]) {
                if (i - j > 0) {
                    int *t = a[i];
                    memmove(&a[j + 1], &a[j], sizeof(int*)*(i - j));
                    a[j] = t;
                }
                break;
            }
            if (a[j][0] >= a[i][0]) {
                cnt++;
            }
        }
    }
}

int** ReconstructQueue(int**a, int n, int* col, int* rn, int** rcol)
{
    if (a == NULL || n < 0 || col == NULL || rn == NULL || rcol == NULL) {
        return NULL;
    } else if (n == 0) {
        *rn = 0; // �ӵ㰡!
        return (int**)malloc(1);
    }
    int **p = mallocArr(n, col, rn, rcol);
    if (p == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col[i]; j++) {
            p[i][j] = a[i][j];
        }
    }
    qsort(p, n, sizeof(int*), cmp);
    sort(p, n);
    return p;
}

int main()
{
    int p[][2] = { {8, 0}, {4, 4}, {8, 1}, {5, 0}, {6, 1}, {5, 2} };
    int *a[] = { p[0], p[1], p[2],p[3], p[4] , p[5] };
    int n = sizeof(a) / sizeof(a[0]);
    int col[] = { 2,2,2,2,2,2,2,2,2 };
    int rn = 0;
    int *rcol = NULL;
    int **pp = ReconstructQueue(a, n, col, &rn, &rcol);
    if (pp != NULL) {
        for (int i = 0; i < rn; i++) {
            printf("(%d,%d) ", pp[i][0], pp[i][1]);
        }
    }
    freeArr(pp, rn);
    return 0;
}
