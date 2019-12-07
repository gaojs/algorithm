//http://bailian.openjudge.cn/practice/4127/
#include <iostream>
using namespace std;

struct node
{
	int x, y;
	int step;
};

const int N = 5;
int maze[N][N] = { 0 };
node ways[N * N] = { 0 };

//Prim最小生成树算法，BFS
//Dijkstra单源最短路径算法，BFS
//Floyd多源最短路径算法，动态规划
//Breadth first search
void bfs()
{

}

int main()
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> maze[i][j];
		}
	}
	cout<<bfs(0,0);
	return 0;
}
