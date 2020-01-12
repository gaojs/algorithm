#include <iostream> 
using namespace std;

const int W=20,H=20;
//���ֵ������ 
char a[H][W]={0};
int count=0;

void dfs(char a[H][W], int h, int w, int r, int c) 
{
	//cout<<"r="<<r<<",c="<<c<<",a="<<a[r][c]<<endl;
	if(a[r][c]=='.')
	{//��ǰλ�ã������� 
		count++;
		a[r][c]='@'; //�߹� 
		if(r>0&&a[r-1][c]=='.') 
		{//�� 
			dfs(a,h,w,r-1,c);
		}
		if(r<h-1&&a[r+1][c]=='.')
		{//�� 
			dfs(a,h,w,r+1,c);
		}
		if(c>0&&a[r][c-1]=='.') 
		{//�� 
			dfs(a,h,w,r,c-1);
		}
		if(c<w-1&&a[r][c+1]=='.') 
		{//�� 
			dfs(a,h,w,r,c+1);
		}
	}
}

int main()
{		
	int w,h,i,j,r,c;
	
	while(cin>>w>>h && w && h)//��͸� 
	{//�������������� 
		//cout<<"w="<<w<<",h="<<h<<endl;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='@')
				{//��ʼ�� 
					a[i][j]='.';
					r=i,c=j;	
				}	
			} 
		}
		count=0;
		dfs(a,h,w,r,c);
		cout<<count<<endl;
	}
	return 0;
}
