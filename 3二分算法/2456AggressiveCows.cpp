//http://bailian.openjudge.cn/practice/2456/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[100000]= {0};

bool isOk(int a[], int n, int cows, int m)
{
	int i=0,b=0,c=0; //begin/before, count
	
	b=0,c=1,i=1; 
	while(i<n&&c<=cows)
	{
		if(a[i]-a[b]>=m)
		{
			b=i;
			c+=1;
		}
		i++;
	}
	//cout<<"b="<<b<<",c="<<c<<",i="<<i<<endl; 
	return (c>=cows);
}

int findMax(int a[], int n, int cows)
{//找最大值 
	int max = 0, m,b,e; //min,begin,end 
	sort(a, a+n); //先从小到大排序
	//for(int i=0;i<n;i++) cout<<a[i]<<" ";
	b=0, e=(a[n-1]-a[0]);///cows+1;	
	//cout<<"b="<<b<<",e="<<e<<endl; 
	while(e>=b)
	{
		m=(b+e)/2;
		//cout<<"m="<<m<<endl; 
		if(isOk(a, n, cows, m))
		{
			//cout<<"b="<<b<<",e="<<e<<",m="<<m<<endl; 
			if(max<m)
			{
				max=m;
			}
			b=m+1;
		}
		else
		{
			e=m-1;
		}
	}
	return max;
}


int main() 
{
	int stalls, cows, i;
	
	scanf("%d%d",&stalls,&cows);
	//cout<<stalls<<" "<<cows<<endl;
	for(i=0;i<stalls;i++)
	{//输入数据 
		scanf("%d",&a[i]);
	}
	cout<<findMax(a, stalls, cows);
}
