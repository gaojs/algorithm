//http://bailian.openjudge.cn/practice/2755
#include <iostream>
using namespace std;

const int N = 30;
int a[N] = { 0 };

int ways(int w, int n)
{
	if (w == 0) return 1;
	if (n <= 0) return 0;
	return ways(w, n - 1) + ways(w - a[n], n - 1);
}

int main()
{
	int n,i;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << ways(40, n);
	return 0;
}

