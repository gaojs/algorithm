//https://www.luogu.org/problem/P5661
//����/�б�/�ṹ��/ѭ��/�ж� 
#include <vector>
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
	vector<subway> vt;
	
	cin>>n; //������������ 
	for(i=0;i<n;i++)
	{
		cin>>b>>p>>t;		
		if(b) //���� 
		{
			bool found = false;
			vector<subway>::iterator it; 
			for(it=vt.begin();it!=vt.end();)
			{
				subway sb=*it;
				if(t-sb.time>45)
				{//��ʱ��Ч�� 
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
		else //���� 
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
