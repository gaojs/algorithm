#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200
int visit[N][N] = { 0 };

bool dfs(char** a, int n, int* col, char *word, int r, int c) 
{
	if (a == NULL || n == 0 || col == NULL || word == NULL) {
		return false; // 参数错误
    } else if (r < 0 || r >= n || c < 0 || c >= *col) {
        return false; // 越界了
    } else if (visit[r][c]) {  
        return false; // 已访问
    } else if (a[r][c] != word[0]) { 
		return false; // 字母不相等 
	} else if (strlen(word) == 1) { // 只有1个字母，并且相等 
		return true;
	} else { // 查看后续的字母 
        visit[r][c] = 1; // 已访问 
		if (dfs(a, n, col, &word[1], r - 1, c)) {
			return true;
		}
		if (dfs(a, n, col, &word[1], r + 1, c)) {
			return true;
		}
		if (dfs(a, n, col, &word[1], r, c - 1)) {
			return true;
		}
		if (dfs(a, n, col, &word[1], r, c + 1)) {
			return true;
		}
        visit[r][c] = 0; // 回溯 
		return false; 
	}
} 

bool exist(char** a, int n, int* col, char *word)
{
	if (a == NULL || n == 0 || col == NULL || word == NULL ) {
		return false;
	} 
    memset(visit, 0, sizeof(visit));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < col[r]; c++) {
			if (a[r][c] != word[0]) {
				continue; // 找其他的 
			} 
			if(dfs(a, n, col, &word[0], r, c)) {
				return true;
			}
		}
	}	
	return false;
}

int main()
{
	/*****************************
    */
    char r1[] = {'A','B','C','E'};
	char r2[] = {'S','F','C','S'};
	char r3[] = {'A','D','E','E'};
	char *a[] = {r1, r2, r3};
	int col[] = {4, 4, 4};
    // char word[] = "ABCCED"; // true
    // char word[] = "SEE"; // true
    char word[] = "ABCB"; // false
	/*****************************
    char r1[] = {'a'};
	char *a[] = {r1};
	int col[] = {1};
	char word[] = "a"; // true
    */
	int n = sizeof(a) / sizeof(a[0]);
	if (exist(a, n, col, word)) {	
		printf("true");	
	} else {
		printf("false");		
	}
	return 0;
}

