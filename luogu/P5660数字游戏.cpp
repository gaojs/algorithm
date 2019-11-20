//https://www.luogu.org/problem/P5660
//字符串/字符数组/循环/判断/输入输出 
#include <stdio.h>
int main()
{
	char a[10]={0};
	int i=0,n=0;
	scanf("%s",a);
	for(i=0;a[i];i++)
	{
		if(a[i]=='1')n++;
	}
	printf("%d", n);
} 
