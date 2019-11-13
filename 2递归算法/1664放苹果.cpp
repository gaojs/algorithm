//http://bailian.openjudge.cn/practice/1664/
//把M个苹果放到N个盘子里，有多少种放法 
#include <iostream>
using namespace std;

int apple(int m, int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (m == 0 || m == 1)
	{
		return 1;
	}
	else if (m < n)
	{
		return  apple(m, m);
	}
	else
	{
		return apple(m, n - 1) + apple(m - n, n);
	}
}

int main()
{
	int k, m, n;
	cin >> k;
	while (k--)
	{
		cin >> m >> n;
		cout << apple(m, n) << endl;
	}
	return 0;
}
