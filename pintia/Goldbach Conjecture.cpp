#include <iostream>
using namespace std;

bool prime(int n)
{
	if(n<2) return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n,i;
	
	cin>>n;
	for(i=2;i*2<=n;i++)
	{
		if(prime(i)&&prime(n-i))
		{
			cout<<i<<" "<<n-i;
			break;
		}
	}
	return 0;
}
