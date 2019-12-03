//http://bailian.openjudge.cn/practice/4151/
//谁后结束，优先选择谁 
#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
	int begin;
	int end;
	
	bool operator<(Node& a)
	{
		return end<a.end;
	}
};

const int N=100;
Node a[N+1]={0};

int count(Node a[], int n)
{
	int sum=0,s=0,i;
	
	for(i=0;i<n;i++)
	{
		if(s <= a[i].begin)
		{
			s = a[i].end;
			sum += 1;
		}
	}
	return sum;
}

int main()
{
	int n,i;
	
	while(cin>>n && n>0)
	{
		for(i=0;i<n;i++)
		{
			cin>>a[i].begin;
			cin>>a[i].end;
		}
		sort(a, a+n);
		cout<<count(a,n)<<endl;		
	}
	return 0;
}
