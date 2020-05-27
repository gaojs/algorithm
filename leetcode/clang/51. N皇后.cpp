bool check(int row, int c, int* visited) {    
    for (int i = 0; i < row; i++) {
        if (visited[i] == c) {
            return false;
        }
        if (visited[i] - c == i - row) {
            return false;
        }
        if (visited[i] - c == row - i) {
            return false;
        }
    }
    //printf("row=%d, c=%d\n", row, c);
    return true;
}

void backtrace(int n, int row, int* visited, int* returnSize, char ***s) {
    if (n == row) {
        s[*returnSize] = (char**)calloc(n, sizeof(char*));
        for (int i = 0; i < row; i++) {
            s[*returnSize][i] = (char*)calloc(n + 1, sizeof(char));
            memset(s[*returnSize][i], '.', n * sizeof(char));
            s[*returnSize][i][visited[i]] = 'Q';
        }        
        (*returnSize)++; 
    } else {
        for (int c = 0; c < n; c++) {
            if (check(row, c, visited)) {
                visited[row] = c;
                //printf("visited[%d], c=%d\n", row, c);
                backtrace(n, row + 1, visited, returnSize, s);
                //visited[row] = 0; // »ØËÝ 
            }
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int *visited = (int*)calloc(n, sizeof(int));
    char ***s = (char***)malloc(n * n * n * sizeof(char**));
    backtrace(n, 0, visited, returnSize, s);
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return s;
}
