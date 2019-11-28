//http://bailian.openjudge.cn/practice/4103/
//f(n)=f(n-1)+2*(f(n-2)+...+f(1)+f(0)+1);
#include <iostream>
using namespace std;

const int N=21;
int a[N]={0}; 

int f(int n)
{	
	if (n <= 0)
	{//ÁÙ½çÌõ¼þ 
		return 1;
	}
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+2;
		for(int j=0;j<i-1;j++)
		{
			a[i]+=2*a[j];
		}
	}
	return a[n];
}

int main()
{
	int n;

	cin >> n;	
	cout << f(n);
	return 0;
}
