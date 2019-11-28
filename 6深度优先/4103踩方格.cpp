//http://bailian.openjudge.cn/practice/4103/
#include <cstring>
#include <iostream>
using namespace std;

const int N = 20; //步数
int w[N + 1][2 * N + 1];

int dfs(int i, int j, int n)
{
	if (n <= 0)
	{//站在原地，1种走法
		return 1;
	}
	else //if (n > 0)
	{//可以往北、东、西三个方向走
		int m = 0;
		w[i][j] = 1;
		if (!w[i - 1][j])
		{//北
			m += dfs(i - 1, j, n - 1);
		}
		if (!w[i][j - 1])
		{//西
			m += dfs(i, j - 1, n - 1);
		}
		if (!w[i][j + 1])
		{//东
			m += dfs(i, j + 1, n - 1);
		}
		w[i][j] = 0;
		return m;
	}
}

int main()
{
	int n;

	cin >> n;
	memset(w, 0, sizeof(w));
	cout << dfs(n, n, n);
	return 0;
}
