#include<cstdio>
main() {
	long long n,m;
	scanf("%lld",&n);
	while(n>1) {
		if(n%2) {
			m=n*3+1;
			printf("%lld*3+1=%lld\n",n,m);
			n=m;
		} else {
			m=n/2;
			printf("%lld/2=%lld\n",n,m);
			n=m;
		}
	}
	printf("End\n");
}