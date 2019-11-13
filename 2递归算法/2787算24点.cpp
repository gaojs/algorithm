//http://bailian.openjudge.cn/practice/2787/
//�����ĸ������ж��������üӼ��˳������24��
//Ҫ����С�������磺(5��(1��5))��5=24
#include <cmath> //abs
#include <iostream>
using namespace std;

const int N = 4; //���ĸ���
const int C24 = 24; //����24
const double EPS = 1e-6; //Сֵ
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
		int count = 0; //�ⷨ����
		//���ѡȡ�������������ǽ��м���
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				double x = a[i];
				double y = a[j];
				int m = 0, k = 0;
				//��ʣ�������ǰ��
				for (k = 0; k < n; k++)
				{
					if (k == i || k == j)
					{//��ѡȡ�ˣ����ƶ�
						continue;
					}
					//�ŵ�b�У�ע����b
					b[m++] = a[k];
				}
				b[m] = x + y; //�ӷ�
				count += count24(b, n - 1);
				b[m] = x - y; //����
				count += count24(b, n - 1);
				b[m] = y - x; //����
				count += count24(b, n - 1);
				b[m] = x * y; //�˷�
				count += count24(b, n - 1);
				if (y != 0)// && x % y == 0)
				{
					b[m] = x / y; //����
					count += count24(b, n - 1);
				}
				if (x != 0)// && y % x == 0)
				{
					b[m] = y / x; //����
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
