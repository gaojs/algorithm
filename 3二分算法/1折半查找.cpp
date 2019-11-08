#include <cstdlib> //rand()/qsort()
#include <iostream> //cout() 
using namespace std;

//显示数组所有的元素
void show(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//qsort要自己定义函数，下面是定义的函数
int cmp(const void* a, const void* b)
{
	//a>b,f=1; a=b,f=0; a<b,f=-1; 
	return *(int*)a - *(int*)b;
}

//入口函数
int main()
{
	const int N = 10, M = 100;
	int a[N] = { 0 }, i, j, n, m, c;

	//产生随机数组 
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	//cstdlib定义的快速排序函数
	qsort(a, N, sizeof(int), cmp);
	show(a, N);
	//提示用户输入待查找的元素
	cout << "input n(0~99)：";
	cin >> n;
	//开始折半查找 
	i = 0, j = N, c = 0;
	while (i <= j)
	{
		c++;
		m = (i + j) / 2;
		if (a[m] == n)
		{
			cout << "Found, it's at " << i << "." << endl;
			cout << "We find it " << c << " times." << endl;
			return 0;
		}
		else if (a[m] < n)
		{
			i = m + 1;
		}
		else
		{
			j = m - 1;
		}
	}
	cout << "Not found!" << endl;
	cout << "We find it " << c << " times." << endl;
	return 0;
}
