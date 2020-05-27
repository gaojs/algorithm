#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void*a, const void*b)
{
    return (long long)*(int*)a - (long long)*(int*)b;
}

int longestConsecutive(int* a, int n)
{
    if (a == NULL || n == 0) {
        return 0;
    }
    qsort(a, n, sizeof(int), cmp);    
    int t =a[0], cnt = 1, max = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == t) {
            continue; 
        } else if (a[i] - t == 1) {
            t = a[i]; 
            cnt++;
            if (max < cnt) {
                max = cnt; 
            }
        } else {
            t = a[i]; 
            cnt = 1;
        }            
    }
    return max;
}

int main()
{
    // int a[] = {1,2,0,1}; // 3
	// int a[] = {100, 4, 200, 1, 3, 2}; // 4
	int a[] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645}; // 4
	int n = sizeof(a) / sizeof(a[0]);
	printf("%d", longestConsecutive(a, n));		
	return 0;
}

