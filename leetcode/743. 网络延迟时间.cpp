#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NODE_COUNT 110
typedef struct {
	int id; //下一个节点ID 
	int time; // 时间值 
} next_t;

typedef struct {
	bool visited; // 是否被访问过 
	int min_time; // 访问到它的最少时间 
	int next_count; // 多少个可达节点 
	next_t next[NODE_COUNT]; // 可达节点列表 
} node_t; 

node_t nodes[NODE_COUNT]= {0}; // 网络节点列表 
//0位存数量；其余存放节点ID，按耗时从大到小存放 
int adj[NODE_COUNT]; // 邻接可访问的ID列表
int visit_cnt; // 访问数量 
int min_time; // 最小耗时

int cmp(const void*a, const void*b)
{ // 按耗时从大到小排序 
	int n1 = *(int*)a, n2 = *(int*)b;
	return -(nodes[n1].min_time - nodes[n2].min_time); 
}

bool push(int k) 
{
	if (!nodes[k].visited) {	
		// printf("push:%d\n", k);
		nodes[k].visited = true;
		if (adj[0] < NODE_COUNT - 1) {
			adj[0]++;
			adj[adj[0]] = k; 
			return true;			
		}
	}
	return false;
}

int pop()
{
	if (adj[0] <= 0) {
		return -1; // 空了 
	} 
	// 按耗时，从大到小排序，取最后一个 
	qsort(&adj[1], adj[0], sizeof(int), cmp);
	int k = adj[adj[0]]; // 最后一个 
	adj[adj[0]] = -1; 
	adj[0]--;
	// printf("pop:%d\n", k);
	return k;	
}

void bfs(int N)
{
	int k = pop();
	if (k >= 0) { // 仍然有节点 
		visit_cnt++; // 访问节点数 
		// printf("bfs:%d, time=%d\n", k, nodes[k].min_time);
		if (min_time < nodes[k].min_time) {
			min_time = nodes[k].min_time; 
		} 
		for (int i = 0; i < nodes[k].next_count; i++) {
			int id = nodes[k].next[i].id;
			int time = nodes[k].next[i].time;
			if (nodes[id].min_time > nodes[k].min_time + time) {
				nodes[id].min_time = nodes[k].min_time + time;
			}			
			// printf("id=%d, time=%d, min_time=%d\n", id, time, nodes[id].min_time);
			push(id); // 入栈 
		}
		bfs(N); 
	} 	
} 

void display(int N) 
{
	for (int r = 1; r <= N; r++) { // 生成网络 
		printf("(%d,%d): ", r, nodes[r].min_time);
		for (int c = 0; c < nodes[r].next_count; c++) {			
			printf("(%d,%d), ", nodes[r].next[c].id, nodes[r].next[c].time);		
		}
		printf("\n");
	}	
}

int networkDelayTime(int**a, int n, int*col, int N, int K)
{
	if (a == NULL || n <= 0 || N <= 0 || K >= N) {
		return -1;
	} else if (N > NODE_COUNT) {
		printf("overflow");
		return -1;
	}
	memset(nodes, 0, sizeof(nodes));
	for (int r = 1; r <= N; r++) { // 生成网络 
		nodes[r].min_time = INT_MAX; // 不可达 
	}
	for (int r = 0; r < n; r++) { // 生成网络 
		int n1 = a[r][0]; // 本节点 
		int n2 = a[r][1]; // 可达节点 
		int time = a[r][2]; // 所耗时间 
		int nc = nodes[n1].next_count;
		nodes[n1].next[nc].id = n2;
		nodes[n1].next[nc].time = time;
		nodes[n1].next_count++; // 邻接数增加 
	}
	// display(N);
	memset(adj, 0, sizeof(adj));
	visit_cnt = 0; 
	min_time = INT_MIN;
	nodes[K].min_time = 0;
	push(K); // k入栈 
	bfs(N); // 开始遍历 
	if (visit_cnt == N) {
		return min_time;
	} else { // 无法访问完全 
		return -1;
	}	
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


