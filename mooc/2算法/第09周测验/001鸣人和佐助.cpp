#include <cstring> 
#include <iostream> 
#include <queue>
using namespace std;

struct Pos
{
	int r,c;
	Pos(int rr,int cc):r(rr),c(cc) { };
};
const int M=200,N=200,T=10;
char a[M][N]={0};
bool v[M][N]={0};
queue<Pos> que;
//�ߵ�(m,n)����t������� 
int mt[M][N]={0};

int bfs(int m, int n, int bt, int br, int bc, int er, int ec, int bs)
{//M��N�еĵ�ͼ�� ���������T������(br,bc),����(er,ec)������s 
	int tail=0,head=0; //���� 
	que.clear();
	memset(v,0,sizeof(v));
	memset(mt,0,sizeof(mt));
	v[br][bc]=true;
	mt[br][bc]=bt;
	que.push(Pos(br,bc));
	while(!que.empty())
	{
		
		int r=rs[head];
		int c=cs[head];
		int t=ts[head];
		int s=ss[head];	
		if(mts[r][c]==0)
		{
			mts[r][c]=t;
		}
		else
		{
			t=max(t,mts[r][c]);
		}
		cout<<"head="<<head<<",r="<<r<<",c="<<c<<",t="<<t<<",s="<<s;//<<endl;	
		if(r==er&&c==ec&&t>=0)
		{
			return s;
		}
		else if(tail<m*n)
		{//*����ͨ·;#��������������
			cout<<",tail="<<tail<<endl;
			if(r-1>=0&&(!v[r-1][c]||t>mts[r-1][c]))
			{//�� 
				if(a[r-1][c]=='*') 
				{	
					v[r-1][c]=true; 
					rs[tail]=r-1;
					cs[tail]=c;
					ts[tail]=t;
					ss[tail]=s+1;
					tail++;
				}
				else if(a[r-1][c]=='#'&&t>0)
				{
					v[r-1][c]=true; 
					rs[tail]=r-1;
					cs[tail]=c;
					ts[tail]=t-1;
					ss[tail]=s+1;
					tail++;
				}
			}
			if(r+1<m&&(!v[r+1][c]||t>mts[r+1][c]))
			{//�� 
				if(a[r+1][c]=='*') 
				{
					v[r+1][c]=true; 
					rs[tail]=r+1;
					cs[tail]=c;
					ts[tail]=t;
					ss[tail]=s+1;
					tail++;
				}
				else if(a[r+1][c]=='#'&&t>0)
				{
					v[r+1][c]=true; 
					rs[tail]=r+1;
					cs[tail]=c;
					ts[tail]=t-1;
					ss[tail]=s+1;
					tail++;
				}
			}
			if(c-1>=0&&(!v[r][c-1]||t>mts[r][c-1]))
			{//�� 
				if(a[r][c-1]=='*') 
				{
					v[r][c-1]=true; 
					rs[tail]=r;
					cs[tail]=c-1;
					ts[tail]=t;
					ss[tail]=s+1;
					tail++;
				}
				else if(a[r][c-1]=='#'&&t>0)
				{
					v[r][c-1]=true; 
					rs[tail]=r;
					cs[tail]=c-1;
					ts[tail]=t-1;
					ss[tail]=s+1;
					tail++;
				}
			}
			if(c+1<n&&(!v[r][c+1]||t>mts[r][c+1]))
			{//�� 
				if(a[r][c+1]=='*') 
				{
					v[r][c+1]=true; 
					rs[tail]=r;
					cs[tail]=c+1;
					ts[tail]=t;
					ss[tail]=s+1;
					tail++;
				}
				else if(a[r][c+1]=='#'&&t>0)
				{
					v[r][c+1]=true; 
					rs[tail]=r;
					cs[tail]=c+1;
					ts[tail]=t-1;
					ss[tail]=s+1;
					tail++;
				}
			}
		}
	}
	return -1;
} 

int main()
{
	int m,n,t,r,c,br,bc,er,ec;
	
	freopen("f:\\in.txt","r",stdin);
	freopen("f:\\o.txt","w",stdout);
	cin>>m>>n>>t;
	//cout<<"m="<<m<<",n="<<n<<",t="<<t<<endl;	
	for(r=0;r<m;r++)	
	{
		for(c=0;c<n;c++)
		{
			cin>>a[r][c];
			switch(a[r][c])
			{//*����ͨ·��#��������������
			case '@'://@��������
				a[r][c]='*';
				br=r,bc=c;
				//cout<<"br="<<br<<",bc="<<bc<<endl;
				break;
			case '+'://+��������
				a[r][c]='*';
				er=r,ec=c;
				//cout<<"er="<<er<<",ec="<<ec<<endl;
				break;
			}
		}
	}
	cout<<bfs(m,n,t,br,bc,er,ec,0);
	return 0;
}
