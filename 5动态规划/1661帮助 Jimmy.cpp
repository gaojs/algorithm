//http://bailian.openjudge.cn/practice/1661/
#include <algorithm>
#include <iostream>
using namespace std;

struct paddle
{//ƽ��
	int x1, x2;//ƽ��ĺ�����
	int y;//ƽ��������꣬���߶�
};

const int N = 1000; //�������Ĳ���
const int RT = 20000; //������������ҷ�Χ
const int LT = -20000; //�������������Χ
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
		{//����i������ĵ���
			if (a[i].x1 >= a[j].x1 && a[i].x1 <= a[j].x2
				&& (a[i].y - a[j].y) < max)
			{//�����е��壬���Ҳ��ܸ�
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
	{//t������(0<=t<=20)
		//jimmy����(x,y)�����׹��߶�max
		cin >> n >> x >> y >> max;
		a[0].x1 = a[0].x2 = x;
		a[0].y = y; //�߶�
		for (j = 1; j <= n; j++)
		{//n�㵲��(x1,x2,h)
			cin >> a[i].x1;
			cin >> a[i].x2;
			cin >> a[i].y;
		}
		a[n + 1].x1 = LT, a[n + 1].x1 = RT;
		a[n + 1].y = 0; //����߶�Ϊ0
		cout << find(a, n, max) << endl;
	}
	return 0;
}
