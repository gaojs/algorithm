//https://www.luogu.org/problem/P5661?contestId=24102
#include <list>
#include <iostream>
using namespace std;

struct subway
{
	int price;//�۸� 
	int time;//ʱ�� 
};

int main()
{
	// bus/subway, price, time
	int n, b, p, t, i, s=0;
	list<subway> lst;
	
	cin>>n; //������������ 
	for(i=0;i<n;i++)
	{
		cin>>b>>p>>t;		
		if(b) //���� 
		{
			while(lst.size()>0)
			{
				subway sb=q.front();
				if(t-sb.time>45
					||)
				{//��ʱ��Ч�� 
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
		else //���� 
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
