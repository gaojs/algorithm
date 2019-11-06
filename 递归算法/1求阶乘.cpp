#include <iostream>
using namespace std;

//求阶乘的函数
int factorial(int n)
{
	if(n==1)
	{
		return 1;
	}
	return n*factorial(n-1);
}

int main()
{
	int n;

	cout << "input n:";
	cin >> n; //输入整数n=20
	cout<<factorial(n);
	return 0;
}
