//http://bailian.openjudge.cn/practice/1088/
#include <algorithm>
#include <iostream>
using namespace std;

struct section
{//����
	int x, y;//����
	int h;//�߶�

	bool operator<(section s1)
	{
		return h < s1.h;
	}
};

const int R = 100, C = 100;
//ÿ�����������
section sec[R * C] = { 0 };
int a[R][C] = { 0 }; //�������
//��ÿ������Ϊ�յ��·�߳���
int len[R][C] = { 0 };

int find(section s[], int a[R][C], int r, int c)
{
	int n = r * c; //Ԫ�ظ���
	int i, j, max = 0; //�·��

	for (i = 0; i < r; i++)
	{//��ʼ����
		for (j = 0; j < c; j++)
		{
			len[i][j] = 1;
		}
	}
	//�Ȱ��߶ȴ�С�������� 
	sort(s, s + n); //�ܹؼ� 
	for (i = 0; i < n; i++)
	{
		int x = s[i].x, y = s[i].y;
		if (y > 0 && a[y][x] > a[y - 1][x])
		{//���Դ����滬����
			if (len[y][x] < len[y - 1][x] + 1)
			{
				len[y][x] = len[y - 1][x] + 1;
			}
		}
		if (y < r - 1 && a[y][x] > a[y + 1][x])
		{//���Դ����滬����
			if (len[y][x] < len[y + 1][x] + 1)
			{
				len[y][x] = len[y + 1][x] + 1;
			}
		}
		if (x > 0 && a[y][x] > a[y][x - 1])
		{//���Դ����滬����
			if (len[y][x] < len[y][x - 1] + 1)
			{
				len[y][x] = len[y][x - 1] + 1;
			}
		}
		if (x< c - 1 && a[y][x] > a[y][x + 1])
		{//���Դ����滬����
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
			sec[n].y = i; //������
			sec[n].x = j; //������
			sec[n].h = a[i][j]; //�߶�
			n++;
		}
	}
	cout << find(sec, a, r, c);
	return 0;
}
