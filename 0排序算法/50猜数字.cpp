#include <cstdlib>
#include <iostream>
using namespace std;

//入口函数
int main()
{
	const int N = 100;
	int n = rand() % N, m = 0;

	cout << "我选了一个数n（0<=n<100），你猜它是啥？请输入：";
	while (true)
	{
		cin >> m;
		if (m == n)
		{
			cout << "恭喜你，猜对了！它是" << n << endl;
			break;
		}
		else if (m < n)
		{
			cout << "猜小了！请继续：";
		}
		else
		{
			cout << "猜大了！请继续：";
		}
	}
	return 0;
}
