#include<cstdio>
main() {
	int n,i,j,k,x=0,y=0,z=0;
	scanf("%d",&n);
	for(; n>0; n--) {
		scanf("%d %d %d",&i,&j,&k);
		x+=i;
		y+=j;
		z+=k;
	}
	printf("%d %d %d %d",x,y,z,x+y+z);
}