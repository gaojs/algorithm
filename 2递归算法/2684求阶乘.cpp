//http://bailian.openjudge.cn/practice/2684/
//�󲻴���n���������Ľ׳˵ĺͣ�����1!+2!+3!+...+n!�� 
#include <iostream>
using namespace std;

//��׳˵ĺ���
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
	cin >> n; //��������n=20
	for (s = 0, i = 1; i <= n; i++)
	{
		s += factor(i);
	}
	cout << s << endl;
	return 0;
}
