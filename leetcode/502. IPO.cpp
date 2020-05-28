#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


int max = 0; // 最大收益

void dfs(int k, int w, int*p, int pn, int*c, int cn)
{
	if (k==0 || w< 0 || p == NULL || pn <= 0|| c == NULL || cn<=0) {
		return;
	}
	for (int i = 0; i < cn; i++) {
		if (w >= c[i]) { // 可以投资
			int w2 = w + p[i]; // 收益增加
			if (max < w2) {
				max = w2;
			}
			// 复制 深度搜索
			int pp[pn], cc[cn];
			for (int j = 0, i2 = 0; i2 < pn; i2++) {
				if (i2 != i) { // 滤掉已投资的这项
					pp[j] = p[i2];
					cc[j] = c[i2];
					j++;
				}
			}
			dfs(k-1, w2, pp, pn-1, cc, cn-1);
		}
	}
}

int findMaximizedCapital(int k, int w, int*p, int pn, int*c, int cn)
{
	if (p == NULL || pn <= 0|| c == NULL || cn<=0) {
		return 0;
	}
	max = 0;
	dfs(k, w, p, pn, c, cn);
	return max;
}

int main()
{
	int k=2, w=0, p[]={1,2,3}, c[]={0,1,1};
	int pn = sizeof(p) / sizeof(p[0]);
	int cn = sizeof(p) / sizeof(p[0]);
	printf("%d", findMaximizedCapital(k,w,p,pn,c,cn));
	return 0;
} 


