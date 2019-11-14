#include<cstdio>
main() {
	int a[100][100]= {0},b[100][100]= {0},m,n,i,j;
	scanf("%d %d", &n,&m);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d",&a[i][j]);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(i==0||i==n-1||j==0||j==m-1)
				b[i][j]=a[i][j];
			else b[i][j]=(a[i][j]+a[i+1][j]+a[i-1][j]+a[i][j+1]+a[i][j-1])/5.0+0.5;

	for(i=0; i<n; i++) {
		for(j=0; j<m; j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
}