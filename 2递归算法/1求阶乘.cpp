#include <iostream>
using namespace std;

//��׳˵ĺ���
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
	cin >> n; //��������n=20
	//for(n=1;n<20;n++)
	cout << n << "'s factorial is " << factorial(n) << endl;
	return 0;
}
