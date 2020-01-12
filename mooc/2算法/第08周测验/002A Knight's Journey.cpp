#include <cstring> 
#include <iostream> 
using namespace std;

const int N=26;
//���ֵ������ 
bool v[N][N]={0};
int xs[N+1]={0};
int ys[N+1]={0};

bool dfs(int p, int q, int x, int y, int n) 
{
	if(!v[x][y])
	{//��ǰλ�ã������� 
		v[x][y]=true;
		xs[n]=x;
		ys[n]=y;
		n++;//�ѷ���
		//cout<<"x="<<x<<",y="<<y<<",n="<<n<<endl;
		if(n>=p*q)
		{//�Ѿ�������� 
			return true;
		} 
		if(x+1<p&&y-2>=0)
		{//1��1��2 
			if(dfs(p,q,x+1,y-2,n))
			{
				return true;
			}
		}
		if(x-1>=0&&y-2>=0)
		{//2��1��2
			if(dfs(p,q,x-1,y-2,n))
			{
				return true;
			}
		}
		if(x-2>=0&&y-1>=0)
		{//3��2��1 
			if(dfs(p,q,x-2,y-1,n))
			{
				return true;
			}
		}
		if(x+2<p&&y-1>=0)
		{//4��2��1 
			if(dfs(p,q,x+2,y-1,n))
			{
				return true;
			}
		}
		if(x-2>=0&&y+1<q)
		{//5��2��1 
			if(dfs(p,q,x-2,y+1,n))
			{
				return true;
			}
		}
		if(x+2<p&&y+1<q)
		{//6��2��1 
			if(dfs(p,q,x+2,y+1,n))
			{
				return true;
			}
		}
		if(x-1>=0&&y+2<q)
		{//7��1��2 
			if(dfs(p,q,x-1,y+2,n))
			{
				return true;
			}
		}
		if(x+1<p&&y+2<q)
		{//8��1��2
			if(dfs(p,q,x+1,y+2,n))
			{
				return true;
			}
		}
		v[x][y]=false;
		n--;//����
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
