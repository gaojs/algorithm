#include <iostream>
using namespace std;

//把整数 n 划分为 小于或等于 m 的一系列数字之和
int f(int n, int m)
{
	if(n==1 || m==1)
	{
		return 1;
	}
	else if(n<m)
	{
		return f(n,n);
	}
	else if(n==m)
	{
		return 1+f(n,m-1);
	}
	else if(n>m)
	{		
		return f(n-m,m) + f(n, m-1);
	} 
}

int main()
{
	int n=0;		 
	while(cin>>n)
	{
		cout<<f(n,n)<<endl;
	}	
	return 0;
}
