//https://www.luogu.org/problem/P5660
//�ַ���/�ַ�����/ѭ��/�ж�/������� 
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
