#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N=100000;
int a[N]={0};

//��ǰk����������ƶ�������� 
int ni(int a[], int n)
{ 	
	if(n<=1)
	{
		return 0;
	}
	else
	{
		int mid=n/2, sum=0,i,j;
		sum+=ni(a,mid);
		sum+=ni(a+mid,n-mid);
		sort(a,a+mid);
		sort(a+mid,a+n);
		//2 3 6 ; 1 4 5
		i=0,j=mid;
		while(i<mid && j<n)
		{			
			while(i<mid && a[i]<=a[j])
			{
				i++;			
			}
			while(j<n && a[i]>a[j])
			{
				sum+=mid-i;
				j++;
			}
		}		
		return sum;	
	}
}

int main()
{
	int n,i;
	
	cin >> n;
	for(i=0;i<n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	cout<<ni(a,n);
	return 0;
}
