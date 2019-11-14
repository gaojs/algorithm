#include<cstdio>
main() {
	int n,a,b,x,y;
	float r,t;
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	r=(float)b/a;
	for(; n>1; n--) {
		scanf("%d %d",&x,&y);
		t=(float)y/x;
		if(t-r>0.05)printf("better\n");
		else if(r-t>0.05)printf("worse\n");
		else printf("same\n");
	}
}