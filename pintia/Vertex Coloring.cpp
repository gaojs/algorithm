#include <iostream>
using namespace std;

struct Edge
{
	int v1,v2;	
};
//n for vertices, m for edges
const int N=10000,M=10000,K=100;
Edge e[M]={0}; //e(v1,v2)为每条边的顶点 
int v[N]={0}; //v[i]每个顶点i的颜色 
int c[K]={0}; //颜色的种类0 

int main()
{	
	int n,m,i,k,j,colors,t;
	
	cin>>n>>m; 
	for(i=0;i<m;i++)
	{
		cin>>e[i].v1>>e[i].v2;
	}
	cin>>k;
	for(i=0;i<k;i++)
	{
		colors=0; //颜色数 
		for(j=0;j<n;j++)
		{
			cin>>v[j];
			for(t=0;t<colors;t++)
			{//查找颜色 
				if(c[t]==v[j])
				{//找到 
					break; 
				}
			}
			if(t==colors)
			{//未找到 
				c[t]=v[j];
				colors++; 
			} 
		}
		for(j=0;j<m;j++)
		{
			if(v[e[j].v1]==v[e[j].v2])
			{
				break;
			}
		} 
		if(j<m)	
		{//不行 
			cout<<"No"<<endl;
		}
		else
		{//可以		 
			cout<<colors<<"-coloring"<<endl;	
		}	
	} 	
	return 0;
}
