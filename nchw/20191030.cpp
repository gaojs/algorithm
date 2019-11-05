#include<iostream>
using namespace std;

int main()
{
	const int N = 10;
	int a[N]={0};
	int i,j,t,x,y,z,c;
	long min, tmp;	
	//输入10个数 
	for(i=0;i<N;i++) 
	{
		cin>>a[i];
	}
	//从小到大排序 
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++) 
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;				
			}
		}
	}
	//查看排序结果 
//	for(i=0;i<N;i++)
//	{
//		cout<<a[i]<<","; 
//	}
	
	
	//计算公式值 
	c=0;//数量 
	min=0;//最小值 
	for(x=0;x<N;x++) 
	{
		for(y=0;y<N;y++) 
		{
			if(y==x)
			{
				continue;
			}
			z=0;
			while(z==x||z==y)z++; 
			//for(z=0;z<N;z++) 
			{
//				if(z==x||z==y)
//				{
//					continue;
//				}
				if(c==0)
				{//第一次 
					//tmp=a[x]*a[x]+a[x]*a[y]-a[y]*a[y]+a[z];
					tmp=(a[x]-a[y])*(a[x]+a[y])+a[x]*a[y]+a[z];
					min=tmp;
				} 
				else
				{//其他次 
					//tmp=a[x]*a[x]+a[x]*a[y]-a[y]*a[y]+a[z];					
					tmp=(a[x]-a[y])*(a[x]+a[y])+a[x]*a[y]+a[z];
					if(min>tmp) 
					{
						min=tmp;
					}					
				 } 
				 c++;//次数自增 
			}			
		}		
	}	
	cout<<min;//<<","<<c;
	return 0; 
} 
