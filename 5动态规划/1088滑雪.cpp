//http://bailian.openjudge.cn/practice/1088/
#include <iostream>
using namespace std;

const int R = 100, C = 100;
//ÿ������ĸ߶�ֵ
int a[R][C] = { 0 };
//��ÿ������Ϊ�յ��·�߳���
int len[R][C] = { 0 };

int find(int a[R][C], int r, int c)
{
	int i, j, k, max = 0;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			len[i][j] = 1;
		}
	}
	for (k = 0; k < r * c; k++)
	{//·������޷���r*c
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (i > 0 && a[i][j] > a[i - 1][j])
				{//���Դ����滬����
					if (len[i][j] < len[i - 1][j] + 1)
					{
						len[i][j] = len[i - 1][j] + 1;
					}
				}
				if (i <r - 1 && a[i][j] > a[i + 1][j])
				{//���Դ����滬����
					if (len[i][j] < len[i + 1][j] + 1)
					{
						len[i][j] = len[i + 1][j] + 1;
					}
				}
				if (j > 0 && a[i][j] > a[i][j - 1])
				{//���Դ����滬����
					if (len[i][j] < len[i][j - 1] + 1)
					{
						len[i][j] = len[i][j - 1] + 1;
					}
				}
				if (j <c - 1 && a[i][j] > a[i][j + 1])
				{//���Դ����滬����
					if (len[i][j] < len[i][j + 1] + 1)
					{
						len[i][j] = len[i][j + 1] + 1;
					}
				}
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
	int r, c, i, j;

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

