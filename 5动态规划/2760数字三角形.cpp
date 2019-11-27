//http://bailian.openjudge.cn/practice/2760/
#include <iostream> 
using namespace std;

//int a[1000][1000];
const int N = (1 + 1000) * 1000 / 2;
int a[N] = { 0 }; //½ÚÊ¡¿Õ¼ä 

int main()
{
	int r, i, j, n, a1, a2, m;

	cin >> r;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j <= i; j++)
		{
			n = (1 + i) * i / 2 + j;
			//cin>>a[i][j];
			cin >> a[n];
		}
	}

	for (i = r - 2; i >= 0; i--)
	{
		for (j = i; j >= 0; j--)
		{
			//a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
			n = (1 + i) * i / 2 + j;
			a1 = a[n + i + 1];
			a2 = a[n + i + 2];
			m = a1 > a2 ? a1 : a2;
			a[n] += m;
		}
	}
	//cout<<a[0][0];
	cout << a[0];
	return 0;
}
