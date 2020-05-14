#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b) {
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* a, int n)
{
    if (a == NULL || n <= 0) {
        return false;
    }
    qsort(a, n, sizeof(int), cmp);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
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

