//http://bailian.openjudge.cn/practice/2815/
#include <iostream>
using namespace std;

const int M = 60, N = 60;
int w[M][N] = { 0 }; //墙wall
int c[M][N] = { 0 }; //颜色color
int m = 0, n = 0; //行m列n

//深度优先搜索depth first search
void dfs(int i, int j, int& color, int& num)
{//1西墙，2北墙，4东墙，8南墙。
	//走过，就涂颜色，加编号
	c[i][j] = color, num++;
	if (!(w[i][j] & 0x01) && j > 0)
	{//没有墙，并且没出界
		if (c[i][j - 1] == 0)
		{//没走过
			dfs(i, j - 1, color, num);
		}
	}
	if (!(w[i][j] & 0x02) && i > 0)
	{//没有墙，并且没出界
		if (c[i - 1][j] == 0)
		{//没走过
			dfs(i - 1, j, color, num);
		}
	}
	if (!(w[i][j] & 0x04) && j < n - 1)
	{//没有墙，并且没出界
		if (c[i][j + 1] == 0)
		{//没走过
			dfs(i, j + 1, color, num);
		}
	}
	if (!(w[i][j] & 0x08) && i < m - 1)
	{//没有墙，并且没出界
		if (c[i + 1][j] == 0)
		{//没走过
			dfs(i + 1, j, color, num);
		}
	}
}


int main()
{
	int i, j, color, max, num;

	cin >> m >> n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> w[i][j];
			c[i][j] = 0;
		}
	}
	color = 0, max = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (c[i][j] == 0)
			{
				//找到新房间，涂颜色
				color++, num = 0;
				dfs(i, j, color, num);
				if (max < num)
				{
					max = num;
				}				
			}
		}
	}
	cout << color << endl << max;
	return 0;
}
