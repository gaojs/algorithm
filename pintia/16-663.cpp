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
	{//���� 
		cin>>a[i];
	}	
	max=maxB=maxE=-1;//��Чֵ 
	sum=0,begin=0;//��ʼֵ 
	for(i=0;i<n;i++)
	{//��0��ʼѰ�� 
		sum+=a[i];
		if(max<sum)
		{//�ҵ�����ĺ��� 
			max=sum; //���� 
			maxB=begin; //��ʼ�� 
			maxE=i; //��ǰΪ������ 
		}
		if(sum<0) //����ǰ��Ĳ��� 
		{//��С��0��begin���¸�Ԫ�ؿ�ʼ 
			sum=0;	
			begin=i+1;
		} 
	}
	if(max<0) cout<<0<<" "<<a[0]<<" "<<a[n-1];
	else cout<<max<<" "<<a[maxB]<<" "<<a[maxE];
} 
