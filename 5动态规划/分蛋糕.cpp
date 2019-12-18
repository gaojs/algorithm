//http://cxsjsxmooc.openjudge.cn/2019t2fall7/003/
//http://cxsjsxmooc.openjudge.cn/2019t2fallall/017/
#include <iostream>
using namespace std;

const int M = 20;
const int MAX = (M * M + 1);
//��1������2�� 
int a[M + 1][M + 1][M * M] = { 0 };

//����ʽ��find(w,h,m)=min(sv,sh)
//svΪ��һ�������У�shΪ��һ��������
//sv=min{sv[i],i=1...w-1} //��߿�Ϊi����ý��
//sv[i]=min(max(find(i,h,k),find(w-i,h,m-1-k)),k=0...m-1
//sh=min{sh[i],i=1...h-1} //�ϱ߿�Ϊi����ý��
//��w��h�ĵ��⣬m��֮���������Сֵ
int find(int w, int h, int m)
{
	if (m <= 0)
	{//ֻ��1��
		return w * h;
	}
	else if (m >= w * h)
	{//û�취����
		return MAX;
	}
	else
	{//����1��
		for (int i = 0; i <= w; i++)
		{//��
			for (int j = 0; j <= h; j++)
			{//��
				a[i][j][0] = i * j; //������
			}
		}
		for (int mt = 1; mt <= m; mt++)
		{
			for (int wt = 0; wt <= w; wt++)
			{
				for (int ht = 0; ht <= h; ht++)
				{
					int svMin = MAX, shMin = MAX;
					for (int i = 1; i < wt; i++)
					{//������,��߿�Ϊi����ý��
						for (int j = 0; j < mt; j++)
						{//����߿�Ϊi�ĵ�������j��
							int left = a[i][ht][j];
							int right = a[wt - i][ht][mt - 1 - j];
							int max = left > right ? left : right;
							if (svMin > max)
							{//�������߶��Ƚ�С
								svMin = max;
							}
						}
					}
					for (int i = 1; i < ht; i++)
					{//������,�ϱ߿�Ϊi����ý��
						for (int j = 0; j < mt; j++)
						{//���ϱ߿�Ϊi�ĵ�������j��
							int up = a[wt][i][j];
							int down = a[wt][ht - i][mt - 1 - j];
							int max = up > down ? up : down;
							if (shMin > max)
							{//�������߶��Ƚ�С
								shMin = max;
							}
						}
					}
					a[wt][ht][mt] = (svMin < shMin) ? svMin : shMin;
				}
			}
		}
		return a[w][h][m];
	}
}

int main()
{
	int w, h, m;

	while (cin >> w >> h >> m)
	{
		if (w == 0 || h == 0 || m == 0)
		{
			break;
		}
		cout << find(w, h, m - 1) << endl;
	}
	return 0;
}

