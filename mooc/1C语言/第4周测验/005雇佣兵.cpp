#include<cstdio>
main() {
	int m,n,x,t=0;
	scanf("%d %d %d",&m,&n,&x);
	while(x>0) {
		while(x>0&&t<m)	{
			x--;
			t+=n;
		}
		if(t>m)t=m;
		if(t==m) n+=t/n;
		t=0;
	}
	printf("%d",n);
}