#include<cstdio>
main() {
	int a[100][100]= {0},m,n,i,j;
	scanf("%d %d", &m,&n);
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	for(j=0; j<n; j++) {
		for(i=0; i<m; i++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}