//http://cxsjsxmooc.openjudge.cn/2019t2fall7/003/
//http://cxsjsxmooc.openjudge.cn/2019t2fallall/017/
#include <iostream>
using namespace std;

const int M = 20;
const int MAX = (M * M + 1);
//切1刀，分2块 
int a[M] = { 0 };

//递推式：find(w,h,m)=min(sv,sh)
//sv为第一刀竖着切，sh为第一刀横着切
//sv=min{sv[i],i=1...w-1} //左边宽为i的最好结果
//sv[i]=min(max(find(i,h,k),find(w-i,h,m-1-k)),k=0...m-1
//sh=min{sh[i],i=1...h-1} //上边宽为i的最好结果
//宽w高h的蛋糕，m刀之后，最大块的最小值
int find(int w, int h, int m)
{
	if (m <= 0)
	{//只有1块
		return w * h;
	}
	else if (m >= w * h)
	{//没办法切了
		return MAX;
	}
	else
	{//多于1块
		int svMin = MAX, shMin = MAX;
		for (int i = 1; i < w; i++)
		{//竖着切,左边宽为i的最好结果
			for (int k = 0; k < m; k++)
			{//在左边宽为i的蛋糕上切k刀
				int left = find(i, h, k);
				int right = find(w - i, h, m - 1 - k);
				int max = left > right ? left : right;
				if (svMin > max)
				{//左右两边都比较小
					svMin = max;
				}
			}
		}		
		for (int i = 1; i < h; i++)
		{//横着切,上边宽为i的最好结果
			for (int k = 0; k < m; k++)
			{//在上边宽为i的蛋糕上切k刀
				int up = find(w, i, k);
				int down = find(w, h - i, m - 1 - k);
				int max = up > down ? up : down;
				if (shMin > max)
				{//左右两边都比较小
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

