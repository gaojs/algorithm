//http://bailian.openjudge.cn/practice/4017/
//ÿ����1���2�㣬N��¥�ݣ��ж��������� 
#include <iostream>
using namespace std;

int stair(int n)
{
	if (n <= 0 || n == 1 || n > 30)
	{
		return 1;
	}
	return stair(n - 1) + stair(n - 2);
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << stair(n) << endl;
	}
	return 0;
}
