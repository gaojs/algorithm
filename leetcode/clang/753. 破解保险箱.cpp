#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_COUNT 10000
int visited[MAX_COUNT] = {0};
char str[MAX_COUNT] = {0};
int len = 0;
int P = 0;

void dfs(int k, int i)
{
    i -= i / P * P;
    i *= 10;
    for (int j = 0; j < k; ++j) {
        int t = i + j;
        if (!visited[t]) {
            visited[t] = 1;
            dfs(k, t);
            str[len++] = j + '0';
        }
    }
}

char *crackSafe(int n, int k)
{
    memset(visited, 0, sizeof(visited));
    memset(str, 0, sizeof(str));
    P = pow(10, n - 1);
    visited[0] = 1;
    len = 0;
    dfs(k, 0);
    for (int i = 0; i < n; i++) {
    	str[len++] = '0';
	}
    return str;
}


int main()
{
	// int n = 1, k = 2; // 01
	int n = 2, k = 2; // 00110 10011 11001
	printf("%s", crackSafe(n,k));
	return 0;
} 


