#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 100000;
static int a[N] = { 0 };

//显示数组所有的元素
void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//入口函数
int main()
{
	int i, j, k, t;
	int bj = 0, yd = 0;

	//生成一组随机数
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cout<<"初始情况:"<<endl;
	//show(a,N);//显示 
	for (i = 1; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{//循环查找插入位置 
			bj++;//比较次数 
			if (a[j] > a[i])
			{//找到插入位置 	
				t = a[i];//临时保存 
				//循环往后移动 
				for (k = i; k > j; k--)
				{
					yd++;//移动次数 
					a[k] = a[k - 1];
				}
				a[j] = t;//插入	
				//cout<<"i="<<i<<",";		
				//cout<<"j="<<j<<endl;
				//show(a,N);	
				break;
			}
		}
	}
	//cout<<"最终结果:"<<endl;
	//show(a,N);
	//cout<<"比较：" <<bj<<"，移动："<<yd;
	return 0;
}
