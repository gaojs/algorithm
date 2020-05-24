#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
	int r, c;
	int val;
} node_t;

#define N 100 // �㹻����
node_t adj[N*N] = {0}; // �ڽӵ��б�(�ٽӱ�) 
bool visit[N][N] = {0}; // �Ƿ��Ѽ����ٽ��б�
int min = INT_MIN; // ��Сֵ 
int count = 0; // �ڵ��� 

void init()
{ // ���������ݽṹ��ʼ�� 
	memset(adj, 0, sizeof(adj));
	memset(visit, 0, sizeof(visit));
	min = INT_MIN; 
	count = 0;
} 

int find(int left, int right, int val) 
{ // ����λ�ã����ֲ��ң��Ӵ�С 
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
{ // ��val�Ӵ�С ��˳����� 
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
{ // ֱ�ӵ������и���Сֵ�Ľڵ�
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
		min = min > t.val ? min : t.val; // ѡ��� 
		if (t.r == n -1 && t.c == n - 1) {
			return true; // �ҵ����մ��� 
		}
		if (t.r > 0 && !visit[t.r - 1][t.c]) { // �� 
			insert(t.r - 1, t.c, a[t.r - 1][t.c]);
		}		
		if (t.r + 1 < n && !visit[t.r + 1][t.c]) { // �� 
			insert(t.r + 1, t.c, a[t.r + 1][t.c]);
		}		
		if (t.c > 0 && !visit[t.r][t.c - 1]) { // �� 
			insert(t.r, t.c - 1, a[t.r][t.c - 1]);
		}		
		if (t.c + 1 < n && !visit[t.r][t.c + 1]) { // �� 
			insert(t.r, t.c + 1, a[t.r][t.c + 1]);
		}
		bfs(a, n); // �������� 
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
	init(); // ��ʼ�� 
	insert(0,0,a[0][0]);
	bfs(a, n); // ������� 
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


