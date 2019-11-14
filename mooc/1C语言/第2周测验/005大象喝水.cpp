#include<cstdio>
main() {
	int h,r,i;
	scanf("%d%d",&h,&r);
	for(i=1;; i++)if(3.14*r*r*h*i>20000)break;
	printf("%d",i);
}