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
	//�������ӣ�time����ʱ��� 
	//srand(time(NULL)); 
	//n=N;//���� 
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			//cout<<rand()<<endl; 
			//a[i]=rand()%(N-1)+1;
			cin>>a[i];
		}
		//show(a,n);
		
		//�����ظ��� 
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
		
		//��ǰ�ƶ� 
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
		
		//��������
		for(i=1;i<n;i++) 
		{
			int t=a[i];//�ݴ�һ�� 
			for(j=i-1;j>=0&&a[j]>t;j--)
				;//�Ҳ����λ�� 
			for(k=i;k>j+1;k--)
			{//�����ƶ� 
				a[k]=a[k-1];
			}
			a[k]=t; 
		}
		show(a,n);
	}
	return 0;
}
