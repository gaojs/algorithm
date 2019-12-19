//http://bailian.openjudge.cn/practice/1661/
#include <algorithm>
#include <iostream>
using namespace std;

struct paddle
{//平板
	int x1, x2;//平板的横坐标
	int y;//平板的纵坐标，即高度
};

const int N = 1000; //挡板最多的层数
const int RT = 20000; //挡板或地面的最右范围
const int LT = -20000; //挡板或地面的最左范围
const int MAX = 50000;
paddle a[N + 2] = { 0 };
int ltMin[N + 2] = { 0 };
int rtMin[N + 2] = { 0 };

int find(paddle a[], int n, int max)
{
	int i, j, lt, rt;

	ltMin[n] = rtMin[n] = a[n].y;
	for (i = n-1; i >= 0; i--)
	{
		lt = max, rt = max;
		for (j = i + 1; j <= n; j++)
		{//查找i层下面的挡板
			if (a[i].x1 >= a[j].x1 && a[i].x1 <= a[j].x2
				&& (a[i].y - a[j].y) < max)
			{//下面有挡板，并且不很高
				lt = a[i].y - a[j].y;
			}
		}
	}
	return ltMin[0] < rtMin[0] ? ltMin[0] : rtMin[0];
}

int main()
{
	int t, i, n, x, y, max, j;

	cin >> t;
	for (i = 0; i < t; i++)
	{//t组数据(0<=t<=20)
		//jimmy坐标(x,y)，最大坠落高度max
		cin >> n >> x >> y >> max;
		a[0].x1 = a[0].x2 = x;
		a[0].y = y; //高度
		for (j = 1; j <= n; j++)
		{//n层挡板(x1,x2,h)
			cin >> a[i].x1;
			cin >> a[i].x2;
			cin >> a[i].y;
		}
		a[n + 1].x1 = LT, a[n + 1].x1 = RT;
		a[n + 1].y = 0; //地面高度为0
		cout << find(a, n, max) << endl;
	}
	return 0;
}
