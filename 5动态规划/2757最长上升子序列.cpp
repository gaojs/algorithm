#include <iostream> 
using namespace std;

const int N=1000;
int a[N]={0}; //array
int c[N]={0}; //count
	
int main()
{
	int n,i,j,m;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	c[0]=1,m=1;
	for(i=1;i<n;i++)
	{
		c[i]=1;
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{				
				if(c[i]<c[j]+1)
				{					
					c[i]=c[j]+1;
				}
			}
		}
		if(m<c[i])
		{
			m=c[i];
		}
	}
	cout<<m;
	return 0;
}
