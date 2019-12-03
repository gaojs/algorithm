//http://bailian.openjudge.cn/practice/4110/
//谁价值大，优先选择谁 
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
	double value;
	double weight;
	
	bool operator<(Node& a)
	{
		return (value/weight)>(a.value/a.weight);
	}
};

const int N=100, W=10000; 
Node a[N+1]={0};

double count(Node a[], int n, int W)
{
	double v = 0, w=0;
	
	for(int i=0;i<n;i++)
	{
		if(w + a[i].weight <= W)
		{
			v += a[i].value;
			w += a[i].weight;
		}
		else 
		{
			v += a[i].value*(W-w)/a[i].weight;
			break; 
		}
	}
	return v;
}

int main()
{
	int n,w,i;
	
	cin>>n>>w;	
	for(i=0;i<n;i++)
	{
		cin>>a[i].value;
		cin>>a[i].weight;	
	}
	sort(a, a+n);
	cout<<fixed<<setprecision(1);	
	cout<<count(a,n,w)<<endl;	
	return 0;
}
