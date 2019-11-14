#include<cstdio>
main() {
	int n,m=0,d,e=1;
	scanf("%d",&n);
	if(n<0) {
		n=-n;
		e=-1;
	}
	while(n>0) {
		d=n%10;
		m=m*10+d*e;
		n=n/10;
	}
	printf("%d",m);
}