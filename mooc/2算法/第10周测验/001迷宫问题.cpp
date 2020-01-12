#include <iostream>
using namespace std;

struct node
{
	int x,y; //坐标 
	int p; //prev前一步 
};
const int N=5,M=5;
node que[N*M]={0};
int a[N][M]={0};
bool v[N][M]={0};

int bfs(int n, int m)
{//右下到左上，反着走 
	int tail=0,head=0; 
	v[n-1][m-1]=true;
	que[tail].x=n-1;
	que[tail].y=m-1;
	que[tail].p=-1;
	tail++; //尾部 
	while(head<tail)
	{
		node p=que[head];
		if(p.x==0&&p.y==0)
		{//到出口了 
			while(true)
			{
				cout<<"("<<p.x<<", "<<p.y<<")"<<endl;
				if(p.p>=0) p=que[p.p];
				else break;
			}
			return 0;
		}
		if(p.x-1>=0&&!v[p.x-1][p.y]&&!a[p.x-1][p.y])
		{//x-1
			v[p.x-1][p.y]=true;
			que[tail].x=p.x-1;
			que[tail].y=p.y;
			que[tail].p=head;
			tail++;
		}
		if(p.x+1<n&&!v[p.x+1][p.y]&&!a[p.x+1][p.y])
		{//x+1
			v[p.x+1][p.y]=true;
			que[tail].x=p.x+1;
			que[tail].y=p.y;
			que[tail].p=head;
			tail++;
		}
		if(p.y-1>=0&&!v[p.x][p.y-1]&&!a[p.x][p.y-1])
		{//y-1
			v[p.x][p.y-1]=true;
			que[tail].x=p.x;
			que[tail].y=p.y-1;
			que[tail].p=head;
			tail++;
		}
		if(p.y+1<m&&!v[p.x][p.y+1]&&!a[p.x][p.y+1])
		{//y+1
			v[p.x][p.y+1]=true;
			que[tail].x=p.x;
			que[tail].y=p.y+1;
			que[tail].p=head;
			tail++;
		}
		head++; 
	}
	return -1;	
}

int main()
{
	int n,m,i,j;
	
	//cin>>n>>m;	
	n=N,m=M; //固定 
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	bfs(n,m);
    return 0;
}
