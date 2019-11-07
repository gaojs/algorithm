#include <cstdlib>
#include <iostream>
using namespace std;

//统计比较次数和交换次数 
const int N=1000000;
static int a[N]={0};
int bj=0,jh=0;

//显示数组所有的元素
void show(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//交换a和b两个数 
void swap(int &a, int &b)
{
	int t;
	t=a;
	a=b;
	b=t; 
	jh++;//交换次数 
} 

//b是开始（begin），e是结束（end） 
void QuickSort(int a[], int b, int e)
{
	if(b>=e)
	{//已经排好序了 
		return;
	}
	int i=b,j=e;	
	//cout<<"i="<<i<<",j="<<j<<endl;
	//关键元素，默认为第一个 
	//将大于a[k]的都移到它右边
	//将小于a[k]的都移到它左边
	while(i<j)
	{
		//从右往左，找到一个可以交换的 
		while(j>i && a[j]>=a[i]) 
		{
			bj++;//比较次数 
			j--;
		}
		//if(i>=j) break; 
		swap(a[i], a[j]);
		//show(a,N);//显示 
		//从左往右，找到一个可以交换的 
		while(i<j && a[i]<=a[j])
		{
			bj++;//比较次数 
			i++; 
		} 
		//if(i>=j) break; 
		swap(a[i], a[j]);
		//show(a,N);//显示 
	}
	//i=j才结束，i就是中间元素 
	QuickSort(a, b, i-1);
	QuickSort(a, i+1, e);		
}

//入口函数
int main()
{
	int i,j,t;

	bj=0,jh=0;
	//生成一组随机数
	for(i=0; i<N; i++)
	{
		a[i]=rand()%100;
	}
	//cout<<"初始情况:"<<endl;
	//show(a,N);//显示 
	QuickSort(a,0,N-1); //排序 
	//cout<<"最终结果:"<<endl;
	//show(a,N);//显示 
	//cout<<"比较：" <<bj<<"，交换："<<jh;
	return 0;
}
