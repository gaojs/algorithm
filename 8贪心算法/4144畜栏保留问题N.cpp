//http://bailian.openjudge.cn/practice/4144/
#include <queue> //priority_queue 
#include <algorithm>
#include <iostream>
using namespace std;

struct Cow
{//奶牛 
	int no; //奶牛编号，从0开始 
	int begin; //开始时间 
	int end; //结束时间
	
	//函数后面加const，表示不改变成员变量 
	bool operator<(const Cow& a) const 
	{//按结束时间排序，便于找到畜栏 
		return end>a.end; //这里要注意 
	}
};

bool cmp(const Cow& a, const Cow& b) 
{//按开始时间排序，谁早，先安排谁 
	if(a.begin==b.begin) return a.end<b.end;
	else return a.begin<b.begin;
}

//优先队列，用的很关键 
//priority_queue默认为大顶堆，即堆顶元素为堆中最大元素
priority_queue<Cow> pq;//进栏的奶牛
const int N=50000, M=1000000;
//这个变量，用的也很巧妙 
int cowStalls[N+1]={0};
Cow a[N+1]={0};

int count(Cow a[], int n)
{	
	int m=0,i;
	for(i=0;i<n;i++)
	{//为每一头奶头分配畜栏 
		if(pq.size() && pq.top().end<a[i].begin)
		{//能安排进来，最早结束的已经OK
			//奶牛的畜栏编号，跟刚出栏的那头奶牛一样 
			cowStalls[a[i].no]=cowStalls[pq.top().no]; 
			pq.pop();//出栏
			pq.push(a[i]);//入栏			
		}
		else
		{
			m++; //新拿来一个畜栏 
			cowStalls[a[i].no]=m;
			pq.push(a[i]);//入栏	
		} 
	}
	return m;
}

int main()
{
	int n,i;
	
	cin>>n;
	for(i=0;i<n;i++)
	{//输入 
		a[i].no=i;
		cin>>a[i].begin;
		cin>>a[i].end;
	}
	sort(a, a+n, cmp); //排序 
	cout<<count(a,n)<<endl;	
	for(i=0;i<n;i++)
	{//输出 
		cout<<cowStalls[i]<<endl;
	}
	return 0;
}
