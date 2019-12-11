//https://pintia.cn/problem-sets/16/problems/663
#include <iostream>
using namespace std;

const int N=10000;
int a[N+1]={0};

int main()
{
	int n,i,j,m,t,max,maxB,maxE;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	max=-1;
	maxB=0,maxE=n-1;	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			m=0;
			for(t=i;t<=j;t++)
			{
				m+=a[t];
			}
			if(max<m)
			{
				max=m;
				maxB=i;
				maxE=j;
			}
		}
	}
	if(max<0) cout<<0<<" "<<a[0]<<" "<<a[n-1];
	else cout<<max<<" "<<a[maxB]<<" "<<a[maxE];
} 
