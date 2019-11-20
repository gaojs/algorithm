//https://www.luogu.org/problem/P5661
//数组/列表/结构体/循环/判断 
#include <vector>
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
	vector<subway> vt;
	
	cin>>n; //输入数据条数 
	for(i=0;i<n;i++)
	{
		cin>>b>>p>>t;		
		if(b) //公交 
		{
			bool found = false;
			vector<subway>::iterator it; 
			for(it=vt.begin();it!=vt.end();)
			{
				subway sb=*it;
				if(t-sb.time>45)
				{//超时无效的 
					vt.erase(it);
				}
				else if(p<=sb.price) 
				{
					vt.erase(it);
					found = true;
					break; 
				}
				else
				{
					it++;
				}
			} 
			if(!found)
			{
				s+=p; 
			}
		} 
		else //地铁 
		{
			s+=p; 
			subway sb;
			sb.price=p;
			sb.time=t;
			vt.push_back(sb);
		}	
	}
	cout<<s;
} 
