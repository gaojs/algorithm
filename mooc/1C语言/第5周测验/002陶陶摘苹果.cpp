#include<cstdio>
main() {
	int i,a[101]= {0},s=0,n=10,m;
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	m+=30;
	for(i=0; i<n; i++) {
		if(a[i]<=m) {
			s++;
		}
	}
	printf("%d",s);
}