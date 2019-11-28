//http://bailian.openjudge.cn/practice/2815/
#include <iostream>
using namespace std;

const int M = 60, N = 60;
int w[M][N] = { 0 }; //ǽwall
int c[M][N] = { 0 }; //��ɫcolor
int m = 0, n = 0; //��m��n

//�����������depth first search
void dfs(int i, int j, int& color, int& num)
{//1��ǽ��2��ǽ��4��ǽ��8��ǽ��
	//�߹�����Ϳ��ɫ���ӱ��
	c[i][j] = color, num++;
	if (!(w[i][j] & 0x01) && j > 0)
	{//û��ǽ������û����
		if (c[i][j - 1] == 0)
		{//û�߹�
			dfs(i, j - 1, color, num);
		}
	}
	if (!(w[i][j] & 0x02) && i > 0)
	{//û��ǽ������û����
		if (c[i - 1][j] == 0)
		{//û�߹�
			dfs(i - 1, j, color, num);
		}
	}
	if (!(w[i][j] & 0x04) && j < n - 1)
	{//û��ǽ������û����
		if (c[i][j + 1] == 0)
		{//û�߹�
			dfs(i, j + 1, color, num);
		}
	}
	if (!(w[i][j] & 0x08) && i < m - 1)
	{//û��ǽ������û����
		if (c[i + 1][j] == 0)
		{//û�߹�
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
				//�ҵ��·��䣬Ϳ��ɫ
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
