#include<cstdio>
int a[1000000]= {0};
main() {
	int n,m,i;
	a[0]=1,a[1]=2;
	for(i=2; i<1000000; i++) {
		a[i]=(2*a[i-1]+a[i-2])%32767;
	}
	scanf("%d",&n);
	for(; n>0; n--) {
		scanf("%d",&m);
		printf("%d\n",a[m-1]);
	}
}