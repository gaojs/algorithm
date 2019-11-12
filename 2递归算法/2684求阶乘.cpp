//http://bailian.openjudge.cn/practice/2684/
//求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!） 
#include <iostream>
using namespace std;

//求阶乘的函数
int factor(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * factor(n - 1);
}

int main()
{
	int n, i, s;

	//cout << "input n(n>=1,n<=16):";
	cin >> n; //输入整数n=20
	for (s = 0, i = 1; i <= n; i++)
	{
		s += factor(i);
	}
	cout << s << endl;
	return 0;
}
