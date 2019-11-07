#include <cstdlib>
#include <iostream>
using namespace std;

const int N=100000;
static int a[N]={0};

//显示数组所有的元素
void show(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//入口函数
int main()
{
	int i,j,t;
	int bj=0,jh=0;

	//生成一组随机数
	for(i=0; i<N; i++)
	{
		a[i]=rand()%100;
	}
	//cout<<"初始情况:"<<endl;
	//show(a,N);//显示 
	for(i=0; i<N; i++)
	{
		bool jhg=false;//交换过 
		for(j=0;j<N-i-1;j++) 
		{
			bj++;//比较次数 
			if(a[j]>a[j+1])
			{//交换两个元素 
				jh++;//交换次数 
				jhg=true;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			}	
		}
		if(!jhg)//一个都没交换过，
		{//就说明数列已经有序了 
			break;
		}
		//cout<<"i="<<i<<endl;
		//show(a,N);
	}
	//cout<<"最终结果:"<<endl;
	//show(a,N);
	//cout<<"比较：" <<bj<<"，交换："<<jh;
	return 0;
}
