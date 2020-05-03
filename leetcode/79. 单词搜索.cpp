#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool dfs(char** board, int boardSize, int* boardColSize, char *word, int r, int c, int *visited) 
{
	if (board == NULL || boardSize == 0 || boardColSize == NULL || word == NULL || visited == NULL) {
		return false;
	} 
	// printf("[%d][%d]=%c, %c\n", r, c, board[r][c], word[0]); 
	if (board[r][c] != word[0])	{ // 字母不相等 
		return false;
	} else if (strlen(word) == 1) { // 只有1个字母，并且相等 
		return true;
	} else { // 查看后续的字母 
		visited[r * boardColSize[0] + c] = 1; // 已访问 
		if (r > 0 && !visited[(r - 1) * boardColSize[0] + c]) {
			if (dfs(board, boardSize, boardColSize, &word[1], r - 1, c, visited)) {
				return true;
			}
		}
		if (r < boardSize - 1 && !visited[(r + 1) * boardColSize[0] + c]) {
			if (dfs(board, boardSize, boardColSize, &word[1], r + 1, c, visited)) {
				return true;
			}
		}
		if (c > 0 && !visited[r * boardColSize[0] + c - 1]) {
			if (dfs(board, boardSize, boardColSize, &word[1], r, c - 1, visited)) {
				return true;
			}
		}
		if (c < boardColSize[r] - 1 && !visited[r * boardColSize[0] + c + 1]) {
			if (dfs(board, boardSize, boardColSize, &word[1], r, c + 1, visited)) {
				return true;
			}
		}
		visited[r * boardColSize[0] + c] = 0; // 回溯 
		return false; 
	}
} 

bool exist(char** board, int boardSize, int* boardColSize, char *word)
{
	if (board == NULL || boardSize == 0 || boardColSize == NULL || word == NULL ) {
		return false;
	} 
	// printf("r=%d, c=%d\n", boardSize, boardColSize[0]);
	int *visited = (int*)calloc(sizeof(int), boardSize * boardColSize[0]);
	if (visited == NULL) {
		return false;
	}
	for (int r = 0; r < boardSize; r++) {
		for (int c = 0; c < boardColSize[r]; c++) {
			if (board[r][c] != word[0]) {
				continue; // 找其他的 
			} else {
				memset(visited, 0, sizeof(int) * boardSize * boardColSize[0]);
				if(dfs(board, boardSize, boardColSize, &word[0], r, c, visited)) {
					// printf("%c", word[0]); 
					free(visited);
					return true;
				}
			} 
		}
	}	
	free(visited);
	return false;
}

int main()
{
	char r1[] = {'A','B','C','E'};
	char r2[] = {'S','F','C','S'};
	char r3[] = {'A','D','E','E'};
	char *board[] = {r1, r2, r3};
	int boardColSize[] = {4, 4, 4};
	// char word[] = "ABCCED";
	// char word[] = "SEE";
	char word[] = "ABCB";
	/*char r1[] = {'a'};
	char *board[] = {r1};
	int boardColSize[] = {1};
	char word[] = "a";*/
	int boardSize = sizeof(board) / sizeof(board[0]);
	if (exist(board, boardSize, boardColSize, word)) {	
		printf("true");	
	} else {
		printf("false");		
	}
	return 0;
}

