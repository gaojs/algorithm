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
	int i, j, t, min;
	int bj = 0, jh = 0;

	//生成一组随机数
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cout<<"初始情况:"<<endl;
	//show(a,N);//显示 
	for (i = 0; i < N - 1; i++)
	{
		min = i;//最小项标号 
		for (j = i + 1; j < N; j++)
		{//循环查找最小项 
			bj++;//比较次数 
			if (a[j] < a[min])
			{//发现了更小的 
				min = j;
			}
		}
		if (min != i)
		{//交换两个元素 
			jh++;//交换次数 
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
		//cout<<"i="<<i<<endl;
		//show(a,N);
	}
	//cout<<"最终结果:"<<endl;
	//show(a,N);
	//cout<<"比较：" <<bj<<"，交换："<<jh;
	return 0;
}
