#include <set>
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
set<int>colors; //颜色的集合

int main()
{	
	int n,m,i,k,j;
	
	cin>>n>>m; 
	for(i=0;i<m;i++)
	{
		cin>>e[i].v1>>e[i].v2;
	}
	cin>>k;
	for(i=0;i<k;i++)
	{
		colors.clear();
		for(j=0;j<n;j++)
		{
			cin>>v[j];
			colors.insert(v[j]);
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
			cout<<colors.size()<<"-coloring"<<endl;	
		}	
	} 	
	return 0;
}
