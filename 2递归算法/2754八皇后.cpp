//http://bailian.openjudge.cn/practice/2754/
//使用递归算法，可以将多层循环转换成递归，简化思路 
//八皇后问题，从第一行开始摆放，后面每行检测是否冲突 
#include <cmath> //用到abs()
#include <iostream>
using namespace std;

//N是能支持的最大的行数和列数 (行列编号从1开始)
const int N = 10, M = 100;
//QueenPos[i]表示第i行的皇后所处的列数 (i从1开始)
int QueenPos[N + 1] = { 0 };
int QueenSol[M][N + 1] = { 0 };
static int QueenCount = 0; //解法数量

//查找n皇后问题的第k行的解决方法 
void Queen(int k, int n)
{
	int i, j;

	if (k > n)
	{//已经完成所有n行 
		if (QueenCount < M)
		{//将解法保存起来
			for (k = 1; k <= n; k++)
			{//k为行数
				//cout << QueenPos[k] << " ";
				QueenSol[QueenCount][k] = QueenPos[k];
			}
			//cout << endl;
		}
		QueenCount += 1;
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
	int n, r, c;

	//cout << "input n(n<=10):";
	cin >> n; //输入几行几列的n 
	QueenCount = 0; //解法数量
	Queen(1, 8); //从第1列开始 
	while (n--)
	{
		cin >> r;
		if (r > 0 && r < M)
		{
			for (c = 1; c <= 8; c++)
			{
				cout << QueenSol[r-1][c];
			}
			cout << endl;
		}
	}
	//cout << "共有 " << QueenCount << " 种放法!" << endl;
	return 0;
}
