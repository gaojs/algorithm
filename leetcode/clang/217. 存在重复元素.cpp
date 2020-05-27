#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    int index;
};

#define N 100000 // ×ã¹»´ó
struct node g[N] = { 0 };

int cmp(const void*a, const void*b) {
    const struct node*a1 = (const struct node*)a;
    const struct node*b1 = (const struct node*)b;
    if (a1->value == b1->value) {
        if (a1->index == b1->index) {
            return 0;
        } else if (a1->index < b1->index) {
            return -1;
        } else {
            return 1;
        }
    } else {
        if (a1->value < b1->value) {
            return -1;
        } else {
            return 1;
        }
    }
}

bool containsNearbyDuplicate(int* a, int n, int k)
{
    if (a == NULL || n <= 0) {
        return false;
    }
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; i++) {
        g[i].value = a[i];
        g[i].index = i;
    }
    qsort(g, n, sizeof(struct node), cmp);
    /** for (int i = 0; i < n; i++) {
        printf("%d,%d   ", g[i].value, g[i].index);
    } */
    for (int i = 1; i < n; i++) {
        if (g[i].value == g[i - 1].value
            && abs(g[i].index - g[i - 1].index) <= k) {
            return true;
        }
    }
    return false;
}

int main()
{
    /*****************************
    */
    // int a[] = { 1,2,3,1 }, k = 3; // true
    // int a[] = { 1,0,1,1 }, k = 1; // true
    int a[] = { 1,2,3,1,2,3 }, k = 2; // true
    int n = sizeof(a) / sizeof(a[0]);
    int returnSize = 0;
    if (containsNearbyDuplicate(a, n, k)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}

