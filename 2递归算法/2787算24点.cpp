//http://bailian.openjudge.cn/practice/2787/
//输入四个数，判断它们能用加减乘除，算出24点
//要考虑小数，比如：(5－(1÷5))×5=24
#include <cmath> //abs
#include <iostream>
using namespace std;

const int N = 4; //数的个数
const int C24 = 24; //常数24
const double EPS = 1e-6; //小值
int count24(double a[], int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		if (abs(a[0] - C24) < EPS)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		double b[N] = { 0 };
		int i = 0, j = 0;
		int count = 0; //解法数量
		//随机选取两个数，让它们进行计算
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				double x = a[i];
				double y = a[j];
				int m = 0, k = 0;
				//将剩余的数，前移
				for (k = 0; k < n; k++)
				{
					if (k == i || k == j)
					{//被选取了，不移动
						continue;
					}
					//放到b中，注意是b
					b[m++] = a[k];
				}
				b[m] = x + y; //加法
				count += count24(b, n - 1);
				b[m] = x - y; //减法
				count += count24(b, n - 1);
				b[m] = y - x; //减法
				count += count24(b, n - 1);
				b[m] = x * y; //乘法
				count += count24(b, n - 1);
				if (y != 0)// && x % y == 0)
				{
					b[m] = x / y; //除法
					count += count24(b, n - 1);
				}
				if (x != 0)// && y % x == 0)
				{
					b[m] = y / x; //除法
					count += count24(b, n - 1);
				}
			}
		}
		return count;
	}
}

int main()
{
	while (true)
	{
		double a[N] = { 0 };
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
			if (a[i] <= 0)
			{
				return 0;
			}
		}
		if (count24(a, N))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
