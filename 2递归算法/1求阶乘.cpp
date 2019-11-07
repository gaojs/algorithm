#include <iostream>
using namespace std;

//求阶乘的函数
int factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

int main()
{
	int n;

	cout << "input n(n>=1,n<=16):";
	cin >> n; //输入整数n=20
	//for(n=1;n<20;n++)
	cout << n << "'s factorial is " << factorial(n) << endl;
	return 0;
}
