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

//Prim��С�������㷨��BFS
//Dijkstra��Դ���·���㷨��BFS
//Floyd��Դ���·���㷨����̬�滮
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
