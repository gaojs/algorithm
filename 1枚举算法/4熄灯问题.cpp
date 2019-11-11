//5��6�еĵƣ�����ĳ���ƣ����ܵĵƸ��ŷ�ת��
//�������еƵĳ�ʼ��״̬����ΰ�����ȫ���ص���
//sample input & output:
// 0 1 1 0 1 0	// 1 0 1 0 1 0
// 1 0 0 1 1 1	// 1 1 0 0 0 1
// 0 0 1 0 0 1	// 0 0 0 1 1 0
// 1 0 0 1 0 1	// 1 1 0 0 0 1
// 0 1 1 1 0 1 	// 1 0 1 0 0 0
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int R=5, C=6;
void show(int a[R][C])
{
	for(int r=0; r<R; r++)
	{		
		for(int c=0; c<C; c++)
		{
			cout<<a[r][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void revert(int a[R][C], int r, int c)
{
	a[r][c]=!a[r][c]; 
	if(r>0) a[r-1][c]=!a[r-1][c]; 
	if(r<R-1) a[r+1][c]=!a[r+1][c]; 
	if(c>0) a[r][c-1]=!a[r][c-1]; 
	if(c<C-1) a[r][c+1]=!a[r][c+1]; 
}

int main()
{
	int a[R][C] = {0};
	int b[R][C] = {0};
	int d[R][C] = {0};
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
		{
			cin>>a[r][c];
		}		
	}
	for(int i=0;i<(1<<C);i++)
	{
		//cout<<i<<endl;
		memcpy(b, a, sizeof(a)); 
		memset(d, 0, sizeof(d)); 
		for(int n=i, c=0; c<C; c++, n=n>>1)
		{
			if(n&1) 
			{
				d[0][C-c-1]=1;
				revert(b, 0, C-c-1);
			}
		}
		for(int r=1; r<R; r++)
		{
			for(int c=0; c<C; c++)
			{
				if(b[r-1][c]) 
				{
					d[r][c]=1;
					revert(b, r, c);
				}
			}
		}
		bool ret = true; 
		for(int c=0; c<C; c++)
		{
			if(b[R-1][c])
			{
				ret = false;
				break;
			}
		}
		if(ret)
		{
			show(d);
		} 
	}	
	return 0;	
}
