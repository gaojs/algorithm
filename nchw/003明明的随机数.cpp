#include<iostream> 
//#include<cstdlib>
//#include<time.h>
using namespace std;

void show(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		//cout<<a[i]<<",";
		cout<<a[i]<<endl;
	}
	//cout<<endl;
}

const int N=1000;
int a[N]={0};
int main()
{
	int n,i,j,k; 
	//设置种子，time返回时间戳 
	//srand(time(NULL)); 
	//n=N;//个数 
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			//cout<<rand()<<endl; 
			//a[i]=rand()%(N-1)+1;
			cin>>a[i];
		}
		//show(a,n);
		
		//划掉重复的 
		for(i=0;i<n;i++)
		{
			if(a[i]>0)
			{
				for(j=i+1;j<n;j++)
				{
					if(a[j]>0 && a[j]==a[i])
					{
						a[j]=0;
					}
				}
			}
		} 
		//show(a,n);
		
		//往前移动 
		for(i=0,j=0;i<n;i++)
		{
			if(a[i]>0) 
			{
				if(i!=j)
				{
					a[j]=a[i];
					a[i]=0;
				} 
				j++;		
			}
		} 
		n=j;
		//show(a,n);
		
		//插入排序
		for(i=1;i<n;i++) 
		{
			int t=a[i];//暂存一下 
			for(j=i-1;j>=0&&a[j]>t;j--)
				;//找插入的位置 
			for(k=i;k>j+1;k--)
			{//往后移动 
				a[k]=a[k-1];
			}
			a[k]=t; 
		}
		show(a,n);
	}
	return 0;
}
