#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
	int r, c;
	int val;
} node_t;

#define N 100 // 足够大了
node_t adj[N*N] = {0}; // 邻接点列表(临接表) 
bool visit[N][N] = {0}; // 是否已加入临接列表
int min = INT_MIN; // 最小值 
int count = 0; // 节点数 

void init()
{ // 将辅助数据结构初始化 
	memset(adj, 0, sizeof(adj));
	memset(visit, 0, sizeof(visit));
	min = INT_MIN; 
	count = 0;
} 

int find(int left, int right, int val) 
{ // 查找位置，二分查找，从大到小 
	if (left > right) {
		return left; 
	} else {
		int mid = left + (right - left) / 2;
		if (val > adj[mid].val) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
		return find(left, right, val);
	}
}

bool insert(int r, int c, int val) 
{ // 按val从大到小 的顺序插入 
	if (count >= N*N) {
		return false;
	}
	// printf("(%d,%d)=%d\n", r, c, val);
	int pos = find(0, count - 1, val);
	// printf("pos=%d\n", pos);
	if (pos < count) {
		int size = sizeof(node_t) * (count - pos);
		memmove(&adj[pos + 1], &adj[pos], size);
	}
	adj[pos].r = r;
	adj[pos].c = c;
	adj[pos].val = val;
	visit[r][c] = true; 
	count++;
	return true; 
}

bool pop(node_t *n)
{ // 直接弹出最有个最小值的节点
	if(count > 0) {
		count--;
		*n = adj[count];
		return true;
	}
	return false;
}

bool bfs(int**a, int n) 
{
	node_t t;
	
	if (pop(&t)) {
		// printf("[%d,%d]=%d\n", t.r, t.c, t.val);
		min = min > t.val ? min : t.val; // 选大的 
		if (t.r == n -1 && t.c == n - 1) {
			return true; // 找到最终答案了 
		}
		if (t.r > 0 && !visit[t.r - 1][t.c]) { // 上 
			insert(t.r - 1, t.c, a[t.r - 1][t.c]);
		}		
		if (t.r + 1 < n && !visit[t.r + 1][t.c]) { // 下 
			insert(t.r + 1, t.c, a[t.r + 1][t.c]);
		}		
		if (t.c > 0 && !visit[t.r][t.c - 1]) { // 左 
			insert(t.r, t.c - 1, a[t.r][t.c - 1]);
		}		
		if (t.c + 1 < n && !visit[t.r][t.c + 1]) { // 右 
			insert(t.r, t.c + 1, a[t.r][t.c + 1]);
		}
		bfs(a, n); // 继续遍历 
	}
	return false;
}

int swimInWater(int**a, int n, int*col)
{
	if (a == NULL || n <= 0) {
		return 0;
	} else if (n > N) {
		printf("n=%d", n);
		return 0;
	} 
	init(); // 初始化 
	insert(0,0,a[0][0]);
	bfs(a, n); // 广度优先 
	return min;	
}

int main()
{
	/***************
	int p[][2] = {{0,2},{1,3}}; // 3
	int *a[] = {p[0],p[1]};*/
	int p[][5] = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
	int *a[] = {p[0],p[1],p[2],p[3],p[4]}; 
	int n = sizeof(a) / sizeof(a[0]);	
	int col[] = {1};
	printf("%d", swimInWater(a, n, col));
	return 0;
} 


