//http://bailian.openjudge.cn/practice/2755/
#include <cstring> 
#include <iostream> 
using namespace std;

const int W = 40;//口袋容纳重量40
const int K = 20;//物品种类20种
//ways[w][k]从k中物品，凑出体积w的方法数
int ways[W + 1][K + 1]; 
int a[K + 1] = { 0 }; 

int main()
{
	int n, i, w, k;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(ways, 0, sizeof(ways));
	for (k = 0; k <= n; k++)
	{//只要不选，都是1种情况
		ways[0][k] = 1;
	}
	for (w = 1; w <= W; w++)
	{
		for (k = 1; k <= n; k++)
		{
			//不选a[k]的情况
			ways[w][k] = ways[w][k - 1];
			if ((w - a[k]) >= 0)
			{//选a[k]的情况
				ways[w][k] += ways[w - a[k]][k - 1];
			}
		}
	}
	cout << ways[40][n];
	return 0;
}
