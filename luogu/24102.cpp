//https://www.luogu.org/problem/P5661?contestId=24102
#include <list>
#include <iostream>
using namespace std;

struct subway
{
	int price;//价格 
	int time;//时间 
};

int main()
{
	// bus/subway, price, time
	int n, b, p, t, i, s=0;
	list<subway> lst;
	
	cin>>n; //输入数据条数 
	for(i=0;i<n;i++)
	{
		cin>>b>>p>>t;		
		if(b) //公交 
		{
			while(lst.size()>0)
			{
				subway sb=q.front();
				if(t-sb.time>45
					||)
				{//超时无效的 
					q.pop();
				}
				else
				{
					break; 
				} 
			} 
			if(q.size()>0)
			{
				subway sb=q.front();				
				s+=p<=sb.price?0:p;
				q.pop();
			}
			else
			{
				s+=p; 
			} 			
		} 
		else //地铁 
		{
			subway sb;
			lst.price=p;
			lst.time=t;
			lst.push_back(sb);
			s+=p; 
		}	
	}
	cout<<s;
} 
