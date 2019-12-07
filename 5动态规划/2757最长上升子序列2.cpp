//http://bailian.openjudge.cn/practice/2757/
#include <cstdio>
#include <iostream>
using namespace std;

const int N=1000;
int a[N]={0};
int c[N]={0};

int findMax(int a[], int n)
{
	int i,j,m=0;
	
	m=c[n-1]=1;
	for(i=n-2;i>=0;i--)
	{
		c[i]=1;
		for(j=n-1;j>i;j--)
		{
			if(a[i]<=a[j])
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
	return m;
}


int main()
{
	int n,i;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	cout<<findMax(a,n);
	return 0;
}

