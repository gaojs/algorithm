//http://bailian.openjudge.cn/practice/2684/ 
#include <iostream>
using namespace std;

long factor(int n)
{//��n�Ľ׳� 
	long sum=0,s=1;
	for(int i=1;i<=n;i++)
	{
		s*=i;
		sum+=s;
	}
	return sum;	
}

int main()
{//������n��1 < n < 12��
	int n;
	cin>>n;
	cout<<factor(n);
	return 0;
} 
