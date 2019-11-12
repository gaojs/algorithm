//http://bailian.openjudge.cn/practice/2692/ 
//12枚硬币，其中1枚假币，重量不同
//用天平称三次，找出假币，确定轻重 
//输入三行，每行是一次称重结果
//银币编号A-L，前4，后4，左右银币 
//状态up/down/even表示右高/右低/平
//input & output sample:
//ABCD EFGH even
//ABIJ EFGL even
//ABCL EFJK up
//K, light/heavy 
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int N = 3;
	string left[N], right[N], state[N];
	int n;

	cin >> n;
	while (n--)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> left[i] >> right[i] >> state[i];
		}
		for (char c = 'A'; c <= 'L'; c++)
		{
			for (int l = 0; l <= 1; l++)
			{
				bool ret = true;
				for (int i = 0; ret && i < N; i++)
				{
					if (state[i] == "even")
					{
						if (left[i].find(c) != string::npos
							|| right[i].find(c) != string::npos)
						{//找到就不等了 
							ret = false;
							continue;
						}
					}
					else if (state[i] == "up")
					{
						if (!(!l && left[i].find(c) != string::npos
							|| l && right[i].find(c) != string::npos))
						{//右边没up
							ret = false;
							continue;
						}
					}
					else if (state[i] == "down")
					{
						if (!(l && left[i].find(c) != string::npos
							|| !l && right[i].find(c) != string::npos))
						{//右边没down
							ret = false;
							continue;
						}
					}
				}
				if (ret)
				{
					//c是假币 
					cout << c << " is the counterfeit coin and it is ";
					if (l)
					{//轻了
						cout << "light." << endl;
					}
					else
					{//重了
						cout << "heavy." << endl;
					}
				}
			}
		}
	}
	return 0;
}
