//http://bailian.openjudge.cn/practice/2729/
#include <iostream>
using namespace std;

long factor(int n)
{//求n的阶乘 
	long s=1;
	for(int i=1;i<=n;i++)
	{
		s*=i;
	}
	return s;	
}

int main()
{//整数n（n<=12）
	int n;
	cin>>n;
	cout<<factor(n);
	return 0;
} 
