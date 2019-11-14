#include<cstdio>
main() {
	int i,n,m,a[101]= {0},s=0;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0; i<=n; i++) {
		if(a[i]==m) s++;
	}
	printf("%d",s);
}