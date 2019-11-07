//使用递归算法，可以将多层循环转换成递归，简化思路 
//八皇后问题，从第一行开始摆放，后面每行检测是否冲突 
#include <cmath> //用到abs()
#include <iostream>
using namespace std;

//N是能支持的最大的行数和列数 (行列编号从1开始)
const int N = 100;
//QueenPos[i]表示第i行的皇后所处的列数 (i从1开始)
int QueenPos[N + 1] = { 0 };

//查找n皇后问题的第k行的解决方法 
void Queen(int k, int n)
{
	int i, j;

	if (k > n)
	{//已经完成所有n行 
		for (k = 1; k <= n; k++)
		{//k为行数
			cout << QueenPos[k] << " ";
		}
		cout << endl;
		return;
	}
	//查找第k行的摆放位置 
	for (i = 1; i <= n; i++)
	{//k为行数，i为列数 
		//检查它跟之前k-1行是否冲突 
		for (j = 1; j <= k - 1; j++)
		{//j为行数， QueenPos[j]为列数 
			if (i == QueenPos[j])
			{//列数相同，纵向冲突 
				break;
			}
			if (abs(k - j) == abs(i - QueenPos[j]))
			{//行差与列差相同，斜向冲突 
				break;
			}
		}
		if (j == k)
		{//不冲突 
			QueenPos[k] = i;
			//继续摆放下一行 
			Queen(k + 1, n);
		}
	}
}

int main()
{
	int n;

	cout << "input n(n<=100):";
	cin >> n; //输入几行几列的n 
	Queen(1, n); //从第1列开始 
	return 0;
}
