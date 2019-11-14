#include<cstdio>
main() {
	int a[5][5]= {0},i,j,x,y,r,c;
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			scanf("%d",&a[i][j]);
	for(i=0; i<5; i++)
		for(j=0; j<5; j++) {
			r=c=0;
			for(x=0; x<5; x++)
				if(a[i][j]<=a[x][j]) r++;
			for(y=0; y<5; y++)
				if(a[i][j]>=a[i][y]) c++;
			if(r==5&&c==5) {
				printf("%d %d %d",i+1,j+1,a[i][j]);
				return 0;
			}
		}
	printf("not found");
}