#include<cstdio>
int a[1000000]= {0};
main() {
	int n,m,t;
	scanf("%d%d",&n,&m);
	while(1) {
		t=n%m;
		if(t==0) {
			printf("%d",m);
			break;
		} else {
			n=m,m=t;
		}
	}
}