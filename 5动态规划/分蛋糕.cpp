//http://cxsjsxmooc.openjudge.cn/2019t2fall7/003/
//http://cxsjsxmooc.openjudge.cn/2019t2fallall/017/
#include <iostream>
using namespace std;

const int M = 20;
const int MAX = (M * M + 1);
//��1������2�� 
int a[M] = { 0 };

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
		int svMin = MAX, shMin = MAX;
		for (int i = 1; i < w; i++)
		{//������,��߿�Ϊi����ý��
			for (int k = 0; k < m; k++)
			{//����߿�Ϊi�ĵ�������k��
				int left = find(i, h, k);
				int right = find(w - i, h, m - 1 - k);
				int max = left > right ? left : right;
				if (svMin > max)
				{//�������߶��Ƚ�С
					svMin = max;
				}
			}
		}		
		for (int i = 1; i < h; i++)
		{//������,�ϱ߿�Ϊi����ý��
			for (int k = 0; k < m; k++)
			{//���ϱ߿�Ϊi�ĵ�������k��
				int up = find(w, i, k);
				int down = find(w, h - i, m - 1 - k);
				int max = up > down ? up : down;
				if (shMin > max)
				{//�������߶��Ƚ�С
					shMin = max;
				}
			}
		}
		return (svMin < shMin) ? svMin : shMin;
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
		cout << find(w, h, m-1) << endl;
	}
	return 0;
}

