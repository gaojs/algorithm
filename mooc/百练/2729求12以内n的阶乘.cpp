//http://bailian.openjudge.cn/practice/2729/
#include <iostream>
using namespace std;

long factor(int n)
{//��n�Ľ׳� 
	long s=1;
	for(int i=1;i<=n;i++)
	{
		s*=i;
	}
	return s;	
}

int main()
{//����n��n<=12��
	int n;
	cin>>n;
	cout<<factor(n);
	return 0;
} 
