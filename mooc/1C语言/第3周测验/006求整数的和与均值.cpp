#include<cstdio>
main() {
	long n,m, s=0,i;
	scanf("%ld",&n);
	for(i=0; i<n; i++) {
		scanf("%ld",&m);
		s+=m;
	}
	printf("%ld %.5lf",s,((double)s)/n);
}