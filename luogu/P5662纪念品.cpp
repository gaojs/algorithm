//https://www.luogu.org/problem/P5662
//贪心算法/二维数组/优先队列/结构体 
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void show(vector< vector<int> >&v, int t, int n)
{
	int i,j;
	
	cout<<endl;
	for(i=0;i<t;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

struct node //比较节点 
{
	int id; //编号 
	int price; //价格 
	float rate; //盈亏比 
	
	friend bool operator<(node a, node b)
	{
		return a.rate < b.rate; //rate大的优先级高
	}
};

int main()
{//天数T,纪念品数量N,金币数量M
	int t,n,m,i,j,d;
	vector< vector<int> > v;
	
	cin>>t>>n>>m;
	cout<<t<<" "<<n<<" "<<m;
	for(i=0;i<t;i++)
	{
		vector<int> r;
		for(j=0;j<n;j++)
		{
			cin>>d;
			r.push_back(d); 
		}
		v.push_back(r);
	}
	show(v, t, n);	
	for(i=1;i<t;i++)
	{
		priority_queue<node> q;		
		for(j=0;j<n;j++)
		{
			int v0=v[i-1][j];
			int v1=v[i][j]; 
			node b;
			b.id=j;
			b.price=v0;
			b.rate=(v1-v0)/(float)v0;
			q.push(b);
		}
		int s=0;
		while(q.size()>0)
		{
			node b=q.top();
			cout<<b.id<<" "<<b.price<<" "<<b.rate<<endl;
			if(b.rate>0 && m>0)
			{
				int v0=v[i-1][b.id];
				int v1=v[i][b.id]; 
				s+=(m/v0)*v1;
				m%=v0; 
			}
			q.pop();
		}	
		s+=m;
		m=s;	
	}
	cout<<m; 
} 

