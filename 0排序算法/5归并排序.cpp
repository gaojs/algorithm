#include <cstdlib>
#include <iostream>
using namespace std;

//统计比较次数和交换次数 
const int N = 1000000;
static int a[N] = { 0 };
static int b[N] = { 0 };
int bj = 0, yd = 0;

//显示数组所有的元素
void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//s是开始（start），m是中间（middle），e是结束（end） 
void Merge(int a[], int s, int m, int e)
{
	int i = s, j = m + 1, k = 0;
	while (i <= m && j <= e)
	{
		bj++;//比较次数 
		if (a[i] <= a[j])
		{
			yd++;//移动次数 
			b[k++] = a[i++];
		}
		else
		{
			yd++;//移动次数 
			b[k++] = a[j++];
		}
	}
	while (i <= m)
	{
		yd++;//移动次数 
		b[k++] = a[i++];
	}
	while (j <= e)
	{
		yd++;//移动次数 
		b[k++] = a[j++];
	}
	for (i = 0; i < e - s + 1; i++)
	{
		yd++;//移动次数 
		a[s + i] = b[i];
	}

}

//s是开始（start），e是结束（end） 
void MergeSort(int a[], int s, int e)
{
	if (s >= e)
	{//已经排好序了 
		return;
	}
	int m = s + (e - s) / 2;
	MergeSort(a, s, m);
	MergeSort(a, m + 1, e);
	Merge(a, s, m, e);
	//cout<<"i="<<s<<",j="<<e<<endl;
	//show(a,N);//显示 
}

//入口函数
int main()
{
	int i, j, t;

	bj = 0, yd = 0;
	//生成一组随机数
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cout<<"初始情况:"<<endl;
	//show(a,N);//显示 
	MergeSort(a, 0, N - 1); //排序 
	//cout<<"最终结果:"<<endl;
	//show(a,N);//显示 
	//cout<<"比较：" <<bj<<"，移动："<<yd;
	return 0;
}
