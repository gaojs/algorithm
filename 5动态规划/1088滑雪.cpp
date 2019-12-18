//http://bailian.openjudge.cn/practice/1088/
#include <iostream>
using namespace std;

const int R = 100, C = 100;
int a[R][C] = { 0 };

int find(int** a, int r, int c)
{
	return 0;
}

int main()
{
	int r, c,i,j;

	cin >> r >> c;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << find(a, r, c);
	return 0;
}

