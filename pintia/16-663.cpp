//https://pintia.cn/problem-sets/16/problems/663
#include <iostream>
using namespace std;

const int N=10000;
int a[N+1]={0};

int main()
{
	int n,i,max,maxB,maxE,sum,begin;
	
	cin>>n;
	for(i=0;i<n;i++)
	{//输入 
		cin>>a[i];
	}	
	max=maxB=maxE=-1;//无效值 
	sum=0,begin=0;//初始值 
	for(i=0;i<n;i++)
	{//从0开始寻找 
		sum+=a[i];
		if(max<sum)
		{//找到更大的和了 
			max=sum; //最大和 
			maxB=begin; //起始点 
			maxE=i; //当前为结束点 
		}
		if(sum<0) //丢弃前面的部分 
		{//和小于0，begin从下个元素开始 
			sum=0;	
			begin=i+1;
		} 
	}
	if(max<0) cout<<0<<" "<<a[0]<<" "<<a[n-1];
	else cout<<max<<" "<<a[maxB]<<" "<<a[maxE];
} 
