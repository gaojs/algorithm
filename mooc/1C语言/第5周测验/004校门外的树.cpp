#include<cstdio>
main() {
	int a[10001]= {0},n,m,i,j,x,y,s=0;
	scanf("%d %d",&n,&m);
	for(i=0; i<m; i++) {
		scanf("%d %d",&x,&y);
		for(j=x; j<=y; j++)
			a[j]=1;
	}
	for(i=0; i<=n; i++) {
		if(a[i]==0)s++;
	}
	printf("%d",s);
}