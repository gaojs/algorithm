//http://bailian.openjudge.cn/practice/2692/ 
//12öӲ�ң�����1ö�ٱң�������ͬ
//����ƽ�����Σ��ҳ��ٱң�ȷ������ 
//�������У�ÿ����һ�γ��ؽ��
//���ұ��A-L��ǰ4����4���������� 
//״̬up/down/even��ʾ�Ҹ�/�ҵ�/ƽ
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
						{//�ҵ��Ͳ����� 
							ret = false;
							continue;
						}
					}
					else if (state[i] == "up")
					{
						if (!(!l && left[i].find(c) != string::npos
							|| l && right[i].find(c) != string::npos))
						{//�ұ�ûup
							ret = false;
							continue;
						}
					}
					else if (state[i] == "down")
					{
						if (!(l && left[i].find(c) != string::npos
							|| !l && right[i].find(c) != string::npos))
						{//�ұ�ûdown
							ret = false;
							continue;
						}
					}
				}
				if (ret)
				{
					//c�Ǽٱ� 
					cout << c << " is the counterfeit coin and it is ";
					if (l)
					{//����
						cout << "light." << endl;
					}
					else
					{//����
						cout << "heavy." << endl;
					}
				}
			}
		}
	}
	return 0;
}
