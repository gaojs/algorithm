#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int networkDelayTime(int**a, int n, int*col, int N, int K)
{
	
}

int main()
{
	int p[][3] ={{2,1,1},{2,3,1},{3,4,1}};
	int *a[] = {p[0],p[1],p[2]}, N = 4, K = 2; // 2
	int col[] = {3,3,3};
	int n = sizeof(a) / sizeof(a[0]);
	printf("%d", networkDelayTime(a, n, col, N, K));
	return 0;
} 


