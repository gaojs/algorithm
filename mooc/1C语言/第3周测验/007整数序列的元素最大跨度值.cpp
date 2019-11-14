#include<cstdio>
main() {
	int n,m,x,y;
	scanf("%d",&n);
	scanf("%d",&m);
	x=y=m;
	for(; n>1; n--) {
		scanf("%d",&m);
		if(x<m)x=m;
		if(y>m)y=m;
	}
	printf("%d",x-y);
}