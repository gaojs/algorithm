//http://bailian.openjudge.cn/practice/1088/
#include <algorithm>
#include <iostream>
using namespace std;

struct section
{//区块
	int x, y;//坐标
	int h;//高度

	bool operator<(section s1)
	{
		return h < s1.h;
	}
};

const int R = 100, C = 100;
//每个区块的数组
section sec[R * C] = { 0 };
int a[R][C] = { 0 }; //方便访问
//以每个区块为终点的路线长度
int len[R][C] = { 0 };

int find(section s[], int a[R][C], int r, int c)
{
	int n = r * c; //元素个数
	int i, j, max = 0; //最长路径

	for (i = 0; i < r; i++)
	{//初始长度
		for (j = 0; j < c; j++)
		{
			len[i][j] = 1;
		}
	}
	//先按高度从小到大排序 
	sort(s, s + n); //很关键 
	for (i = 0; i < n; i++)
	{
		int x = s[i].x, y = s[i].y;
		if (y > 0 && a[y][x] > a[y - 1][x])
		{//可以从上面滑过来
			if (len[y][x] < len[y - 1][x] + 1)
			{
				len[y][x] = len[y - 1][x] + 1;
			}
		}
		if (y < r - 1 && a[y][x] > a[y + 1][x])
		{//可以从下面滑过来
			if (len[y][x] < len[y + 1][x] + 1)
			{
				len[y][x] = len[y + 1][x] + 1;
			}
		}
		if (x > 0 && a[y][x] > a[y][x - 1])
		{//可以从左面滑过来
			if (len[y][x] < len[y][x - 1] + 1)
			{
				len[y][x] = len[y][x - 1] + 1;
			}
		}
		if (x< c - 1 && a[y][x] > a[y][x + 1])
		{//可以从右面滑过来
			if (len[y][x] < len[y][x + 1] + 1)
			{
				len[y][x] = len[y][x + 1] + 1;
			}
		}
	}
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (max < len[i][j])
			{
				max = len[i][j];
			}
		}
	}
	return max;
}

int main()
{
	int r, c, i, j, n = 0;

	cin >> r >> c;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cin >> a[i][j];
			sec[n].y = i; //纵坐标
			sec[n].x = j; //横坐标
			sec[n].h = a[i][j]; //高度
			n++;
		}
	}
	cout << find(sec, a, r, c);
	return 0;
}
