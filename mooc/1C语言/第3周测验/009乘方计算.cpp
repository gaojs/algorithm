#include<cstdio>
main() {
	int a,n,s=1;
	scanf("%d %d",&a,&n);
	for(; n>0; n--)s*=a;
	printf("%d",s);
}