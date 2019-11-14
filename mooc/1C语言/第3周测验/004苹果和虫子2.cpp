#include<cstdio>
main() {
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	for(; n>0&&y>0; y-=x,n--);
	printf("%d",n);
}