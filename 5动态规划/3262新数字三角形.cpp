//http://bailian.openjudge.cn/practice/3262/
#include <iostream> 
using namespace std;

const int N = (1 + 100) * 100 / 2;
int a[N] = { 0 }; //½ÚÊ¡¿Õ¼ä 

int main()
{
	int n, i, j, t, a1, a2, m, r, c;

	while (cin >> n && n)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				t = (1 + i) * i / 2 + j;
				cin >> a[t];
			}
		}
		cin >> r >> c;

		for (i = n - 2; i >= 0; i--)
		{
			for (j = i; j >= 0; j--)
			{
				t = (1 + i) * i / 2 + j;
				a1 = a[t + i + 1];
				a2 = a[t + i + 2];
				m = a1 > a2 ? a1 : a2;
				a[t] = a[t] > m ? a[t] : m;
			}
		}
		t = (1 + r - 1) * (r - 1) / 2 + (c - 1);
		cout << a[t] << endl;
	}
	return 0;
}
