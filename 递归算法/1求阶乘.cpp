#include <iostream>
using namespace std;

//��׳˵ĺ���
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
	cin >> n; //��������n=20
	cout<<factorial(n);
	return 0;
}
