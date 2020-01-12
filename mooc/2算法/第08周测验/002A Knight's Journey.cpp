#include <cstring> 
#include <iostream> 
using namespace std;

const int N=26;
//存放值的数组 
bool v[N][N]={0};
int xs[N+1]={0};
int ys[N+1]={0};

bool dfs(int p, int q, int x, int y, int n) 
{
	if(!v[x][y])
	{//当前位置，可以走 
		v[x][y]=true;
		xs[n]=x;
		ys[n]=y;
		n++;//已访问
		//cout<<"x="<<x<<",y="<<y<<",n="<<n<<endl;
		if(n>=p*q)
		{//已经遍历完成 
			return true;
		} 
		if(x+1<p&&y-2>=0)
		{//1下1左2 
			if(dfs(p,q,x+1,y-2,n))
			{
				return true;
			}
		}
		if(x-1>=0&&y-2>=0)
		{//2上1左2
			if(dfs(p,q,x-1,y-2,n))
			{
				return true;
			}
		}
		if(x-2>=0&&y-1>=0)
		{//3上2左1 
			if(dfs(p,q,x-2,y-1,n))
			{
				return true;
			}
		}
		if(x+2<p&&y-1>=0)
		{//4下2左1 
			if(dfs(p,q,x+2,y-1,n))
			{
				return true;
			}
		}
		if(x-2>=0&&y+1<q)
		{//5上2右1 
			if(dfs(p,q,x-2,y+1,n))
			{
				return true;
			}
		}
		if(x+2<p&&y+1<q)
		{//6下2右1 
			if(dfs(p,q,x+2,y+1,n))
			{
				return true;
			}
		}
		if(x-1>=0&&y+2<q)
		{//7上1右2 
			if(dfs(p,q,x-1,y+2,n))
			{
				return true;
			}
		}
		if(x+1<p&&y+2<q)
		{//8下1右2
			if(dfs(p,q,x+1,y+2,n))
			{
				return true;
			}
		}
		v[x][y]=false;
		n--;//撤回
	}
	return false;
}

void print(int n)
{
	char x,y;
	for(int i=0;i<n;i++)
	{
		y='A'+ys[i], x='1'+xs[i];
		cout<<y<<x;
	}
	cout<<endl;
}
	 
int main()
{		
	int n,i,p,q;
	
	//freopen("f:\\in.txt","r",stdin);
	//freopen("f:\\o.txt","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>p>>q;
		memset(v,0,sizeof(v));
		memset(xs,0,sizeof(xs));
		memset(ys,0,sizeof(ys));
		cout<<"Scenario #"<<i<<":"<<endl;
		if(!dfs(p,q,0,0,0))
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			print(p*q);
		}
		cout<<endl;
	}
	return 0;
}
